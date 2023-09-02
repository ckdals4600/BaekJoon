#include <iostream>
#include <cmath>

using namespace std;

int y, x;
int cnt = 0;

void z(int n, int startX, int startY) {
	int p = pow(2, --n);
	int c = pow(p, 2);

	if (n == 0) {
		cnt += x - startX + (y - startY) * 2;
	}else{
		if (startX + p > x && startY + p > y) {
			z(n, startX, startY);
		}
		else if (startX + p <= x && startY + p > y) {
			cnt += c;
			z(n, startX + p, startY);
		}
		else if (startX + p > x && startY + p <= y) {
			cnt += 2 * c;
			z(n, startX, startY + p);
		}
		else if (startX + p <= x && startY + p <= y) {
			cnt += 3 * c;
			z(n, startX + p, startY + p);
		}
	}
}

int main() {
	int n;

	cin >> n >> y >> x;

	z(n, 0, 0);
	cout << cnt;
}