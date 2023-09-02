#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	cin.tie(nullptr); 
	ios_base::sync_with_stdio(false);

	int height, width;
	cin >> height >> width;

	vector<vector<int>> map(height, vector<int>(width));
	vector<vector<int>> distances(height, vector<int>(width,-1));
	int startX, startY;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				startX = j;
				startY = i;
				distances[i][j] = 0;
			}
			else if (map[i][j] == 0) {
				distances[i][j] = 0;
			}
		}
	}

	queue<vector<int>> countDistance;
	countDistance.push({ startX,startY,0 });

	while (!countDistance.empty()) {
		int x = countDistance.front()[0];
		int y = countDistance.front()[1];
		int count = countDistance.front()[2] + 1;
		countDistance.pop();

		if (x + 1 < width) {
			if (distances[y][x + 1] != 0 && distances[y][x + 1] == -1 || distances[y][x + 1] > count) {
				distances[y][x + 1] = count;
				countDistance.push({ x + 1, y, count });
			}
		}

		if (y + 1 < height) {
			if (distances[y + 1][x] != 0 && distances[y + 1][x] == -1 || distances[y + 1][x] > count) {
				distances[y + 1][x] = count;
				countDistance.push({ x, y + 1, count });
			}
		}

		if (x > 0) {
			if (distances[y][x - 1] != 0 && distances[y][x - 1] == -1 || distances[y][x - 1] > count) {
				distances[y][x - 1] = count;
				countDistance.push({ x - 1, y, count });
			}
		}

		if (y > 0) {
			if (distances[y - 1][x] != 0 && distances[y - 1][x] == -1 || distances[y - 1][x] > count) {
				distances[y - 1][x] = count;
				countDistance.push({ x, y - 1, count });
			}
		}
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << distances[i][j] << ' ';
		}
		cout << '\n';
	}



	return 0;
}