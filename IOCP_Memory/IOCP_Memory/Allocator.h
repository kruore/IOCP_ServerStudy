
#include "memoryapi.h"

#pragma once


class StompAllocator
{
	enum {PAGE_SIZE = 0x1000};

public:
	static void*	Alloc(__int32 size);
	static void		Release(void* ptr);

};

