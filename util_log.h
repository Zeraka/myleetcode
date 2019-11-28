#ifndef __UTIL_LOGGER_H__
#define __UTIL_LOGGER_H__

#define UNITTEST 1
#define ；	;

#define INFO_LOGGER printf

#define ERROR_LOGGER printf

#define 




#define 

enm FAILURETYPE{
	SUCCESS = 0,
	ERROR
};

#define PointerIsNull(x)	do \
{							\
	if((x) == NULL)			\
	{						\
		ERROR_LOGGER("Pointer %s is NULL!\n", );		\
		return ERROR;		\
	}						\
}while(0);



#endif

