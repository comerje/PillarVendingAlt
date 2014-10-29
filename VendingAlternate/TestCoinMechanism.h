
#ifndef TESTCOINMECHANISM_H__
#define TESTCOINMECHANISM_H__

#include "TestResult.h"

class TestCoinMechanism
{
public:
	eTestResult TestInsertValidCoinsEmptyCoinReturn();
	eTestResult TestInsertInvalidCoins1InCoinReturn();
	eTestResult TestReturn3ValidCoinsAfterInserting();
};

#endif
