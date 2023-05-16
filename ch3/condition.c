#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h> // to use srand

int main(void)
{
  // if
  int age = 15;
  if (age >= 20)
    printf("Adult.\n");
  else
    printf("Student.\n");

    if (age < 20 && age >= 17)
      printf("High school student.\n");
    else if (age < 17 && age >= 14)
      printf("Middle school student.\n");
    else if (age < 14 && age >= 8)
      printf("Elementary school student.\n");
    else
      printf("Too young to be a student.\n");

  // break, continue
  for (int i = 1; i <= 30; i++)
  {
    if(i >= 6)
    {
      printf("Other students can go.\n");
      break;
    }
    printf("number %d student should prepare one's presentation.\n", i);
  }

  for (int i = 1; i <= 30; i++)
  {
    if(i >= 6 && i <= 10)
    {
      if(i == 7 || i == 9)
      {
        printf("number %d student is absent today.\n", i);
        continue;
      }
      printf("number %d student should prepare one's presentation.\n", i);
    }
  }

  // and, or
  int a = 10;
  int b = 11;
  int c = 12;
  int d = 12;

  if (a == b && c == d)
    printf("a and b is same. Also c and d is same.\n");
  else if (a == b || c == d)
    printf("At least, a and b or c and d is same.\n");
  else
    printf("Different.\n");

  // switch
  srand(time(NULL));
  int i = rand() % 3;
  if (i == 0)
    printf("rock\n");
  else if (i == 1)
    printf("cissors\n");
  else if (i == 2)
    printf("paper\n");
  else
    printf("???!!!\n");

  switch(i)
  {
    case 0:
      printf("rock\n");
      break;
    case 1:
      printf("cissors\n");
      break;
    case 2:
      printf("paper\n");
      break;
    default:
      printf("???!!!\n");
      break;
  }

  int age2 = 15;
  switch(age2)
  {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7: printf("Too young to be a student.\n"); break;
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13: printf("Elementary school student.\n"); break;
    case 14:
    case 15:
    case 16: printf("Middle school student.\n"); break;
    case 17:
    case 18:
    case 19: printf("High school student.\n"); break;
    default: printf("Adult.\n"); break;
  }

  return 0;
}