#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<unsigned long long> result;
	int n;
	cin >> n;

	while (n--) {
		int t;
		cin >> t;
		vector<unsigned long long> triangle(t);

		triangle[0] = 1;
		triangle[1] = 1;
		triangle[2] = 1;

		for (int i = 3; i < t; i++) {
			triangle[i] = triangle[i - 3] + triangle[i - 2];
		}

		result.push_back(triangle[t - 1]);
	}

	for (unsigned long long i : result) cout << i << '\n';

	return 0;
}