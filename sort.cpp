#include <iostream>
#include <cstring>

using namespace std;

int sort1(int arr[], int n)
{	


int main()
{
		cout << "Enter the values of a and b"<<endl;
		int a,b;
		cin >> a >> b;
		regSwap(a,b);
		cout <<"Now the values of a, b = "<<a<<", "<<b<<endl;
	   	aritSwap(a,b);
		cout <<"Now the values of a, b = "<<a<<", "<<b<<endl;
	   	xorSwap(a,b);
		cout <<"Now the values of a, b = "<<a<<", "<<b<<endl;
		
		cout << "Enter the values of x and y"<<endl;
		float x,y;
		cin >> x >> y;
		regSwap(x,y);
		cout <<"Now the values of x, y = "<<x<<", "<<y<<endl;
	   	aritSwap(x,y);
		cout <<"Now the values of x, y = "<<x<<", "<<y<<endl;
	   	xorSwap(x,y);
		cout <<"Now the values of x, y = "<<x<<", "<<y<<endl;
		return 0;
}
