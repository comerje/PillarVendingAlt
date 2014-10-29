
#ifndef DISPLAY_H__
#define DISPLAY_H__

#include <string>
#include "AbstractConductor.h"
#include "Component.h"

class Display : public Component
{
public:
	Display(AbstractConductor& machine);
	~Display();
	void (*DisplayCallback)(std::string& msg);

	virtual void Notify(eNotifyMessageType msgType, MessageData* msg);

private:
	void HandleNotification(MessageData* msg);
};

#endif
