#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main() {
	int n;

	cin >> n;

	int maxTime = 0;
	priority_queue<pair<int,int>> durations;

	for(int i = 0; i < n; i++) {
		int start, end;

		cin >> start >> end;
		durations.push({ -end , start});

		if (end > maxTime) maxTime = end;
	}

	int count = 1;
	int end = -durations.top().first;
	int start = durations.top().second;
	durations.pop();


	while (!durations.empty()) {
		pair<int, int> time = durations.top();

		int cStart = durations.top().second;
		int cEnd = -durations.top().first;
		durations.pop();


		if (end <= cStart || start >= cEnd) {
			count++;
			end = cEnd;
			start = cStart;
		}
	}

	cout << count;
	return 0;
}
