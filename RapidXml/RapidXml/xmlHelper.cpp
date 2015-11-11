
#include "xmlHelper.h"

bool XmlHelper::praseFile( const char* fileName )
{
	XMLFile file(fileName);
	const char* xmlData = file.data();

	int strLen = strlen(xmlData);
	if (strLen>=MAX_XML_DATA_SIZE) 
	{
		return false;
	}

	memcpy(m_data, xmlData, strLen);
	m_data[strLen] = '\0';

	m_doc.parse<0>(m_data);

	return true;
}

XmlHelper::XmlHelper()
{
	memset(m_data, 0, sizeof(m_data));
}

int XmlHelper::getValueN32( const char* Name )
{
	XMLNode* node = m_doc.first_node(Name);
	int nValue = 0;
	if (node)
	{
		const char* Value = node->value();
		sscanf( Value, "%d",  &nValue);
	}
	return nValue;
}

unsigned int XmlHelper::getValueU32( const char* Name )
{
	XMLNode* node = m_doc.first_node(Name);
	unsigned int nValue = 0;
	if (node)
	{
		const char* Value = node->value();
		sscanf( Value, "%u",  &nValue);
	}
	return nValue;
}

const char* XmlHelper::getValueString( const char* Name )
{
	XMLNode* node = m_doc.first_node(Name);
	const char* Value = 0;
	if (node)
	{
		Value = node->value();
	}
	return Value;
}

