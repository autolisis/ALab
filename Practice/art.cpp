#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void addEdge(vector < vector <bool> > &graph, int noVert, int i, int j)
{
	graph[i][j]=true;
	graph[j][i]=true;
}

bool isNeighbor(vector < vector <bool> > &graph, int noVert, int i, int j)
{
	return graph[i][j] || graph[j][i];
}

void dfs(vector < vector <bool> > &graph, int noVert, int startVert)
{
	vector < bool > visited(noVert, false);
	stack <int> dfs;
	dfs.push(startVert);
	visited[startVert]=1;
	while (!dfs.empty())
	{
		int curVert = dfs.top();
		visited[curVert] = 1;
		cout << curVert<<" ";
		dfs.pop();
		for (int i=0; i<noVert; i++)
		{
			if (isNeighbor(graph, noVert, curVert, i))
					if (!visited[i])
						dfs.push(i);
		}
	}
}

int main()
{
	int n;
	cout << "Enter the number n of vertices: ";
	cin >> n;
	vector< vector <bool> > graph(n, vector<bool> (n, 0));
	for (int firstVert=0; firstVert<n; firstVert++)
	{
		cout << "Enter the number of neighbours of vertex "<<firstVert<<" : ";
		int noNeighbors;
		cin >> noNeighbors;
		for (int i=0; i<noNeighbors; i++)
		{	int secondVert;
			cin >> secondVert;
			if (secondVert < n && secondVert >=0)
				addEdge(graph, graph.size(), firstVert, secondVert);
		}
	}
	int startVert;
	cin >> startVert;
	dfs(graph, graph.size(), startVert);
}
