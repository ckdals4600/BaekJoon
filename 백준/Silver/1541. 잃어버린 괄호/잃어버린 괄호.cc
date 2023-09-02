#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
	queue<int> nums;
	string ex;
	
	cin >> ex;

	string num = "";
	int sum = 0;

	for (char c : ex) {
		if (c == '+') {
			sum += stoi(num);
			num = "";
		}
		else if (c == '-') {
			nums.push(sum + stoi(num));
			sum = 0;
			num = "";
		}
		else {
			num += c;
		}
	}

	nums.push(sum + stoi(num));

	int result = nums.front();
	nums.pop();

	while (!nums.empty()) {
		result -= nums.front();
		nums.pop();
	}

	cout << result;

	return 0;
}