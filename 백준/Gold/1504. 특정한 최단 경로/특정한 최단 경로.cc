#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

vector<int> findPath(vector<map<int, int>>& road, int start) {
	vector<int> shortCost(road.size(), -1);
	shortCost[start] = 0;

	priority_queue<vector<int>> que;

	que.push({ 0,start,-1 });

	while (!que.empty()) {
		int preV = que.top()[2];
		int d = -que.top()[0];
		int v = que.top()[1];
		que.pop();

		for (auto iter : road[v]) {
			int newD = iter.second + d;
			if (v != preV && shortCost[iter.first] == -1 || newD < shortCost[iter.first]) {
				que.push({ -newD,iter.first,v });
				shortCost[iter.first] = newD;
			}
		}
	}

	return shortCost;
}

int main() {
	int vecNum, roadNum, v1, v2;
	cin >> vecNum >> roadNum;

	vector<map<int, int>> road(vecNum);

	for (int i = 0; i < roadNum; i++) {
		int sv, ev, d;
		cin >> sv >> ev >> d;
		road[sv - 1].insert({ ev - 1,d });
		road[ev - 1].insert({ sv - 1,d });
	}

	cin >> v1 >> v2;
	v1--;
	v2--;

	vector<int> shortCostStart0 = findPath(road, 0);
	vector<int> shortCostStartV1 = findPath(road, v1);
	vector<int> shortCostStartV2 = findPath(road, v2);

	int case1 = shortCostStart0[v1] + shortCostStartV1[v2] + shortCostStartV2[vecNum - 1];
	int case2 = shortCostStart0[v2]  + shortCostStartV2[v1] + shortCostStartV1[vecNum - 1];
	

	if (shortCostStart0[v1] == -1 || shortCostStartV1[v2] == -1 || shortCostStartV2[vecNum - 1] == -1) {
		case1 = -1;
	}
	if (shortCostStart0[v2] == -1 || shortCostStartV2[v1] == -1 || shortCostStartV1[vecNum - 1] == -1) {
		case2 = -1;
	}

	if (case1 == -1 && case2 == -1) {
		cout << -1;
	}
	else {
		cout << min(case1, case2);
	}

	return 0;
}