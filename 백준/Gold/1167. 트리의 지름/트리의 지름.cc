#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

int n;

pair<int, int> dfs(int i, vector<map<int, int>>& treeVec) {
	stack<pair<int, int>> sta;
	vector<bool> isVisit(n, false);
	int max = 0;
	int maxV;

	sta.push({ i,0 });
	isVisit[i] = true;

	while (!sta.empty()) {
		int v = sta.top().first;
		int d = sta.top().second;
		sta.pop();

		if (max < d) {
			maxV = v;
			max = d;
		}

		for (auto vec : treeVec[v]) {
			if (!isVisit[vec.first]) {
				sta.push({ vec.first, vec.second + d });
				isVisit[vec.first] = true;
			}
		}
	}

	return { maxV, max };
}

int main() {
	cin >> n;

	vector<map<int, int>> treeVec(n);

	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;

		while (1) {
			int end;
			cin >> end;
			if (end == -1)
				break;
			
			int d;
			cin >> d;

			treeVec[v - 1].insert({ end - 1, d });
		}
	}

	cout << dfs(dfs(0, treeVec).first, treeVec).second;

}