
#ifndef KEYPAD_H__
#define KEYPAD_H__

#include "AbstractConductor.h"
#include "Component.h"
#include "ProductType.h"

class KeyPad : public Component
{
public:
	KeyPad(AbstractConductor& machine);
	~KeyPad();
	void EnterCode(eProductType product);

	virtual void Notify(eNotifyMessageType msgType, MessageData* msg);
};

#endif
