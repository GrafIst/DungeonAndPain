#pragma once

#include <string>
#include "EMagicType.h";

using namespace std;

class IMagicEffect
{
protected:
	string magicName;
	int manaCost;
	//EMagicType::EMagicType magicType;
	uint16_t magicType;

public:
	virtual ~IMagicEffect();
	virtual void SetType(uint16_t _newType);
	virtual void UseMagicEffect() = 0;

};

