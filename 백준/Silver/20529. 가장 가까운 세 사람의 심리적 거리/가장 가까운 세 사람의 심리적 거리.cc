#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<vector<char>>> testCase;
vector<int> result;

bool promising(int contains, int distance, int min) {
	if (contains == 2) return false;
	if (distance > min) return false;

	return true;
}

void back(vector<bool> studentContainCheck, vector<int> testStundent, int contains,int distance, int& min, const int test) {
	if (contains == 2 && min > distance) {
		min = distance;
	}

	if (promising(contains, distance, min)) {
		for (int i = (contains > -1) ? testStundent[contains] + 1: 0; i < testCase[test].size(); i++) {
			int newD = distance;
			if (studentContainCheck[i]) {

				for (int num : testStundent) {
					int d = 0;
					for (int j = 0; j < 4; j++) {
						if (testCase[test][i][j] != testCase[test][num][j])
							d++;
					}
					newD += d;
				}
				
				vector<bool> studentContainChecktemp = studentContainCheck;
				vector<int> testStundenttemp = testStundent;
				studentContainChecktemp[i] = false;
				testStundenttemp.push_back(i);
				int tempC = contains+ 1;

				back(studentContainChecktemp, testStundenttemp, tempC, newD, min, test);
			}
		}
	}
}

int main() {
	
	int t;
	cin >> t;

	for (int k = 0; k < t; k++) {
		int n;

		cin >> n;

		vector<vector<char>> mbti(n,vector<char>(4));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> mbti[i][j];
			}
		}

		testCase.push_back(mbti);
	}

	for (int i = 0; i < t; i++) {
		int min = INT16_MAX;
		if (testCase[i].size() > 32) {
			min = 0;
		}

		map<string,int> duplicate;
		for (vector<char> test : testCase[i]) {
			string mbti({ test[0],test[1],test[2],test[3] });

			if (duplicate.find(mbti) != duplicate.end()) {
				duplicate[mbti]++;
				if (duplicate[mbti] > 3) {
					min = 0;
					break;
				}
			}
			else {
				duplicate[mbti] = 1;
			}
		}
		
		if (min != 0) {
			back(vector<bool>(testCase[i].size(), true), vector<int>(), -1, 0, min, i);
		}
		cout << min << endl;
	}

	return 0;
}