#include "Merchant.h"

//CONSTRUCTOR & DESTRUCTOR
Merchant::Merchant() : Character()
{
	merchantShopName = "Default Shop Name";
	//Weapon defaultSword("DefaultSword", "ADefaultSword", 1, 1, Sword, 1, 1);
	//merchantWeaponStock.push_back(new Weapon());
}

Merchant::~Merchant()
{

}

Merchant::Merchant(string _creatureName, string _characterLastName, string _creatureDescription, string _creatureCatchPhrase, Inventory* _creatureInventory,
	int _characterMoney, ECharacterRace _characterRace, string _merchantShopName)
	:Character(_creatureName, _characterLastName, _creatureDescription, _creatureCatchPhrase,_creatureInventory,
		_characterMoney, _characterRace)
{
	merchantShopName = _merchantShopName;
	//merchantWeaponStock = _merchantWeaponStock;
}

//METHOD
void Merchant::AddWeaponToStock(Weapon &_weapon)
{
	//merchantWeaponStock.push_back(&_weapon);
}

void Merchant::ShowStock()
{
	std::cout << "Here is what I have to offer :" << std::endl;
	int i = 0;
	for (Item* _item : creatureInventory->GetItemsInventory())
	{
		std::cout << i << "-" << _item->GetItemName() << " - " << _item->GetItemPrice() << "$" << std::endl;
		i++;
	}
}

void Merchant::SellWeaponTo(Character* _character)
{
	//TODO Merchant sell a weapon to a character
	ShowStock();
	cout << "Interested ?" << endl;
	char answer;
	cin >> answer;
	if (answer == 'y') {
		//Ask what weapon
		int indexAnswer;
		cout << "(write index of the one you want :)" << endl;
		do {
			cin >> indexAnswer;
		} while (indexAnswer > creatureInventory->GetItemsInventory().size()); //make sure player answer is in bound with the vector

		Item* itemSelected = creatureInventory->GetItemFromInventory(indexAnswer);

		//check if player has enough money to buy it
		if (_character->GetCharacterMoney() >= itemSelected->GetItemPrice()) { //need the attribute of parents to be public or protected so the child can access it
			cout << "Here, it's yours : " << endl;
			//detect if item is weapon or not
			if (itemSelected->GetItemType() == EItemType::WeaponType) {
				_character->AddWeaponAmount(1);
			}
			_character->GetCreatureInventory()->AddItemToInventory(itemSelected);

			creatureInventory->GetItemsInventory().erase(creatureInventory->GetItemsInventory().begin() + indexAnswer); //remove weapon from merchant stock, it uses iterators

		}
		else {
			//not enough money
			cout << "Come back when you have enough money peasant" << endl;
		}
	}
	else {
		cout << "Not interested ? Alright then, see you later." << endl;
	}

}

void Merchant::BuyWeaponFrom(Character* _character)
{
	//TODO Merchant buy a weapon from a character
	cout << "You want to sell me your weapon ?" << endl;
	//ask which weapon
	Item* weaponToSell;
	weaponToSell = _character->GetCreatureInventory()->GetFirstWeapon();

	int tempIndexItem = 0;

	if (_character->GetWeaponAmount() > 1) {
		cout << "You have multiple weapon, which one do you want to sell :" << endl;
		_character->AnnounceWeapon();
		int indexWeapon;
		cin >> indexWeapon;
		for (Item* _item : _character->GetCreatureInventory()->GetItemsInventory()) {	
			int tempIndexWeapon = 0;
			if (_item->GetItemType() == EItemType::WeaponType) {
				tempIndexWeapon++;
				if (tempIndexWeapon == indexWeapon) {
					weaponToSell = _item;
					break;
				}
				tempIndexWeapon++;
			}
		}
	}

	int weaponPrice = weaponToSell->GetItemPrice();
	//float weaponDurability = weaponToSell->GetWeaponDurability();   //How am i supposed to get the durability if only the child has it
	float weaponDurability = 1;
	if (characterMoney >= weaponPrice) {
		int merchantPrice = weaponPrice / (1 - weaponDurability);
		cout << "I'm ready to pay " << merchantPrice << "$ for this one. Take it or leave it (y/n)" << endl;
		char answer;
		cin >> answer;
		if (answer == 'y') {
			cout << "Here you go." << endl;
			_character->GetCreatureInventory()->RemoveItemFromInventory(weaponToSell,tempIndexItem+1);
			//add money
			_character->AddMoney(merchantPrice);
		}
	}
	else {
		//merchant not have enough money
		cout << "I'm sorry, i don't have enough money to buy yours" << endl;
	}
}

void Merchant::UseMagicEffect()
{
	cout << "do some magic" << endl;
}
