
#include <iostream>
#include "TestCoinMechanism.h"

//void Demo()
//{
//	VendingConductor vm;
//	CoinMechanism* cm = (new CoinMechanism(vm));
//	Display* ds = (new Display(vm));
//	KeyPad* kp = (new KeyPad(vm));
//	ProductFeeder* pf = (new ProductFeeder(vm));
//
//	vm.RegisterComponent(cm);
//	vm.RegisterComponent(ds);
//	vm.RegisterComponent(kp);
//	vm.RegisterComponent(pf);
//
//	vm.Initialize();
//
//	cm->InsertCoin(eCoin::Quarter);
//	cm->InsertCoin(eCoin::Quarter);
//	cm->InsertCoin(eCoin::Quarter);
//	cm->InsertCoin(eCoin::Quarter);
//
//	kp->EnterCode(eProductType::Candy);
//}

int main(int argc, const char* argv[])
{
	TestCoinMechanism tests;
	std::cout << (tests.TestInsertInvalidCoins1InCoinReturn() == eTestResult::Passed ? "Passed" : "Failed") << std::endl
		<< (tests.TestInsertValidCoinsEmptyCoinReturn() == eTestResult::Passed ? "Passed" : "Failed") << std::endl
		<< (tests.TestReturn3ValidCoinsAfterInserting() == eTestResult::Passed ? "Passed" : "Failed") << std::endl;

	std::cin.get();
	return 0;
}