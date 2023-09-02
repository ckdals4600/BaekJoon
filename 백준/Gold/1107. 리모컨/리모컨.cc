#include <iostream>
#include <set>

using namespace std;

int main() {
	int start = 100;
	int channel;
	int button[10] = { 0, };
	int m;

	cin >> channel >> m;

	while (m--) {
		int b;
		cin >> b;
		button[b] = -1;
	}

	int min = (channel > start) ? channel - start : start - channel;
	
	for (int i = channel; i < 1000000; i++) {
		bool isOk = true;
		int digit = 0;
		int n = i;
		while (n / 10 > 0 || n % 10 > 0) {
			digit++;
			if (button[n % 10] == -1) {
				isOk = false;
				break;
			}
			n /= 10;
		}

		if (i == 0) {
			digit++;
			if (button[i] == -1) {
				isOk = false;
			}
		}

		if (isOk) {
			min = (i - channel + digit < min) ? i - channel + digit : min;
			break;
		}

	}

	for (int i = channel; i > -1; i--) {
		bool isOk = true;
		int digit = 0;
		int n = i;
		while (n / 10 > 0 || n % 10 > 0) {
			digit++;
			if (button[n % 10] == -1) {
				isOk = false;
				break;
			}
			n /= 10;
		}
		if (i == 0) {
			digit++;
			if (button[i] == -1) {
				isOk = false;
			}
		}

		if (isOk) {
			min = (channel - i + digit < min) ? channel - i + digit : min;
			break;
		}

	}

	cout << min;
}