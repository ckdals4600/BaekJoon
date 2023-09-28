#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int row, col;
	cin >> row >> col;

	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };

	vector<vector<int>> maps(row,vector<int>(col));
	vector<vector<vector<int>>> isVisit(2, vector<vector<int>>(row, vector<int>(col, 0)));
	queue<vector<int>> que; //x,y,횟수,벽 깨부순 횟수;;
	int result = -1;

	for (int y = 0; y < row; y++) {
		string line;
		cin >> line;
		for (int x = 0; x < col; x++) {
			maps[y][x] = line[x] - '0';
		}
	}

	isVisit[0][0][0] = 1;
	isVisit[1][0][0] = 1;
	que.push({ 0,0,0 });

	while (!que.empty()) {
		int x = que.front()[0];
		int y = que.front()[1];
		int isBoroke = que.front()[2];
		int d = isVisit[isBoroke][y][x];
		que.pop();

		if (x == col - 1 && y == row - 1) {
			result = d;
			break;
		}

		
		for (int i = 0; i < 4; i++) {
			int newX = x + dx[i];
			int newY = y + dy[i];
			
			if (newX < 0 || newX >= col || newY < 0 || newY >= row) continue;
			if (maps[newY][newX] == 0 && isVisit[isBoroke][newY][newX] == 0) {
				que.push({ newX,newY,isBoroke });
				isVisit[isBoroke][newY][newX] = d + 1;
			}
			else if (maps[newY][newX] == 1 && isBoroke == 0 && isVisit[1][newY][newX] == 0) {
				que.push({ newX,newY,1 });
				isVisit[1][newY][newX] = d + 1;
			}
		}
	}

	cout << result;

	return 0;
}