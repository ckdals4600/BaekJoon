#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n;

	cin >> n;

	priority_queue<int> waits;

	for(int i = 0; i < n; i++) {
		int time;
		cin >> time;

		waits.push(-time);
	}

	int totalTime = 0;
	while (n > 0) {
		totalTime += -waits.top() * n--;
		waits.pop();
	}

	cout << totalTime;
}