#include <stdio.h>

int board[20][20];  // supports up to N=20
int solutionCount = 0;

// Print the board with solution number
void printBoard(int N) {
    solutionCount++;
    printf("Possible Solution %d:\n", solutionCount);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(board[i][j] ? "Q " : ". ");
        printf("\n");
    }
    printf("\n");
}

// Check if placing queen at (row, col) is safe
int isSafe(int row, int col, int N) {
    for (int i = 0; i < col; i++) if (board[row][i]) return 0;
    for (int i=row, j=col; i>=0 && j>=0; i--, j--) if (board[i][j]) return 0;
    for (int i=row, j=col; i<N && j>=0; i++, j--) if (board[i][j]) return 0;
    return 1;
}

// Solve recursively
int solve(int col, int N) {
    if (col >= N) { printBoard(N); return 1; } // solution found

    int res = 0;
    for (int i = 0; i < N; i++) {
        if (isSafe(i, col, N)) {
            board[i][col] = 1;
            res = solve(col+1, N) || res; // try next column
            board[i][col] = 0;            // backtrack
        }
    }
    return res;
}

int main() {
    int N;
    printf("Enter board size (N): ");
    scanf("%d", &N);

    if (!solve(0, N))
        printf("No solution exists\n");
    else
        printf("Total solutions found: %d\n", solutionCount);

    return 0;
}
