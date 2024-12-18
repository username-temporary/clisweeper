#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
int8_t **board_gen (int x, int y,int bombs,unsigned int seed ){
	/* to generate random numbers we will be taking in a seed and then incriment the seed every time we add a bomb
	if the function fails for whatever reason it returns a NULL pointer*/
	/*the first 4 bits are used to indicate how many bombs there are (aka 0-8) I will be doing this by using mod 8 
	to see how many bombs there are instead of taking the number itself*/

	/* making an empty board*/
	int8_t ** board= calloc(x,sizeof(int8_t*));
	if (malloc==NULL){
		return NULL;
	}
	int i;
	for (i=0;i<x;i++){
		board[i]=calloc(y,sizeof(int8_t*));	
		if (board[i]==NULL){
			return NULL;
		}
	}
	
	/*filling the board randomly with bombs (a bomb isgoing to be represented by the 6th bit) while also adding the appropriate numbers around the bombs*/
	srandom(seed);
	int total_spaces= x*y;
	int j;
	int pos [2]={0};
	for (i=0;i<bombs;i++){
		pos[0]=0;
		pos[1]=0;
		for (j=0;j<random()%total_spaces+1;j++){
			pos[1]++;
			pos[0]=pos[1]==y?pos[0]++:pos[1]+0;
			pos[1]%y;
			printf("x=%d,y=%d\n",pos[0],pos[1]);
		}
	}	
		
		
	return board;	

}
int main (){
	
	int8_t **board=board_gen(5,5,2,382734);	
	for(int i=0,i<5,i++){
		for (int j=0,j<5,j++){
		printf("%d ",board[i][j]);
		}
		printf("\n");
	}
}


