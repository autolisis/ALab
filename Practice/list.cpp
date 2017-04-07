#include <iostream>
#include <list>
#include <cstdio>
using namespace std;

list<int> a;

int main()
{
	a.push_front(3);
	a.push_front(4);
	a.push_front(4);
	cout << a.front();
	a.pop_front();
	for (auto i : a)
		cout << i << endl;
}
