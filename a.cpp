//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n,e,fr,sc;
	cin >> n >> e;
	vector<vector<int>> nd(n);
	for(int i=0; i<e; i++){
	    cin >> fr >> sc;
	    nd[fr].push_back(sc);
	    nd[sc].push_back(fr);
	}
	for(int i=0; i<n; i++){
	    cout << nd[i].size() << " ";
	}
	return 0;
}
