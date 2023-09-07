#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main() {
	int totalX, totalY, totalZ;

	cin >> totalX >> totalY >> totalZ;

	vector<vector<vector<int>>> tomatoBox(totalZ, vector<vector<int>>(totalY, vector<int>(totalX)));
	set<vector<int>> isOK;
	int isNoNum = 0;
	int onGoingDate = 0;

	for (int z = 0; z < totalZ; z++) {
		for (int y = 0; y < totalY; y++) {
			for (int x = 0; x < totalX; x++) {
				cin >> tomatoBox[z][y][x];

				if (tomatoBox[z][y][x] == 1) {
					isOK.insert({ x,y,z });
				}
				else if (tomatoBox[z][y][x] == 0) {
					isNoNum++;
				}
			}
		}
	}

	while (!isOK.empty() && isNoNum > 0) {
		set<vector<int>> isOKTemp = isOK;
		isOK.clear();
		onGoingDate++;

		while (!isOKTemp.empty() && isNoNum > 0) {

			int x = (*isOKTemp.begin())[0];
			int y = (*isOKTemp.begin())[1];
			int z = (*isOKTemp.begin())[2];
			isOKTemp.erase({ x,y,z });

			if (x + 1 < totalX && tomatoBox[z][y][x + 1] == 0) {
				tomatoBox[z][y][x + 1] = 1;
				isNoNum--;
				isOK.insert({ x + 1,y,z });
			}

			if (x > 0 && tomatoBox[z][y][x - 1] == 0) {
				tomatoBox[z][y][x - 1] = 1;
				isNoNum--;
				isOK.insert({ x - 1,y,z });
			}

			if (y + 1 < totalY && tomatoBox[z][y + 1][x] == 0) {
				tomatoBox[z][y + 1][x] = 1;
				isNoNum--;
				isOK.insert({ x,y + 1,z });
			}

			if (y > 0 && tomatoBox[z][y - 1][x] == 0) {
				tomatoBox[z][y - 1][x] = 1;
				isNoNum--;
				isOK.insert({ x,y - 1,z });
			}

			if (z + 1 < totalZ && tomatoBox[z + 1][y][x] == 0) {
				tomatoBox[z + 1][y][x] = 1;
				isNoNum--;
				isOK.insert({ x,y,z + 1 });
			}

			if (z > 0 && tomatoBox[z - 1][y][x] == 0) {
				tomatoBox[z - 1][y][x] = 1;
				isNoNum--;
				isOK.insert({ x,y,z - 1 });
			}

		}

	}

	if (isNoNum > 0) {
		cout << -1;
	}
	else {
		cout << onGoingDate;
	}
	
}