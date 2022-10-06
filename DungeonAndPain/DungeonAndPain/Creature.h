#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Attack.h"
#include "Inventory.h"
#include "IMagicEffect.h"

using namespace std;

class Creature : public IMagicEffect
{
protected:
	string creatureName;
	string creatureDescription;
	int creatureHp;
	vector<Attack> creatureAttacksMoveset;
	int creatureDefense;
	string creatureCatchPhrase;
	Inventory* creatureInventory;

public:
	//CONSTRUCTOR & DESTRUCTOR
	Creature();
	~Creature();
	Creature(string _creatureName, string _creatureDescription, int _creatureHp, vector<Attack> _creatureAttacksMoveset, int _creatureDefense, string _creatureCatchPhrase, Inventory* _creatureInventory);

	//GET
	string GetName() { return creatureName; };
	string GetDescription() { return creatureDescription; };
	int GetHp() { return creatureHp; };
	vector<Attack> GetAttackMoveser() { return creatureAttacksMoveset; };
	int GetDefense() { return creatureDefense; };
	string GetCatchPhrase() { return creatureCatchPhrase; };
	Inventory* GetCreatureInventory() { return creatureInventory; };

	//METHODS
	void AttackCreature(Creature* _creatureTarget);
	void Heal();
	void Introduce();

	//SET
	void SufferDamage(int _damage);
	void AddMoveToMoveset(Attack _attack);


	//IMPLEMENTATION OF INTERFACE
	void UseMagicEffect();

};

