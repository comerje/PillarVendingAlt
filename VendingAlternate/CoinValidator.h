
#ifndef COINVALIDATOR_H__
#define COINVALIDATOR_H__

#include "Coin.h"

class CoinValidator
{
public:
	static bool IsValid(eCoin coin)
	{
		return !(eCoin::Penny == coin);
	}
};

#endif
