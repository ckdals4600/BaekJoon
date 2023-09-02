#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	queue<pair<int, int>> move;
	vector<bool> map(100001,true);

	move.push({ n,0 });
	map[n] = 0;

	int min = (n > k) ? n - k : k - n;
	int result = 0;
	while (!move.empty()) {
		int current = move.front().first;
		int count = move.front().second + 1;
		move.pop();

		if (current == k) {
			result = count - 1;
			break;
		}

		if (count <= min) {
			if (current * 2 < 100001) {
				if (map[current * 2]) {
					move.push({ current * 2 , count });
					map[current * 2] = false;
				}
			}

			if (current -1 > -1) {
				if (map[current - 1]) {
					move.push({ current - 1 , count });
					map[current - 1] = false;
				}
			}

			if (current + 1 < 100001) {
				if (map[current + 1]) {
					move.push({ current + 1 , count });
					map[current + 1] = false;
				}
			}

			
		}
	}

	cout << result;
}