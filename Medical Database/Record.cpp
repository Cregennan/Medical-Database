#include "Record.h"
Record::Record(std::string DateTime, std::string Diagnosis, std::vector<std::string> Results) {
	this->DateTime = DateTime;
	this->Diagnosis = Diagnosis;
	this->Results = Results;
}
std::string Record::Format2File() {
	std::string s;
	s += this->DateTime + "#" + this->Diagnosis;
	for (std::string a : this->Results) {
		s += "#" + a;
	}
	return s;
}
