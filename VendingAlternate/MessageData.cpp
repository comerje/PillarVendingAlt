#include "MessageData.h"

MessageData::MessageData(std::string& msg)
:m_message(msg),
 m_product(eProductType::NoProduct)
{
}

MessageData::MessageData(eProductType product)
:m_message(""),
 m_product(product)
{
}

MessageData::~MessageData()
{
}
