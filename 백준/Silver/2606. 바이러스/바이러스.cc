#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int comNum;
	int conNum;

	cin >> comNum >> conNum;

	vector<vector<int>> cons(comNum + 1);
	vector<bool> isInfected(comNum,false);
	queue<int> infection;
	int infectionCount = 0;

	if (comNum * (conNum - 1) / 2 <= conNum) {
		cout << comNum - 1;
	}
	else {
		while (conNum--) {
			int con1, con2;
			cin >> con1 >> con2;

			cons[con1].push_back(con2);
			cons[con2].push_back(con1);
		}

		infection.push(1);
		isInfected[1] = true;

		while (!infection.empty()) {
			int cur = infection.front();
			infection.pop();

			for (int com : cons[cur]) {
				if (!isInfected[com]) {
					infection.push(com);
					infectionCount++;
					isInfected[com] = true;
				}
			}
		}

		cout << infectionCount;
	}
	
}