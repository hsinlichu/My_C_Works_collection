#include<iostream>
#include<process.h>
#include<cmath>
using namespace std;

class coordinate
{
public:
	coordinate();
	coordinate(int, int);
	int distance(coordinate);

protected:
	int x, y;
};

coordinate::coordinate()
{
	x = y = 0;
}
coordinate::coordinate(int a,int b)
{
	x = a;
	y = b;
}
int coordinate::distance(coordinate b)
{ 
	//cout <<"¶ZÂ÷: "<< abs(b.x - x) + abs(b.y - y) << endl;
	return abs(b.x - x) + abs(b.y - y); 
}

class parkingLot:public coordinate
{
public:
	parkingLot();
	parkingLot(int, int, int);
	int readX() { return x; }
	int readY() { return y; }
	void storedChange(int a);
	int getcapacity() 
	{ 
		//cout << "capacity " << capacity << endl;
		return capacity;
	}
	int getstored();

private:
	int capacity;
	int stored;
};

parkingLot::parkingLot(int a, int b, int c) :coordinate(a,b)
{
	capacity = c;
	stored = 0;
}
parkingLot::parkingLot() {
	capacity = 0;
	stored = 0;
	
}
int parkingLot::getstored() 
{
	//cout << "getStore " << stored << endl;
	return stored;
}
void parkingLot::storedChange(int a) 
{
	stored += a;
	//cout << "Change " << a << " Store now is " << stored << endl;
}





int main() {
	int parkingNumber;
	cin >> parkingNumber;
	parkingLot *parking;
	parking = new parkingLot[parkingNumber];
	for (int i = 0; i < parkingNumber; i++)
	{
		int x, y, c;
		cin >> x >> y >> c;
		parkingLot input(x, y, c);
		parking[i] = input;
		//cout << "parking: " << i + 1 << " store:" << parking[i].getstored() << endl;
	}
	int bicycleNumber;
	cin >> bicycleNumber;
	coordinate *bicycle;
	bicycle = new coordinate[bicycleNumber];
	for (int i = 0; i < bicycleNumber; i++)
	{
		int x, y;
		cin >> x >> y ;
		coordinate input(x, y);
		bicycle[i] = input;
	}

	for (int i = 0;i < bicycleNumber;i++)
	{
		//cout << "bicycle: " << i+1 <<"-------------------------------"<< endl;
		int initial = 0;
		while (parking[initial].getcapacity() == parking[initial].getstored())
		{
			initial++;
		}
		parkingLot *a = parking+initial;
		(*a).storedChange(1);

		int shortestdestence = bicycle[i].distance(parking[initial]);
		//cout << "initialparking: " << initial + 1 << " store:" << parking[initial].getstored() << endl;
		//cout << "shortestdestence:¡@"<<shortestdestence << endl;
		for (int j = 0;j < parkingNumber;j++)
		{
			//cout << "parking: " << j+1<<" store:"<< parking[j] .getstored()<< endl;
			if (parking[j].getcapacity() != parking[j].getstored())
			{
				if (bicycle[i].distance(parking[j]) < shortestdestence)
				{
					(*a).storedChange(-1);
					a = parking+j;
					shortestdestence = bicycle[i].distance(parking[j]);
					(*a).storedChange(1);
		
					//cout << "(<)Store at parking: " << j + 1 << endl;
				}
				else if (bicycle[i].distance(parking[j]) == shortestdestence)
				{
					//cout << "distance equal" << endl;
					if (parking[j].readX() < (*a).readX())
					{
						(*a).storedChange(-1);
						a = parking+j;
						(*a).storedChange(1);
						
						//cout << "(X)Store at parking: " << j + 1 << endl;
					}
					else if (parking[j].readX() == (*a).readX())
					{
						//cout << "X equal" << endl;
						if (parking[j].readY() < (*a).readY())
						{
							(*a).storedChange(-1);
							a = parking+j;
							(*a).storedChange(1);
							(*a).getstored();
							
							//cout << "(Y)Store at parking: " << j + 1 << endl;
						}
					}

				}
				
			}
			//else cout << j + 1 << "º¡·S" << endl;
		}
		
	}
	
	for (int i = 0;i < parkingNumber;i++)
	{
		cout  <<parking[i].getstored() << endl;
	}

	system("pause");
	return 0;
}
