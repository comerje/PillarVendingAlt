
#ifndef MESSAGEDATA_H__
#define MESSAGEDATA_H__

#include <string>
#include "ProductType.h"

class MessageData
{
public:
	MessageData(std::string& msg);
	MessageData(eProductType product);
	~MessageData();

	std::string m_message;
	eProductType m_product;
};

#endif
