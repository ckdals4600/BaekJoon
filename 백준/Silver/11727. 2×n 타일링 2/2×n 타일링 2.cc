#include <iostream>

using namespace std;


int square[1001] = { 0,1,3, };

int main() {

	int width;
	cin >> width;

	for (int i = 3; i <= width; i++) {
		square[i] = (square[i - 1] + square[i - 2]*2) % 10007 ;
	}

	cout << square[width];
}