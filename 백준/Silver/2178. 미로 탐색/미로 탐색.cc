#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>

using namespace std;

bool findRoute(queue<pair<int, int>>&, vector<pair<int, int>>&, const vector<vector<int>>&);
bool visited(pair<int, int>, vector<pair<int, int>>&);
void rightRoute(const vector<vector<int>>&, pair<int, int>, queue<pair<int, int>>&);

int rowSize, colSize;

int main() {
	
	string line;

	cin >> rowSize >> colSize;
	
	vector<vector<int>> map(rowSize, vector<int>(colSize,0));
	queue<pair<int,int>> que;
	vector<pair<int, int>> visit;
	int count = 1;

	for (int i = 0; i < rowSize; i++) {
		cin >> line;
		for (int j = 0; j < colSize; j++) {
			map[i][j] = line[j] - '0';
		}
	}

	que.push(make_pair(0, 0));

	while (!findRoute(que, visit, map)) {
		count++;
	}

	cout << count;
	
}

bool findRoute(queue<pair<int,int>>& que, 
	vector<pair<int, int>>& visit, 
	const vector<vector<int>>& map) {

	queue<pair<int, int>> temp;
	pair<int, int> xy;

	
	while (!que.empty()) {
		xy = que.front();
		que.pop();

		int x = xy.first;
		int y = xy.second;
		
		if (y == rowSize - 1 && x == colSize - 1)
			return true;

		if (!visited(xy, visit)) {
			rightRoute(map, make_pair(x + 1, y), temp);
			rightRoute(map, make_pair(x - 1, y), temp);
			rightRoute(map, make_pair(x, y + 1), temp);
			rightRoute(map, make_pair(x, y - 1), temp);
			visit.push_back(xy);
		}
	}

	que = temp;
	return false;
}

void rightRoute(const vector<vector<int>>& map, 
	pair<int, int> xy,
	queue<pair<int, int>>& que) {
	int x = xy.first;
	int y = xy.second;

	if (x > -1 && x < colSize
		&& y > -1 && y < rowSize
		&& map[y][x] == 1) {
		que.push(xy);
	}
}

bool visited(pair<int, int> xy, vector<pair<int, int>>& visit) {
	return (find(visit.begin(), visit.end(), xy) != visit.end());
}