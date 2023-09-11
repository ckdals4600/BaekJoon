#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n;

	cin >> n;

	vector<vector<int>> map(n);
	vector<vector<int>> isRoute;

	for (int i = 0; i < n * n; i++) {
		int isOk;
		cin >> isOk;
		if(isOk == 1) map[i / n].push_back(i%n);
	}

	for (int i = 0; i < n; i++) {
		queue<int> findRoute;
		vector<int> isVisit(n,0);

		findRoute.push(i);

		while (!findRoute.empty())
		{
			int v = findRoute.front();
			findRoute.pop();

			for (int j : map[v]) {
				if (isVisit[j] == 0) {
					findRoute.push(j);
					isVisit[j] = 1;
				}
			}
		}

		isRoute.push_back(isVisit);
	}


	for (int i = 0; i < n * n; i++) {
		cout << isRoute[i / n][i % n] << " ";
		if (i % n == n - 1) cout << '\n';
	}

	return 0;
}