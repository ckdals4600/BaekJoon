#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;


int main() {
	int cityNum, bus;

	cin >> cityNum >> bus;
	
	vector<vector<long>> result(cityNum, vector<long>(cityNum, LONG_MAX));

	for (int i = 0; i < bus; i++) {
		int j, k;
		long d;
		cin >> j >> k >> d;

		result[j - 1][k - 1] = min(result[j - 1][k - 1], d);
	}

	for (int i = 0; i < cityNum; i++) {
		result[i][i] = 0L;	
	}

	for (int k = 0; k < cityNum; k++) {

		for (int i = 0; i < cityNum; i++) {
			for (int j = 0; j < cityNum; j++) {
				if (result[i][k] + result[k][j] > 0) {
					result[i][j] = min(result[i][j], result[i][k] + result[k][j]);
				}				
			}
		}

	}

	
	for (int i = 0; i < cityNum; i++) {
		for (int j = 0; j < cityNum; j++) {
			if (result[i][j] >= LONG_MAX) {
				cout << 0 << " ";
			}
			else {
				cout << result[i][j] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}