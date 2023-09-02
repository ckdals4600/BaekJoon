#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>

using namespace std;

void p_1260();
void p_1260_treeprint(map<int, vector<int>>&);
void DFS(map<int, vector<int>>&, int, int&);
void BFS(map<int, vector<int>>&, int, int&);
bool visited(vector<int>, int);


int main() {
	p_1260();
}

void p_1260() {
	int nodeCount, lineCount, startNode;
	map<int, vector<int>> treeDFS, treeBFS;

	cin >> nodeCount >> lineCount >> startNode;

	while (lineCount--) {
		int firstNode, secondNode;
		cin >> firstNode >> secondNode;

		treeDFS[firstNode].push_back(secondNode);
		treeDFS[secondNode].push_back(firstNode);
	}

	treeBFS = treeDFS;

	for (auto& item : treeDFS) {
		sort(item.second.rbegin(), item.second.rend());
	}

	for (auto& item : treeBFS) {
		sort(item.second.begin(), item.second.end());
	}

	DFS(treeDFS, startNode, nodeCount);
	BFS(treeBFS, startNode, nodeCount);
}

void p_1260_treeprint(map<int, vector<int>>& tree) {
	for (auto item : tree) {
		cout << "[" << item.first << " : ( ";
		for (auto i : item.second)
			cout << i << ", ";
		cout << ")" << " ]" << endl;
	}
}

void DFS(map<int, vector<int>>& tree, int startNode, int& nodeCount) {
	vector<int> meetNode;
	stack<int> dfs;
	int currentNode;

	dfs.push(startNode);

	while (!dfs.empty()) {
		currentNode = dfs.top();
		dfs.pop();

		if (!visited(meetNode, currentNode)) {
			meetNode.push_back(currentNode);

			for (auto node : tree[currentNode]) {
				if (!visited(meetNode, node)) {
					dfs.push(node);
				}
			}
		}
	}

	for (auto i : meetNode)
		cout << i << " ";

	cout << endl;

}

void BFS(map<int, vector<int>>& tree, int startNode, int& nodeCount) {
	vector<int> meetNode;
	queue<int> bfs;
	int currentNode = startNode;

	bfs.push(startNode);


	while (!bfs.empty()) {
		currentNode = bfs.front();
		bfs.pop();

		if (!visited(meetNode, currentNode)) {
			meetNode.push_back(currentNode);

			for (auto node : tree[currentNode]) {
				if (!visited(meetNode, node)) {
					bfs.push(node);
				}
			}
		}
	}

	for (auto i : meetNode)
		cout << i << " ";

	cout << endl;
}

bool visited(vector<int> meetNode, int target) {
	return (find(meetNode.begin(), meetNode.end(), target) != meetNode.end());

}
