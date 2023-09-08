#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() {
	int t, n;
	char op;
	int num;

	vector<string> results;

	cin >> t;

	while (t--) {
		cin >> n;
		multiset<int> pq;
		for(int i = 0; i < n; i++) {
			cin >> op >> num;

			if (op == 'I') {
				pq.insert(num);
			}
			else if(!pq.empty()){
				if (num == 1) {
					pq.erase(--pq.end());
				}
				else if (num == -1) {
					pq.erase(pq.begin());
				}
			}
		}

		if (pq.empty()) {
			results.push_back("EMPTY\n");
		}
		else {
			results.push_back(to_string(*pq.rbegin()) + " " + to_string(*pq.begin()) + '\n');
		}
	}

	for (auto s : results)
		cout << s;
}