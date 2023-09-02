#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	unordered_map<int, string> nums;
	unordered_map<string, int> names;
	vector<string> matters;

	int dic, pro;

	cin >> dic >> pro;

	for (int i = 0; i < dic; i++) {
		string name;
		cin >> name;
		nums.insert(pair<int, string>(i,name));
		names.insert(pair<string, int>(name,i));
	}

	for (int i = 0; i < pro; i++) {
		string s;
		cin >> s;
		matters.push_back(s);
	}

	for (auto s : matters) {
		if (isdigit(s[0])) {
			cout << nums[stoi(s) - 1] << '\n';
		}
		else {
			cout << names[s] + 1 << '\n';
		}
	}
}