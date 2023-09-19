#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main() {
	int vNum, rNum, start;
	cin >> vNum >> rNum >> start;
	start--;

	vector<multimap<int,int>> road(vNum);

	while (rNum--) {
		int sv, ev, d;
		cin >> sv >> ev >> d;
		sv--, ev--;
		road[sv].insert({ ev, d });
	}

	priority_queue<pair<int,int>> que;
	vector<int> shortPath(vNum, -1);
	
	que.push({ 0,start });
	shortPath[start] = 0;

	while (!que.empty()) {
		int v = que.top().second;
		int d = -que.top().first;
		que.pop();

		for (auto i : road[v]) {
			int newD = i.second + d;
			int newV = i.first;

			if (shortPath[newV] == -1 || newD < shortPath[newV]) {
				shortPath[newV] = newD;
				que.push({ -newD, newV });
			}
		}
	}

	for (int i : shortPath) {
		if (i == -1) {
			cout << "INF\n";
		}else{
			cout << i << '\n';
		}
	}
}