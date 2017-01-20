#include <iostream>

using namespace std;

void prod2(int a[] , int n)
{
    for(int i=0 ; i<n ; i++)
    {
        for(int j = i+1 ; j<n ; j++)
        {
            cout<<a[i]<<" , "<<a[j]<<endl;
        }
    }
}

void prod(int a[] , int n)
{
    for(int i=0 ; i<n ; i++)
    {
        for(int j = i+1 ; j<n ; j++)
        {
            for(int k = j+1 ; k<n ; k++)
            {
                if(k==i || k==j)
                    continue;

                cout<<a[i]<<" , "<<a[j]<<" , "<<a[k]<<endl;
            }
        }
    }
}

int main()
{
    int a[]={1,4,2,6,8};
    prod2(a,5);
    prod(a,5);
    return 0;
}
