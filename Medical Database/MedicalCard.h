#pragma once
#include <exception>
#include <functional>
#include "Record.h"
class MedicalCard 
{
    std::string Name;
    int Age;
    std::vector<Record*> Records;
    
public:
    friend class MedicalOrganization;
    friend class Helper;
    unsigned int GetHash();
    void AddRecord(Record* record);
    void RemoveRecord(int ID);
    MedicalCard(std::string Name, int Age);
    std::string ToString();
    std::string Format2File();
    std::string Format2Row();
};

