#include<iostream>
using namespace std;

union transfer {
	char ascii;
	int number;
};


int main() {
	union transfer A;
	A.ascii = 'A';


	char input[10];
	int checkNumber;
	int englishNumber;
	while (cin>>input) {
		union transfer english;

		english.ascii = input[0];
		if (english.number == (33 - 10 + A.number))english.number = 30 + A.number - 10;
		if (english.number == (34 - 10 + A.number))english.number = 31 + A.number - 10;
		if (english.number == (35 - 10 + A.number))english.number = 33 + A.number - 10;
		if (english.number == (18 - 10 + A.number))english.number = 34 + A.number - 10;
		if (english.number == (24 - 10 + A.number))english.number = 35 + A.number - 10;
		if (english.number>(17 - 10 + A.number) && english.number<(23 - 10 + A.number))english.number--;
		if (english.number>(22 - 10 + A.number) && english.number<(30 - 10 + A.number))english.number -= 2;
		englishNumber = english.number - A.number + 10;
		//cout << englishNumber << endl;
		checkNumber = englishNumber / 10 + (englishNumber % 10) * 9;





		int x;
		for (int i = 1;i<9;i++) {
			
			switch (input[i]) {
			case '1':x = 1;break;
			case '2':x = 2;break;
			case '3':x = 3;break;
			case '4':x = 4;break;
			case '5':x = 5;break;
			case '6':x = 6;break;
			case '7':x = 7;break;
			case '8':x = 8;break;
			case '9':x = 9;break;
			}
					
			//cout << x << "*" << (9 - i) << "=" << x*(9 - i) << endl;

			checkNumber +=x*(9 - i);
		}
		switch (input[9]) {
		case '1':x = 1;break;
		case '2':x = 2;break;
		case '3':x = 3;break;
		case '4':x = 4;break;
		case '5':x = 5;break;
		case '6':x = 6;break;
		case '7':x = 7;break;
		case '8':x = 8;break;
		case '9':x = 9;break;
		}
		
		checkNumber += x;
		//cout << checkNumber << endl;

		if (checkNumber % 10 == 0) {
			cout << "real" << endl;
		}
		else {
			cout << "fake" << endl;
		}
	}

	//system("pause");
	return 0;
}