#include <iostream>
#include <vector>
using namespace std;
 
 
void popKSubsetN(int k, int n, vector < vector < vector<string> > > &DP) {
    string str = "";
     
    for (int len = 0; len <= k; len++) {
        DP[len][0].push_back(str);
        str = str + "0";
    }
    for (int len = 1; len <= k; len++) {
        for (int n = 1; n <= len; n++) {
            for (string str : DP[len - 1][n])
                DP[len][n].push_back("0" + str);
 
            for (string str : DP[len - 1][n - 1])
                DP[len][n].push_back("1" + str);
        }
    }
	for (string str : DP[k][n])
		cout << str << endl;
	cout << endl;
}
 
int main() {
	int k,n;
	cin >> k >> n;
	vector < vector < vector<string> > > DP(k+1, vector < vector<string> >(k+1));
    popKSubsetN(k, n, DP);
 
    return 0;
}
