#pragma once

#include "Creature.h"
#include "Character.h"
#include <math.h>

class Merchant :
    public Creature //QUESTION : does this correspond to a type of inheritance or access specifier ?
{
    string merchantShopName;
    vector<Weapon*> merchantWeaponStock;

public:
    //CONSTRUCTOR & DESTRUCTOR
    Merchant();
    ~Merchant();
    Merchant(string _creatureName, string _creatureDescription, string _creatureCatchPhrase, Inventory* _creatureInventory,
        string _merchantShopName, vector<Weapon*> _merchantWeaponStock);

    //GET
    string GetMerchantShopName() { return merchantShopName; };
    //vector<Weapon*> GetMerchantWeaponStock() { return merchantWeaponStock; };

    //METHOD
    void AddWeaponToStock(Weapon &_weapon); //it should add a reference of a weapon and not a copy with this
    void ShowStock();
    void SellWeaponTo(Character* _character);
    void BuyWeaponFrom(Character* _character);

    //if i want my Merchant (child) to use Introduce() (from Parent of Parent), i need to have Parent encapsulation in header to be public and not protected

    void UseMagicEffect();


};

