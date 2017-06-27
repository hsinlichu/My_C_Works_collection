#include<stdio.h>
//#include<process.h>
using namespace std;

int main() {
	int year, month, firstday,numberofday;
	scanf("%d%d%d",&year,&month,&firstday);


	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		numberofday = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		numberofday = 30;
		break;
	case 2:
		
		if (year % 400 == 0)
		{
			numberofday = 29;
			break;
		}
		else if (year % 100 == 0)
		{
			numberofday = 28;
			break;
		}
		else if (year % 4 == 0)
		{
			numberofday = 29;
			break;
		}
		else
		{
			numberofday = 28;
			break;
		}
	default:
		printf("invalid\n");
		return 0;
	}
	if (firstday < 0 || firstday>6)
	{
		printf("invalid\n");
		return 0;
	}

	printf(" Su Mo Tu We Th Fr Sa\n");
	printf("=====================\n");
	int daycounter=0;
	for (int i = 0; i < firstday; i++,daycounter++)printf("   ");
	for (int i = 1; i <= numberofday; i++,daycounter++)
	{
		if (daycounter==7)
		{
			printf("\n");
			daycounter = 0;
		}
		printf("%3d", i);
	}
	printf("\n=====================\n");



	//system("pause");
	return 0;
}