#ifndef _balan_h_
#define _balan_h_
#include "stack.h"

const int MAX_LENGTH = 63;
const int MAX_LENGTH_OPERATOR = 7;
const double M_PI = 3.14;
const int TRUE = 1;
const int FALSE = 0;

char* trimRegex(char * mathRegex) {
  return trim(mathRegex);
}
char* formatRegex(char* mathRegex) {
  char* result = malloc(MAX_LENGTH * sizeof(char));
  char* temp = malloc(MAX_LENGTH * sizeof(char));
  int index = 0;

  for (int i = 0; i < strlen(mathRegex); i++) {
    if(!isDigital(mathRegex[i])) {
      if(mathRegex[i] == ' ') continue;
      if(strlen(temp) != 0) { 
        strcat(result, temp);
        strcat(result, "#");
      }
      char *operator = malloc(MAX_LENGTH_OPERATOR * sizeof(char));
      operator[0] = mathRegex[i];
      if(isOperator(operator)) {
        strcat(result, operator);
        strcat(result, "#");
      } else {
        do {
          operator[strlen(operator)] = mathRegex[++i];
        } while(mathRegex[i] && !isOperator(operator));
        strcat(result, operator);
        strcat(result, "#");
      }
      // Reset temp
      for (index=0; index < MAX_LENGTH; index++) { temp[index] = '\0'; } 
      free(operator);
      index=0;
    } else {
      temp[index++] = mathRegex[i];
      if((i + 1) == strlen(mathRegex)) {
        strcat(result, temp);
        strcat(result, "#");
      }
    }
  }
  return result;
}

// double doCalc(char* operator, char* a) {
//   /*
//   Apply for cos, sin, tan,. ...
//   */
//   if(operator == "cos") {

//   }
//   if(operator == "sin") {

//   }
//   if(operator == "tan") {

//   }
//   return 0.0;
// }
double doCalc(char* operator, char* a, char* b) {
  /*
  +, -, *, /, ...
  */
  if(strcmp(operator,"*") == 0) {

  } 
  if(strcmp(operator,"/") == 0) {

  } 
  if(strcmp(operator,"-") == 0) {

  } 
  if(strcmp(operator,"+") == 0) {

  }
  return 0.0;
}

char** infixToPostfix(char * formatMath) {
  char ** math = split(formatMath, "#");
  const int len = length(math);
  char ** postfix = malloc (len * sizeof(char*));
  int index = 0;
  struct stack* s = create();
  for(int i = 0; i < len; i++) {
    if(isOperator(*(math + i))) { 
      if (strcmp(*(math + i), "(") == 0) {
        push(&s, *(math + i));
      } else if (strcmp(*(math + i), ")") == 0) {
        char* topToken = pop(&s);
        while (strcmp(topToken, "(") != 0) {
          postfix[index++] = strdup(topToken);
          topToken = pop(&s);
        }
      } else {
        while(!isEmpty(s) && (getPriority(peek(s)) >= getPriority(*(math + i)))) {
          postfix[index++] = strdup(pop(&s));
        }
        push(&s, *(math + i));
      }
    } else {
      postfix[index++] = strdup(*(math + i));
    }
  }
  free(s);
  postfix[index] = NULL;
  return postfix;
}

void calc(char** postfix) {
  const int len = length(postfix);
  struct stack* s = create();
  for(int i = len - 1; i >= 0; i--) { push(&s, *(postfix + i)); }
  printStack(s);
}

double calculate(char * mathRegex) {
  char * trimMath = trimRegex(mathRegex);
  char * formatMath = formatRegex(trimMath);
  char ** postfixString = infixToPostfix(formatMath);
  calc(postfixString);
  return 0.0;
}


#endif

