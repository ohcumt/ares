
#include <iostream>
#include <string>
#include "RapidXml/xmlHelper.h"
#include "aresLog/aresLog.h"


using namespace rapidxml;
using namespace std;

AresLog log = AresLog::getSingleton();


int main() 
{
	char* fileName = "example/string.xml";
	XmlHelper xmlHelper;

	xmlHelper.praseFile(fileName);
	
	int nValue = xmlHelper.getValueN32("tagN32");

	unsigned int uValue = xmlHelper.getValueU32("tagU32");
	const char* szValue = xmlHelper.getValueString("tagStr");

	log.printf(nValue);
	log.printf(uValue);
	log.printf(szValue);

	return 0;
	 
}




