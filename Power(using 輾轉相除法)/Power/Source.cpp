#include<iostream>
//#include<process.h>
using namespace std;

int GCD(int, int);

int main() {
	//while (1) {
		int a,b,c,d,e,f,g;
		cin >> a >> b >> c >> d >> e >> f >> g;

		if (a < 0) {
			b += (-a)*c;
			b = -b;
			a = 0;	
		}
		else {
			b += (a)*c;
			a = 0;
		}
		if (e < 0) {
			f += (-e)*g;
			f = -f;
			e = 0;
		}
		else {
			f += (e)*g;
			e = 0;
		}

		int LEFT, UP, DOWN;
		switch (d)
		{
		case 0:
			UP = b*g + c*f;
			DOWN = g*c;
			break;
		case 1:
			UP = b*g -c*f;
			DOWN = g*c;
			break;
		case 2:
			UP = b*f;
			DOWN = g*c;
			break;
		case 3:
			UP = b*g;
			DOWN = f*c;
			break;
		default:
			cout << "The value of d is wrong!" << endl;
			break;
		}

		if (UP < 0 && DOWN < 0) {
			UP = -UP;
			DOWN = -DOWN;
		}
		if (UP < 0) {
			LEFT = (-UP) / DOWN;
			LEFT = -LEFT;
			UP = (-UP) % DOWN;
			int n = GCD(UP, DOWN);
			UP /= n;
			DOWN /= n;
		}
		else {
			LEFT = UP / DOWN;
			UP = UP % DOWN;
			int n = GCD(UP, DOWN);
			UP /= n;
			DOWN /= n;
		}
		
		cout << LEFT << "\n" << UP << "\n" << DOWN << endl;
		
		
	//}

	//system("pause");
	return 0;
}

int GCD(int a, int b) {  //輾轉相除法
	while (b!=0)
	{                    
		int t = b;       //讓a永遠是被除數(較大)
		b = a%b;         //b永遠是除數
		a = t;
	}
	return a;
}