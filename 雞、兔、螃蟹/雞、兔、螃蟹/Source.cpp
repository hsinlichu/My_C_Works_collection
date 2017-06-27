#include<iostream>
//#include<process.h>
using namespace std;

void line(int &,int,int,int,int);

struct coordinate{
	int x;
	int y;	
};

struct lineConst{
	int xcofficient;
	int ycofficient;
	int constant;
};
lineConst line1,line2,line3,line4;


int main() {
	coordinate a,b,c,d;
	
	cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
	
	




	//system("pause");
	return 0;
}

void line(int &p,int a,int b,int c,int d){
	p.xcofficient=(d-b);
	p.ycofficient=(a-c);
	p.constant=(d-b)*(-a)+(a-c)*(-b);	
	
}

