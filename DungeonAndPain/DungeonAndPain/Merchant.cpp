#include "Merchant.h"

//CONSTRUCTOR & DESTRUCTOR
Merchant::Merchant() : Creature()
{
	merchantMoney = 100000;
	merchantShopName = "Default Shop Name";
	merchantWeaponStock.push_back(new Weapon());
}

Merchant::~Merchant()
{
	merchantWeaponStock.~vector();
}

Merchant::Merchant(string _creatureName, string _creatureDescription, string _creatureCatchPhrase, int _merchantMoney, string _merchantShopName, vector<Weapon*> _merchantWeaponStock)
	: Creature(_creatureName, _creatureDescription, _creatureCatchPhrase)
{
	merchantMoney = _merchantMoney;
	merchantShopName = _merchantShopName;
	merchantWeaponStock = _merchantWeaponStock;
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
	for (Weapon* _weapon : GetMerchantWeaponStock())
	{
		std::cout << i << "-" << _weapon->GetItemName() << " - " << _weapon->GetItemPrice() << "$" << std::endl;
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

		int indexWeapon = _character->GetCreatureInventory()->SelectWeapon();
		Weapon* weaponSelected = _character->GetCreatureInventory()->GetWeaponFromInventory(indexWeapon);

		//check if player has enough money to buy it
		if (_character->GetCharacterMoney() >= weaponSelected->GetItemPrice()) { //need the attribute of parents to be public or protected so the child can access it
			cout << "Here, it's yours : " << endl;
			//detect if item is weapon or not
			if (weaponSelected->GetItemType() == EItemType::WeaponType) {
				_character->AddWeaponAmount(1);
			}
			_character->GetCreatureInventory()->AddItemToInventory(weaponSelected);

			creatureInventory->GetItemsInventory().erase(creatureInventory->GetItemsInventory().begin() + indexWeapon); //remove weapon from merchant stock, it uses iterators

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
	int indexWeapon;
	Weapon* weaponToSell;

	indexWeapon = _character->GetCreatureInventory()->SelectWeapon();
	weaponToSell = _character->GetCreatureInventory()->GetWeaponFromInventory(indexWeapon);

	int weaponPrice = weaponToSell->GetItemPrice();
	float weaponDurability = weaponToSell->GetWeaponDurability();
	if (merchantMoney >= weaponPrice) {
		int merchantPrice = weaponPrice / (1 - weaponDurability);
		cout << "I'm ready to pay " << merchantPrice << "$ for this one. Take it or leave it (y/n)" << endl;
		char answer;
		cin >> answer;
		if (answer == 'y') {
			cout << "Here you go." << endl;
			_character->GetCreatureInventory()->RemoveItemFromInventory(weaponToSell,indexWeapon+1);
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
