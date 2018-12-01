#include "CPU.h"


Statistics TCPU::Run(double q1, double q2, int runTime)
{
	Statistics stat;

	stat.taskSl = 0;
	stat.taskN = 0;
	stat.taskR = 0;

	int coreState = corsN;
	srand(time(NULL));

	for (int tact = 0; tact < runTime; tact++)
	{
		double chance = ((double)rand() / (RAND_MAX));
		if (chance < q1)
		{
			try {
				Task t;
				t.cors = rand() % corsN;
				queue.Push(t);
			}
			catch (char* ex)
			{
				if (ex == "Queue full")
					stat.taskR++;
			}
		}


		for (int i = 0; i < corsN - coreState; i++)
		{
			chance = ((double)rand() / (RAND_MAX));
			if (chance < q2)
				coreState++;
		}

		
		try
		{
			while (coreState - queue.Test().cors >= 0)
			{
				coreState -= queue.Change().cors;
				stat.taskN++;
			}
		}
		catch (char* ex)
		{
			if (ex == "Queue empty")
				stat.taskSl++;
		}

	}

	return stat;
}