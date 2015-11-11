
#ifndef __SINGLETON_H__ 
#define __SINGLETON_H__

template <typename T>
class Singleton
{
public:
	static T& getSingleton()
	{
		static T s_singleton;
		return s_singleton;
	}
};

#endif //__SINGLETON_H__



