
#include <iostream>
#include "aresLog.h"

using namespace std;
using namespace NSLogType;

void AresLog::setLogLevel( LogLevel lv )
{
	_logLv = lv;
}

AresLog::~AresLog()
{

}

AresLog::AresLog()
:_logLv(NSLogType::WARNING)
{

}

AresLog::AresLog( LogLevel lv )
{
	_logLv = lv;
}

void AresLog::log( LogLevel lv, const char * logInfo )
{
	if (_logLv<=lv) 
	{
		cout<<logInfo<<endl;
	}
}

const char* AresLog::getLogLevel() const
{

#undef ENUM_LOG_HEAD
#undef ENUM_LOG_ITEM
#undef ENUM_LOG_TAIL
#define  ENUM_LOG_HEAD(Ele) switch(_logLv) {
#define  ENUM_LOG_ITEM(Name, Lv)  case Lv: return #Name;
#define  ENUM_LOG_TAIL(Ele) default: return "not define log level"; }

#include "enumLog.h"

#undef ENUM_LOG_HEAD
#undef ENUM_LOG_ITEM
#undef ENUM_LOG_TAIL

}

void AresLog::printf( const char* szText )
{
	cout<<szText<<endl;
}

void AresLog::printf( int szText )
{
	cout<<szText<<endl;
}

void AresLog::printf( unsigned int szText )
{
	cout<<szText<<endl;
}


