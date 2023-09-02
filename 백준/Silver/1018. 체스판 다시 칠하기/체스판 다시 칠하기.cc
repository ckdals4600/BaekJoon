#include <iostream>

using namespace std; 

char b[50][50];
int minChange = 2500;

void countChange(int startX, int startY, char start) {
	int cnt = 0;

	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if ((x + y) % 2 == 0) {
				if (b[startY + y][startX + x] != start) cnt++;
			}
			else {
				if (b[startY + y][startX + x] == start) cnt++;
			}

			if (cnt > minChange) return;
		}
	}

	if (cnt < minChange) minChange = cnt;
}



int main() {

	int y, x;
	cin >> y >> x;

	for (int i = 0; i < y; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < x; j++) {
			b[i][j] = line.at(j);
		}
	}


	for (int i = 0; i < y - 7; i++) {
		for (int j = 0; j < x - 7; j++) {
			countChange(j, i, 'W');
			countChange(j, i, 'B');
		}
	}

	cout << minChange;

	return 0;
}