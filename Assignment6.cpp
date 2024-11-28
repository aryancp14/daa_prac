#include <iostream>
#include <vector>
using namespace std;

void printSolution(const vector<vector<int>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl; 
}

bool isSafe(const vector<vector<int>>& board, int row, int col) {
    for (int i = 0; i < col; i++) {
        if (board[row][i])      return false;
        
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])     return false;
        
    }

    for (int i = row, j = col; i < board.size() && j >= 0; i++, j--) {
        if (board[i][j])     return false;
        
    }

    return true;
}

bool solveNQUtil(vector<vector<int>>& board, int col) {
    if (col >= board.size()) {
        printSolution(board);
        return true;
    }

    bool res = false;
     
    for (int i = 0; i < board.size(); i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1; 
           
            res = solveNQUtil(board, col + 1) || res;

            board[i][col] = 0;
        }
    }

    return res;
}

void solveNQ(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));
   
    if (!solveNQUtil(board, 0)) {
        cout << "Solution does not exist" << endl; 
    }
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    solveNQ(N);
    return 0;
}
