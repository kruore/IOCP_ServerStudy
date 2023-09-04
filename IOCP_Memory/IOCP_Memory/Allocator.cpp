#include "Allocator.h"


void* StompAllocator::Alloc(__int32 size)
{
	const __int64 pageCount = (size + PAGE_SIZE - 1) / PAGE_SIZE;
	const __int64 dataOffset = pageCount * PAGE_SIZE - size;
	void* baseAddress =  ::VirtualAlloc(NULL, pageCount * PAGE_SIZE, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	return static_cast<void*>(static_cast<__int8>(baseAddress)+dataOffset)
}

void StompAllocator::Release(void* ptr)
{
	::VirtualFree(ptr, 0, MEM_RELEASE);
}