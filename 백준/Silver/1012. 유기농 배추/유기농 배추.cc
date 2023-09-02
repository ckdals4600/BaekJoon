#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main() {
	int t;
	cin >> t;

	vector<int> result;

	while (t--) {
		int height, width, k;

		cin >> width >> height >> k;
		set<pair<int, int>> isExist;
		int groupNum = 0;

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			isExist.insert({x,y});
		}

		while (!isExist.empty()) {
			int beignX = (*isExist.begin()).first;
			int beginY = (*isExist.begin()).second;
			groupNum++;

			queue<pair<int, int>> findGroup;

			findGroup.push({ beignX,beginY });
			isExist.erase({ beignX,beginY });

			while (!findGroup.empty()) {
				int x = findGroup.front().first;
				int y = findGroup.front().second;
				findGroup.pop();

				if (x + 1 < width && isExist.find({ x + 1,y }) != isExist.end()) {
					findGroup.push({ x + 1,y });
					isExist.erase({ x + 1,y });
				}

				if (x > 0 && isExist.find({ x - 1,y }) != isExist.end()) {
					findGroup.push({ x - 1,y });
					isExist.erase({ x - 1,y });
				}

				if (y + 1 < height && isExist.find({ x,y + 1 }) != isExist.end()) {
					findGroup.push({ x,y + 1 });
					isExist.erase({ x,y + 1 });
				}

				if (y > 0 && isExist.find({ x,y - 1 }) != isExist.end()) {
					findGroup.push({ x ,y - 1 });
					isExist.erase({ x,y - 1 });
				}

			}
			
		}

		result.push_back(groupNum);
	}


	for (int num : result)
		cout << num << endl;
}