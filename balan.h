#ifndef _balan_h_
#define _balan_h_
const int MAX_LENGTH = 63;
const int MAX_LENGTH_OPERATOR = 7;

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
        // To do sin, cos , tan, cot
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



double calculate(char * mathRegex) {
  char * trimMath = trimRegex(mathRegex);
  char * formatMath = formatRegex(trimMath);
  printf("%s", formatMath);
  char ** math = split(formatMath, "#");
  printf("%s", *math);
  return 0.0;
}


#endif

