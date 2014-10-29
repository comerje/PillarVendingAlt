
#include "Display.h"
#include <iostream>
#include "MessageData.h"

void WriteToStdOut(std::string& msg)
{
	std::cout << msg << std::endl;
}

Display::Display(AbstractConductor& machine)
:Component(machine),
 DisplayCallback(&WriteToStdOut)
{
}

Display::~Display()
{
}

void Display::Notify(eNotifyMessageType msgType, MessageData* msg)
{
	if(eNotifyMessageType::DisplayMessage == msgType)
	{
		std::auto_ptr<MessageData> data;
		data.reset(msg);
		HandleNotification(msg);
	}
}

void Display::HandleNotification(MessageData* msg)
{
	DisplayCallback(msg->m_message);
}
