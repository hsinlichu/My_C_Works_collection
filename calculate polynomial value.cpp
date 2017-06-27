#include<iostream>
#include<process.h>
using namespace std;

int main() {

	int n;
	
	cout << "Please input how many term you want: " << endl;
	cin >> n;

	float *matrix = new float[n + 1];
	
	cout << "Please input coefficient: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> *(matrix + i);
	}

	float x;
	cout << "Please input x: " << endl;
	cin >> x;
	float sum = 0;
	float term = 0;
	for (int i = 0; i < n; i++) {

		if (i == 0)term = (*matrix);
		else term = term*(*(matrix +i)) * x / (*(matrix +i - 1));
		sum += term;
	}
	cout << "f(" << x << ")=" << sum << endl;

	system("pause");
	return 0;
}