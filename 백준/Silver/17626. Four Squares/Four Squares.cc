#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> sqr(n + 1, 5);
	sqr[0] = 0;
	sqr[1] = 1;
	sqr[2] = 2;
	sqr[3] = 3;

	for (int i = 4; i < n + 1; i++) {
		double iMaxDouble = sqrt(i);
		int iMaxInt = iMaxDouble;

		if (iMaxDouble - iMaxInt == 0) {
			sqr[i] = 1;
		}
		else {
			int max = sqrt(i);
			for (int j = 0; j < max + 1; j++) {
				if (sqr[j * j] + sqr[i - j * j] < sqr[i]) {
					sqr[i] = sqr[j * j] + sqr[i - j * j];
				}
			}
		}
	}

	cout << sqr[n];

	return 0;
}