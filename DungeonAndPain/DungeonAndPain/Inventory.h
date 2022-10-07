#pragma once
#include <vector>
#include "Item.h"
#include "Weapon.h"

using namespace std;


class Inventory
{
	vector<Item*> itemsInventory;
	vector<Weapon*> weaponInventory;

public:
	//CONSTRUCTOR & DESTRUCTOR
	Inventory();
	~Inventory();
	Inventory(vector<Item*> _itemsInventory);
	Inventory(vector<Weapon*> _weaponsInventory);
	
	//GET
	vector<Item*> GetItemsInventory() { return itemsInventory; };
	vector<Weapon* > GetWeaponsInventory() { return weaponInventory; };
	Item* GetItemFromInventory(int _indexItem) { return itemsInventory[_indexItem]; };
	Weapon* GetWeaponFromInventory(int _indexWeapon) { return weaponInventory[_indexWeapon]; };

	Weapon* GetFirstWeapon();
	int SelectWeapon();

	//METHOD
	void AddItemToInventory(Item* _item);
	void AddItemToInventory(vector<Item*> _items);
	void RemoveItemFromInventory(Item* _item, int _indexItem);
	
};

