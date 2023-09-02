#include <iostream>

using namespace std;

int main() {
	int loop, x, y;
	int quadrilateral[101][101];
	int scale = 0;

	cin >> loop;
	
	for (int i = 0; i < loop; i++) {
		cin >> x >> y;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				if (quadrilateral[x + j][y + k] != 1) {
					quadrilateral[x + j][y + k] = 1;
					scale++;
				}
			}			
		}
	}

	cout << scale;
}