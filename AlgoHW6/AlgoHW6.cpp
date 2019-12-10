#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

// Determines if a board configurtion is legal for the n queens problem
// board: An array of queen positions
// n: The number of queens
// Returns true if legal, false otherwise
bool isLegalPosition(vector<int> board, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (board[i] != 0 && board[j] != 0) {
				if (board[i] == board[j]) return false; // check for vertical overlap
				int rowDiff = abs(i - j);
				int colDiff = abs(board[i] - board[j]);
				if (rowDiff == colDiff) return false; // check for diagonal overlap
			}
		}
	}
	return true;
}

// Determines the next legal position for a given baord
// board: An arrray of queen positions
// n: The number of queens
// Returns the next legal position
vector<int> nextLegalPosition(vector<int> board, int n) {
	for (int i = 1; i < n; i++) {
		if (board[i] == 0) { // if the board is partial
			int newPos;
			if (isLegalPosition(board, n)) {
				newPos = i;
			} else newPos = i - 1;
			for (int a = 0; a < n; a++) {
				vector<int> newBoard = board;
				newBoard[newPos] = a; // fill in position after last valid position
				if (isLegalPosition(newBoard, n)) return newBoard;
			}
			break;
		}
	}
	// here the board must be full
	for (int i = n - 1; i >= 0; i--) {
		int prevPos = board[i];
		for (int j = 0; j < n; j++) {
			if (j != prevPos) {
				vector<int> newBoard = board;
				newBoard[i] = j;
				if (isLegalPosition(newBoard, n)) return newBoard;
			}
		}
		board[i] = 0;
	}
	return vector<int>(n);
}

int main() {
	vector<int> pos1 = { 1, 6, 8, 3, 7, 4, 2, 5 };
	vector<int> pos2 = {1,6,8,3,5,0,0,0};
	vector<int> ans1 = nextLegalPosition(pos2, 8);
	for (int i = 0; i < 8; i++) {
		cout << ans1[i] << " ";
	}
}