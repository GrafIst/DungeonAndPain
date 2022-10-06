#include "Monster.h"

Monster::Monster():Creature()
{
	creatureCatchPhrase = "Growl, i'm a monster";
	lootsDrop.push_back(Item());
}

Monster::~Monster()
{
	lootsDrop.~vector();
}

Monster::Monster(string _creatureName, string _creatureDescription, int _creatureHp, vector<Attack> _creatureAttacksMoveset, int _creatureDefense, string _creatureCatchPhrase, Inventory* _creatureInventory
	, vector<Item> _lootsDrop)
	:Creature(_creatureName, _creatureDescription, _creatureHp, _creatureAttacksMoveset, _creatureDefense, _creatureCatchPhrase, _creatureInventory)
{
	lootsDrop = _lootsDrop;
}