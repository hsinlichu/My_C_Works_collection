#include<iostream>
#include<process.h>
using namespace std;

int main() {
	int year, week,times;
	cin >> year >> week >> times;
	for (size_t i = 0; i < times; i++)
	{
		int month, day, total = 0;
		int error = 0;
		cin >> month >> day;
		if (month < 1 || month>12)
		{
			error = -1;
			cout << error << endl;
			continue;
		}
		else if(day < 1 ||day>31)error = -2;
		
		int check=0;
		switch (month)
		{
		case 4:
		case 6:
		case 9:
		case 11:
			if (day>30)
			{
				error = -2;
			}
			break;
		case 2:
			//cout << "2ды" << endl;
			
			if (year % 400 == 0)
			{
				check = 29;
				break;
			}
			else if (year % 100 == 0)
			{
				check = 28;
				break;
			}
			else if (year % 4 == 0)
			{
				check = 29;
				break;
			}
			else
			{
				check = 28;
				break;
			}

			
		}
		if (month == 2 && day > check)error = -2;
		if (error != 0)
		{
			cout << error << endl;
			continue;
		}


		for (size_t j = month-1; j > 0; j--)
		{
			switch (j)
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				total += 31;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				total += 30;
				break;
			case 2:
				int check;
				if (year % 400 == 0)
				{
					total += 29;
					break;
				}
				else if (year % 100 == 0)
				{
					total += 28;
					break;
				}
				else if (year % 4 == 0)
				{
					total += 29;
					break;
				}
				else
				{
					total += 28;
					break;
				}
			default:
				cout << "You are wrong!!" << endl;
				break;
			}
		}
		total += day;
		//cout << total << endl;
		cout << ((total - 1) % 7 + week) % 7 << endl;
		
	}




	system("pause");
	return 0;
}