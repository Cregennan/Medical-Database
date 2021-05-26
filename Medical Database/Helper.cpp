#include "Helper.h"
#include <iostream>
#include "MedicalOrganization.h"
#include "MedicalCard.h"
#include "Record.h"
#include <sstream>
#include <exception>
std::vector<std::string> Helper::Parse(std::string haystack, std::string needle) {
    std::vector<std::string> a;
    std::string s = haystack;
    std::string delimiter = needle;

    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        a.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    a.push_back(s);
    return a;
}

std::string Helper::RequireString(std::string message = "") {
    std::cout << message << std::endl << "> ";
    std::string s;
    std::getline(std::cin, s);
    std::cout << std::endl;
    std::cin.clear();
    return s;
}
int Helper::RequireInt(std::string message = "") {
    int a = 0;
    std::cout << message << std::endl << "> ";
    std::string line;
    std::getline(std::cin, line);
    std::istringstream tmp(line);
    tmp >> a >> std::ws;
    std::cout << std::endl;
    std::cin.clear();
    return a;
}

MedicalCard* Helper::CreateMedicalCard() {
    MedicalCard* Card;

    std::string Name = Helper::RequireString("Enter patient name.");
    int Age = Helper::RequireInt("Enter patient age");
    Card = new MedicalCard(Name, Age);
    std::cout << "Do you want to create Records to this Patient?" << std::endl << "Type YES or NO";
    std::string dorecord = Helper::RequireString();
    if (dorecord == "YES") {
        while (true) {
            Record* R = Helper::CreateRecord();
            Card->AddRecord(R);
            std::string again = Helper::RequireString("Do you want to add another Record fot this patient? Enter YES or NO");
            if (again == "NO") {
                break;
            }
        }
    }
    return Card;
}
Record* Helper::CreateRecord() {
    std::string DateTime = Helper::RequireString("Enter session DateTime");
    std::string Diagnosis = Helper::RequireString("Enter patient's diagnosis");
    std::string _Recs = Helper::RequireString("Enter recomendations divided by comma");
    std::vector<std::string> Recs = Helper::Parse(_Recs, ",");

    Record* R = new Record(DateTime, Diagnosis, Recs);
    return R;
}
