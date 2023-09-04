#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, m;

	cin >> n >> m;

	int conInfo = 0;
	vector<vector<int>> graph(n + 1);
	queue<int> que;
	vector<bool> isVisit(n + 1, false);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	if (m >= n * (n - 1) / 2) {
		cout << 1;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (!isVisit[i]) {
				conInfo++;
				que.push(i);
				isVisit[i] = true;
				while (!que.empty()) {
					int node = que.front();
					que.pop();

					for (int nextNode : graph[node]) {
						if (!isVisit[nextNode]) {
							que.push(nextNode);
							isVisit[nextNode] = true;
						}
					}
				}
			}
		}

		cout << conInfo;
	}
	
}