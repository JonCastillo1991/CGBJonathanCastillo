#pragma once
#include <string>
#include <string.h>
#include <iostream>
#include <list>
#define stringify( name ) #name

using namespace std;

class base {
public:
	//pure virtual function
	virtual void print();
};

void base::print() {
		cout << "Weapon Name: ";
		cout << "Description: ";
		cout << "Manufacturer: ";
		cout << "Type: ";
		cout << "Rarity: ";
		cout << "Element: ";
}

class weapon : public base {
public:
	string weaponName;
	string description;
	string manufactuer;
	string type;
	string rarity;
	string element;
	string ammo;
	void print() {
		cout << "Weapon Name: " << weaponName << endl;
		cout << "Description: " << description << endl;
		cout << "Manufacturer: " << manufactuer << endl;
		cout << "Type: " << type << endl;
		cout << "Rarity: " << rarity << endl;
		cout << "Element: " << element << endl;
	}
};

class backpack : public base {
public:

	list<weapon*> weaponList;
	virtual void print() {
		list<weapon*>::iterator weaponIt = weaponList.begin();
		for (list<weapon*>::iterator weaponIt = weaponList.begin(); weaponIt != weaponList.end(); weaponIt++) {
			(*weaponIt)->print();
		}
		system("pause");
	}
};

enum weaponType {
	Combat_Rifle,
	Repeater_Pistol,
	Revolver,
	Launcher,
	Shotgun,
	SMG,
	Sniper_Rifle,
	weaponMAX
};
const char* convert_weaponType[] = {
	stringify( Combat_Rifle ),
	stringify( Repeater_Pistol ),
	stringify( Revolver ),
	stringify( Launcher ),
	stringify( Shotgun ),
	stringify( SMG ),
	stringify( Sniper_Rifle)
};

enum rarityType {
	Common,
	Uncommon,
	Rare,
	Epic,
	Legendary,
	rarityMAX
};
const char* convert_rarityType[] = {
	stringify( Common ),
	stringify( Uncommon ),
	stringify( Rare ),
	stringify( Epic ),
	stringify( Legendary )
};

enum elementType {
	NonElemental,
	Fire,
	Corrosive,
	Shock,
	Cryo,
	Radiation,
	elementMAX
};
const char* convert_elementType[] = {
	stringify( NonElemental ),
	stringify( Fire ),
	stringify( Corrosive ),
	stringify( Shock ),
	stringify( Cryo ),
	stringify( Radiation )
};

enum manufacturerType {
	Atlas,
	Bandit,
	Dahl,
	Eridians,
	Gearbox,
	Hyperion,
	Jakobs,
	Maliwan,
	S_SMunitions,
	Tediore,
	Torgue,
	Vladof,
	manufacturerMAX
};
const char* convert_manufactureType[] = {
	stringify( Atlas ),
	stringify( Bandit ),
	stringify( Dahl ),
	stringify( Eridians ),
	stringify( Gearbox ),
	stringify( Hyperion ),
	stringify( Jakobs ),
	stringify( Maliwan ),
	stringify( S_SMunitions ),
	stringify( Tediore ),
	stringify( Torgue ),
	stringify( Vladof )
};