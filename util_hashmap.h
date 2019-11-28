#ifndef __UTIL_HASHMAP_H__
#define __UTIL_HASHMAP_H__

#include "util_linklist.h"

typedef struct HashMapkv_t{
	void *key;
	void *value;
}HashMapkv;

typedef struct HashMap_t{
	int hashMapSize;
	int initialCapacity;//初始容量
		

}HashMap;


#endif