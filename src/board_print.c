#include <stdio.h>
#include <stdlib.h>

#include "../include/board.h"
#include "../include/board_print.h"

void print_board(Board board, int width, int height) {
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      if (board[i][j].type == TILE)
        printf("X");
      else 
        printf("%d", board[i][j].value);
    }
    printf("\n");
  }
  
  return;
}
