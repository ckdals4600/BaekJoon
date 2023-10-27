#include <iostream>
#include <vector>
#include <queue>
#define ULONG_MAX 0xFFFFFFFFUL

using namespace std;

struct cmp {
	bool operator()(pair<unsigned long, int>& a, pair<unsigned long, int>& b) {
		return a.first > b.first;
	}
};

int main() {
	vector<int> result;
	int cityN, busN;
	int start, end;
	vector<vector<unsigned long>> citys;
	vector<unsigned long> findMinCost;
	vector<int> findRoute;


	cin >> cityN >> busN;

	citys.assign(cityN, vector<unsigned long>(cityN, ULONG_MAX));
	findMinCost.assign(cityN, ULONG_MAX);
	findRoute.assign(cityN, -1);

	for (int i = 0; i < busN; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		if (citys[s - 1][e - 1] == ULONG_MAX || citys[s - 1][e - 1] > t) {
			citys[s - 1][e - 1] = t;
		}
	}

	cin >> start >> end;
	start--;
	end--;
	
	priority_queue<pair<unsigned long, int>, vector<pair<unsigned long, int>> , cmp> que;
	findMinCost[start] = 0;
	que.push({ 0L , start });

	while (!que.empty()) {
		unsigned long c = que.top().first;
		int n = que.top().second;
		que.pop();

		for (int i = 0; i < cityN; i++) {
			if (citys[n][i] != ULONG_MAX && c + citys[n][i] < findMinCost[i]) {
				findMinCost[i] = c + citys[n][i];
				findRoute[i] = n;
				que.push({ findMinCost[i] ,i });
			}
		}
	}

	int rN = 0;
	result.push_back(end);

	while (result[rN] != start) {
		result.push_back(findRoute[result[rN++]]);
	}

	cout << findMinCost[end] << '\n';
	cout << ++rN << '\n';

	for (int i = result.size() - 1; i > -1; i--) {
		cout << result[i] + 1 << " ";
	}

	return 0;
}