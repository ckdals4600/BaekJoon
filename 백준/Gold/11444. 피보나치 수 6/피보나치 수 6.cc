#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<long long, long long> piboMap;
long long divNum = 1000000007;

long long pibo(long long n) {
	if (n == 0) {
		return 1;
	}
	else if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 1;
	}
	else if (piboMap.find(n) != piboMap.end()) {
		return piboMap[n];
	}
	else if (n % 2 == 0) {
		long long n1 = pibo(n / 2) % divNum;
		long long n2 = pibo((n / 2) - 1) % divNum;
		long long result = (n1 * ((long long)2 * n2 + n1)) % divNum;
		piboMap.insert({ n, result });
		return piboMap[n];
	}
	else if (n % 2 != 0) {
		long long n1 = pibo((n + 1) / 2) % divNum;
		long long n2 = pibo((n - 1) / 2) % divNum;
		long long result = (n1 * n1 + n2 * n2) % divNum;
		piboMap.insert({ n, result });
		return piboMap[n];
	}

	
}

int main() {
	long long n;
	cin >> n;

	cout << pibo(n);
}