#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

void printArr(int a[], int n)	//Utility function to print an array
{	cout<<endl;
	for (int i=0; i<n; i++)
		cout<<a[i]<<' ';
	cout<<endl;
}


void checkSwap(int &a, int &b)
{	if (a > b)
		swap(a,b);
}
void networkSort(int a[], int n)
{	
	checkSwap(a[1], a[2]);
	checkSwap(a[0], a[2]);
	checkSwap(a[0], a[1]);
	checkSwap(a[3], a[4]);
	checkSwap(a[5], a[6]);
	checkSwap(a[3], a[5]);
	checkSwap(a[4], a[6]);
	checkSwap(a[4], a[5]);
	checkSwap(a[0], a[4]);
	checkSwap(a[0], a[3]);
	checkSwap(a[1], a[5]);
	checkSwap(a[2], a[6]);
	checkSwap(a[2], a[5]);
	checkSwap(a[1], a[3]);
	checkSwap(a[2], a[4]);
	checkSwap(a[2], a[3]);
}


int isSorted(int a[], int n)	//Function to check if an array is sorted
{	
	int i=0;
	while (i<n-1)
	{	if (a[i] > a[i+1])
			return 0;
		i++;
	}
	return 1;

}
int flagSorted = 0;
int temp[7];
void bruteSort(int a[], int size, int n)	//Function that generates each permutation of n-element array and calls isSorted() on each permutation
{
	if (flagSorted == 1)
		return;
	if (size==1)
	{	
		if (isSorted(a, 7) == 1)
		{	flagSorted=1;
			memcpy(temp, a, 7*sizeof(int));
		}
		return;
	}
	for (int i=0; i<size; i++)
	{	if (flagSorted == 1)
			return;
		bruteSort(a, size-1, n);
		if (flagSorted == 1)
			return;
		if ((size & 1) == 1)
			swap(a[0], a[size-1]);
		else
			swap(a[i], a[size-1]);
	}
}


void merge(int a[], int l, int m, int h)
{	int i, j, k, t[20];
	i=l;
	k=l;
	j=m+1;
	while (i<=m && j<=h)
	{	if (a[i] < a[j])
			t[k++] = a[i++];
		else
			t[k++] = a[j++];
	}
	while (i<=m)
		t[k++]=a[i++];
	while (j<=h)
		t[k++]=a[j++];

	for(i=l; i<k; i++)
		a[i]=t[i];
}
void mergeSort(int a[], int l, int h)	//Normal merge-sort routine
{	if (l < h)
	{	int m=(l+h)/2;
		mergeSort(a, l, m);
		mergeSort(a, m+1, h);
		merge(a, l, m, h);
	}
}


int main()
{
	int a[7];

	srand(time(NULL));
	clock_t beforeTime=clock();
	for (int exec=0; exec<100; exec++)
	{	for (int i=0; i<7; i++)
			a[i]=rand()%2500;
		networkSort(a, 7);
	}
	clock_t netTime = clock()-beforeTime;

	beforeTime=clock();
	for (int exec=0; exec<100; exec++)
	{	for (int i=0; i<7; i++)
			a[i]=rand()%2500;
		bruteSort(a, 7, 7);
	}
	clock_t bruTime = clock()-beforeTime;

	beforeTime=clock();
	for (int exec=0; exec<100; exec++)
	{	for (int i=0; i<7; i++)
			a[i]=rand()%2500;
		mergeSort(a, 0, 6);
	}
	clock_t merTime = clock()-beforeTime;

	cout<<endl<<"Time analysis complete: "<<endl
		<<"Network sort: "<<netTime<<endl
		<<"Brute sort: "<<bruTime<<endl
		<<"Merge sort: "<<merTime<<endl;
}
