
#include "VendingConductor.h"
#include "MessageData.h"
#include "StringFormatter.h"

VendingConductor::VendingConductor()
{
}

static bool deleteAll(Component* c)
{
	delete c;
	c = NULL;
	return true;
}

VendingConductor::~VendingConductor()
{
	// cleanup memory in list
	m_components.remove_if(deleteAll);
}

void VendingConductor::Initialize()
{
	m_total = 0;
	MessageData* data = new MessageData(std::string("INSERT COIN"));
	SendMessage(eNotifyMessageType::DisplayMessage, data);
}

void VendingConductor::RegisterComponent(Component* component)
{
	std::list<Component*>::iterator itr = std::find(m_components.begin(), m_components.end(), component);
	if(itr == m_components.end())
		m_components.push_back(component);
}

void VendingConductor::NotifyCoinTotalChanged(int total)
{
	m_total = total;
	MessageData* data = new MessageData(StringFormatter::FormatCurrency(total));
	SendMessage(eNotifyMessageType::DisplayMessage, data);
}

void VendingConductor::NotifyProductSelected(eProductType product)
{
	if(m_total >= product)
	{
		MessageData* feedData = new MessageData(product);
		SendMessage(eNotifyMessageType::FeedProduct, feedData);

		MessageData* changeMachineData = new MessageData(product);
		SendMessage(eNotifyMessageType::DispenseChange, changeMachineData);

		return;
	}

	MessageData* data = new MessageData(std::string("PRICE " + StringFormatter::FormatCurrency(product)));
	SendMessage(eNotifyMessageType::DisplayMessage, data);

	if(!m_total)
	{
		Initialize();
		return;
	}

	MessageData* data2 = new MessageData(StringFormatter::FormatCurrency(m_total));
	SendMessage(eNotifyMessageType::DisplayMessage, data2);
}

void VendingConductor::NotifyProductDispensed()
{
	MessageData* data = new MessageData(std::string("THANK YOU"));
	SendMessage(eNotifyMessageType::DisplayMessage, data);
	Initialize();
}

void VendingConductor::NotifyMoneyReturned()
{
	Initialize();
}

void VendingConductor::SendMessage(eNotifyMessageType msgType, MessageData* data)
{
	for(std::list<Component*>::iterator itr = m_components.begin(); itr != m_components.end(); ++itr)
		(*itr)->Notify(msgType, data);
}
