#include "Weapon.h"

Weapon::Weapon():Item()
{
	itemType = EItemType::ItemDefault;
	weaponType = EWeaponType::Sword;
	weaponDamage = 3;
	weaponDurability = 1;
}

Weapon::~Weapon()
{
}

Weapon::Weapon(string _itemName, string _itemDescription, float _itemWeight, int _itemPrice, EWeaponType _weaponType, int _weaponDamage, float _weaponDurability, EItemType _itemType)
	:Item(_itemType ,_itemName, _itemDescription, _itemWeight, _itemPrice) //when adding parent constructor, need to have the exact same order than the parent constructor. Need the same name in Parent and Child here, but i can change between file but i wouldn't recommend it
{
	itemType = _itemType;
	weaponType = _weaponType;
	weaponDamage = _weaponDamage;
	weaponDurability = (_weaponDurability >= 0 && _weaponDurability <= 1) ? _weaponDurability : 1;
}

void Weapon::DecreaseDurability()
{
	weaponDurability -= 0.05;
	if (weaponDurability <= 0) {
		WeaponBreak();
	}
}

void Weapon::WeaponBreak()
{
	cout << "Oh no the weapon broke" << endl;
	Weapon::~Weapon();
}

void Weapon::WeaponSell()
{
	cout << "You sold your weapon" << endl;
	Weapon::~Weapon();
}
