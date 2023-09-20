#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int cityNum, busNum;
	int startCity, endCity;

	cin >> cityNum >> busNum;

	vector<multimap<int, long long>> busInfo(cityNum + 1);
	priority_queue<pair<long long, int>> que;
	vector<long long> shortPath(cityNum + 1, -1);

	for (int i = 0; i < busNum; i++) {
		int s, e;
		long long d;
		cin >> s >> e >> d;

		busInfo[s].insert({ e,d });
	}

	cin >> startCity >> endCity;

	que.push({ 0,startCity });
	shortPath[startCity] = 0;
	
	while (!que.empty()) {
		int v = que.top().second;
		long long d = -que.top().first;
		que.pop();

		if (d > shortPath[v]) continue;

		for (auto iter : busInfo[v]) {
			int nextV = iter.first;
			long long nextD = iter.second + d;

			if (shortPath[nextV] == -1 || nextD < shortPath[nextV]) {
				shortPath[nextV] = nextD;
				que.push({ -nextD, nextV });
			}
		}
	}

	cout << shortPath[endCity];
	return 0;
}