#include <bits/stdc++.h>
using namespace std;

// Function to print the board configuration
void printBoard(const vector<string>& board) {
    for (const auto& row : board)
        cout << row << "\n";
    cout << "\n";
}

// Function to check if placing a queen is safe
bool isSafe(int row, int col, const vector<string>& board, const int& n) {
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q') return false;

    // Check left upper diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;

    // Check right upper diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q') return false;

    return true;
}

// Recursive backtracking function
void solve(int row, vector<string>& board, const int& n) {
    if (row == n) { // base case: all queens placed
        printBoard(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';
            solve(row + 1, board, n);
            board[row][col] = '.'; // backtrack
        }
    }
}

int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;

    vector<string> board(n, string(n, '.'));
    cout << "\nAll possible solutions:\n\n";
    solve(0, board, n);

    return 0;
}
