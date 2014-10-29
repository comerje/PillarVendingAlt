
#ifndef VENDINGCONDUCTOR_H_
#define VENDINGCONDUCTOR_H_

#include <list>
#include "AbstractConductor.h"
#include "Component.h"
#include "ProductType.h"

class VendingConductor : public AbstractConductor
{
public:
	VendingConductor();
	~VendingConductor();
	void Initialize();

	virtual void RegisterComponent(Component* component);
	virtual void NotifyCoinTotalChanged(int total);
	virtual void NotifyProductSelected(eProductType product);
	virtual void NotifyProductDispensed();
	virtual void NotifyMoneyReturned();

protected:
	void SendMessage(eNotifyMessageType msgType, MessageData* data);
	
	int m_total;
	std::list<Component*> m_components;
};

#endif
