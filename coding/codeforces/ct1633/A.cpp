#include<iostream>
using namespace std;
 
int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int t;
		cin >> t;
		int a = t%7;
		if(a <= t%10) t -= a;
		else t += 7 - a;
		cout << t << endl;
	}
	
	return 0;	
}
