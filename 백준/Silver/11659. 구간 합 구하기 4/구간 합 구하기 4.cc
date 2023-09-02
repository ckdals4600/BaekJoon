#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n, m;

	cin >> n >> m;

	vector<int> result(m);
	vector<int> nums(n);
	vector<int> sums(n);

	int sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
		sum += nums[i];
		sums[i] = sum;
	}

	for (int k = 0; k < m; k++) {
		int i, j;
		cin >> i >> j;
		if(i > 1)
			result[k] = sums[j - 1] - sums[i - 2];
		else
			result[k] = sums[j - 1];
	}

	for (int n : result)
		cout << n << '\n';
}