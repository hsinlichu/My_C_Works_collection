#include<iostream>
using namespace std;


int main() {
	
	int sudoku[9][9];
	while (cin>> sudoku[0][0]) {
		
		for (int i = 0;i < 9;i++) {
			for (int j = 0;j < 9;j++) {
				if (i == 0 && j == 0) {
				}
				else {
					cin >> sudoku[i][j];
				}
			}
		}
		int totalnumber = 0;
		for (int i = 0;i < 9;i++) {
			for (int j = 0;j < 9;j++) {
				totalnumber += sudoku[i][j];
			}
		}
		if (totalnumber != 45 * 9) {
			cout << "no" << endl;
			goto end;
		}
		for (int i = 0;i < 9;i++) {
			int rowtotal = 0;
			for (int j = 0;j < 9;j++) {
				rowtotal += sudoku[i][j];
			}
			if (rowtotal != 45) {
				cout << "no" << endl;
				goto end;
			}
		}
		for (int i = 0;i < 9;i++) {
			int columntotal = 0;
			for (int j = 0;j < 9;j++) {
				columntotal += sudoku[j][i];
			}
			if (columntotal != 45) {
				cout << "no" << endl;
				goto end;
			}
		}
		for (int i = 0;i < 7;i+=3) {
			for (int j = 0;j < 7;j+=3) {
				int blocktotal=0;
				for (int k = 0;k < 3;k++) {
					for (int l = 0;l < 3;l++) {
						blocktotal += sudoku[i + k][j + l];
					}
				}
				if (blocktotal != 45) {
					cout << "no" << endl;
					goto end;
				}
			}
		}

		
		cout << "yes" << endl;
	end:;
		
	}
	return 0;
}