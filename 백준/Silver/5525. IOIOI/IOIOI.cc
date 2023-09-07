#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	int count;
	string s;
	string p = "I";

	cin >> n >> m >> s;

	while (n--) {
		p += "OI";
	}

	string::size_type pos = s.find(p);
	count = 0;

	while (pos != string::npos) {
		count++;

		pos = s.find(p, pos + 1);
	}

	cout << count;
}