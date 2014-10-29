
#ifndef PRODUCTFEEDER_H__
#define PRODUCTFEEDER_H__

#include "AbstractConductor.h"
#include "Component.h"

class ProductFeeder : public Component
{
public:
	ProductFeeder(AbstractConductor& machine);
	~ProductFeeder();
	void (*DispenseCallback)(eProductType product);
	void HandleNotification(MessageData* msg);

	virtual void Notify(eNotifyMessageType msgType, MessageData* msg);
};

#endif
