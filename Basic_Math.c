#include <stdio.h>
#include <time.h>


char add_to_history(float x, char operator, float y, float z) {

  time_t rawtime;
  struct tm *info;

  time(&rawtime);

  info = localtime(&rawtime);

  FILE* fp = fopen("history.txt", "a"); 
  if (fp == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  fprintf(fp, "%s <%f %c %f = %f>\n", asctime(info), x, operator, y, z);
  
  fclose(fp);
}


float add(float x, float y) {
  add_to_history(x, '+', y, x + y);
  return x + y;
}

float sub(float x, float y) {
  add_to_history(x, '-', y, x - y);
  return x - y;
}

float multiply(float x, float y) {
  add_to_history(x, '*', y, x * y);
  return x * y;
}

float div(float x, float y) {
  add_to_history(x, '/', y, x / y);
  return x / y;
}

char show_history() {
  FILE* fp = fopen("history.txt", "r");

  if (fp == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  char line[1000] = "";
  while (fgets(line, sizeof(line), fp)) {
    printf("%s\n", line);
  }

  fclose(fp);
}

int main() {
  int choice;
  printf("Choose:\n  1-Addition\n  2-Subtraction\n  3-Multiplication\n  4-Division\n  5-History\n>>> ");
  scanf("%d", &choice);
  
  float x, y, z;

  if (choice == 1) {
    printf("\nIf X + Y = Z\n");
    printf("X =  "); 
    if(scanf("%f", &x) != 1) {
      printf("Invalid input. Please enter a number.\n");
      return 0;
    }
    printf("Y =  "); 
    if(scanf("%f", &y) != 1) {
      printf("Invalid input. Please enter a number.\n");
      return 0;
    }
    z = add(x, y);
    printf("\n,then Z = %2f\n", z);

  } else if (choice == 2) {
    printf("\nIf X - Y = Z\n");
    printf("X =  "); 
    if(scanf("%f", &x) != 1) {
      printf("Invalid input. Please enter a number.\n");
      return 0;
    }
    printf("Y =  "); 
    if(scanf("%f", &y) != 1) {
      printf("Invalid input. Please enter a number.\n");
      return 0;
    }
    z = sub(x, y);
    printf("\n,then Z = %2f\n", z);

  } else if (choice == 3) {
    printf("\nIf X x Y = Z\n");
    printf("X =  "); 
    if(scanf("%f", &x) != 1) {
      printf("Invalid input. Please enter a number.\n");
      return 0;
    }
    printf("Y =  "); 
    if(scanf("%f", &y) != 1) {
      printf("Invalid input. Please enter a number.\n");
      return 0;
    }
    z = multiply(x, y);
    printf("\n,then Z = %2f\n", z);

  } else if (choice == 4) {
    printf("\nIf X ÷ Y = Z\n");
    printf("X =  "); 
    if(scanf("%f", &x) != 1) {
      printf("Invalid input. Please enter a number.\n");
      return 0;
    }
    printf("Y =  "); 
    if(scanf("%f", &y) != 1) {
      printf("Invalid input. Please enter a number.\n");
      return 0;
    }
    z = div(x, y);
    printf("\n,then Z = %2f\n", z);

  } else if (choice == 5) {
    show_history();
    printf("\n");
    printf("\n");
  } else {
    printf("Invalid choice.\n");
    return 0;
  }
  printf("\n");
  return 0;
}
