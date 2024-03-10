#include <stdio.h>

int add(int x, int y) {
  return x + y;
}

int sub(int x, int y) {
  return x - y;
}

int multiply(int x, int y) {
  return x * y;
}

int div(int x, int y) {
  return x / y;
}

int main() {
  int choice;
  printf("Choose:\n  1-Addition\n  2-Subtraction\n  3-Multiplication\n  4-Division\n>>> ");
  scanf("%d", &choice);
  int x, y, z;
  printf("X =  "); 
  scanf("%d", &x);
  printf("Y =  "); 
  scanf("%d", &y);
  
  if (choice == 1) {
    z = add(x, y);
  } else if (choice == 2) {
    z = sub(x, y);
  } else if (choice == 3) {
    z = multiply(x, y);
  } else if (choice == 4) {
    z = div(x, y);
  }

  printf("Z = %d", z);

  return 0;
}
