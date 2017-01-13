#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int findMax1(int arr[], int n) 	//Conventional Approach
{	
	int i,max = arr[0];
	for (i=0; i<n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}


int getMax2(int arr[], int l, int u)	//Helper Function for 2
{	if ((u == l+1) || (u == l))
		return max(arr[u], arr[l]);
	return max(getMax2(arr, l, (u+l)/2), getMax2(arr, (u+l)/2+1, u));
}

int findMax2(int arr[], int n)	//Binary search inspired Approach
{
	return getMax2(arr, 0, n-1);
}


int findMax3(int arr[], int n)	//Elimination Approach
{	int i,j;
	for (i=0; i<n; i++)
	{	for (j=0; j<n; j++)
		{	if (arr[i] < arr[j])
				break;
			if (j == n-1)
				return arr[i];
		}
	}
}	



int findMax4(int arr[], int n)	//Bubble Sort Inspired Approach
{	int i, temp[n];
	for (i=0; i<n; i++)	//Replace with memcpy
		temp[i] = arr[i];
	for (i=0; i<n-1; i++)
	{	if (temp[i] > temp[i+1])
			swap(temp[i], temp[i+1]);
	}
	return temp[n-1];
}

		
int findMax5(int arr[], int n)	//Graph Theory Inspired Approach
{	int i, j, lesserThan[n][n] = {0}, rowSum[n] = {0};
	for (i=0; i<n; i++)	
	{	for (j=0; j<n; j++)
		{	lesserThan[i][j] = (arr[i] < arr[j] ? 1 : 0);
			rowSum[i] += lesserThan[i][j];
		}
	}
	for (i=0; i<n; i++)
	{	if (rowSum[i] == 0)
			return arr[i];
	}
}

int findMax6(int arr[], int n)	//Sort and Pick Approach
{	int i, temp[n];
	for(i=0; i<n; i++)	//Replace with memcpy
		temp[i] = arr[i];
	sort(temp, temp+n);
	return temp[n-1];
}


void heapify(int *arr, int n, int i)
{
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	
	if (arr[l] > arr[largest] && l < n)
		largest = l;
	if (arr[r] > arr[largest] && r < n)
		largest = r;
	
	if (largest != i)
	{	int tem = arr[largest];
		arr[largest] = arr[i];
		arr[i] = tem;
		heapify(arr, n, largest);
	}
}

int findMax7(int arr[], int n)	//Heapify and Pick Approach
{
	int temp[n+1] = {0};
	memcpy(temp, arr, n*sizeof(*arr));
	heapify(temp, n, n/2-1);
	return temp[1];
}

int main()
{	
	int n, i;
	cout <<"Enter size: ";
	cin >> n;
	int arr[n] = {0};
	for (i=0; i<n; i++)
		cin >> arr[i];
	cout << "\nMaximum has been determined through 7 different approaches \n\n";
	cout << "1: " << findMax1(arr, n);
	cout << "\n2: " << findMax2(arr, n);
	cout << "\n3: " << findMax3(arr, n);
	cout << "\n4: " << findMax4(arr, n);
	cout << "\n5: " << findMax5(arr, n);
	cout << "\n6: " << findMax6(arr, n);
	cout << "\n7: " << findMax7(arr, n);
	return 0;
}
