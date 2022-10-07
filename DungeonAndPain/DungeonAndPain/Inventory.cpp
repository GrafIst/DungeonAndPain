#include "Inventory.h"

Inventory::Inventory()
{
	itemsInventory.push_back(new Item());
}

Inventory::~Inventory()
{
	//need to delete all my pointer in my destructors
	for (Item* _item : itemsInventory) {
		//delete _item;
		_item->~Item();
	}
	for (Weapon* _weapon : weaponInventory) {
		//delete _item;
		_weapon->~Weapon();
	}
	itemsInventory.clear();
}

Inventory::Inventory(vector<Item*> _itemsInventory)
{
	itemsInventory = _itemsInventory;
}
Inventory::Inventory(vector<Weapon*> _weaponsInventory)
{
	weaponInventory = _weaponsInventory;
}




//Weapon* Inventory::GetAllWeaponsFromInventory()
//{
//	vector<Item*> weaponsVector;
//	for (Item* _items : itemsInventory) {
//		if (_items->GetItemType() == EItemType::WeaponType) {
//			weaponsVector.push_back(_items);
//		}
//	}
//	return weaponsVector;
//}

int Inventory::SelectWeapon() {
	cout << "Select a weapon : (input the index)" << endl;
	for (int i = 0; i<weaponInventory.size(); i++) {
		cout << i << " - " << weaponInventory[i]->GetItemName();
	}
	int choiceWeapon;

	do{
		cin >> choiceWeapon;
	} while (choiceWeapon < weaponInventory.size());

	return choiceWeapon;
}



Weapon* Inventory::GetFirstWeapon()
{
	return weaponInventory[0];
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
