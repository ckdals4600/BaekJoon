#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

int row, col;
vector<string> maps(row);
int maxAlpha = 0;
int maxNum = 0;
vector<bool> duplicate;

void DFS(int x, int y, int m) {
	if (m > maxNum) {
		maxNum = m;
	}

	if (maxNum != maxAlpha && x > 0 && !duplicate[maps[y][x - 1] - 'A']) {
		duplicate[maps[y][x - 1] - 'A'] = true;
		DFS(x - 1, y, m + 1);
		duplicate[maps[y][x - 1] - 'A'] = false;

	}

	if (maxNum != maxAlpha && x + 1 < col && !duplicate[maps[y][x + 1] - 'A']) {
		duplicate[maps[y][x + 1] - 'A'] = true;
		DFS( x + 1, y, m + 1);
		duplicate[maps[y][x + 1] - 'A'] = false;
	}
	
	if (maxNum != maxAlpha && y > 0 && !duplicate[maps[y - 1][x] - 'A']) {
		duplicate[maps[y - 1][x] - 'A'] = true;
		DFS(x, y - 1, m + 1);
		duplicate[maps[y - 1][x] - 'A'] = false;
	}

	if (maxNum != maxAlpha && y + 1 < row && !duplicate[maps[y + 1][x] - 'A']) {
		duplicate[maps[y + 1][x] - 'A'] = true;
		DFS(x, y + 1, m + 1);
		duplicate[maps[y + 1][x] - 'A'] = false;

	}
}

int main() {
	cin >> row >> col;

	maps.resize(row);
	stack<pair<vector<int>, vector<bool>>> que;
	vector<bool> dup(26, true);
	

	for (int y = 0; y < row; y++) {
		cin >> maps[y];
	}

	for (int y = 0; y < row; y++) {
		for (int x = 0; x < col; x++) {
			if (dup[maps[y][x] - 'A']) {
				maxAlpha++;
				dup[maps[y][x] - 'A'] = false;
			}
		}
	}

	dup[maps[0][0] - 'A'] = true;

	duplicate = dup;
	DFS(0,0,1);

	cout << maxNum;

	return 0;
}