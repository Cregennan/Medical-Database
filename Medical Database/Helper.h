#pragma once
#include <string>
#include <vector>
#include "MedicalCard.h"
#include "Record.h"
class Helper
{
public:
	static std::vector<std::string> Parse(std::string haystack, std::string needle);
	static std::string RequireString(std::string message);
	static int RequireInt(std::string message);
	static MedicalCard* CreateMedicalCard();
	static Record* CreateRecord();
	static void EditMedicalCard(MedicalCard* Card);
	static void EditMedicalCardRecords(MedicalCard* Card);


};

