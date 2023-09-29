#include <iostream>
#include <vector>

using namespace std;

int a;

vector<vector<long long>> matrixMulti(vector<vector<long long>>& adj1, vector<vector<long long>>& adj2) {
	vector<vector<long long>> temp(a, vector<long long >(a,0));

	for (long long i = 0; i < a; i++) {
		for (long long j = 0; j < a; j++) {
			for (long long k = 0; k < a; k++) {
				temp[i][j] += (adj1[i][k] * adj2[k][j]) % 1000;
			}

			temp[i][j] = temp[i][j] % 1000;
		}
	}

	return temp;
}

vector<vector<long long>> pow(vector<vector<long long>>& adj, long long b) {
	if (b == 1) {
		return adj;
	}

	vector<vector<long long>> p = pow(adj, b / 2);
	vector<vector<long long>> pp = matrixMulti(p, p);

	if (b % 2 == 0) {
		return pp;
	}
	else {
		return matrixMulti(pp, adj);
	}
}

int main() {
	long long b;
	cin >> a >> b;

	vector<vector<long long>> adj(a, vector<long long>(a));
	vector<vector<long long>> vec;

	for (long long i = 0; i < a; i++) {
		for(long long j = 0; j < a; j++){
			cin >> adj[i][j];
		}
	}

	vec = pow(adj, b);

	for(long long i = 0; i < a; i++)
	{
		for (long long j = 0; j < a; j++) {
			cout << vec[i][j] % 1000 << ' ';
		}
		cout << '\n';
	}

	return 0;
}