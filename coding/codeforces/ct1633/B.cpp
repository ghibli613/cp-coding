#include<iostream>
#include<string>
using namespace std;
 
int main()
{
	int n;
	cin >> n;
	string t;
	while(n--)
	{
		cin >> t;
		int a = 0, b = 0, len = t.length();
		for(int i = 0; i < len; i++)
		{
			if(t[i] == '0') a++;
			else b++;
		}
		if(a < b) cout << a << endl;
		else if(a==b) cout << a-1 << endl;
		else cout << b << endl;
			
	}
	
	return 0;	
}
