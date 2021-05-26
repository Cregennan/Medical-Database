#pragma once
#include <string>
#include <vector>
class Record
{
	friend class MedicalCard;
	std::string DateTime;
	std::string Diagnosis;
	std::vector<std::string> Results;
public:
	std::string Format2File();
	Record(std::string DateTime, std::string Diagnosis, std::vector<std::string> Results);
};

