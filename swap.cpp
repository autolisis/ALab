#include <iostream>
#include <cstring>

using namespace std;

int regSwap(int &x, int &y) //Using temp variable
{
	int t=0;
	t=x;
	x=y;
	y=t;
}

int aritSwap(int &x, int &y) //Arithmetic Manipulation
{
	if((x>0 && y<0) || (x<0 && y>0))
	{
		x = x+y;
		y = x-y;
		x = x-y;
	}
	else
	{
		x = x-y;
		y = x+y;
		x = y-x;
	}
}

int xorSwap(int &x, int &y)	//XOR
{	
	x = x^y;
	y = x^y;
	x = x^y;
}

float regSwap(float &x, float &y) //Using temp variable
{
	float t=0;
	t=x;
	x=y;
	y=t;
}

float aritSwap(float &x, float &y) //Arithmetic Manipulation
{
	if((x>0 && y<0) || (x<0 && y>0))
	{
		x = x+y;
		y = x-y;
		x = x-y;
	}
	else
	{
		x = x-y;
		y = x+y;
		x = y-x;
	}
}

float xorSwap(float &x, float &y)	//Convert both floats to meaningless "int" representations, swap the ints, and then convert back to float
{
	int a, b;
//	void *ptra = &a, *ptrb = &b;
	memcpy(&a, &x, sizeof(x));
	memcpy(&b, &y, sizeof(y));
	a = a^b;
	b = a^b;
	a = a^b;
	memcpy(&x, &a, sizeof(x));
	memcpy(&y, &b, sizeof(y));
}


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
