#include <iostream>

using namespace std;

int main() {
    int result[3] = { 0,0,0 };
	int input;

	for (int i = 0;i < 12; i++) {
		cin >> input;
		result[i / 4] += input;

		if (i % 4 == 3) {
				switch (result[i/4])
			{
			case 0:
				cout << "D" << endl;
				break;
			case 1:
				cout << "C" << endl;
				break;
			case 2:
				cout << "B" << endl;
				break;
			case 3:
				cout << "A" << endl;
				break;
			case 4:
				cout << "E" << endl;
				break;
			default:
				break;
			}
		}
	}
}