#ifndef __QUEUE_H__
#define __QUEUE_H__

const int MaxSize = 100;

using namespace std;

template <class T>
class TQueue
{
	T *pMem;
	int size;
	int top;
public:
	TQueue(int _Size)
	{
		size = _Size;
		top = -1;
		if ((size > MaxSize) || (size < 1))
			throw size;
		pMem = new T[size];
	}

	~TQueue()
	{
		delete[] pMem;
	}

	void Push(T el)
	{
		if (IsFull())
			throw "Full";

		top++;
		for (int i = top; i > 0; i--)
			pMem[i] = pMem[i - 1];

		pMem[0] = el;
	}
	T Change()
	{
		if (IsEmpty())
			throw "Empty";

		top--;
		return pMem[top + 1];
	}

	T Test()
	{
		if (IsEmpty())
			throw "Empty";

		return pMem[0];
	}

	int IsEmpty(void) const { return top == -1; }
	int IsFull(void) const { return top == size - 1; }
	int Count() { return top + 1; };
};

#endif