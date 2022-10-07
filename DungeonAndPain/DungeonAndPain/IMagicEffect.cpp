#include "IMagicEffect.h"

IMagicEffect::~IMagicEffect()
{

}

void IMagicEffect::SetType(uint16_t _newType)
{
	magicType = _newType;
}
