#include<stdio.h>
#include<stdlib.h>
#include<process.h>


class ustack
{
	int *stk;
	int max;
	int next;
public:
	ustack();
	ustack(int);
	~ustack();
	void clear();
	void push(int);
	int pop();
	int size();
	void resize();
};

ustack::ustack() :next(0),max(10)
{
	stk = new int[max];
}
ustack::ustack(int a) : next(0),max(a)
{
	stk = new int[max];
}
ustack::~ustack()
{
	delete[] stk;
}
void ustack::clear()
{
	for (int i = 0; i <= next; ++i)stk[i] = 0;
}
void ustack::push(int a)
{
	if (next == max)this->resize();
	stk[next++] = a;
}
int ustack::pop()
{
	if (next == 0)
	{
		printf("You don't have anything to pop out!\n");
		return 0;
	}
	else return stk[--next];
}
int ustack::size()
{
	return 10 - next;
}
void ustack::resize()
{
	int origin = max;
	max *= 2;
	int* stk2 = new int[max];
	for (int i = 0; i < origin; i++)
	{
		stk2[i] = stk[i];
	}
	stk = stk2;
	//printf("Resize!!\n");
}

int main(void)
{

	ustack istack(8);
	for (int i = 0; i < 13; i++)
	{
		int input;
		scanf("%d", &input);
		istack.push(input);
	}
	printf("Pop:\n");
	for (int i = 0; i < 13; i++)printf("%d\n", istack.pop());



	system("pause");
	return 0;
}
