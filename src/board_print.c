#include <stdio.h>
#include <stdlib.h>

#include "../include/board.h"
#include "../include/board_print.h"

static void print_line(char middle,char edge, int lenght){
  printf("   ");
  printf("%c",edge);
    for (int j=0; j<lenght*2-1;j++)printf("%c",middle);
  printf("%c\n",edge);
}
void print_board(Board board) {
  char empty = ' ';
  char bomb = 'X';
  char flag = 'F';
  char horizontal_line='-';
  char vertical_line='|';
  char corners='+';
 //printing the horizontal line of numbers over the board 


 // to avoid long numbers that make the baord unreadable we will print the second digit of the number above it 
 const int number_offset=19;
 // number offset represents how many spaces we need to go from 1- 10 with the gaps between numbers accounted for  
 if (board.width>9){
    printf("  ");//offset to align the first digit with the board 
    for (int i= 0;i<board.width/10;i++){
        for (int j=0;j< number_offset;j++)
          printf(" ");
      
      printf("%d",(i+1));
    }
    printf("\n");
 }
 //printing the line of numbers that denotes the first digit of the bombs horizontal position
 printf("   ");
  for (int i=0;i<board.width;i++){
    printf(" %d",(i+1)%10);
  }
  printf("\n");

  print_line(horizontal_line,corners,board.width);
  
  //board itself             base          cyan1         green2         red3      blue4         red5         cyan6        purple 7     white 8    red flag 
 const char* color_array[]={"\033[0;37m","\033[0;36m","\033[0;32m","\033[0;31m","\033[0;34m","\033[0;31m","\033[0;36m","\033[0;35m","\033[0;37m","\033[0;31m"};
 for (int i = 0; i < board.height; i++) {
    //printing vertical numbers
    if (i<9)
      printf("  %d",i+1);
    else if(i<99)
      printf (" %d",i+1);
    else
      printf("%d",i+1);

    for (int j = 0; j < board.width; j++) {
      if (*board.lost && board.tiles[j][i].type == MINE) { 
        printf("%c%c", vertical_line, bomb);
        continue; 
      }
      if(board.tiles[j][i].flag){
        //changing to falg color
        printf("%c%s",vertical_line,color_array[9]);
        printf("%c",flag); 
        printf("%s",color_array[0]);
      }
      else if (!board.tiles[j][i].cleared) 
        printf("%c%c",vertical_line,empty);        
      else{
        //changing color to the one associated with the nubmer
        printf("%c%s",vertical_line,color_array[board.tiles[j][i].value]);
        printf("%d", board.tiles[j][i].value);
        //resetting back to base color
        printf("%s",color_array[0]);
      }
    }
    

    printf("%c\n",vertical_line);
    if (i!=board.height-1)print_line(horizontal_line,vertical_line,board.width);
 }
 //final line
 print_line(horizontal_line,corners,board.width);
 return;
}


void print_command_list() {
  printf("Command list:\n"); 
  printf("c x_coordinate y_coordinate : clear tile on position(x_coordinate, y_coordinate)\n");
  printf("f x_coordinate y_coordinate : flag tile on position(x_coordinate y_coordinate)\n");
  printf("u x_coordinate y_coordinate : unflag tile on position(x_coordinate y_coordinate)\n");
  return;
}

