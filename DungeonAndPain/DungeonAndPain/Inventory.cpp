#include "Inventory.h"

Inventory::Inventory()
{
	itemsInventory.push_back(new Item());
}

Inventory::~Inventory()
{
	//need to delete all my pointer in my destructors
	for (Item* _item : itemsInventory) {
		delete _item;
	}
	itemsInventory.clear();
}

Inventory::Inventory(vector<Item*> _itemsInventory)
{
	itemsInventory = _itemsInventory;
}

Item* Inventory::GetFirstWeapon()
{
	for (Item* _items : itemsInventory) {
		if (_items->GetItemType() == EItemType::WeaponType) {
			return _items;
		}
	}
}



void Inventory::AddItemToInventory(Item* _item)
{
	itemsInventory.push_back(_item);
}

void Inventory::AddItemToInventory(vector<Item*> _items)
{
	itemsInventory.insert(itemsInventory.end(), _items.begin(), _items.end());
}

void Inventory::RemoveItemFromInventory(Item* _item, int _indexItem)
{
	//need to know what index that _item is based on this inventory
	itemsInventory.erase(itemsInventory.begin() + _indexItem);
	//could be better implemented
}
