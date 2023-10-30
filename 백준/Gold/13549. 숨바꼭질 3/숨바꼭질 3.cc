#include <iostream>
#include <vector>
#include <deque>
#define LONG_MAX 2147483647L

using namespace std;

int main() {
	int s, e;
	cin >> s >> e;

	deque<long> que;
	vector<long> checkTime(200001, LONG_MAX);
	int move[2] = {-1,1};

	que.push_front(s);
	checkTime[s] = 0;

	while (que.size()) {
		long n = que.front();
		que.pop_front();

		if (n == e)
			break;

		if (n * 2 < 200001 && checkTime[n * 2] > checkTime[n]) {
			checkTime[n * 2] = checkTime[n];
			que.push_front(n * 2);
		}

		for (int i = 0; i < 2; i++) {
			int newN = n + move[i];

			if (newN > 200000 || newN < 0 || checkTime[newN] < checkTime[n] + 1) {
				continue;
			}
			
			checkTime[newN] = checkTime[n] + 1;
			que.push_back(newN);
			
		}


		
	}

	cout << checkTime[e];
	return 0;
}