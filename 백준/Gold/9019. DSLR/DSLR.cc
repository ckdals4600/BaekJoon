#include <iostream>
#include <vector>
#include <queue>

using namespace std;

string findMin(int a, int b) {
	bool duplicateCheck[10000] = { false, };

	queue<pair<int, string>> q;
	pair<int, string> num;

	q.push(make_pair(a, ""));

	while (!q.empty()) {
		num = q.front();
		q.pop();

		if (num.first == b)
			return num.second;

		int d = (num.first * 2) % 10000;
		int s = (num.first - 1) > -1 ? num.first - 1 : 9999;
		int r = num.first / 10 + ((num.first % 10) * 1000);
		int l = ((num.first * 10) % 10000) + num.first / 1000;

		if (!duplicateCheck[d]) {
			duplicateCheck[d] = true;
			q.push(make_pair(d, num.second + "D"));
		}

		if (!duplicateCheck[s]) {
			duplicateCheck[s] = true;
			q.push(make_pair(s, num.second + "S"));
		}

		if (!duplicateCheck[l]) {
			duplicateCheck[l] = true;
			q.push(make_pair(l, num.second + "L"));
		}

		if (!duplicateCheck[r]) {
			duplicateCheck[r] = true;
			q.push(make_pair(r, num.second + "R"));
		}
	}

}


int main() {
	int t;
	vector<pair<int, int>> input;

	cin >> t;

	while (t--) {
		int a, b;
		cin >> a >> b;
		input.push_back(make_pair(a,b));
	}

	for (auto p : input) {
		cout << findMin(p.first, p.second) << '\n';
	}
}