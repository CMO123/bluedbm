#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <string>

#define SORTER_THREAD_COUNT 16


#ifndef __DEFINES_H__
#define __DEFINES_H__


typedef enum {
	BGKEY_BINARY32,
	BGKEY_BINARY64
} BgKeyType;

typedef enum {
	BGVAL_NONE,
	BGVAL_BINARY32,
	BGVAL_BINARY64
} BgValType;

typedef struct {
	bool valid;
	uint64_t key;
	uint64_t value;
} BgKvPair;

class BgUserProgram {
public:
static uint64_t EdgeProgram(uint64_t vertexValue, BgKvPair edge);
static uint64_t VertexProgram(uint64_t v1, uint64_t v2);
static bool Converged(uint64_t v1, uint64_t v2);
};
typedef enum {
	BGUSERPROG_NULL,
	BGUSERPROG_BFS,
	BGUSERPROG_PAGERANK,
	BGUSERPROG_UPDATE, // dummy for pagerank, to update visited list
	BGUSERPROG_SSSP
} BgUserProgramType; //FIXME


#endif
