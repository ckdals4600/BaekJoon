#include <iostream>
#include <deque>

using namespace std;

int main() {

    int t;
    deque<pair<int,int>> result;

    cin >> t;

    while (t--) {
        int num;
        cin >> num;

        if (num == 0) {
            result.push_back({1,0});
        }
        else if (num == 1) {
            result.push_back({ 0,1 });
        }
        else if (num == 2) {
            result.push_back({ 1,1 });
        }
        else {
            deque<int> fibonnaciCount0(num + 1, 0);
            deque<int> fibonnaciCount1(num + 1,0);

            fibonnaciCount0[0] = 1;
            fibonnaciCount0[1] = 0;
            fibonnaciCount0[2] = 1;

            fibonnaciCount1[0] = 0;
            fibonnaciCount1[1] = 1;
            fibonnaciCount1[2] = 1;

            for (int i = 3; i <= num; i++) {
                fibonnaciCount0[i] = fibonnaciCount0[i - 1] + fibonnaciCount0[i - 2];
                fibonnaciCount1[i] = fibonnaciCount1[i - 1] + fibonnaciCount1[i - 2];
            }

            result.push_back({ fibonnaciCount0[num],  fibonnaciCount1[num] });
        }
    }

    for (auto cnt : result)
        cout << cnt.first << ' ' << cnt.second << endl;
}