#include "Item.h"

Item::Item()
{
	itemType = EItemType::ItemDefault;
	itemName = "Default Item";
	itemDescription = "A simple item";
	itemWeight = 3.14;
	itemPrice = 10;
}

Item::~Item()
{

}

Item::Item(EItemType _itemType, string _itemName, string _itemDescription, float _itemWeight, int _itemPrice)
{
	itemType = _itemType;
	itemName = _itemName;
	itemDescription = _itemDescription;
	itemWeight = _itemWeight;
	itemPrice = _itemPrice;
}
