#pragma once

#include <vector>
#include "Creature.h"
#include "Item.h"

using namespace std;

class Monster :
    protected Creature
{
    //vector<Item*> lootsDrop;

public:
    //CONSTRUCTOR & DESTRUCTOR
    Monster();
    ~Monster();
    Monster(string _creatureName, string _creatureDescription, int _creatureHp, vector<Attack> &_attacksMoveset, int _creatureDefense, string _creatureCatchPhrase, Inventory* _creatureInventory);

    //GET
    //vector<Item*> GetLootsDrop() { return creatureInventory->GetItemsInventory(); };

    void UseMagicEffect();

};

