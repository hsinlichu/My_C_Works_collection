#include<iostream>
#include<vector>
#include<process.h>
using namespace std;

int main() {
	int number;
	cin >> number;
	vector<int>input(number);
	int result[] = {0,0,0};
	for (int i = 0;i<input.size();i++)cin >> input.at(i);
	for (int i = 0;i < number;i++) {
		switch (input.at(i)%3)
		{
		case 0:
			result[0] += 1;
			break;
		case 1:
			result[1] += 1;
			break;
		case 2:
			result[2] += 1;
			break;
		default:
			cout << "There is something wrong." << endl;
			break;
		}
	}
	for (int i = 0;i < 3;i++) {
		cout << result[i];
		if (i != 2)cout << " ";
	}


	system("pause");
	return 0;
}