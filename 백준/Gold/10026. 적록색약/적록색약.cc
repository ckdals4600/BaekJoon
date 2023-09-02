#include <iostream>
#include <vector>

using namespace std;

int n;

int noGroup;
vector<vector<char>> colorMap;
vector<vector<int>> groupMap;


void findG(int x, int y, char color) {
	groupMap[y][x] = 1;
	noGroup--;

	if (x > 0 && colorMap[y][x - 1] == color && groupMap[y][x - 1] == -1) {
		findG(x - 1, y, color);
	}

	if (x < n - 1 && colorMap[y][x + 1] == color && groupMap[y][x + 1] == -1) {
		findG(x + 1, y, color);
	}


	if (y > 0 && colorMap[y - 1][x] == color && groupMap[y - 1][x] == -1) {
		findG(x, y - 1, color);
	}

	if (y < n - 1 && colorMap[y + 1][x] == color && groupMap[y + 1][x] == -1) {
		findG(x, y + 1, color);
	}
}

pair<int, int> findNoXy() {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (groupMap[y][x] == -1)
				return { x,y };
		}
	}
}

int findColorGroup() {
	noGroup = n * n;
	groupMap = vector<vector<int>>(n, vector<int>(n, -1));
	int groupCount = 0;

	while (noGroup > 0) {
		groupCount++;
		pair<int, int> xy = findNoXy();
		findG(xy.first, xy.second,colorMap[xy.second][xy.first]);
	}

	return groupCount;
}

int main() {
	cin >> n;	

	vector<vector<char>> colorMapNoRG = vector<vector<char>>(n);
	colorMap = vector<vector<char>>(n);
	
	for (int i = 0; i < n; i++) {
		string color;
		cin >> color;
		
		for (auto c : color) {
			colorMap[i].push_back(c);
			if (c == 'G')
				colorMapNoRG[i].push_back('R');
			else
				colorMapNoRG[i].push_back(c);
		}
	}

	cout << findColorGroup() << ' ';

	colorMap = colorMapNoRG;

	cout << findColorGroup() << '\n';

}