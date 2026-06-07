#include <stdio.h>
#include <stdbool.h>

int solutionCount = 0;

bool isSafe(int N, int board[N][N], int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

void printSolution(int N, int board[N][N])
{
    printf("\nSolution %d:\n", ++solutionCount);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void solveNQUtil(int N, int board[N][N], int col)
{

    if (col >= N) {
        printSolution(N, board);
        return;
    }

    for (int i = 0; i < N; i++) {

        if (isSafe(N, board, i, col)) {


            board[i][col] = 1;


            solveNQUtil(N, board, col + 1);

            board[i][col] = 0;
        }
    }
}

void solveNQ(int N)
{
    int board[N][N];


    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    solveNQUtil(N, board, 0);

    if (solutionCount == 0)
        printf("Solution does not exist\n");
    else
        printf("\nTotal solutions = %d\n", solutionCount);
}

int main()
{
    int N;

    printf("Enter value of N: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Enter a positive number.\n");
        return 0;
    }

    solveNQ(N);

    return 0;
}