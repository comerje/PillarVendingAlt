
#ifndef COMPONENT_H__
#define COMPONENT_H__

#include "AbstractConductor.h"
#include "NotifyMessageType.h"
#include "MessageData.h"

class Component
{
public:
	Component(AbstractConductor& machine);
	virtual ~Component();

	virtual void Notify(eNotifyMessageType msgType, MessageData* msg) = 0;

protected:
	AbstractConductor& m_machine;
};

#endif