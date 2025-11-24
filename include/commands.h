#include <stdlib.h>

#include "board.h" 

bool check_command(Board board, char command, Position pos); 

void command_translator(char input, Board board, Position pos);

void clear_tile(Board board, Position pos);

void flag_tile(Board board, Position pos);

void unflag_tile(Board board, Position pos);
