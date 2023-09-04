#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> tile(n + 1);
	tile[1] = 1;
	tile[2] = 2;

	for (int i = 3; i <= n; i++) {
		tile[i] = (tile[i - 1] + tile[i - 2]) % 10007;
	}

	cout << tile[n] ;
}