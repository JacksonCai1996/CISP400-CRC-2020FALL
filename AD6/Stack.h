#ifndef STACK_H
#define STACK_H

template<typename STACKTYPE>
class Stack 
{
public:
	Stack()
	{
		size = -1;
		top = 0;
	}
	

	void push(const STACKTYPE& data)
	{
		size++;
		stackPtr[size] = data;
		
	}

	bool pop(STACKTYPE& data)
	{
		if (size > -1)
		{
			top = size;
			data = stackPtr[size];
			size--;
			return true;
		}

		return false;
	}

private:
	STACKTYPE* stackPtr = new STACKTYPE[6];
	int top;
	int size;
};

#endif // !STACK_H