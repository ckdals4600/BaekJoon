#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int n;

	cin >> n;

	vector<vector<int>> map(n, vector<int>(n));
	set<pair<int, int>> house;
	vector<vector<bool>> isVisit(n, vector<bool>(n, false));
	queue<pair<int, int>> findComplex;
	vector<int> houseCountInComplex;

	for (int y = 0; y < n; y++) {
		string houserArray;
		cin >> houserArray;
		int x = 0;

		for (char c : houserArray) {
			map[y][x] = c - '0';
			if (c == '1') {
				house.insert({ y,x });
			}
			x++;
		}
	}

	int complexConut = 0;

	while (!house.empty()) {
		findComplex.push(*house.begin());
		isVisit[(*house.begin()).first][(*house.begin()).second] = true;
		house.erase(*house.begin());
		houseCountInComplex.push_back(1);

		while (!findComplex.empty()) {
			int x = findComplex.front().second;
			int y = findComplex.front().first;
			findComplex.pop();

			if (x + 1 < n && map[y][x + 1] == 1 && !isVisit[y][x + 1]) {
				findComplex.push({ y,x + 1 });
				isVisit[y][x + 1] = true;
				house.erase({ y, x + 1 });
				houseCountInComplex[complexConut]++;
			}

			if (y + 1 < n && map[y + 1][x] == 1 && !isVisit[y + 1][x]) {
				findComplex.push({ y + 1,x });
				isVisit[y + 1][x] = true;
				house.erase({ y + 1, x });
				houseCountInComplex[complexConut]++;
			}

			if (x > 0 && map[y][x - 1] == 1 && !isVisit[y][x - 1]) {
				findComplex.push({ y,x - 1 });
				isVisit[y][x - 1] = true;
				house.erase({ y, x - 1 });
				houseCountInComplex[complexConut]++;
			}

			if (y > 0 && map[y - 1][x] == 1 && !isVisit[y - 1][x]) {
				findComplex.push({ y - 1,x });
				isVisit[y - 1][x] = true;
				house.erase({ y - 1, x });
				houseCountInComplex[complexConut]++;
			}
		}

		complexConut++;
	}

	sort(houseCountInComplex.begin(), houseCountInComplex.end());

	cout << complexConut << endl;
	for (int n : houseCountInComplex) {
		cout << n << endl;
	}
}