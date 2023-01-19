#include <iostream>
#include <string>
#include <string.h>
#include "classes.h"


using namespace std;

void addWeaponsToBackpack();
void navigateBackpack();
void printBackPack();
void generateDescription(weapon* weaponAux);

int choice = 1;
backpack* ptrBackpack;

void main() {
	ptrBackpack = new backpack;
	int weaponType = 0;
	int weaponRarity = 0;
	int weaponElement = 0;
	int weaponManufacturer = 0;
	for (int i = 0; i < 35; i++) {
		weapon* weaponAux;
		weaponAux = new weapon;
		if (weaponType == weaponMAX) {
			weaponType = 0;
		}
		if (weaponRarity == rarityMAX) {
			weaponRarity = 0;
		}
		if (weaponElement == elementMAX) {
			weaponElement = 0;
		}
		if (weaponManufacturer == manufacturerMAX) {
			weaponManufacturer = 0;
		}
		weaponAux->weaponName = "Weapon " + to_string(i);
		weaponAux->manufactuer = convert_manufactureType[weaponManufacturer];
		weaponAux->type = convert_weaponType[weaponType];
		weaponAux->rarity = convert_rarityType[weaponRarity];
		weaponAux->element = convert_elementType[weaponElement];
		weaponType++;
		weaponRarity++;
		weaponElement++;
		weaponManufacturer++;
		generateDescription(weaponAux);
		ptrBackpack->weaponList.push_back(weaponAux);
	}
	while (choice != 0)
	{
		system("cls");
		cout << "1) Add Weapon to backpack \n2) Navigate Backpack \n3)Print Backpack \n0)Exit \nChoice:";
		cin >> choice;
		switch (choice) {
		case 1: 
			addWeaponsToBackpack();
			break;
		case 2:
			navigateBackpack();
			break;
		case 3:
			printBackPack();
			break;
		case 0:
			break;
		default:
			break;
		}
	}
}

void addWeaponsToBackpack() {
	weapon* weaponAux;
	weaponAux = new weapon;
	int aux = 0;
	cout << "Please Enter New Weapon Name:";
	cin >> weaponAux->weaponName;
	cout << "\n";
	for (int i = 0; i < weaponMAX; i++) {
		cout << i << ")" << convert_weaponType[i] << endl;
	}
	cout << "Please enter weapon type (use the number):";
	cin >> aux;
	weaponAux->type = convert_weaponType[aux];
	cout << endl;
	for (int i = 0; i < rarityMAX; i++) {
		cout << i << ")" << convert_rarityType[i] << endl;
	}
	cout << "Please enter rarity type (use the number):";
	cin >> aux;
	weaponAux->rarity = convert_rarityType[aux];
	cout << endl;
	for (int i = 0; i < elementMAX; i++) {
		cout << i << ")" << convert_elementType[i] << endl;
	}
	cout << "Please enter element type (use the number):";
	cin >> aux;
	weaponAux->element = convert_elementType[aux];
	cout << endl;
	for (int i = 0; i < manufacturerMAX; i++) {
		cout << i << ")" << convert_manufactureType[i] << endl;
	}
	cout << "Please enter manufacturer type (use the number):";
	cin >> aux;
	weaponAux->manufactuer = convert_manufactureType[aux];
	cout << "Would you like to autogenerate the description? \n1)Yes \n2)No";
	int auxChoice;
	cin >> auxChoice;
	if (auxChoice == 1) {
		generateDescription(weaponAux);
	}
	else {
		cout << "\nPlease enter your description: ";
		cin >> weaponAux->description;
	}
	ptrBackpack->weaponList.push_back(weaponAux);
}

void navigateBackpack() {
	if (ptrBackpack->weaponList.empty())
	{
		cout << "Backpack is empty!";
	}
	else {
		system("cls");
		int numOfResultsByPage;
		cout << "How many results do you want per page?:";
		cin >> numOfResultsByPage;
		int i = ptrBackpack->weaponList.size();
		int pages = ceil(i / numOfResultsByPage);
		int onPage = 0;
		int pageOption = 0;
		list<weapon*>::iterator weaponIt = ptrBackpack->weaponList.begin();
		while (pageOption != 3) {
			cout << "Page" << onPage + 1 << "/" << pages + 1 << endl;
			cout << "Current Weapons in Backpack" << endl;
			switch (pageOption) {
			case 1: 
				if (onPage != 0){
					onPage--;
					for (int j = 0; j < numOfResultsByPage * 2; j++) {
						if (weaponIt != ptrBackpack->weaponList.end()) {
							weaponIt--;
						}
					}
				}
				break;
			case 2:
				if (onPage < pages) {
					onPage++;
				}
				break;
			case 3:
				break;
			}
			for (int i = 0; i < numOfResultsByPage && weaponIt != ptrBackpack->weaponList.end(); i++) {
				cout << (*weaponIt)->weaponName << endl;
				weaponIt++;
			}
			cout << "\n\n 1)Previous Page \n2)Next Page \n3)Exit";
			cin >> pageOption;
		}
		system("pause");
	}
}

void printBackPack() {
	ptrBackpack->print();
}

void generateDescription(weapon* weaponAux) {
	weaponAux->description = weaponAux->weaponName + " is the title of a group " + weaponAux->rarity + " of " + weaponAux->type + " in Borderlands 3 manufactured by " + weaponAux->manufactuer;
}