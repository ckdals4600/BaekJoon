#include <iostream>
#include <set>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int m;
	set<int> s;

	cin >> m;

	while (m--) {
		string command;

		cin >> command;

		if (command == "all") {
			s = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
		}
		else if (command == "empty") {
			s.clear();
		}
		else {
			int i;
			cin >> i;

			if (command == "add") {
				s.insert(i);
			}
			else if (command == "remove") {
				s.erase(i);
			}
			else if (command == "check") {
				if (s.find(i) != s.end()) cout << 1 << '\n';
				else cout << 0 << '\n';
			}
			else if (command == "toggle") {
				if (s.find(i) != s.end()) s.erase(i);
				else s.insert(i);
			}
		}
	}
}