#include <stdlib.h>
#include <stdbool.h>

#pragma once

typedef enum {
  MINE, TILE
} Tile_Type;

typedef struct {
  int x;
  int y; 
} Position;

typedef struct {
  Tile_Type type;
  Position pos; // The tiles coordinates
  int value;
  bool flag;
  bool cleared; // For printing purposes
} Tile;

typedef struct {
  Tile** tiles; // Array of tiles
  int width; // Board's width
  int height; // Board's height
  int mines; // Number of total mines in board
  Position first_pos; // The player's first played tile
} Board;

Board board_create(int width, int height, int mines);

void board_fill(Board board);

bool check_command(Board board, char command, Position pos);

void clear_tile(Board board, Position pos);
