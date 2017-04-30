#pragma once
#include "header.h"
#include "Memory.h"

class Algorithms
{
public:
	Algorithms();
	~Algorithms();

	static void FIFO(Memory l);
	static void LRU(Memory l);
	static void OPT(Memory l);
	static void ALRU(Memory l);
	static void RAND(Memory l);

};
