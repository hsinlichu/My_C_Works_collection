#include<iostream>
//#include<process.h>
#include<cmath>
using namespace std;

class coordinate {
protected:
	int x, y;
public:
	coordinate();
	coordinate(int, int);
	int readX();
	int readY();
	long long distencesquare(coordinate);
};
coordinate::coordinate() {
	x = y = 0;
}
coordinate::coordinate(int a, int b) {
	x = a;
	y = b;
}
int coordinate::readX() {
	return x;
}
int coordinate::readY() {
	return y;
}
long long coordinate::distencesquare(coordinate a)
{
	//cout << "a.x:" << a.x << ",x:" << x << endl;
	//cout <<"distencesquare" <<(long long)(pow((a.x - x), 2) + pow((a.y - y), 2)) << endl;
	return (long long)(pow((a.x - x), 2) + pow((a.y - y), 2));
}


class circle:public coordinate
{
public:
	circle(int,int,int);
	void printcircle();
	int innerdot();
	friend int twounion(circle, circle);
	friend int threeunion(circle, circle,circle);
private:
	int radius;
	coordinate center;
};
circle::circle(int a, int b, int c):radius(c),center(a,b)
{
	x = a;
	y = b;
}
void circle::printcircle()
{
	cout << "(" << x << "," << y << ") r=" << radius << endl;
}
int circle::innerdot()//ok
{
	int leftx = x - radius;
	//cout << "lefex:" << leftx << endl;
	int downy = y - radius;
	//cout << "downy:" << downy << endl;
	int dotsum=0;
	for (int i = leftx; i <= (leftx+2*radius); i++)
	{
		for (int j = downy; j <= (downy + 2 * radius); j++)
		{
			coordinate testpoint(i, j);
			
			if (testpoint.distencesquare(center) <= (int)pow(radius, 2))
			{
				dotsum++;
				//cout << "(" << i << "," << j << ")" << endl;
			}
		}
	}
	//cout << "innerdot:" << dotsum << endl;
	return dotsum;
}
int twounion(circle a, circle b)//ok
{ 
	circle *left;
	circle *down;
	if ((a.x - a.radius) <= (b.x - b.radius))left = &a;
	else left = &b;
	if ((a.y - a.radius) <= (b.y - b.radius))down = &a;
	else down = &b;
	/*
	cout << "left:";
	(*left).printcircle();
	cout << "down:";
	(*down).printcircle();
	*/
	int testaquare = 2 * (a.radius + b.radius);
	int leftx = (*left).x - (*left).radius;
	int downy = (*down).y - (*down).radius;

	int dotsum=0;
	for (int i = leftx; i <= (leftx + testaquare); i++)
	{
		for (int j = downy; j <= (downy + testaquare); j++)
		{
			coordinate testpoint(i, j);
			//cout << "(" << i << "," << j << ")" << endl;
			if ((testpoint.distencesquare(a.center) <= (int)pow(a.radius, 2))&& (testpoint.distencesquare(b.center) <= (int)pow(b.radius, 2)))
			{
				dotsum++;
				//cout << "answer(" << i << "," << j << ")----------------" << endl;
			}
		}
	}
	//cout << "twounion:" << dotsum << endl;
	return dotsum;
}

int threeunion(circle a, circle b,circle c)//ok
{
	circle *left=&a;
	circle *down=&a;
	if ((b.x - b.radius) <= ((*left).x - (*left).radius))left = &b;
	else if((c.x - c.radius) <= ((*left).x - (*left).radius))left = &c;
	if ((b.y - b.radius) <= ((*down).y - (*down).radius))down = &b;
	else if ((c.y - c.radius) <= ((*down).y - (*down).radius))down = &c;
	/*
	cout << "left:";
	(*left).printcircle();
	cout << "down:";
	(*down).printcircle();
	*/
	int testaquare = 2 * (a.radius + b.radius+c.radius);
	int leftx = (*left).x - (*left).radius;
	int downy = (*down).y - (*down).radius;

	int dotsum = 0;
	for (int i = leftx; i <= (leftx + testaquare); i++)
	{
		for (int j = downy; j <= (downy + testaquare); j++)
		{
			coordinate testpoint(i, j);
			//cout << "(" << i << "," << j << ")" << endl;
			if (((testpoint.distencesquare(a.center) <= (int)pow(a.radius, 2)) &&
				 (testpoint.distencesquare(b.center) <= (int)pow(b.radius, 2)))&&
				 (testpoint.distencesquare(c.center) <= (int)pow(c.radius, 2)))
			{
				dotsum++;
				//cout << "answer(" << i << "," << j << ")----------------" << endl;
			}
		}
	}
	//cout << "threeunion:" << dotsum << endl;
	return dotsum;
}


int main() {
	int time;
	cin >> time;
	for (int i = 0; i < time;++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		circle input1(a, b, c);
		cin >> a >> b >> c;
		circle input2(a, b, c);
		cin >> a >> b >> c;
		circle input3(a, b, c);
		//cout << threeunion(input1,input2, input3) << endl;
		int sum;
		sum = input1.innerdot() + input2.innerdot() + input3.innerdot() - 2 * (twounion(input1, input2)
			+ twounion(input1, input3) + twounion(input2, input3)) + 4 * threeunion(input1, input2, input3);
		cout << sum << endl;

	}
	//system("pause");
	return 0;
}