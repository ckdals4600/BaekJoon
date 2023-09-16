#include <iostream>

using namespace std;

unsigned long long pow(unsigned long long a, unsigned long long b, unsigned long long c) {
	if (b == 0) {
		return 1;
	}

	unsigned long long p = pow(a, b / 2, c);

	if (b % 2 == 0) {
		return p * p % c;
	}
	else {
		return p * p % c * a % c;
	}
}

int main() {
	unsigned long long a, b, c;

	cin >> a >> b >> c;

	cout << pow(a, b, c);

	return 0;
}