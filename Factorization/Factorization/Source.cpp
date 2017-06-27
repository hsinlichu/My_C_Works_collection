#include<iostream>
//#include<process.h>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
	int a, b, c;
	int coB, coC;
	int solution = 0;
	cin >> a >> b >> c;
	if (b == 0 && c == 0)
	{
		if(a>0)cout << solution << " " << solution << " " << a;
		else cout << a << " " << solution << " " << solution  ;
		//system("pause");
		return 0;
	}
	vector<int>factor;
	if (c != 0)
	{
		for (int i = 1;i <= pow(fabs(c), 0.5);i++)
		{
			if (c%i == 0)
			{
				factor.push_back(-i);
				factor.push_back(i);
				factor.push_back(c / i);
				factor.push_back(-c / i);
			}
		}
		sort(factor.begin(), factor.end());
		//for (int item : factor)cout << item << " , ";
		//cout << endl;
		int D3;
		
		for (vector<int>::const_iterator i = factor.begin();i < factor.end();i++)
		{
			D3 = pow(*i, 3) + a*pow(*i, 2) + b*(*i) + c;
			//cout << D3 << endl;
			if (D3 == 0)
			{
				//cout << "answer:" << -item << endl;
				solution = -(*i);
				break;
			}
		}

		coB = a - solution;
		coC = c / solution;
	}
	else
	{
		coB = a;
		coC = b;
	}
	//cout << "co: " << coB << "," << coC << endl;
	//cout << "x^2+" << coB << "x+" << coC << endl;
	int root1, root2;
	
	root1 = (-coB + pow((pow(coB, 2) - 4* coC), 0.5)) / 2;
	root2 = (-coB - pow((pow(coB, 2) - 4* coC), 0.5)) / 2;
	int answer[] = { -root1 ,-root2,solution };
	sort(answer, answer + 3);
	for (int i = 0;i < 3;++i)
	{
		cout << answer[i];
		if (i != 2)cout << " ";
	}
	
	//system("pause");
	return 0;
}