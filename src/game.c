#include <stdlib.h>
#include <stdio.h>

#include "../include/board.h"
#include "../include/board_print.h"

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// User enters width, height and number of mines 
int main(int argc, char* argv[]) {
  
  if (argc != 4) {
    printf("Enter board's dimensions(width, height) and number of mines\n");
    return 1;
  }
  int width = atoi(argv[1]);
  if (width <= 0 || width >= MAX_WIDTH) {
    printf("Invalid width\n");
    return 1;
  }

  int height = atoi(argv[2]);
  if (height <= 0 || height >= MAX_HEIGHT) {
    printf("Invalid height\n");
    return 1;
  }

  int mines = atoi(argv[3]);
  if (mines <= 0 || mines >= width*height) {
    printf("Invalid amount of mines\n");
    return 1;
  }

  Board board = board_create(width, height, mines);
  print_board(board);

  char command;
  Position pos;
  int first = scanf("%c %d %d", &command, &pos.x, &pos.y);
  while (first != 3 /*|| !check_command(board, command, pos)*/) {
    printf("Invalid command\n");
    print_command_list();
    first = scanf("%c %d %d", &command, &pos.x, &pos.y);
  }

  // User input is 1 initialised while the tile array is 0 initialised
  pos.x--;
  pos.y--;
  board.first_pos = pos;
  board_fill(board);

  // We clear the first tile since it will not be a mine
  
  clear_tile(board, pos);
  print_board(board);

  return 0;
}
