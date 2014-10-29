
#include "ProductFeeder.h"
#include <iostream>

void DispenseProductToStdOut(eProductType product)
{
	std::cout << "DISPENSING " << product << std::endl;
}

ProductFeeder::ProductFeeder(AbstractConductor& machine)
:Component(machine),
 DispenseCallback(DispenseProductToStdOut)
{
}

ProductFeeder::~ProductFeeder()
{
}

void ProductFeeder::HandleNotification(MessageData* msg)
{
	DispenseCallback(msg->m_product);
	Component::m_machine.NotifyProductDispensed();
}

void ProductFeeder::Notify(eNotifyMessageType msgType, MessageData* msg)
{
	if(eNotifyMessageType::FeedProduct == msgType)
	{
		std::auto_ptr<MessageData> data;
		data.reset(msg);
		HandleNotification(msg);
	}
}
