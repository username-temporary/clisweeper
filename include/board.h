#include <stdlib.h>
#include <stdbool.h>

#pragma once

typedef enum {
  MINE,
  TILE
} Tile_Type;

typedef struct {
  int x;
  int y
} Position;

typedef struct {
  Tile_Type type;
  Position pos; // The tiles coordinates
  int value;
  bool flag;
  bool revealed; // For printing purposes
} Tile;

typedef Tile* Board;

Board board_create(int width, int height, int mines, Position init_pos);
