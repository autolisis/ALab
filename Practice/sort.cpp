#include <iostream>
#include <cstring>

using namespace std;

void printPerm(int a[], int n)
{	for (int i=0; i<n; i++)
		cout<<a[i]<<' ';
	cout<<endl;
}

int isSorted(int a[], int n)
{	
	for (int i=0; i<n-1; i++)
		if (a[i] > a[i+1])
			return 0;
	return 1;
}

int * genPerm(int a[], int size, int n)
{	
	if (size==1)
	{	if (isSorted(a, 7))
			return a;
	}
	for (int i=0; i<size; i++)
	{	genPerm(a, size-1, n);
		
		if (i%2==0)
			swap(a[0], a[size-1]);
		else
			swap(a[i], a[size-1]);
	}
}


int * bruteSort(int a[], int n)
{
	return (genPerm(a, 7, 7));
}


int main()
{
	int * a = new int[7];
	for (int i=0; i<7; i++)
		cin >> a[i];
	a = bruteSort(a, 7);
	printPerm(a, 7);
}
