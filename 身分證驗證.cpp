#include<iostream>
#include<process.h>
#include<typeinfo>
#include<sstream>
#include<string>

using namespace std;

union transfer{
	char ascii;
	int number;	
};


int main(){
	union transfer A;
	A.ascii='A';
	
	
	string input[10];
	int checkNumber;
	int englishNumber;
	while(getline(cin,input)){
		union transfer english;
		
		english.ascii=input[0];
		if(english.number==(33-10+A.number))english.number=30+A.number-10;
		if(english.number==(34-10+A.number))english.number=31+A.number-10;
		if(english.number==(35-10+A.number))english.number=33+A.number-10;
		if(english.number==(18-10+A.number))english.number=34+A.number-10;
		if(english.number==(24-10+A.number))english.number=35+A.number-10;
		if(english.number>(17-10+A.number)&&english.number<(23-10+A.number))english.number--;
		if(english.number>(22-10+A.number)&&english.number<(30-10+A.number))english.number-=2;
		englishNumber=english.number-A.number+10;
		cout<<englishNumber<<endl;
		checkNumber=englishNumber/10+(englishNumber%10)*9;

		ostringstream number;
		int x;




		for(int i=1;i<9;i++){
			number << input[i];
			number >> x;
			cout<<x<<"*"<<(9-i)<<"="<<x*(9-i)<<endl;
			
			checkNumber+=(int)x*(9-i);			
		}
		number << input[9];
		number >> x;

		checkNumber+=x;
		cout<<checkNumber<<endl;
		
		if(checkNumber%10==0){
			cout<<"real"<<endl;
		}
		else{
			cout<<"fake"<<endl;
		}		
	}
	
	system("pause");
	return 0;
} 
