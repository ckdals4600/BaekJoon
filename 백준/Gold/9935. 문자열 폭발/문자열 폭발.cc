#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string str, boom;
	cin >> str >> boom;
	int flag = 0;
	
	string temp = "";
	int t = 0;
	int delNum = 0;

	for (int i = 0; i < str.size(); i++) {
		
		if (t == i) {
			temp += str[i];
			t++;
		}

		if (!temp.empty() && i - delNum >= 0) {
			if (temp[i - delNum] != boom[flag]) {
				flag = 0;
			}

			if (temp[i - delNum] == boom[flag]) {
				flag++;
			}
		}
		

		if (flag == boom.size()) {
			temp.erase(i - boom.size() + 1 - delNum, boom.size());
			flag = 0;
			i = (i - 2*(int)boom.size() > 0) ? i - 2 * (int)boom.size() : -1;
			delNum += boom.size();
		}
	}

	if (temp.empty()) {
		cout << "FRULA";
	}
	else {
		cout << temp;
	}
	

	return 0;
}