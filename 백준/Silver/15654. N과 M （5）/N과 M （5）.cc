#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n,m;
	vector<int> nums;
	cin >> n >> m;

	nums.assign(n, 0);


	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());

	queue<pair<set<int> , vector<int>>> que;

	for (int i = 0; i < n; i++) {
		que.push({
			{nums[i]} ,{nums[i]}
			});
	}

	while(!que.empty()){
		set<int> set = que.front().first;
		vector<int> vec = que.front().second;
		que.pop();

		if (set.size() == m) {
			for (int i : vec) {
				cout << i << " ";
			}
			cout << '\n';
			continue;
		}

		for (int i : nums) {
			if (set.find(i) == set.end()) {
				set.insert(i);
				vec.push_back(i);
				que.push({ set,vec });
				set.erase(i);
				vec.pop_back();
			}
		}
	}
	

	return 0;
}