#include <iostream>

using namespace std;

int gcd(int x ,int y)
{
    if(x==0)
	if (y==0)
	{	cout <<"Indeterminate. ";
		return -1;
	}
    	else
		return y;
    if(x==y)
	return x;
    if(y>x)
	return gcd(y, x);

    return gcd((x%y) ,y);
}

int gcd(int arr[], int l, int u)
{
    if(u==l)
	return arr[l];

    return gcd(gcd(arr, (u+l)/2, l), gcd(arr, u, (u+l)/2+1));
}

int main()
{
	int x, y, n;
	cout << "Case 1: \n\n";
	cout << "Enter two numbers: \n\n";
	cin >> x >> y;
	cout << "GCD = "<<gcd(x, y)
		<<"Case 2: \n\nEnter array size. ";
	cin >> n;
	int arr[n];
	cout << "Enter "<<n<<" numbers: ";
	for(int i=0; i<n; i++)
		cin>>arr[i];
	cout <<"GCD = "<<gcd(arr, 0, n-1)<<endl; 

	return 0;
}
