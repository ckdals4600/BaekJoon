#include <iostream>
#include <vector>

using namespace std;

int main() {
	int totalX, totalY;
	cin >> totalY >> totalX;

	vector<vector<int>> map(totalY,vector<int>(totalX));

	for (int y = 0; y < totalY; y++) {
		for (int x = 0; x < totalX; x++) {
			cin >> map[y][x];
		}
	}

	int max = 0;
	for (int y = 0; y < totalY; y++) {
		for (int x = 0; x < totalX; x++) {
			if (x + 3 < totalX) {
				if(max < map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y][x + 3]) max = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y][x + 3];
			}

			if (y + 3 < totalY) {
				if (max < map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 3][x]) max = map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 3][x];
			}

			if (x + 1 < totalX && y + 1 < totalY) {
				if (max < map[y][x] + map[y][x + 1] + map[y + 1][x] + map[y + 1][x + 1]) max = map[y][x] + map[y][x + 1] + map[y + 1][x] + map[y + 1][x + 1];
			}

			if (y + 2 < totalY && x + 1 < totalX) {
				if (max < map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 2][x + 1]) max = map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 2][x + 1];
				if (max < map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y][x + 1])max = map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y][x + 1];
			}

			if (y + 2 < totalY && x > 0) {
				if (max < map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y][x - 1])max = map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y][x - 1];
				if (max < map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 2][x - 1])max = map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 2][x - 1];
			}
			if (x + 2 < totalX && y + 1 < totalY) {
				if (max < map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x])max = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x];
				if (max < map[y][x] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 1][x + 2])max = map[y][x] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 1][x + 2];
				if (max < map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x + 2])max = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x + 2];
			}
			if (x + 2 < totalX && y > 0) {
				if (max < map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y - 1][x + 2])max = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y - 1][x + 2];
			}

			if (y + 2 < totalY && x + 1 < totalX) {
				if (max < map[y][x] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 2][x + 1])max = map[y][x] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 2][x + 1];
			}
			if (y + 2 < totalY && x > 0){
				if (max < map[y][x] + map[y + 1][x] + map[y + 1][x - 1] + map[y + 2][x - 1])max = map[y][x] + map[y + 1][x] + map[y + 1][x - 1] + map[y + 2][x - 1];
			}
			if (x + 2 < totalX && y > 0) {
				if (max < map[y][x] + map[y][x + 1] + map[y - 1][x + 1] + map[y - 1][x + 2])max = map[y][x] + map[y][x + 1] + map[y - 1][x + 1] + map[y - 1][x + 2];
			}
			if (x + 2 < totalX && y + 1 < totalY) {
				if (max < map[y][x] + map[y][x + 1] + map[y + 1][x + 1] + map[y + 1][x + 2])max = map[y][x] + map[y][x + 1] + map[y + 1][x + 1] + map[y + 1][x + 2];
				;
			}

			if (x + 2 < totalX && y + 1 < totalY) {\
				if (max < map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x + 1])max = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x + 1];
			}
			if (x + 2 < totalX && y > 0) {
				if (max < map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y - 1][x + 1])max = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y - 1][x + 1];
			}
			if (y + 2 < totalY && x + 1 < totalX) {
				if (max < map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 1][x + 1])max = map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 1][x + 1];
			}
			if (y + 2 < totalY && x > 0) {
				if (max < map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 1][x - 1])max = map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 1][x - 1];
			}
		}
	}

	cout << max;
}