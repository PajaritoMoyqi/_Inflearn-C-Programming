#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h> // to use srand
#include <stdlib.h> // You failed to #include <stdlib.h>.
// As a result, the functions you called were assumed to accept an unknown number of arguments and return a value of type int.
// This causes undefined behavior.

int main(void)
{
  srand(time(NULL));
  int num = rand() % 100 + 1; // 1-100 사이의 숫자
  printf("%d\n", num);

  int answer;
  int chance = 5;
  while(chance > 0)
  {
    printf("You only can guess %d times.\n", chance--);
    printf("Guess the number. (1-100)\n");
    scanf("%d", &answer);
    if (answer > num)
      printf("DOWN!\n");
    else if (answer < num)
      printf("UP!\n");
    else if (answer == num)
    {
      printf("You gotcha!\n");
      break;
    }
    else
      printf("Error occurred.\n");

    if (chance == 0)
      printf("You now have no chance. Bye bye.\n");
  }

  return 0;
}