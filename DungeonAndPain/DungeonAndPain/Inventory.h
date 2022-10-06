#pragma once
#include <vector>
#include "Item.h"
#include "Weapon.h"

using namespace std;


class Inventory
{
	vector<Item*> itemsInventory;

public:
	//CONSTRUCTOR & DESTRUCTOR
	Inventory();
	~Inventory();
	Inventory(vector<Item*> _itemsInventory);
	
	//GET
	vector<Item*> GetItemsInventory() { return itemsInventory; };
	Item* GetItemFromInventory(int _indexItem) { return itemsInventory[_indexItem]; };
	Weapon* GetAllWeaponsFromInventory();
	Item* GetFirstWeapon();

	//METHOD
	void AddItemToInventory(Item* _item);
	void AddItemToInventory(vector<Item*> _items);
	void RemoveItemFromInventory(Item* _item, int _indexItem);
	
};

