#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <vector>

using namespace std;

void countCycle(map<int, int>, int);

int main() {
	int testCase;
	int permutationSize;
	map<int, int> permutation;
	vector<int> result;

	cin >> testCase;

	while (testCase--) {
		cin >> permutationSize;
		permutation.clear();
		for (int i = 1; i <= permutationSize; i++) {
			cin >> permutation[i];
		}
		countCycle(permutation, permutationSize);

	}

}

void countCycle(map<int, int> permutation, int size) {
	vector<int> visited;
	vector<vector<int>> cycle;
	stack<int> stk;
	int persentNode;
	int i = 1;
	int cycleSize = 1;

	stk.push(1);
	

	while (i<=size) {
		persentNode = stk.top();
		stk.pop();

		if (find(visited.begin(), visited.end(), persentNode) == visited.end()) {
			stk.push(permutation[persentNode]);
			visited.push_back(persentNode);
		}
		else {
			while (find(visited.begin(), visited.end(), ++i) != visited.end());
			if (i <= size) {
				stk.push(i);
				cycleSize++;
			}
		}
	}

	cout << cycleSize << endl;
}