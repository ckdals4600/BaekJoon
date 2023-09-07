#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	vector<int> treeHeights;

	cin >> n >> m;

	for(int i = 1; i <= n; i++) {
		int treeHeight;
		cin >> treeHeight;
		treeHeights.push_back(treeHeight);
	}

	sort(treeHeights.rbegin(), treeHeights.rend());

	int max = treeHeights[0];
	int min = 0;
	int mid = (min + max) / 2;

	long long branch = 0;

	while (min <= max) {
		branch = 0;

		for (int i : treeHeights) {
			if (i <= mid)
				break;
			branch += i - mid;
		}

		if (branch == m) {
			break;
		}
		else if (branch < m) {
			max = mid - 1;
		}
		else
		{
			min = mid + 1;
		}

		mid = (min + max) / 2;

	}

	cout << mid;

}