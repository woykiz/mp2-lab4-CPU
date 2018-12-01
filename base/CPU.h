#ifndef __CPU_H__
#define __CPU_H__

#include "queue.h"
#include <time.h>
#include <iostream>

using namespace std;

struct Task
{
	int cors;
};

struct Statistics
{
	int taskSl;
	int taskN;
	int taskR;
	double taskRCPU() { return ((double)taskR / (double)taskN); }
	double taskSlCPU() { return ((double)taskSl / (double)taskN); }
};


class TCPU
{
	TQueue<Task> queue;
	int corsN;
public:
	TCPU(int queueSize, int coreNums) : queue(queueSize), corsN(coreNums) {}
	Statistics Run(double q1, double q2, int time);
};

#endif