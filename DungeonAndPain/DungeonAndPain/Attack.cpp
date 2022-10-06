#include "Attack.h"

Attack::Attack()
{
	attackName = "Default Attack";
	//Weapon defaultSword("DefaultSword", "ADefaultSword", 1, 1, Sword, 1, 1);
	attackWeapon = new Weapon();
	attackDamagePoints = attackWeapon->GetWeaponDamage() + 3; //need to be affected by weapon damage
	attackDamageType = EDamageType::Slashing;
	attackBonus = 2;
}

Attack::~Attack()
{

}

Attack::Attack(string _attackName, Weapon* _attackWeapon, int _attackDamagePoints, EDamageType _attackDamageType, int _attackBonus)
{
	attackName = _attackName;
	attackWeapon = _attackWeapon;
	attackDamagePoints = attackWeapon->GetWeaponDamage() + _attackDamagePoints; //need to be affected by weapon damage
	attackDamageType = _attackDamageType;
	attackBonus = 2;
}

bool Attack::CanHurt()
{
	return false;
}
