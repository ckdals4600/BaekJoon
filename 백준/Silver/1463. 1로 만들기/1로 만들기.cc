#include <iostream>

using namespace std;


int dp[1000001] = { 0,0,1,1,0, };

int main() {

	int num;

	cin >> num;

	for (int i = 4; i <= num; i++) {
		if (i % 6 == 0)
			dp[i] = min(dp[i / 2], dp[i / 3]) + 1;
		else if (i % 3 == 0)
			dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
		else if (i % 2 == 0)
			dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
		else
			dp[i] = dp[i - 1] + 1;
	}

	cout << dp[num];
}


