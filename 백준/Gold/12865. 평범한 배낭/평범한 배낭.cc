#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	vector<pair<int, int>> items; // 무게, 가치
	int itemNum, possibleMaxWeight;

	cin >> itemNum >> possibleMaxWeight;


	for (int i = 0; i < itemNum; i++) {
		int weight, value;

		cin >> weight >> value;
		
		items.push_back({ weight,value });
	}

	vector<vector<int>> knapsack(itemNum + 1,vector<int>(possibleMaxWeight + 1, 0));

	for (int w = 1; w <= possibleMaxWeight; w++) {
		for (int i = 1; i <= itemNum; i++) {
			if (w - items[i - 1].first < 0) {
				knapsack[i][w] = knapsack[i - 1][w];
			}
			else {
				knapsack[i][w] = max(knapsack[i - 1][w], knapsack[i - 1][w - items[i - 1].first] + items[i - 1].second);
			}
		}
	}

	cout << knapsack[itemNum][possibleMaxWeight];

	

	return 0;
}