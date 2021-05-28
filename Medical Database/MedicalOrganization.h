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
	/*Стандартный конструктор*/
	MedicalOrganization();
	/*Добавление карты*/
	void AddCard(MedicalCard* Card);
	/*
	* Удаление карты.
	* @param ID - id карты в таблице
	*/
	void RemoveCard(int ID);
	/*
	* Поиск карты человека по имени
	* В случае, если в базе нет подходяшей карты, будет сгенерировано исключение
	*/
	MedicalCard* FindCard(std::string Name);
	void Welcome();
	void Load(std::string filename);
	void Save(std::string filename);
	void PrintAllCards();
	void PrintCardsArray();
	void EditCardDecorator();
	

};

