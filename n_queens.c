// Program 9

#include <stdbool.h>
#include <stdio.h>

bool is_safe(int board[], int row, int col) {
  for (int i = 0; i < row; i++) {
    if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
      return false;
    }
  }
  return true;
}

bool solve_n_queens_util(int board[], int row, int n) {
  if (row == n) {
    return true;
  }

  for (int col = 0; col < n; col++) {
    if (is_safe(board, row, col)) {
      board[row] = col;
      if (solve_n_queens_util(board, row + 1, n)) {
        return true;
      }
      board[row] = -1; 
    }
  }
  return false;
}

void print_board(int board[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i] == j) {
        printf("Q ");
      } else {
        printf(". ");
      }
    }
    printf("\n");
  }
}

void solve_n_queens(int n) {
  int board[n];
  for (int i = 0; i < n; i++) {
    board[i] = -1;
  }

  if (solve_n_queens_util(board, 0, n)) {
    print_board(board, n);
  } else {
    printf("Solution does not exist.\n");
  }
}

int main() {
  int n;
  printf("Enter the value of N: ");
  scanf("%d", &n);
  solve_n_queens(n);
  return 0;
}
