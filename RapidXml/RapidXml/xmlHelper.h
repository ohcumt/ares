
#ifndef __XML_HELPER_H__
#define __XML_HELPER_H__
#include <iostream>
#include "rapidxml.hpp"
#include "rapidxml_iterators.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml_utils.hpp"


#define MAX_XML_DATA_SIZE 1024


class XmlHelper
{
	typedef rapidxml::file<> XMLFile;
	typedef rapidxml::xml_document<> XMLDoc;
	typedef rapidxml::xml_node<> XMLNode;
public:
	XmlHelper();

	bool praseFile(const char* fileName);

	int getValueN32(const char* Name);
	unsigned int getValueU32(const char* Name);
	const char* getValueString(const char* Name);

private:
	char m_data[MAX_XML_DATA_SIZE];
	XMLDoc m_doc;
};


#endif //__XML_HELPER_H__



