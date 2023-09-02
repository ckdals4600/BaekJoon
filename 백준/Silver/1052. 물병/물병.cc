#include <iostream>

using namespace std;

int main() {
    int n, k;
    int answer;
    int buy = 0;

    cin >> n >> k;

    if (n > k) {
        while (1) {
            int cnt = 0;
            int temp = n + buy;

            while (temp > 0) {
                if (temp % 2 == 1) {
                    cnt++;
                }
                temp /= 2;
            }

            if (cnt > k) buy++;
            else break;
        }

    }
    
    cout << buy;
}