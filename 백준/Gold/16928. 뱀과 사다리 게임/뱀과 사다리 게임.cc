#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main() {
	int laderCount, snakeCount;
	map<int, int> lader;
	map<int, int> snake;

	cin >> laderCount >> snakeCount;

	while (laderCount--) {
		int key, value;

		cin >> key >> value;

		lader[key] = value;
	}

	while (snakeCount--) {
		int key, value;

		cin >> key >> value;

		snake[key] = value;
	}

	queue<pair<int, int>> boardSpace;
	int spaceMinCount[101] = { -1, };
	int spaceBefore[101] = { -1, };

	boardSpace.push({ 1,0 });
	spaceMinCount[1] = 0;

	while (!boardSpace.empty()) {
		int space = boardSpace.front().first;
		int count = boardSpace.front().second;
		boardSpace.pop();
		
		if (space == 100) {
			break;
		}

		count++;

		for (int i = 1; i <= 6; i++) {
			int move = space + i;

			if (move < 101) {

				if (lader.find(move) != lader.end()) {
					move = lader[move];
				}
				else if (snake.find(move) != snake.end()) {
					move = snake[move];
				}

				if (spaceMinCount[move] == 0 || spaceMinCount[move] > count) {
					spaceMinCount[move] = count;
					boardSpace.push({ move,count });
				}
			}
		}
	}

	cout << spaceMinCount[100];
}