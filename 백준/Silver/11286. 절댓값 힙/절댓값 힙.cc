#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	priority_queue<pair<int,int>> maxHeap;
	vector<int> result;
	int n;
	cin >> n;

	while (n--) {
		int i;
		cin >> i;

		if (i == 0) {
			if (maxHeap.empty()) {
				result.push_back(0);
			}
			else {
				result.push_back(maxHeap.top().first * maxHeap.top().second);
				maxHeap.pop();
			}
		}else{
			if (i < 0) {
				maxHeap.push({ i, 1 });
			}
			else {
				maxHeap.push({ -i, -1 });
			}
		}
	}

	for (int i : result) cout << i << '\n';

	return 0;
}