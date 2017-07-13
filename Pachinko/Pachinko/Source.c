#include<stdio.h>
#include<stdlib.h>
//#include<process.h>
#define MAX 128

typedef struct //left probability
{
	int nominator, denominator;
}fraction;

fraction add(fraction, fraction);
fraction sub(fraction, fraction);
fraction mul(fraction, fraction);
void fractionReduction(fraction*);

int main(void)
{
	int number;
	scanf("%d", &number);
	int pinNumber = number*(number + 1) / 2;
	fraction one;
	fraction zero;
	one.denominator = 1, one.nominator = 1;
	zero.nominator = 0, zero.denominator = 1;
	fraction pin[MAX][MAX];

	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			pin[i][j].nominator = a;
			pin[i][j].denominator = a + b;
			fractionReduction(&pin[i][j]);
		}
	}
	for (int i = 0;i <= number + 1;++i)pin[number][i] = one;
	//for (int i = 0; i < number; i++)for (int j = 0; j <= i; j++)printf(j == i ? "%2d/%2d\n" : "%2d/%2d ", pin[i][j].nominator, pin[i][j].denominator);
	fraction dpin[MAX][MAX];
	for (int i = 0; i < MAX; i++)for (int j = 0; j < MAX; j++)dpin[i][j] = zero;
	dpin[0][0] = one;
	for (int i = 0; i < number + 1; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			//printf("%d %d\n",i,j);
			//printf("1:\n");
			dpin[i + 1][j] = add(dpin[i + 1][j], mul(dpin[i][j], pin[i][j]));
			//printf("2:\n");
			dpin[i + 1][j + 1] = add(dpin[i + 1][j + 1], mul(dpin[i][j], sub(one, pin[i][j])));
		}
	}
	for (int i = 0; i < number + 1; i++)printf("%d/%d\n", dpin[number][i].nominator, dpin[number][i].denominator);
	//system("pause");
	return 0;
}

fraction add(fraction a, fraction b)
{

	fraction c;
	c.nominator = a.nominator*b.denominator + b.nominator*a.denominator;
	c.denominator = a.denominator * b.denominator;
	//printf("add %d/%d+%d/%d = %d/%d\n", a.nominator, a.denominator, b.nominator, b.denominator, c.nominator, c.denominator);
	fractionReduction(&c);
	return c;
}
fraction sub(fraction a, fraction b)
{
	//printf("sub %d/%d-%d/%d\n",a.nominator,a.denominator,b.nominator,b.denominator);
	fraction c;
	c.nominator = a.nominator*b.denominator - b.nominator*a.denominator;
	c.denominator = a.denominator * b.denominator;
	fractionReduction(&c);
	return c;
}
fraction mul(fraction a, fraction b)
{
	//printf("mul %d/%d*%d/%d\n",a.nominator,a.denominator,b.nominator,b.denominator);
	fraction c;
	c.nominator = a.nominator*b.nominator;
	c.denominator = a.denominator * b.denominator;
	fractionReduction(&c);
	return c;
}
void fractionReduction(fraction* z)
{
	int GCD;
	if ((*z).nominator == 0)
	{
		(*z).denominator = 1;
		return;
	}
	int a = (*z).denominator;
	int b = (*z).nominator;

	//printf("GCD %d/%d\n", b, a);
	while (b)
	{
		int t = b;
		b = a%b;
		a = t;
	}
	GCD = a;
	(*z).nominator /= GCD;
	(*z).denominator /= GCD;
}