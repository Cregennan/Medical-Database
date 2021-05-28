#include "MedicalOrganization.h"
#include "Helper.h"
#include "fort.hpp"
MedicalOrganization::MedicalOrganization() {

}
void MedicalOrganization::AddCard(MedicalCard* Card) {
	this->Cards.push_back(Card);
	int hash = Card->GetHash();
	CardTable.Add(hash, Card);
}
void MedicalOrganization::RemapCardTable() {
	Tree<MedicalCard*> T;
	std::vector<MedicalCard*> _cards = this->Cards;
	while (!_cards.empty()) {
		MedicalCard* _card = _cards.back();
		T.Add(_card->GetHash(), _card);
		_cards.pop_back();
	}
	this->CardTable = T;
}
void MedicalOrganization::RemoveCard(int ID) {
	if (ID < 0 || ID > this->Cards.size() - 1) {
		throw std::exception("No such Medical Card");
	}
	this->Cards.erase(this->Cards.begin() + ID);
	RemapCardTable();
}
MedicalCard* MedicalOrganization::FindCard(std::string Name) {
	unsigned int hash = std::hash<std::string>{}(Name);
	MedicalCard* answer = this->CardTable.Find(hash);
	return answer;
}
void MedicalOrganization::Welcome() {
	std::cout << "+------------------------------------------------------+" << std::endl << "|        Welcome to RadioNurshat Medical Clinic        |" << std::endl << "+------------------------------------------------------+" << std::endl;
}

void MedicalOrganization::Load(std::string filename) {
	std::ifstream fin(filename);
	std::string line;
	while (std::getline(fin, line)) {
		//������� ������ �������� - �������, ������
		std::vector<std::string> FirstParsed = Helper::Parse(line, "=");
		std::vector<std::string> HumanSide = Helper::Parse(FirstParsed[0], "+");
		//������ ����� ��� ��������
		std::string Name = HumanSide[0];
		int Age = std::stoi(HumanSide[1]);
		//�������� ��������
		MedicalCard* Card = new MedicalCard(Name, Age);

		//������� ������ ��������, $ ��������� ������ � �����, # ���� �����, ������ 2 ���� - ����� � �������, ��������� ������
		std::vector<std::string> Records = Helper::Parse(FirstParsed[1], "$");
		for (std::string _Record : Records) {
			//���� �����
			std::vector<std::string> RecordParams = Helper::Parse(_Record, "#");
			std::string DateTime = RecordParams[0];
			std::string Diagnosis = RecordParams[1];
			//���������� �������� ������ 2 ���������
			RecordParams.erase(RecordParams.begin());
			RecordParams.erase(RecordParams.begin());
			Record* _R = new Record(DateTime, Diagnosis, RecordParams);
			Card->AddRecord(_R);
		}
		//�������� � ������ � � ������
		this->AddCard(Card);
	}
	fin.close();
}


void MedicalOrganization::Save(std::string filename) {
	std::ofstream fout(filename);
	//for(int i = 0; i<this->Cards.size() -1; i++){
	//}
	for (MedicalCard* Card : this->Cards) {
		fout << Card->Format2File() << std::endl;
	}
	fout.close();
}
void MedicalOrganization::PrintAllCards() {
	for (MedicalCard* Card : this->Cards) {
		std::cout << Card->Format2Row() << std::endl;
	}
}
void MedicalOrganization::PrintCardsArray() {
	fort::char_table table;
	table << fort::header << "ID" << "Name" << fort::endr;
	for (int i = 0; i < this->Cards.size(); i++) {
		table << i << this->Cards[i]->Name << fort::endr;
	}
	std::cout << table.to_string() << std::endl;
}
void MedicalOrganization::EditCardDecorator() {
	while (true) {
		this->PrintCardsArray();
		int i = Helper::RequireInt("Enter MedicalCard ID");
		if (this->Cards.size() == 0) {
			std::cout << "No Cards in Organization" << std::endl;
			continue;
		}
		if (i > this->Cards.size() - 1 || i < 0) {
			std::cout << "Invalid Card ID" << std::endl;
			continue;
		}
		Helper::EditMedicalCard(this->Cards[i]);
		std::string again = Helper::RequireString("Do you want to edit another Medical Card? Enter y or n");
		if (again == "n") {
			break;
		}
		else {
			continue;
		}
	}
	
}