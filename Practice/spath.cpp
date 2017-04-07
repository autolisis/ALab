#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

void addEdge(vector < vector <bool> > &graph, int noVert, int i, int j) {
	graph[i][j]=1;
	graph[j][i]=1;
}

bool isNeighbor(vector < vector <bool> > &graph, int noVert, int i, int j) {
	return graph[i][j] || graph[j][i];
}

void bfs(vector < vector <bool> > &graph, int noVert, int sVert) {
	vector < bool > visited(noVert, 0);
	queue <int> bfq;
	bfq.push(sVert);
	visited[sVert]=1;
	int level=0;
	while (! bfq.empty()) {
		int curVert = bfq.front();
		bfq.pop();
		if (!visited[curVert]) {
			cout << curVert<< " ";
			visited[curVert] = 1;
		}
		else 
			level++;
		for (int i=0; i<noVert; i++)
			if (isNeighbor(graph, noVert, curVert, i))
					if (!visited[i])
						bfq.push(i);
	}
	cout <<endl<< "No. of levels: "<<level;
}

void sPath(vector < vector <bool> > &graph, int noVert, int sVert, int dVert) {
	vector < bool > visited(noVert, 0);
	vector < int > prev(noVert, -1);
	queue <int> bfq;
	bfq.push(sVert);
	visited[sVert]=1;
	while (! bfq.empty()) {
		int curVert = bfq.front();
		bfq.pop();
		if (curVert==dVert)
			break;
		if (!visited[curVert]) {
			visited[curVert] = 1;
		}
		for (int i=0; i<noVert; i++)
			if (isNeighbor(graph, noVert, curVert, i))
					if (!visited[i]) {
						prev[i]=curVert;
						bfq.push(i);
					}
	}
	list <int> path;
	for (int i = dVert; i != sVert; i=prev[i]) {
		path.push_front(i);
	}
	path.push_front(sVert);
	for (auto i : path)	{
		cout << i << " -> ";
	}
}


int main() {
	int n;
	cout << "Enter the number n of vertices: ";
	cin >> n;
	vector< vector <bool> > graph(n, vector<bool> (n, 0));
	for (int firstVert=0; firstVert<n; firstVert++) {
		cout << "Enter the number of neighbours of vertex "<<firstVert<<" : ";
		int noNeighbors;
		cin >> noNeighbors;
		for (int i=0; i<noNeighbors; i++) {
			int secondVert;
			cin >> secondVert;
			if (secondVert < n && secondVert >=0)
				addEdge(graph, graph.size(), firstVert, secondVert);
		}
	}
	int sVert, dVert;
	cin >> sVert >> dVert;
	bfs(graph, graph.size(), sVert);
	cout << endl;
	sPath(graph, graph.size(), sVert, dVert);
	cout << endl;
}
