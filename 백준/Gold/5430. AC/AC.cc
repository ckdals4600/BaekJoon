#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

int main() {
	int t;

	cin >> t;

	vector<string> result;

	while (t--) {
		string ops, numbers;
		int size;
		deque<int> num;

		cin >> ops >> size >> numbers;

		int parse = 0;
		for (char number : numbers) {
			if ('0' <= number && number <= '9') {
				parse = parse * 10 + (number - '0');
			}
			else if(number != '[') {
				num.push_back(parse);
				parse = 0;
			}
		}

		int dNumber = 0;
		for (char op : ops) {
			if (op == 'D') {
				dNumber++;
				if (dNumber > size) {
					break;
				}
			}
		}


		if (dNumber > size) {
			result.push_back("error");
		}
		else if (dNumber == size) {
			result.push_back("[]");
		}
		else {
			bool isR = false;

			for (char op : ops) {
				if (op == 'R') {
					isR = !isR;
				}
				else {
					if (!isR) {
						num.pop_front();
					}
					else {
						num.pop_back();
					}
				}
			}

			string v = "[";
			int j;
			if (isR) {
				for (j = num.size() - 1; j > 0; j--) {
					v += to_string(num[j]);
					v += ",";
				}
			}
			else {
				for (j = 0; j < num.size() - 1; j++) {
					v += to_string(num[j]);
					v += ",";
				}
			}

			v += to_string(num[j]);
			v += "]";

			result.push_back(v);
		}

	}
	int i;
	for (i = 0; i < result.size() - 1; i++) {
		cout << result[i] << endl;
	}

	cout << result[i];
}
