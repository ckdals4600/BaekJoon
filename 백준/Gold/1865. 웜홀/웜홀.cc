#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main() {
	int testCase, nodeNum, roadNum, holeNum;
	cin >> testCase;
	
	vector<string> result;

	while (testCase--) {
		cin >> nodeNum >> roadNum >> holeNum;

		vector<vector<int>> mapInfo;
		vector<int> shortPath(nodeNum, INT16_MAX);
		shortPath[0] = 0;

		for (int i = 0; i < roadNum; i++) {
			int sn, en, t;
			cin >> sn >> en >> t;
			sn--, en--;
			mapInfo.push_back({ sn, en ,t });
			mapInfo.push_back({ en, sn ,t });
		}

		for (int i = 0; i < holeNum; i++) {
			int sn, en, t;
			cin >> sn >> en >> t;
			sn--, en--;
			mapInfo.push_back({ sn, en ,-t });
		}

		
		bool isYes = false;
		for (int v = 0; v < nodeNum; v++) {
			for (auto iter : mapInfo) {
				int sn = iter[0];
				int en = iter[1];
				int d = iter[2];

				if (shortPath[sn] + d < shortPath[en]) {
					if (v != nodeNum - 1) {
						shortPath[en] = shortPath[sn] + d;
					}
					else {
						isYes = true;
					}
				}
			}
		}

		if (isYes) {
			result.push_back("YES\n");
		}
		else {
			result.push_back("NO\n");
		}
	}

	for (auto r : result) {
		cout << r;
	}

	return 0;
}