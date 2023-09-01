#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	priority_queue<int> heap;
	vector<int> result;

	while (n--) {
		int num;
		cin >> num;
		if (num == 0) {
			if (heap.empty()) {
				result.push_back(0);
			}
			else {
				result.push_back(heap.top());
				heap.pop();
			}
		}
		else {
			heap.push(-num);
		}
	}

	for (int num : result) {
		cout << -num << '\n';
	}

}