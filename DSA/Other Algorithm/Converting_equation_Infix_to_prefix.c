//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> Converting infix algebraic equations to postfix algebraic equation using polish notation
 Source -> Khalil Ahammad Sir,Assistent professior,Comilla University 
 Created -> 11/03/2023
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N (int)1e4
// Stack and its operations
int top =-1;
char stack[N];

void push(char c){
  if(top == strlen(stack))
    printf("Stack overflo\n");
  else
    stack[++top] = c;
}

char pop(){
  if(top<0){
    printf("Stack Underflow\n");
    exit(1);
  }
  else{
    char c = stack[top];
    stack[top--] ='\0';
    return c;
  }
}

/*
  piority of operators (down to upword)
    ^
    * /
    + -
*/
int piority(char Operator){
  if(stack[top] == '^')
    return 1;
  else if((stack[top] == '*' || stack[top] == '/') && Operator != '^')
    return 1;
  else if((Operator == '+' || Operator == '-') && (stack[top] == '+' || stack[top] == '-') )
    return 1;
  else return 0;
}



void infix_to_postfix(char Q[],char P[]){
  int p_pos=0;
  push('(');          //adding sentinel to stack
  Q[strlen(Q)]=')';   //adding sentinel to the given expression 
  for(int i=0; i< strlen(Q);i++){
    //If a operator found 
    if(Q[i] == '^' || Q[i] == '*' || Q[i] == '+' || Q[i] == '-' || Q[i] == '/' ){
      while(piority(Q[i]) && stack[top] != '('){
        P[p_pos++] = pop();
      }
      push(Q[i]);
    }
    else if(Q[i] == '(')
      push(Q[i]);
    else if(Q[i] == ')'){
      while(stack[top] != '(') P[p_pos++] = pop();
      pop();
    }
    //If operant found
    else  
      P[p_pos++]=Q[i];
  }
  P[p_pos] = '\0';
}

int main(){
  char Q[N],P[N];
  scanf("%s",Q);
  printf("Infix algebraic equations = %s\n",Q);

  infix_to_postfix(Q,P);
  
  printf("\nPostfix algebraic equations = %s\n",P);
  return (( 0 - 0 ));
}

/*
Input :
  A+(B*C-(D/E^F)*G)*H
Output :
  ABC*DEF^/G*-H*+
*/
