#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>


using namespace std;

int main() {
	int studentNum, roadNum, party;
	cin >> studentNum >> roadNum >> party;
	party--;

	vector<map<int, int>> roadInfo(studentNum);
	vector<map<int, int>> roadInfoReverse(studentNum);

	for (int i = 0; i < roadNum; i++) {
		int s, e, d;
		cin >> s >> e >> d;

		roadInfo[s - 1].insert({ e - 1,d });
		roadInfoReverse[e - 1].insert({ s - 1,d });
	}


	priority_queue<pair<int, int>> que;
	vector<int> shortPath(studentNum, -1);
	vector<int> shortPathReverse(studentNum, -1);

	que.push({ 0, party });
	shortPath[party] = 0;


	while (!que.empty()) {
		int d = -que.top().first;
		int v = que.top().second;
		que.pop();

		for (auto i : roadInfo[v]) {
			if (shortPath[i.first] == -1 || shortPath[i.first] > d + i.second) {
				shortPath[i.first] = d + i.second;
				que.push({ -(d + i.second), i.first });
			}
		}

	}

	que = {};

	que.push({ 0, party });
	shortPathReverse[party] = 0;

	while (!que.empty()) {
		int d = -que.top().first;
		int v = que.top().second;
		que.pop();

		for (auto i : roadInfoReverse[v]) {
			if (shortPathReverse[i.first] == -1 || shortPathReverse[i.first] > d + i.second) {
				shortPathReverse[i.first] = d + i.second;
				que.push({ -(d + i.second), i.first });
			}
		}

	}
	int maxNum = shortPath[party] + shortPathReverse[party];
	for (int i = 1; i < studentNum; i++) {
		maxNum = max(maxNum, shortPath[i] + shortPathReverse[i]);
	}

	cout << maxNum;

	return 0;
}