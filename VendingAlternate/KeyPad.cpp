
#include "KeyPad.h"

KeyPad::KeyPad(AbstractConductor& machine)
:Component(machine)
{
}

KeyPad::~KeyPad()
{
}

void KeyPad::EnterCode(eProductType product)
{
	Component::m_machine.NotifyProductSelected(product);
}

void KeyPad::Notify(eNotifyMessageType msgType, MessageData* msg)
{
}