#pragma once
#include "MedicalCard.h"
#include "Tree.h"
#include "Record.h"
#include <iostream>
#include <fstream>
class MedicalOrganization
{
	Tree<MedicalCard*> CardTable;
	std::vector<MedicalCard*> Cards;
	void RemapCardTable();
	std::string Format2File();

public:
	/*����������� �����������*/
	MedicalOrganization();
	/*���������� �����*/
	void AddCard(MedicalCard* Card);
	/*
	* �������� �����.
	* @param ID - id ����� � �������
	*/
	void RemoveCard(int ID);
	/*
	* ����� ����� �������� �� �����
	* � ������, ���� � ���� ��� ���������� �����, ����� ������������� ����������
	*/
	MedicalCard* FindCard(std::string Name);
	void Welcome();
	void Load(std::string filename);
	void Save(std::string filename);
	void PrintAllCards();
	void PrintCardsArray();
	void EditCardDecorator();
	

};

