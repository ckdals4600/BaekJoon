#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	set<string> noListen;
	set<string> duplicate;
	
	int n, m;

	cin >> n >> m;

	while (n--) {
		string name;
		cin >> name;
		noListen.insert(name);
	}

	while (m--) {
		string name;
		cin >> name;

		if (noListen.find(name) != noListen.end()) {
			duplicate.insert(name + '\n');
		}
	}
	
	cout << duplicate.size() << '\n';
	for (string name : duplicate)
		cout << name;
}