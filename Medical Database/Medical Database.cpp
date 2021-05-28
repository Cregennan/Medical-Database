
#include <iostream>
#include "MedicalOrganization.h"
#include "Helper.h"
#include "fort.hpp"
using namespace std;

int main()
{

	setlocale(0, "ru");
	MedicalOrganization Centre;
	Centre.Welcome();
	Centre.Load("database.txt");
	MedicalCard* LastCard = nullptr;
	Record* LastRecord = nullptr;

	
		while (true) {
			cout <<endl<< "Enter action" << endl;
			cout << "1: Create Medical Card" << endl;
			cout << "2: Delete Medical Card" << endl;
			cout << "3: Show All Medical Cards" << endl;
			cout << "4: Find Medical Card" << endl;
			cout << "5: Edit Medical Card" << endl;

			cout << "0: Save and exit" << endl;
			int option = 0;
			try {
				option = Helper::RequireInt("");
			}
			catch (std::exception e) {
				cout << e.what() << endl;
				continue;
			}
			
			
			if (option == 1) {
				MedicalCard* Card = Helper::CreateMedicalCard();
				Centre.AddCard(Card);
				Centre.PrintAllCards();
			}
			if (option == 2) {
				while (true) {
					try {
						Centre.PrintCardsArray();
						int id = Helper::RequireInt("Choose ID from Table Above");
						Centre.RemoveCard(id);
						cout << "Medical Card Deleted." << endl;
						break;
					}
					catch (std::exception e) {
						cout << e.what() << endl;
					}
				}
			}
			if (option == 3) {
				Centre.PrintAllCards();
			}
			if (option == 4) {
				try {

					std::string Name = Helper::RequireString("Enter Patient's name");
					MedicalCard* Card = Centre.FindCard(Name);
					cout << Card->Format2Row() << endl;

				}
				catch (std::exception e) {
					cout << e.what() << endl;
				}
			}
			if (option == 5) {
				try {
					Centre.EditCardDecorator();
				}
				catch (std::exception e) {
					cout << e.what() << endl;
				}
			}

			if (option == 0) {
				Centre.Save("database.txt");
				break;
			}
		}
	
}

