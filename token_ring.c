#include<stdio.h>
#include<stdlib.h>

int N = 4;
int M = 5;


int select_update(int stable[N] ) {

   int tokens[N];
   int index = 0; 

   int i;
   for(i=1; i<N; i++) {
      if(stable[i] != stable[i-1]) {
         tokens[index] = i;
         index++;
      }
   }

  
   //TODO: havoc
   int selection = rand() % index;

   return tokens[selection];

}

int is_stable(int state[N]) {

   int tokens = 0; 

   int i;
   for(i=1; i<N; i++) {
      if(state[i] != state[i-1]) {
         tokens++;
      }
   }

   //Add the 0 processes token
   if( state[0] == state[N-1] ) {
      tokens++;
   }

   //printf("tokens = %d\n", tokens);
   if( tokens == 1 ) {
      //printf("is STABLE!\n");
      return 1;
   }
   //printf("is NOT stable\n");   
   return 0;

}

void print_state(int state[N]) {

   int i;
   for(i=0; i<N; i++) {
      printf("Process %i holds: %i\n", i, state[i]);
   }

   printf("\n");
}


int main(){

   srand(0);
   int state[N];
   
   int i;
   for( i = 0; i < N; i++) {
      //TODO: set with havoc 
      state[i] = rand() % M;
   }

   print_state(state);

   while(!is_stable(state)) {
      
      int update_sel = select_update(state);
      state[update_sel] = state[update_sel -1];
      print_state(state);
   }

}
