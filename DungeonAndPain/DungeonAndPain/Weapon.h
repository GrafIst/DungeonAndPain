#pragma once
#include "Item.h"
#include "EWeaponType.h"

class Weapon :
    public Item
{
    EWeaponType weaponType;
    int weaponDamage;
    float weaponDurability;

public:
    Weapon();
    ~Weapon();
    Weapon(string _itemName, string _itemDescription, float _itemWeight, int _itemPrice,
        EWeaponType _weaponType, int _weaponDamage, float _weaponDurability, EItemType _itemType=EItemType::ItemDefault);
    //This constructor combine Parent Constructor (Item) and Child Constructor (Weapon)

    //GET
    EWeaponType GetWeaponType() { return weaponType; };
    int GetWeaponDamage() { return weaponDamage; };
    float GetWeaponDurability() { return weaponDurability; };

    //METHOD
    void DecreaseDurability();
    void WeaponBreak();
    void WeaponSell();

};

