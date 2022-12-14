#include "Creature.h"

//CONSTRUCTOR & DESTRUCTOR
Creature::Creature() {
	creatureName = "Default Creature";
	creatureDescription = "A simple basic creature";
	creatureHp = 10;
	creatureAttacksMoveset.push_back(Attack());
	creatureDefense = 5;
	creatureCatchPhrase = "Oh hi";
	creatureInventory = new Inventory();
	SetType(EMagicType::Ice);
}

Creature::~Creature() {
	creatureAttacksMoveset.~vector();
}

Creature::Creature(string _creatureName, string _creatureDescription, int _creatureHp, vector<Attack>& _creatureAttacksMoveset, int _creatureDefense, string _creatureCatchPhrase, Inventory* _creatureInventory) {
	creatureName = _creatureName;
	creatureDescription = _creatureDescription;
	creatureHp = _creatureHp;
	creatureAttacksMoveset = _creatureAttacksMoveset;
	creatureDefense = _creatureDefense;
	creatureCatchPhrase = _creatureCatchPhrase;
	creatureInventory = _creatureInventory;
}

Creature::Creature(string _creatureName, string _creatureDescription, string _creatureCatchPhrase)
{
	creatureName = _creatureName;
	creatureDescription = _creatureDescription;
	creatureCatchPhrase = _creatureCatchPhrase;
}

//METHODS

void Creature::AttackCreature(Creature* _creatureTarget) {

}

void Creature::Heal() {

}

void Creature::Introduce() {
	cout << "Hi, I'm " << creatureName << ". " << creatureCatchPhrase << endl;
}

//SET
void Creature::SufferDamage(int _damage) {

}

void Creature::AddMoveToMoveset(Attack _attack)
{
	creatureAttacksMoveset.push_back(_attack);
}

void Creature::UseMagicEffect()
{
	cout << "do some magic" << endl;
}


