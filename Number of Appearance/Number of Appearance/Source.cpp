#include<iostream>
#include<process.h>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int input[7];
	for (size_t i = 0; i < 7; i++) {
		input[i] = M % 10;
		M /= 10;
	}
	int times=0;
	for (size_t i = 0; i < 6; i++)
	{
		if (N == (input[i +1] * 10 + input[i]))times += 1;
	}
	cout << times;

	system("pause");
	return 0;
}