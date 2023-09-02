#include <iostream>
#include <set>
#include <queue>

using namespace std;

int main() {
	int n;
	set<string> words;
	priority_queue<pair<int,string>, vector<pair<int, string>>, greater<pair<int, string>>> w;

	cin >> n;

	while (n--) {
		string temp;
		cin >> temp;
		words.insert(temp);
	}

	for (string s : words)
		w.push(make_pair(s.length(),s));


	while (!w.empty()) {
		cout << w.top().second << endl;
		w.pop();
	}
	return 0;
}