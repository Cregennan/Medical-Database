#include "MedicalCard.h"
#include "Helper.h"
#include <iostream>
#include "fort.hpp"
MedicalCard::MedicalCard(std::string Name, int Age) {
	this->Name = Name;
	this->Age = Age;
}

void MedicalCard::AddRecord(Record* record) {
	this->Records.push_back(record);
}
void MedicalCard::RemoveRecord(int ID) {
	if (ID < 0 || ID > this->Records.size() - 1) {
		throw std::exception("No such Record");
	}
	this->Records.erase(this->Records.begin() + ID);
}
unsigned int MedicalCard::GetHash() {
	return (unsigned) std::hash<std::string>{}(this->Name);
}
std::string MedicalCard::ToString() {
	return this->Name;
}
std::string MedicalCard::Format2File() {
	std::string s;
	s += this->Name + "+" + std::to_string(this->Age) + "=";
	for(Record* R: this->Records){
		s += R->Format2File() + "$";
	}
	s.erase(s.size() - 1);
	return s;
}
std::string MedicalCard::Format2Row() {
	std::string s;
	//s += "NAME: " + this->Name + "   AGE: " + std::to_string(this->Age) + "\n";

	fort::char_table table;
	table << fort::header << "PATIENT: " + this->Name + ", AGE: " + std::to_string(this->Age) << fort::endr;
	std::string rec_exists = (this->Records.size() > 0) ? "" : ": NONE";
	table << fort::header << "RECORDS" + rec_exists << fort::endr;

	if (this->Records.size() > 0) {
		table << fort::header << "ID" << "DateTime" << "Diagnosis" << "Recommendations" << fort::endr;
	}
	
	for(int i =0; i< this->Records.size(); i++){

		std::string Res;
		for (std::string s : this->Records[i]->Results) {
			Res += s + ", ";
		}
		Res.erase(Res.size() -1);
		table << i << this->Records[i]->DateTime << this->Records[i]->Diagnosis << Res << fort::endr;
	}

	return table.to_string();

}
