#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	unordered_map<string, string> sitePasswords;
	vector<string> result;

	while (n--) {
		string site, password;

		cin >> site >> password;

		sitePasswords.insert({ site, password });
	}

	while (m--) {
		string site;
		cin >> site;

		result.push_back(sitePasswords[site] + '\n');
	}

	for (string s : result)
		cout << s;

	return 0;
}