#include <iostream>


using namespace std;


void printPerm(int a[], int n)
{	for (int i=0; i<n; i++)
		cout<<a[i]<<' ';
	cout<<endl;
}



void genPerm(int a[], int size, int n)
{	
	if (size==1)
	{	printPerm(a, n);
		return;
	}
	for (int i=0; i<size; i++)
	{	genPerm(a, size-1, n);
		
		if (i%2==0)
			swap(a[0], a[size-1]);
		else
			swap(a[i], a[size-1]);
	}
}


int main()
{	
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	genPerm(a, 9, 9);

	return 0;
}
