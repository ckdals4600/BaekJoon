#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cmp {
	bool operator()(vector<int>& a, vector<int>& b){
		if (a[0] == b[0]) {
			if (a[1] == b[1]) {
				return a[2] > b[2];
			}
			return a[1] > b[1];
		}
		return a[0] > b[0];
	}
};

void printMap() {

}

int main() {
	int babySharkX, babySharkY;
	int babySharkSize = 2;
	int duetime = 0;
	int eatFood = 0;
	vector<vector<bool>> isVisit;
	vector<vector<int>> seaMap;
	int remainFood[6] = { 0, };
	

	int moveX[4] = { 0, -1, 1, 0 };
	int moveY[4] = { -1, 0, 0, 1 };

	int mapSize;
	cin >> mapSize;

	seaMap.assign(mapSize, vector<int>(mapSize, 0));
	isVisit.assign(mapSize, vector<bool>(mapSize, false));

	for (int y = 0; y < mapSize; y++) {
		for (int x = 0; x < mapSize; x++) {
			cin >> seaMap[y][x];
			if (seaMap[y][x] == 9) {
				babySharkX = x;
				babySharkY = y;
			}
			else if (seaMap[y][x] > 0) {
				remainFood[seaMap[y][x] - 1]++;
			}

		}
	}

	for (int i = 1; i < 6; i++) {
		remainFood[i] += remainFood[i - 1];
	}

	priority_queue<vector<int>, vector<vector<int>>, cmp> que;
	que.push({ 0, babySharkY ,babySharkX });
	isVisit[babySharkY][babySharkX] = true;

	while (!que.empty()) {
		
		if (babySharkSize < 7 && remainFood[babySharkSize - 2] < 1 || remainFood[5] == 0) {
			break;
		}

		int count = que.top()[0];
		int y = que.top()[1];
		int x = que.top()[2];
		que.pop();

		isVisit[y][x] = true;

		if (seaMap[y][x] > 0 && seaMap[y][x] < babySharkSize) {

			duetime += count;
			eatFood++;

			if (eatFood == babySharkSize) {
				eatFood = 0;
				if (babySharkSize < 7) {
					babySharkSize++;
				}
			}

			for (int i = seaMap[y][x] - 1; i < 6; i++) {
				remainFood[i]--;
			}

			seaMap[y][x] = 9;
			seaMap[babySharkY][babySharkX] = 0;

			babySharkX = x;
			babySharkY = y;

			que = priority_queue<vector<int>, vector<vector<int>>, cmp>();
			que.push({ 0, babySharkY, babySharkX });

			isVisit.assign(mapSize, vector<bool>(mapSize, false));
			isVisit[babySharkY][babySharkX] = true;

			continue;
		}

		for (int m = 0; m < 4; m++) {
			int newX = x + moveX[m];
			int newY = y + moveY[m];

			if (newX < 0 || newX >= mapSize || newY < 0 || newY >= mapSize) {
				continue;
			}

			if (seaMap[newY][newX] > babySharkSize || isVisit[newY][newX]) {
				continue;
			}

			que.push({  count + 1 ,newY, newX });
			isVisit[newY][newX] = true;
		}
	}

	cout << duetime;
}