#include<iostream>
#include<process.h>
#include<string>
using namespace std;

template<class type1>
type1 umax(type1 x, type1 y, type1 z) {
	
	type1 max = x;
	if (y > max)max = y;
	if (z > max)max = z;
	return max;
}


int main() {
	int i = 1;
	while (true) {
		
		cout << "Please choose your data type:\n1.int, 2.float, 3.double, 4.char : " << endl;
		char dataType;
		cin >> dataType;
		switch (dataType) {
			case '1':
				int a1, b1, c1;
				cout << "Please input three int: " << endl;
				cin >> a1>>b1>>c1;
				cout << i << ": " << umax(a1, b1, c1) << endl;
				break;
			case '2':
				float a2, b2, c2;
				cout << "Please input three float: " << endl;
				cin >> a2>>b2>>c2;
				cout << i << ": " << umax(a2, b2, c2)<<endl;
				break;
			case '3':
				double a3, b3, c3;
				cout << "Please input three double: " << endl;
				cin >> a3>>b3>>c3;
				cout << i << ": " << umax(a3, b3, c3) << endl;
				break;
			case '4':
				char a4, b4, c4;
				cout << "Please input three char: " << endl;
				cin >> a4>>b4>>c4;
				cout << i << ": " << umax(a4, b4, c4) << endl;
				break;
			default:
				cout << "Your input type is wrong";
				i = i - 1;
				break;
		}
		i++;
	}

	system("pause");
	return 0;
}

