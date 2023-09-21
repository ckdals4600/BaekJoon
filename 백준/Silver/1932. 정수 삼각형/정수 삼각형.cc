#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int size;
	cin >> size;

	vector<vector<int>> triangle(size);
	vector<vector<int>> triangleMax(size);

	for (int i = 0; i < size; i++)
	{
		int max = 0;
		for (int j = 0; j < i + 1; j++)
		{
			int n;
			cin >> n;
			if (max < n) max = n;
			triangle[i].push_back(n);
		}
	}

	triangleMax[0].push_back(triangle[0][0]);

	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (j == 0) {
				triangleMax[i].push_back(triangleMax[i - 1][0] + triangle[i][0]);
			}
			else if (j == i) {
				triangleMax[i].push_back(triangleMax[i - 1][j - 1] + triangle[i][j]);
			}
			else {
				triangleMax[i].push_back(max(triangleMax[i - 1][j - 1] + triangle[i][j], triangleMax[i - 1][j] + triangle[i][j]));
			}
		}
	}

	int maxSum = triangleMax[size - 1][0];
	for (int i = 1; i < size; i++)
	{
		maxSum = max(triangleMax[size - 1][i], maxSum);
	}

	cout << maxSum;

	return 0;
}