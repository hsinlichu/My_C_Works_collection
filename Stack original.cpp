#include<stdio.h>
#include<stdlib.h>
#include<process.h>


class ustack
{
	int stk[10];
	int next;
public:
	ustack();
	void clear();
	void push(int);
	int pop();
	int size();
};

ustack::ustack() :next(0)
{

}
void ustack::clear()
{
	for (int i = 0; i <= next; ++i)stk[i] = 0;
}
void ustack::push(int a)
{
	if (next == 10)printf("You already reach the maximun!\n");
	else stk[next++] = a;
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

int main(void)
{
	
	ustack istack;
	for (int i = 0; i < 11; i++)
	{
		int input;
		scanf("%d", &input);
		istack.push(input);
	}
	for (int i = 0; i < 11; i++)printf("%d\n",istack.pop());



	system("pause");
	return 0;
}
