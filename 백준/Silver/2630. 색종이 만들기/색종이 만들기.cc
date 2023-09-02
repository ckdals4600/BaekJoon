#include <iostream>
#include <vector>

using namespace std;

int whiteNum = 0;
int blueNum = 0;

void cut(int startX, int startY, int size, const vector<vector<int>> &map) {
	int startColor = map[startY][startX];
	bool isDiff = false;

	for (int y = 0; y < size && !isDiff; y++)
		for (int x = 0; x < size && !isDiff; x++) 
			if (startColor != map[startY + y][startX + x]) isDiff = true;


	if (!isDiff) {
		if (startColor == 0) whiteNum++;
		else blueNum++;
	}
	else {
		int newSize = size / 2;
		cut(startX, startY, newSize, map);
		cut(startX + newSize, startY, newSize, map);
		cut(startX, startY + newSize, newSize, map);
		cut(startX + newSize, startY + newSize, newSize, map);
	}
}

int main() {
	int n;

	cin >> n;

	vector<vector<int>> map(n,vector<int>(n));

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
		}
	}

	cut(0, 0, n, map);

	cout << whiteNum << '\n' << blueNum;
}