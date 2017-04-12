#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

void removeEdge(vector < vector <bool> > &graph, int i, int j) {
	graph[i][j]=0;
	graph[j][i]=0;
}

void addEdge(vector < vector <bool> > &graph, int i, int j) {
	graph.at(i).at(j)=1;
	graph.at(j).at(i)=1;
}

void addnVert(vector < vector <bool> > &graph, vector <bool> &pseudo, int n, int i, int j) {
	if (n==0)
		return;
	int newVert=graph.size()+1;
	vector< vector <bool> > newGraph(newVert, vector<bool> (newVert, 0));
	for (int i = 0; i < graph.size(); i++) {
		for (int j = 0; j < graph.size(); j++) {
			if (graph.at(i).at(j))
				newGraph.at(i).at(j)=1;
		}
	}
	graph=newGraph;
	pseudo.push_back(1);
	removeEdge(graph, i, j);
	addEdge(graph, i, newVert-1);
	addEdge(graph, newVert-1, j);
	addnVert(graph, pseudo, n-1, newVert-1, j); }

bool isNeighbor(vector < vector <bool> > &graph, int noVert, int i, int j) {
	return graph[i][j] || graph[j][i];
}


vector <int> bfs(vector < vector <bool> > &graph, int sVert) {
	int noVert=graph.size();
	vector < bool > visited(noVert, 0);
	vector < int > parent(noVert, -1);
	queue <int> bfq;
	bfq.push(sVert);
	visited[sVert]=1;
	while (! bfq.empty()) {
		int curVert = bfq.front();
		bfq.pop();
		if (!visited[curVert]) {
			visited[curVert] = 1;
		}
		for (int i=0; i<noVert; i++)
			if (isNeighbor(graph, noVert, curVert, i))
					if (!visited[i]) {
						parent[i]=curVert;
						bfq.push(i);
					}
	}
	return parent;
}


int main() {
	int n;
	cout << "Enter the number n of vertices: ";
	cin >> n;
	vector< vector <bool> > graph(n, vector<bool> (n, 0));
	vector <bool> pseudo(n, 0);
	for (int firstVert=0; firstVert<n; firstVert++) {
		cout << "Mention each edge exactly once!!!";
		cout << "Enter the number of new neighbours of vertex "<<firstVert<<" : ";
		int noNeighbors;
		cin >> noNeighbors;
		for (int i=0; i<noNeighbors; i++) {
			int secondVert;
			cin >> secondVert;
			if (secondVert < n && secondVert >=0)
				addEdge(graph, firstVert, secondVert);
			cout << "Enter edge weight: ";
			int weight;
			cin >> weight;
			addnVert(graph, pseudo, weight-1, firstVert, secondVert);
		}
	}
	int sVert;
	cout << "Enter source vertex: ";
	cin >> sVert;
	vector <int> parent = bfs(graph, sVert);
	list <int> path;
	for (int dVert=0; dVert<n; dVert++) {
		if(dVert==sVert)
			continue;
		path.clear();
		for (int i = dVert; i != -1; i=parent[i]) {
			path.push_front(i);
		}
		cout << "Shortest path from "<<sVert<< " to " <<dVert<<endl;
		for (auto i : path)	{
			if (!pseudo.at(i))
				cout << i << " -> ";
		}
		cout <<endl;
	}
	cout << "\nShortest path: ";
	cout << endl;
}
