#include <stdio.h>

int main(void)
{
  // ++
  int a = 10;
  printf("%d\n", a);
  printf("%d\n", a++);
  printf("%d\n", a);
  printf("%d\n", ++a);
  printf("%d\n", a);

  printf("\n\n");
  // for
  for (int i = 1; i <= 10; i++)
  {
    printf("Hello World! %d\n", i);
  }

  printf("\n\n");
  // while
  int j = 1;
  while (j <= 10)
  {
    printf("2nd Hello World! %d\n", j++);
  }

  printf("\n\n");
  // do while
  int k = 1;
  do
  {
    printf("3rd Hello World! %d\n", k++);
  } while (k <= 10);

  // double loop
  for (int i = 1; i <= 9; i++)
  {
    for (int j = 1; j <= 9; j++)
    {
      printf("%d x %d = %d\n", i, j, i*j);
    }
  }

  printf("\n\n");
  // making incrising stars(asterisk)
  for (int i = 1; i <= 5; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      printf("*");
    }
    printf("\n");
  }

  printf("\n\n");
  // making decresing stars(asterisk)
  for (int i = 5; i > 0; i--)
  {
    for (int j = 0; j < i; j++)
    {
      printf("*");
    }
    printf("\n");
  }

  printf("\n\n");
  // making stars right aligned
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5 - i; j++)
    {
      printf(" ");
    }
    for (int k = 0; k <= i; k++)
    {
      printf("*");
    }
    printf("\n");
  }
  
  return 0;
}