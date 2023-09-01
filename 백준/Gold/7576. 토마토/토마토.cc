#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int width, height;

	cin >> width >> height;
	
	vector<vector<int>> box(height, vector<int>(width));
	queue<pair<int,int>> tomato;
	int noDoneNum = 0;

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			cin >> box[y][x];
			if (box[y][x] == 0) {
				noDoneNum++;
			}
			else if (box[y][x] == 1)
			{
				tomato.push({ x,y });
			}
		}
	}

	int count = 0;
	while (noDoneNum > 0 && !tomato.empty())
	{
		count++;
		queue<pair<int, int>> temp;

		while (!tomato.empty()) {
			int x = tomato.front().first;
			int y = tomato.front().second;
			tomato.pop();

			if (x > 0 && box[y][x - 1] == 0) {
				box[y][x - 1] = 1;
				temp.push({ x - 1, y });
				noDoneNum--;
			}

			if (x + 1 < width && box[y][x + 1] == 0) {
				box[y][x + 1] = 1;
				temp.push({ x + 1, y });
				noDoneNum--;
			}

			if (y > 0 && box[y - 1][x] == 0) {
				box[y - 1][x] = 1;
				temp.push({ x, y - 1 });
				noDoneNum--;
			}

			if (y + 1 < height && box[y + 1][x] == 0) {
				box[y + 1][x] = 1;
				temp.push({ x, y + 1 });
				noDoneNum--;
			}
		}

		tomato = temp;
	}
	
	if (noDoneNum > 0)
		cout << -1;
	else
		cout << count;

}