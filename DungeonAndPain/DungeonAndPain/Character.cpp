#include "Character.h"

Character::Character():Creature()
{
    characterLastName = "LastName";
    characterMoney = 100;
    //Weapon defaultSword("DefaultSword", "ADefaultSword", 1, 1, Sword, 1, 1);
    //characterWeapon = new Weapon(); //use new to pointer to new object
    characterRace = ECharacterRace::Human;
    characterJob = ECharacterJob::Villager;
    weaponAmount = 1;
}

Character::~Character()
{

}

Character::Character(string _creatureName, string _characterLastName, string _creatureDescription, int _creatureHp, vector<Attack> _creatureAttacksMoveset, int _creatureDefense, string _creatureCatchPhrase, Inventory* _creatureInventory, 
    int _characterMoney, ECharacterRace _characterRace, ECharacterJob _characterJob)
	:Creature(_creatureName, _creatureDescription, _creatureHp, _creatureAttacksMoveset, _creatureDefense, _creatureCatchPhrase, _creatureInventory) 
    //_characterLastName -> I can change the order of the child constructor (mix between Child & Parents parameters) if I also change the order in the header file
{
    characterLastName = _characterLastName;
    characterMoney = _characterMoney;
    //characterWeapon = _characterWeapon;
    characterRace = _characterRace;
    characterJob = _characterJob;
    weaponAmount = 1;
}

void Character::Loot(Character* _character)
{
    cout << "He take the money of the defeated character" << endl;
    characterMoney + _character->GetCharacterMoney();
    cout << "His weapon is " << _character->GetCharacterWeapon()->GetItemName() << ". " << _character->GetCharacterWeapon()->GetItemDescription();
    cout << "Will he switch it with his own weapon " << characterWeapon->GetItemName() << "or ignore it ? (y/n)" << endl;
    char answer;
    cin >> answer;
    if (answer == 'y') {
        SwitchWeapon(_character);
    }
    else {
        cout << "He keeps his current weapon" << endl;
    }
}

//void Character::SwitchWeapon(Character* _character)
//{
//    characterWeapon = _character->GetCharacterWeapon();
//    cout << "He switches his own weapon with the one from the defeated enemy" << endl;
//}
//
//void Character::SwitchWeapon(Item* _weapon)
//{
//    characterWeapon = _weapon;
//    cout << "He switches his own weapon with the new one" << endl;
//}



void Character::AddMoney(int _money)
{
    characterMoney += _money;
}

void Character::AnnounceWeapon()
{
    Inventory tempWeaponInventory;

    for (Item* _item : creatureInventory->GetItemsInventory()) {
        int i = 0;
        if (_item->GetItemType() == EItemType::WeaponType) {
            i++;
            tempWeaponInventory.AddItemToInventory(_item);
            cout << i << "- " << _item->GetItemName() << " - " << _item->GetItemDescription() << endl;
        }
    }
}

//void Character::Buy(Merchant& _merchant)
//{
//
//}
//
//void Character::Sell(Merchant& _merchant)
//{
//
//}
