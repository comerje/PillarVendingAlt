
#ifndef COINMECHANISM_H__
#define COINMECHANISM_H__

#include <list>
#include "AbstractConductor.h"
#include "Component.h"
#include "Coin.h"

class CoinMechanism : public Component
{
public:
	CoinMechanism(AbstractConductor& machine);
	~CoinMechanism();
	void InsertCoin(eCoin coin);
	void ReturnMoney();

	virtual void Notify(eNotifyMessageType msgType, MessageData* msg);

	std::list<eCoin> CoinReturn;

private:
	int Total() const;
	void MakeChange(int price);
	void ReturnCoin(eCoin coinType, int count);

	std::list<eCoin> m_coins;
};

#endif
