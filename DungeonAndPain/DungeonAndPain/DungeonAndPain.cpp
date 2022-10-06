#include <iostream>
#include <vector>
#include <string>

#include "Creature.h"
#include "Character.h"
#include "Monster.h"
#include "Merchant.h"
#include "Inventory.h"
#include "Item.h"

using namespace std;

int main()
{
    cout << "Hello World !" << endl;

    //NEED TO CONVERT ALL THE WEAPON (in Attack) TO REFERENCE AND STUFF
    Weapon ironSword("Iron Sword", "A basic iron sword", 4.3f, 20, Sword, 6, 0.9f);
    Weapon woodenHammer("Wooden Hammer", "A sturdy wooden hammer", 8.1f, 65, Hammer, 9, 0.6f);

    Attack ironSwordSlash("Sword Slash", &ironSword, 4, Slashing, 1); //Implemented the reference of the Weapon instead of a copy
    vector<Attack> defaultMoveset(3, ironSwordSlash);

    vector<Item*> merchantWeaponStock = { &ironSword, &woodenHammer };

    Inventory inventoryMerchant(merchantWeaponStock);
    Item bone(EItemType::CollectibleType, "Bone", "A solid white bone", 10, 4);
    vector<Item*> skelettonLoots(3, &bone);
    Inventory skelettonLootsInventory(skelettonLoots);

    Monster skeletton("Skellington", "This skelleton know jazz for some reason",15, defaultMoveset, 3, "Heyo, am a cool bonedude", skelettonLootsInventory)

    /*Merchant merchantA("Jack", "Polter", "A travelling merchant", 100, defaultMoveset, 15, "Come here, i've got stuff to sell",&inventoryMerchant, 100, &ironSword, Elve, Villager, "Everything's cheap", merchantWeaponStock);

    Merchant merchantB("Loic", "Reynard", "Another travelling merchant", 100, defaultMoveset, 15, "so much cheap stuff you wouldnt believe", inventoryMerchant, 2000, &ironSword, Human, Villager, "Goldie", merchantWeaponStock);

    merchantA.Introduce();*/

    //cout << merchantA.GetName() << endl;
    //cout << merchantA.GetCharacterLastName() << endl;
    //child of child and child need public encapsulation to have access to parent function

}