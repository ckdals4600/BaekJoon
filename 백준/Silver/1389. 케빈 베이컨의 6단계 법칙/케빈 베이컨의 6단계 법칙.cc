#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

using namespace std;

int findKavinBacon(int, int);
bool findFriendship(int, queue<int>&, vector<int>&);

map<int, vector<int>> friendshipMap;

int main() {
	int userNum, friendNum;

	cin >> userNum >> friendNum;


	
	int user1, user2;

	for (int i = 0; i < friendNum; i++) {
		cin >> user1 >> user2;

		friendshipMap[user1].push_back(user2);
		friendshipMap[user2].push_back(user1);
	}

	vector<int> kavinBacon(userNum + 1, 0);

	for (int start = 1; start <= userNum; start++) {
		for (int target = 1; target <= userNum; target++){
			kavinBacon[start] += findKavinBacon(start, target);
		}
	}

	int smallestUser = 1;

	for (int user = 2; user <= userNum; user++) {
		if (kavinBacon[smallestUser] > kavinBacon[user])
			smallestUser = user;
	}

	cout << smallestUser;


}

int findKavinBacon(int start, int target) {
	vector<int> visit;
	queue<int> bfsQueue;
	int friendshipCount = 0;

	bfsQueue.push(start);

	while (!findFriendship(target, bfsQueue, visit)) {
		friendshipCount++;
	}

	return friendshipCount;

}

bool findFriendship(int target, queue<int>& bfsQueue, vector<int>& visit) {

	int node;
	queue<int> temp;

	while (!bfsQueue.empty()) {
		node = bfsQueue.front();
		bfsQueue.pop();

		if (node == target)
			return true;


		if (find(visit.begin(), visit.end(), node) == visit.end()) {
			for (auto user : friendshipMap[node]) {
				temp.push(user);
			}
		}
	}

	bfsQueue = temp;

	return false;

}