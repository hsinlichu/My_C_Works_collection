#include<iostream>
//#include<process.h>
using namespace std;

int main() {
	int column = 0, row = 0;
	while (cin >> row >> column) {
		
		int *matrix = new int[column*row];

		for (int i = 0;i < row;i++) {
			for (int j = 0; j <column;j++) {
				cin >> *(matrix+i*column +j);
			}
		}
		for (int i = 0;i < column;i++) {
			for (int j = 0;j <row;j++) {
				cout << *(matrix +j*column+i )<<" ";
			}
			cout << endl;
		}
		delete[] matrix;
	}
	//system("pause");
	return 0;





}



