#include<stdio.h>
#include<iostream>
#include<process.h>
using namespace std;

int main() {
	int specialPrize[3];
	const int prize[9] = { 0, 0, 0, 200, 1000, 4000, 10000, 40000, 200000 };
	for (size_t i = 0; i < 3; i++)cin>>specialPrize[i];
	int firstPrize[3];
	for (size_t i = 0; i < 3; i++)cin >> firstPrize[i];

	
	int input,total=0;	
	
	int sum = 0, x;
	while (scanf("%d", &x) == 1) {
		for (int i = 0; i < 3; i++) {
			if (x == specialPrize[i])
				sum += 2000000;
		}
		for (int i = 0; i < 3; i++) {
			int base = 1e+8;
			for (int j = 8; j >= 3; j--, base /= 10) {
				if (x%base == firstPrize[i] % base) {
					sum += prize[j];
					break;
				}
			}
		}
		//cout << "over" << endl;
	}
	printf("%d\n", sum);


	system("pause");
	return 0;
}