#include <iostream>
#include <set>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

/* Utility function to add an edge to a graph */
void addEdge(vector < vector <bool> > &graph, pair <int, int> edge) {
	graph[edge.first][edge.second]=true;
	graph[edge.second][edge.first]=true;
}

/* Utility function to count number of leaves in a graph */
int numberLeaves(vector < vector <bool> > &graph) {
		vector <int> degreeSeq (graph.size());
		for (unsigned int i = 0; i < graph.size(); i++) {
			int degree=0;
			for (unsigned int j = 0; j < graph.size(); j++) {
				if (graph[i][j])
					degree++;
			}
			degreeSeq[i]=degree;
		}
		int noLeaves = 0;
		for (int i : degreeSeq)
			if (i==1)
				noLeaves++;
		return noLeaves;
}

/* Utility function - Returns true if two vertices i and j are neighbors in graph */
bool isNeighbor(vector < vector <bool> > &graph, int noVert, int i, int j)	{
	return graph[i][j] || graph[j][i];
}

/* Returns 1 if any vertex has only 0 neigbours -> The edge was used to make a cycle */
bool isCyclic(vector < vector <bool> > &graph) {
	vector <int> degreeSeq (graph.size(), 0);
	for (unsigned int i = 0; i < graph.size(); i++) {
		int degree=0;
		for (unsigned int j = 0; j < graph.size(); j++) {
			if (graph[i][j])
				degree++;
		}
		degreeSeq[i]=degree;
	}

	for (auto i : degreeSeq)
		if (i == 0)
			return true;
	return false;
}

vector <vector < vector <bool> > > trees;
vector <int> treeLeaves;
vector < pair <int, int> > edges;

/* Utility function to enumerate the number of edges into edges vector */
void populateEdges(vector < vector <bool> > &graph, vector < pair <int, int> > &edges) {
	for (unsigned int i=0; i<graph.size(); i++)
		for (unsigned int j = i; j < graph.size(); j++) {
			if (graph[i][j])
				edges.push_back(make_pair(i,j));
		}
}

/* Code adapted from the code to generate all binary strings of len n with k bits set */
/* This is exactly similar to our problem: Choose only |V|-1 edges out of the |E| edges in the graph */
void popTrees(vector < vector <bool> > &graph, int noEdges, int requiredEdges) {
	string str = "";
	static vector < vector < vector<string> > > DP(2*noEdges, vector < vector<string> >(2*noEdges));

	for (int len = 0; len <= noEdges; len++) {
		DP[len][0].push_back(str);
		str = str + "0";
	}
	for (int len = 1; len <= noEdges; len++) {
		for (int n = 1; n <= len; n++) {
			for (string str : DP[len - 1][n])
				DP[len][n].push_back("0" + str);

			for (string str : DP[len - 1][n - 1])
				DP[len][n].push_back("1" + str);
		}
	}
	/* For all such binary strings with k bits set, create its corresponding graph and check if it is cyclic */
	/* 	if not, add it to the list of spantrees */
	for (string str : DP[noEdges][requiredEdges]) {
		vector < vector <bool> > newTree(requiredEdges+1, vector <bool> (requiredEdges+1, false));

		for (unsigned int edge=0; edge<str.length(); edge++) {
			if (str.at(edge) == '1')
				addEdge(newTree, edges[edge]);
		}
		if (!isCyclic(newTree)) {
			trees.push_back(newTree);
			treeLeaves.push_back(numberLeaves(newTree));
		}
	}
}

/* Black box function - Generates all possible spanning trees of graph, gets their leaf count and returns
	true if there exists a spanning tree with at most k leaves */
bool hasatMostkLeafTree(vector <vector <bool> > &graph, int k, int &treeIndex) {
	int noEdges = edges.size();
	int noVerts = graph.size();

	/* Populate list of trees and number of leaves only once to improve efficiency */
	static bool populated = false;
	if (!populated)	{
		populated=true;
		popTrees(graph, noEdges, noVerts-1);
	}

	/* Iterate through the already generated list until we find a tree with at most k leaves */
	for (unsigned int i = 2; i < treeLeaves.size(); i++) {
		if (treeLeaves.at(i) <= k) {
			treeIndex=i;
			return true;
		}
	}
	return false;
}

/* Function that returns the minLeaf tree through treeIndex reference */
void minLeafSpanningTree(vector < vector <bool> > &graph, int &treeIndex) {
	for (unsigned int i = 0; i < graph.size()-1; i++) {
		/* Calling blackbox */
		if(hasatMostkLeafTree(graph, i, treeIndex))
			break;
	}
}

int main() {
	/* Input graph */
	int n;
	cout << "Enter the number n of vertices: ";
	cin >> n;
	vector< vector <bool> > graph(n, vector<bool> (n, 0));
	for (int firstVert=0; firstVert<n; firstVert++) {
		cout << "Enter the number of neighbours of vertex "<<firstVert<<" : ";
		int noNeighbors;
		cin >> noNeighbors;
		cout << "Enter the neighbours of vertex "<< firstVert << ' ';
		for (int i=0; i<noNeighbors; i++) {
			int secondVert;
			cin >> secondVert;
			if (secondVert < n && secondVert >=0)
				addEdge(graph, make_pair(firstVert, secondVert));
		}
	}
	/* Get list of edges in graph */
	populateEdges(graph, edges);
	/* treeEdges holds list of all edges in a certain spanning tree */
	vector < pair <int,int> > treeEdges;
	/* TreeIndex refers to the index of the Tree that has minLeafTree */
	int treeIndex;
	treeIndex = 0;

	minLeafSpanningTree(graph, treeIndex);


	/* Output the minLeafSpanTree */
	cout <<endl << "Edges of minLeafSpanTree: "<<endl;
	populateEdges(trees.at(treeIndex), treeEdges);
	for (auto i : treeEdges) {
		cout << i.first << ',' << i.second <<endl;
	}

	return 0;
}
