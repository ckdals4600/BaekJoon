#include <iostream>
#include <vector>

using namespace std;

int p_12759_check(int row, int col, int plusRow, int plusCol, int player, int board[][3]);
int p_12759();

int main() {
	cout << p_12759();
}


int p_12759() {
	int board[3][3], last = 9;
	fill(&board[0][0], &board[2][3], 0);

	int player;
	int row, col;
	

	cin >> player;


	while (1) {
		

		cin >> row >> col;
		
		row--, col--;

		board[row][col] = player;

		if (p_12759_check(row, 0, 0, 1, player, board) == 3) break;
		if (p_12759_check(0, col, 1, 0, player, board) == 3) break;

		if (row == col) if(p_12759_check(0, 0, 1, 1, player, board) == 3) break;
		if (row + col == 2) if (p_12759_check(0, 2, 1, -1, player, board) == 3) break;

		if (--last == 0) return 0;

		player = (player == 1) ? 2 : 1;
	}

	return player;
}


int p_12759_check(int row, int col, int plusRow, int plusCol, int player, int board[][3]) {
	int bingGo = 0;
	for (int i = 0; i < 3; i++) {
		if (board[row][col] == player) bingGo++;
		row = row + plusRow, col = col + plusCol;
	}
	return bingGo;
}