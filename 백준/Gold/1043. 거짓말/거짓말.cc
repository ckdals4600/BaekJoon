#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
	int peopleNum, m;
	cin >> peopleNum >> m;

	int n;
	vector<int> know;
	vector<bool> isKnow(peopleNum + 1, false);
	map<int, vector<int>> peopleJoinParty;
	vector<vector<int>> party(m);
	set<int> notalkParty;

	cin >> n;

	while (n--) {
		int people;
		cin >> people;

		know.push_back(people);
		isKnow[people] = true;
	}


	for (int i = 1; i <= peopleNum; i++) {
		peopleJoinParty.insert({ i, {} });
	}

	for(int i = 0; i < m; i++) {
		cin >> n;

		while (n--) {
			int people;
			cin >> people;

			party[i].push_back(people);
			peopleJoinParty[people].push_back(i);
		}
	}


	for (auto i = 0; i < know.size(); i++) {
		for (int i : peopleJoinParty[know[i]]) {
			if (notalkParty.find(i) == notalkParty.end()) {
				notalkParty.insert(i);

				for (int j : party[i]) {
					if (!isKnow[j]) {
						know.push_back(j);
						isKnow[j] = true;
					}
				}
			}
		}
	}
	
	cout << m - notalkParty.size();
}