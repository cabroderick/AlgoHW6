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
	for (int i = 0; i < n; i++) { // maybe change back to 1
		if (board[i] == 0) { // if the board is partial
			int newPos;
			if (isLegalPosition(board, n)) {
				newPos = i;
			} else newPos = i - 1;
			for (int j = newPos; j >= 0; j--) {
				int newVal = board[j];
				if (newVal != n) {
					for (int a = newVal + 1; a <= n; a++) {
						vector<int> newBoard = board;
						newBoard[j] = a; // fill in position after last valid position
						if (isLegalPosition(newBoard, n)) return newBoard;
					}
				}
				// here the row must be emptied out
				board[j] = 0;
			}
			return vector<int>(n, 0); // case when all solutions have been found
		}
	}
	// here the board must be full
	for (int i = n - 1; i >= 0; i--) {
		int prevPos = board[i];
		if (prevPos != n) {
			for (int j = prevPos + 1; j <= n; j++) {
				vector<int> newBoard = board;
				newBoard[i] = j;
				if (isLegalPosition(newBoard, n)) return newBoard;
			}
		}
		
		board[i] = 0;
	}
	return vector<int>(n, 0); // no valid solutions after current board
}

// Determines if a given board is full
// board: The board
// n: The size of the board
// Returns true if full, false otherwise
bool isFull(vector<int> board, int n) {
	for (int i = 0; i < n; i++) {
		if (board[i] == 0) return false; // if there are any 0s the board is not full
	}
	return true;
}

// Determines if a given board is empty
// board: The board
// n: The size of the board
// Returns true if empty, false otherwise
bool isEmpty(vector<int> board, int n) {
	for (int i = 0; i < n; i++) {
		if (board[i] != 0) return false; // if there are any non-0s the board is not empty
	}
	return true;
}

// Solves the n queens problem for a given board size
// n: The board size
// Returns a list of the completed boards
vector<vector<int>> nQueens(int n) {
	vector<vector<int>> solutions; // vector containing the solutions to the problem

	vector<int> test(n, 0);
	test = nextLegalPosition(test, n);
	while (!isEmpty(test, n)) {
		test = nextLegalPosition(test, n);
		if (isFull(test, n)) solutions.push_back(test);
	}
	return solutions;

	/*
	/*
	for (int i = 1; i <= n; i++) {
		vector<int> board(n, 0);
		board[0] = i;
		while (!isEmpty(board, n)) {
			board = nextLegalPosition(board, n);
			if (isFull(board, n)) solutions.push_back(board);
		}
		return solutions;
	}
	*/
	
	/*
	
	for (int i = 1; i <= n; i++) {
		vector<int> board(n, 0);
		board[0] = i; // initializes first row value
		while (!isFull(board, n) && !isEmpty(board, n)) {
			board = nextLegalPosition(board, n);
		}
		if (!isEmpty(board, n)) solutions.push_back(board);
	}
	return solutions;
	*/
}


// Prints solutions 4-15 for the n queens problem
void printSolutions() {
	for (int i = 4; i <= 15; i++) {
		vector<vector<int>> solutions = nQueens(i);
		int size = solutions.size();
		cout << "The n queens problem has " << size << " solutions for n = " << i << ":" << endl;
		for (int a = 0; a < size; a++) {
			for (int b = 0; b < solutions[a].size(); b++) {
				cout << solutions[a][b] << " ";
			}
			cout << endl;
		}
	}
}

int main() {
	
	vector<int> pos1 = { 1, 6, 8, 3, 7, 4, 2, 5 };
	vector<int> pos2 = { 1, 6, 8, 3, 7, 0, 0, 0 };
	vector<int> empty(8, 0);
	vector<int> ans2 = nextLegalPosition(pos2, 8);
	vector<int> ans1 = nextLegalPosition(pos1, 8);
	for (int i = 0; i < 8; i++) {
		cout << ans1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 8; i++) {
		cout << ans2[i] << " ";
	}
	cout << endl;
	
	vector<vector<int>> four = nQueens(8);
	for (int i = 0; i < four.size(); i++) {
		for (int j = 0; j < four[i].size(); j++) {
			cout << four[i][j] << " ";
		}
		cout << endl;
	}
	

}