/* 
    These functions are compulsory for tree search algorithms but they are specific
    to problems. More clearly, you must must update their blocks but do not change
    their input and output parameters.
    
    Also, if you need, you can add new functions at the end of file by declaring them in TREE_SEARCH.h
    We need change all function 
*/

#include "GRAPH_SEARCH.h"
#include "data_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//______________________________________________________________________________
State* Create_State(COORDINATE** map, int map_size)
{
	State *state = (State*)malloc(sizeof(State));
    if(state==NULL)
    	Warning_Memory_Allocation(); 

	state->Map_Size = map_size;
   	
    Print_State(state, map);
            
	int x,y,count = 0;
		
   	do{ 
		printf("Enter the coordinate of the state x and y: ");
        scanf("%d,%d", &x, &y);
		if(x >= 0 && y >= 0 && x < map_size * 2 + 1 && y < map_size * 2 + 1 && map[y][x].x != -1 && map[y][x].y != -1){
			state->coordinate.x = x;
			state->coordinate.y = y;
			break;
		}else if(count == 5){
			printf("You have entered wrong coordinate 5 times. Program is terminating...\n");
			exit(0);
		}else{
			printf("Invalid coordinate!\n");
			count++;
		}
   	}while(1);
	       
    return state;    
}

//______________________________________________________________________________
void Print_State(const State *const state, COORDINATE** map)
{ 
	int i,j;
	int map_size = state->Map_Size;
    for ( i = 0; i < map_size + 1; i++){
		for ( j = 0; j < map_size - i ; j++){
			printf("   ");
		}
		
		for ( j = map_size - i; j < map_size * 2 + 1; j++)
		{
			if(map[i][j].x == -1 || map[i][j].y == -1)
				printf("***   ");
			else
				printf("%d,%d   ", map[i][j].x, map[i][j].y);
		}
        printf("\n\n");
	}

	for ( i = map_size + 1; i < map_size *2+ 1; i++){
		for ( j = 0; j < i - map_size; j++){
			printf("   ");
		}
		
		for ( j = 0; j < map_size * 2 - i + map_size + 1; j++)
		{
			if(map[i][j].x == -1 || map[i][j].y == -1)
				printf("***   ");
			else
				printf("%d,%d   ", map[i][j].x, map[i][j].y);
			
		}
        printf("\n\n");
	}

}

void Print_State_with_size(int Map_Size, COORDINATE** map)
{ 
	int i,j;
	int map_size = Map_Size;
    for ( i = 0; i < map_size + 1; i++){
		for ( j = 0; j < map_size - i ; j++){
			printf("   ");
		}
		
		for ( j = map_size - i; j < map_size * 2 + 1; j++)
		{
			if(map[i][j].x == -1 || map[i][j].y == -1)
				printf("***");
			else
				printf("%d,%d   ", map[i][j].x, map[i][j].y);
		}
        printf("\n\n");
	}

	for ( i = map_size + 1; i < map_size *2+ 1; i++){
		for ( j = 0; j < i - map_size; j++){
			printf("   ");
		}
		
		for ( j = 0; j < map_size * 2 - i + map_size + 1; j++)
		{
			if(map[i][j].x == -1 || map[i][j].y == -1)
				printf("***");
			else
				printf("%d,%d   ", map[i][j].x, map[i][j].y);
			
		}
        printf("\n\n");
	}

}

void Print_State_Just_Coordinate(const State *const state){
	printf("(%d,%d)", state->coordinate.x, state->coordinate.y);
}

//______________________________________________________________________________
void Print_Action(const enum ACTIONS action)
{
   switch(action){
            case  GO_east:      printf("GO_east"); break;
            case  GO_west:      printf("GO_west"); break;
            case  GO_northeast: printf("GO_northeast"); break;
            case  GO_northwest: printf("GO_northwest"); break;
            case  GO_southeast: printf("GO_southeast"); break;
            case  GO_southwest: printf("GO_southwest"); break;
    }    
}

//______________________________________________________________________________
int Result(const State *const parent_state, const enum ACTIONS action, Transition_Model *const trans_model, COORDINATE** map)
{
	
    State new_state;
	new_state.Map_Size = parent_state->Map_Size;
	//Print_State_with_size(parent_state->Map_Size, map);		
	//	printf("Map Size ================ %d\n",parent_state->Map_Size);
		 if (action == 0 && parent_state->coordinate.x + 1 <= parent_state->Map_Size * 2 && map[parent_state->coordinate.y][parent_state->coordinate.x + 1].x != -1 && parent_state->coordinate.x + 1 != -1 && parent_state->coordinate.y != -1 && parent_state->coordinate.x + 1 != -1 ){
			new_state.coordinate.x = parent_state->coordinate.x + 1; 
			new_state.coordinate.y = parent_state->coordinate.y;
		 }else if (action == 1 && parent_state->coordinate.x - 1 != -1 && map[parent_state->coordinate.y][parent_state->coordinate.x - 1].x != -1 && parent_state->coordinate.y != -1){
			new_state.coordinate.x = parent_state->coordinate.x - 1;
			new_state.coordinate.y = parent_state->coordinate.y;
		 }else if (action == 2 && !(parent_state->coordinate.x + 1 > parent_state->Map_Size * 2) && map[parent_state->coordinate.y - 1][parent_state->coordinate.x + 1].y != -1 && map[parent_state->coordinate.y - 1][parent_state->coordinate.x + 1].x != -1 && parent_state->coordinate.x + 1 != -1 && parent_state->coordinate.y - 1 != -1 ){
			new_state.coordinate.x = parent_state->coordinate.x + 1;
			new_state.coordinate.y = parent_state->coordinate.y - 1;
		 }else if (action == 3 && parent_state->coordinate.x != -1 && map[parent_state->coordinate.y - 1][parent_state->coordinate.x].y != -1 && parent_state->coordinate.y - 1 != -1 ){
			new_state.coordinate.x = parent_state->coordinate.x;
			new_state.coordinate.y = parent_state->coordinate.y - 1;
		 }else if (action == 4 && !(parent_state->coordinate.y + 1 > parent_state->Map_Size * 2) && map[parent_state->coordinate.y + 1][parent_state->coordinate.x].y != -1 && parent_state->coordinate.y + 1 != -1 && parent_state->coordinate.x != -1 ){
			new_state.coordinate.x = parent_state->coordinate.x;			
			new_state.coordinate.y = parent_state->coordinate.y + 1;
		 }else if (action == 5 && !(parent_state->coordinate.y + 1 > parent_state->Map_Size * 2) && map[parent_state->coordinate.y - 1][parent_state->coordinate.x + 1].y && map[parent_state->coordinate.y - 1][parent_state->coordinate.x + 1].x != -1 && parent_state->coordinate.x - 1 != -1 && parent_state->coordinate.y + 1 != -1){
			new_state.coordinate.x = parent_state->coordinate.x - 1;
			new_state.coordinate.y = parent_state->coordinate.y + 1;
		 }else{
			return FALSE;
		 }
		/* if(parent_state->coordinate.y == 300)
		 	exit(1);
		if(parent_state->coordinate.y == 300)
		 	exit(1);
		if(parent_state->coordinate.y == 300)
		 	exit(1);
		if(parent_state->coordinate.y == 300)
		 	exit(1); */
         trans_model->new_state = new_state;
         trans_model->step_cost = 1;  
         return TRUE;                                               
}

float Compute_Heuristic_Function(const State *const state, const State *const goal)
{
		if(abs(state->coordinate.x - goal->coordinate.x) > abs(state->coordinate.y - goal->coordinate.y))
			return abs(state->coordinate.x - goal->coordinate.x);
		else
			return abs(state->coordinate.y - goal->coordinate.y);
}

// ==================== WRITE YOUR OPTIONAL FUNCTIONS ==========================

COORDINATE** Create_Map(int map_size)
{	
	int i,j,k,l;

	COORDINATE **map = (COORDINATE **)malloc((map_size * 2 + 1) * sizeof(COORDINATE *));
	for (i = 0; i < map_size * 2 + 1; i++) {
		map[i] = (COORDINATE *)malloc((map_size * 2 + 1) * sizeof(COORDINATE));
	}

    for ( i = 0; i < map_size + 1; i++){
		for ( j = 0; j < map_size - i ; j++){
			map[i][j].x = -1;
			map[i][j].y = -1;
		}
		
		for ( j = map_size - i; j < map_size * 2 + 1; j++)
		{
			map[i][j].x = j;
			map[i][j].y = i;
		}
	}

	for ( i = map_size + 1,k = map_size * 2 - 1; i < map_size *2+ 1; i++,k--){
		for ( j = 6; j > k; j--){
			map[i][j].x = -1;
            map[i][j].y = -1;
		}
		
		for ( j = 0; j < map_size * 2 - i + map_size + 1; j++)
		{
			map[i][j].x = j;
            map[i][j].y = i;
		}
	}

    Print_State_with_size(map_size, map);

	printf("Enter of the number of barriers: ");
	scanf("%d", &l);

    printf("Enter the coordinates of the barrier or barriers: ");
    
	for ( i = 0; i < l; i++){
		scanf("%d,%d", &j, &k);
		map[k][j].x = -1;
		map[k][j].y = -1;
	}

	return map;
}
