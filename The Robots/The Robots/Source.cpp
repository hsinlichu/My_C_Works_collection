#include<iostream>
//#include<process.h>
using namespace std;

int main() {
	int M, N, X1, Y1, E1, N1, F1, X2, Y2, E2, N2, F2;
	cin >> M >> N >> X1 >> Y1 >> E1 >> N1 >> F1 >> X2 >> Y2 >> E2 >> N2 >> F2;
	int time = 1;
	int R1N = N1;
	int R1E = E1;
	int R2E = E2;
	int R2N = N2;
	while (F1!=0||F2!=0)
	{
		if (F1 != 0)
		{
			if (R1N != 0)
			{
				Y1++;
				R1N--;
			}
			else
			{
				X1++;
				R1E--;
				if (R1E == 0)
				{
					R1N = N1;
					R1E = E1;
				}
			}
			F1--;
		}
		if (F2 != 0)
		{
			if (R2E != 0)
			{
				X2++;
				R2E--;
			}
			else
			{
				Y2++;
				R2N--;
				if (R2N == 0)
				{
					R2E = E2;
					R2N = N2;
				}
			}
			F2--;
		}
		cout << "R1o(" << X1 << "," << Y1 << ")" << F1 <<  endl;
		cout << "R2o(" << X2 << "," << Y2 << ")" << F2 << endl;
		if (X1 == M)X1 = 0;
		if (X2 == M)X2 = 0;
		if (Y1 == N)Y1 = 0;
		if (Y2 == N)Y2 = 0;
		
		cout << "R1(" << X1 << "," << Y1 << ")" << F1 << endl;
		cout << "R2(" << X2 << "," << Y2 << ")" << F2 <<"--------time:"<<time<< endl;
		if (X1 == X2&&Y1 == Y2)
		{
			cout << "robots explode at time " << time << endl;
			system("pause");
			return 0;
		}
		
		time++;
	}
	cout << "robots will not explode" << endl;
	system("pause");
	return 0;
}