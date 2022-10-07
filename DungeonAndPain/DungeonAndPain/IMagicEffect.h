#pragma once

#include <string>
using namespace std;

class IMagicEffect
{
protected:
	string magicName;
	int manaCost;


public:
	virtual ~IMagicEffect();
	virtual void UseMagicEffect() = 0;

};

