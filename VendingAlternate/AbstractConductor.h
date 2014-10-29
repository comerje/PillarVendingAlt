
#ifndef ABSTRACTCONDUCTOR_H__
#define ABSTRACTCONDUCTOR_H__

#include "ProductType.h"

class Component;

class AbstractConductor
{
public:
	virtual void RegisterComponent(Component* component) = 0;
	virtual void NotifyCoinTotalChanged(int total) = 0;
	virtual void NotifyProductSelected(eProductType product) = 0;
	virtual void NotifyProductDispensed() = 0;
	virtual void NotifyMoneyReturned() = 0;
};

#endif
