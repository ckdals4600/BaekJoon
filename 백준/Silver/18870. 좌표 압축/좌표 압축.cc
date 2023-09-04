#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int main() {
	int n;
	vector<int> locate;
	set<int> seq;
	unordered_map<int, int> idx;

	cin >> n;

	while (n--) {
		int num;
		cin >> num;
		locate.push_back(num);
		seq.insert(num);
	}

	int i = 0;
	for (auto num : seq) {
		idx.insert({ num, i++ });
	}

	for (int num : locate)
		cout << idx[num] << " ";

}