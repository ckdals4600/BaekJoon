#include <iostream>

using namespace std;

int main() {
	int changeType[10];
	int coin, numberOfChangeType, changeCount = 0;

	cin >> numberOfChangeType >> coin;

	for (int i = 0; i < numberOfChangeType; i++)
		cin >> changeType[i];

	for (int i = --numberOfChangeType; i > -1 && coin != 0; i--) {
		if (coin >= changeType[i]) {
			changeCount += coin / changeType[i];
			coin %= changeType[i];
		}
	}

	cout << changeCount;
}