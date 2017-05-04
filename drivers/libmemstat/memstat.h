#ifndef MEMSTAT_H
#define MEMSTAT_H

#include <inttypes.h>

typedef struct {
	uint16_t maxHeapSize;
	uint16_t maxStackSize;
} mem_stat_t;

// returns maximum stack and heap size in bytes
extern mem_stat_t* memstatGetStat(void);

#endif