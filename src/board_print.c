#include <stdio.h>
#include <stdlib.h>

#include "../include/board.h"
#include "../include/board_print.h"

void print_board(Board board) {
  for (int i = 0; i < board.height; i++) {
    for (int j = 0; j < board.width; j++) {
      if (!board.tiles[j][i].cleared) 
        printf("| ");        
      else 
        if (board.tiles[j][i].flag)
          printf("|F");
        else
          printf("|%d", board.tiles[j][i].value);
    }
    printf("|\n|");
    for (int j=0; j<board.width*2-1;j++)printf("-");
    printf("|\n");
  }
  return;
}


void print_command_list() {
  printf("Command list:\n"); 
  printf("c x_coordinate y_coordinate : clear tile on position(x_coordinate, y_coordinate)\n");
  printf("f x_coordinate y_coordinate : flag tile on position(x_coordinate y_coordinate)\n");
  printf("u x_coordinate y_coordinate : unflag tile on position(x_coordinate y_coordinate)\n");
  return;
}

