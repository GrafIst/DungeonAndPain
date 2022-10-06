#pragma once

#include "Creature.h"
#include "ECharacterRace.h"
#include "ECharacterJob.h"

//#include "Merchant.h"

using namespace std;


class Character :
    public Creature
{
protected:
    string characterLastName;
    int characterMoney;
    ECharacterRace characterRace;
    ECharacterJob characterJob;
    int weaponAmount;

public:
    
    //CONSTRUCTOR & DESTRUCTOR
    Character();
    ~Character();
    /*Character(string _creatureName, string _creatureDescription, int _creatureHp, vector<Attack> _creatureAttacksMoveset, int _creatureDefense, string _creatureCatchPhrase, 
        string _characterLastName, int _characterMoney, Weapon _characterWeapon, ECharacterRace _characterRace, ECharacterJob _characterJob);*/
    Character(string _creatureName, string _characterLastName, string _creatureDescription, int _creatureHp, vector<Attack> _creatureAttacksMoveset, int _creatureDefense, string _creatureCatchPhrase, Inventory* _creatureInventory,
         int _characterMoney, ECharacterRace _characterRace, ECharacterJob _characterJob);

    Character(string _creatureName, string _characterLastName, string _creatureDescription, string _creatureCatchPhrase, Inventory* _creatureInventory, int _characterMoney, ECharacterRace _characterRace);

    //GET & SET
    string GetCharacterLastName() { return characterLastName; };
    int GetCharacterMoney() { return characterMoney; };
    //Weapon* GetCharacterWeapon() { return characterWeapon; };
    ECharacterRace GetCharacterRace() { return characterRace; };
    ECharacterJob GetCharacterJob() { return characterJob; };
    int GetWeaponAmount() { return weaponAmount; };
    void AddWeaponAmount(int _amountOfWeapon) { weaponAmount + _amountOfWeapon; };


    //METHOD
    void Loot(Character* _character);
    void AddMoney(int _money);

    void AnnounceWeapon();
};

