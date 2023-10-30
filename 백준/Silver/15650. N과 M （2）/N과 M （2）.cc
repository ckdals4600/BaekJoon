#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n,m;
	cin >> n >> m;

	queue<deque<int>> que;

	for (int i = 1; i <= n; i++) {
		que.push({ i });
	}

	while (!que.empty()) {
		deque<int> deq = que.front();
		que.pop();

		if (deq.size() == m) {
			for (int i : deq) cout << i << " ";
			cout << "\n";
			continue;
		}

		for (int i = deq.back() + 1; i <= n; i++) {
			deq.push_back(i);
			que.push(deq);
			deq.pop_back();
		}		
	}

	

	return 0;
}