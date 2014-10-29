
#include "TestCoinMechanism.h"
#include "VendingConductor.h"
#include "CoinMechanism.h"
#include "Coin.h"

eTestResult TestCoinMechanism::TestInsertValidCoinsEmptyCoinReturn()
{
	VendingConductor vc;
	CoinMechanism* cm = new CoinMechanism(vc);
	cm->InsertCoin(eCoin::Dime);
	cm->InsertCoin(eCoin::Nickel);
	cm->InsertCoin(eCoin::Quarter);
	
	int result = cm->CoinReturn.size();

	return (0 == result ? eTestResult::Passed : eTestResult::Failed);
}

eTestResult TestCoinMechanism::TestInsertInvalidCoins1InCoinReturn()
{
	VendingConductor vc;
	CoinMechanism* cm = new CoinMechanism(vc);
	cm->InsertCoin(eCoin::Penny);
		
	int result = cm->CoinReturn.size();

	return (1 == result ? eTestResult::Passed : eTestResult::Failed);
}

eTestResult TestCoinMechanism::TestReturn3ValidCoinsAfterInserting()
{
	VendingConductor vc;
	CoinMechanism* cm = new CoinMechanism(vc);
	cm->InsertCoin(eCoin::Dime);
	cm->InsertCoin(eCoin::Nickel);
	cm->InsertCoin(eCoin::Quarter);
	cm->ReturnMoney();

	int result = cm->CoinReturn.size();

	return (3 == result ? eTestResult::Passed : eTestResult::Failed);
}
