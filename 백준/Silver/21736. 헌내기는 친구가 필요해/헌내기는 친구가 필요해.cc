#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int totalY, totalX;
	cin >> totalY >> totalX;

	int meet = 0;
	int startX, startY;
	vector<vector<char>> campus(totalY, vector<char>(totalX));
	queue<pair<int, int>> que;
	vector<vector<bool>> isVisit(totalY, vector<bool>(totalX, false));

	for (int y = 0; y < totalY; y++) {
		for (int x = 0; x < totalX; x++) {
			cin >> campus[y][x];

			if (campus[y][x] == 'I') {
				startX = x;
				startY = y;
			}
		}
	}

	que.push({ startX, startY });
	isVisit[startY][startX] = true;

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		if(x + 1 < totalX && campus[y][x + 1] != 'X' && !isVisit[y][x + 1]) {
			que.push({ x+1 ,y });
			isVisit[y][x + 1] = true;

			if (campus[y][x + 1] == 'P')
				meet++;
		}
		if (y + 1 < totalY && campus[y + 1][x] != 'X' && !isVisit[y + 1][x]) {
			que.push({ x ,y + 1 });
			isVisit[y + 1][x] = true;

			if (campus[y + 1][x] == 'P')
				meet++;
		}

		if (x > 0 && campus[y][x - 1] != 'X' && !isVisit[y][x - 1]) {
			que.push({ x - 1 ,y });
			isVisit[y][x - 1] = true;

			if (campus[y][x - 1] == 'P')
				meet++;
		}

		if (y > 0 && campus[y - 1][x] != 'X' && !isVisit[y - 1][x]) {
			que.push({ x ,y - 1 });
			isVisit[y - 1][x] = true;

			if (campus[y - 1][x] == 'P')
				meet++;
		}
	}

	if (meet == 0) {
		cout << "TT";
	}
	else {
		cout << meet;
	}
}