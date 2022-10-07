#pragma once

namespace EMagicType {
	enum EMagicType {
		Wind = 1 << 0,
		Fire = 1 << 1,
		Earth = 1 << 2,
		Water = 1 << 3,
		Metal = 1 << 4,
		Blood = 1 << 5,
		Lava = 1 << 6,
		Lighting = 1 << 7,
		Ice = 1 << 8,
		Spirit = 1 << 9,
		Fighting = 1<<1 | 1<<2, //combine Fire and Earth flag
		WindSpirit = EMagicType::Wind | EMagicType::Spirit //combine Wind and Spirit flag
	};
}