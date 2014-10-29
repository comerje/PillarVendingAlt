
#include "CoinMechanism.h"
#include "CoinValidator.h"

CoinMechanism::CoinMechanism(AbstractConductor& machine)
:Component(machine)
{
}

CoinMechanism::~CoinMechanism()
{
}

void CoinMechanism::InsertCoin(eCoin coin)
{
	if(!CoinValidator::IsValid(coin))
	{
		CoinReturn.push_back(coin);
		return;
	}

	m_coins.push_back(coin);
	Component::m_machine.NotifyCoinTotalChanged(Total());
}

void CoinMechanism::ReturnMoney()
{
	CoinReturn.insert(CoinReturn.end(), m_coins.begin(), m_coins.end());
	m_coins.clear();
	Component::m_machine.NotifyMoneyReturned();
}

void CoinMechanism::Notify(eNotifyMessageType msgType, MessageData* msg)
{
	if(eNotifyMessageType::DispenseChange == msgType)
	{
		MakeChange(msg->m_product);
	}
}

int CoinMechanism::Total() const
{
	int total = 0;
	for(std::list<eCoin>::const_iterator iter = m_coins.begin(); iter != m_coins.end(); ++iter)
		total += *iter;

	return total;
}

void CoinMechanism::MakeChange(int price)
{
	int toReturn = Total() - price;
	if(0 == toReturn)
		return;

	int quartersToReturn = toReturn / 25;
	toReturn -= (quartersToReturn*25);

	int dimesToReturn = toReturn / 10;
	toReturn -= (dimesToReturn*10);
	
	int nickelsToReturn = toReturn / 5;

	ReturnCoin(eCoin::Quarter, quartersToReturn);
	ReturnCoin(eCoin::Dime, dimesToReturn);
	ReturnCoin(eCoin::Nickel, nickelsToReturn);
}

void CoinMechanism::ReturnCoin(eCoin coinType, int count)
{
	for(int i = 0; i < count; ++i)
		CoinReturn.push_back(coinType);
}