#pragma once

#include <string>
#include <iostream>
#include "EItemType.h"

using namespace std;

class Item
{
public:
	EItemType itemType;
	string itemName;
	string itemDescription;
	float itemWeight;
	int itemPrice;

public:
	//CONSTRUCTOR & DESTRUCTOR
	Item();
	~Item();
	Item(EItemType _itemType, string _itemName, string _itemDescription, float _itemWeight, int _itemPrice);

	//GET
	EItemType GetItemType() { return itemType; };
	string GetItemName() { return itemName; };
	string GetItemDescription() { return itemDescription; };
	float GetItemWeight() { return itemWeight; };
	int GetItemPrice() { return itemPrice; };

	//virtual float GetWeaponDurability() = 0;

	//METHOD
};

