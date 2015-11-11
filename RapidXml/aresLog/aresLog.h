
#ifndef __ARES_LOG_H__
#define __ARES_LOG_H__

#include "../singleton/Singleton.h"

namespace NSLogType
{

#undef ENUM_LOG_HEAD
#undef ENUM_LOG_ITEM
#undef ENUM_LOG_TAIL
#define  ENUM_LOG_HEAD(Ele) enum Ele {
#define  ENUM_LOG_ITEM(Lv, Num)   Lv = Num,
#define  ENUM_LOG_TAIL(Ele)   };

#include "enumLog.h"

#undef ENUM_LOG_HEAD
#undef ENUM_LOG_ITEM
#undef ENUM_LOG_TAIL

}


// log 实时输出,暂时不做缓存
class AresLog : public Singleton<AresLog>
{
public:




	AresLog();
	AresLog( NSLogType::LogLevel lv);
	~AresLog();

	void setLogLevel(NSLogType::LogLevel lv);
	const char* getLogLevel() const ;

	void log(NSLogType::LogLevel lv, const char * logInfo );
	void printf(const char * szText );
	void printf(int szText );
	void printf(unsigned int szText );
	

private:
	NSLogType::LogLevel _logLv;
};








#endif // __ARES_LOG_H__









