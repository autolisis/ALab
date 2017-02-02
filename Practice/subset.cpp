#include <iostream>

using namespace std;

void subs2(int a[], int n)
{	
	for (int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			cout<<a[i]<<", "<<a[j]<<endl;
}

void subs3(int a[], int n)
{	
	for (int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			for(int k=j+1; k<n; k++)
				cout<<a[i]<<", "<<a[j]<<", "<<a[k]<<endl;
}

int main()
{	int a[]={1,2,3,4,5};
	subs2(a,5);
	subs3(a,5);
	return 0;
}
