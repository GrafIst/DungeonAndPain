#pragma once

#include <string>
using namespace std;

class IMagicEffect
{
protected:
	string magicName;
	int manaCost;

public:
	IMagicEffect();
	virtual ~IMagicEffect();

	virtual void UseMagicEffect() = 0;

};

