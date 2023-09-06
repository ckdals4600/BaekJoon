#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;

	cin >> n;

	vector<int> stairs;
	vector<vector<int>> scores(n, vector<int>(2));

	while (n--) {
		int i;
		cin >> i;
		stairs.push_back(i);
	}

	scores[0][0] = 0;
	scores[0][1] = stairs[0];

	if (stairs.size() > 1) {
		scores[1][0] = stairs[1];
		scores[1][1] = stairs[0] + stairs[1];

		for (int i = 2; i < stairs.size(); i++) {
			scores[i][0] = stairs[i] + max(scores[i - 2][1], scores[i - 2][0]);
			scores[i][1] = stairs[i] + scores[i - 1][0];
		}
	}

	cout << max(scores[stairs.size() - 1][0], scores[stairs.size() - 1][1]);
}