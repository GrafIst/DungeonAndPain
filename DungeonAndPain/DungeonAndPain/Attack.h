#pragma once
#include <string>
#include "Weapon.h";

#include "EDamageType.h"

using namespace std;

class Attack
{
	string attackName;
	Weapon* attackWeapon;
	int attackDamagePoints;
	EDamageType attackDamageType;
	int attackBonus;

public:
	//CONSTRUCTOR & DESTRUCTOR
	Attack();
	~Attack();
	Attack(string _attackName, Weapon* _attackWeapon, int _attackDamagePoints, EDamageType _attackDamageType, int _attackBonus);

	//GET
	string GetAttackName() { return attackName; };
	Weapon* GetAttackWeapon() { return attackWeapon; };
	int GetAttackDamagePoints() { return attackDamagePoints; };
	EDamageType GetDamageType() { return attackDamageType; };
	int GetAttackBonus() { return attackBonus; };

	//METHODS
	bool CanHurt();

};

