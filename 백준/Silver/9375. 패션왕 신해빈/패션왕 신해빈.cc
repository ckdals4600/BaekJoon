#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	vector<int> results;

	while (t--) {	
		int n = 0;

		map<string, int> m;
		int variableCount = 0;
		int result = 0;

		cin >> n;
		result = n;

		for (int i = 0; i < n; i++) {

			string wearName, wearVariable;
			cin >> wearName >> wearVariable;

			if (m.find(wearVariable) == m.end()) {
				m.insert({ wearVariable, 1 });
				variableCount++;
			}
			else {
				m[wearVariable] = m[wearVariable] + 1;
			}
		}

		
		int totalMul = 1;

		for (auto iter = m.begin(); iter != m.end(); iter++) {
			totalMul *= (iter->second + 1);
		}

		result = totalMul-1;

		results.push_back(result);
	}

	for (auto r : results) cout << r << '\n';

}