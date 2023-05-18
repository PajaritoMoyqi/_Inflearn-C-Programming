#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
  int i; // O
  
  int arr[5];
  // O O O O O
  // arr[0] arr[1] arr[2] arr[3] arr[4]

  int arr2[2][5];
  // O O O O O // arr[0][0] arr[0][1] arr[0][2] arr[0][3] arr[0][4]
  // O O O O O // arr[1][0] arr[1][1] arr[1][2] arr[1][3] arr[1][4]

  int arr3[3][2][5];
  // O O O O O // arr[0][0][0] arr[0][0][1] arr[0][0][2] arr[0][0][3] arr[0][0][4]
  // O O O O O // arr[0][1][0] arr[0][1][1] arr[0][1][2] arr[0][1][3] arr[0][1][4]

  // O O O O O // arr[1][0][0] arr[1][0][1] arr[1][0][2] arr[1][0][3] arr[1][0][4]
  // O O O O O // arr[1][1][0] arr[1][1][1] arr[1][1][2] arr[1][1][3] arr[1][1][4]

  // O O O O O // arr[2][0][0] arr[2][0][1] arr[2][0][2] arr[2][0][3] arr[2][0][4]
  // O O O O O // arr[2][1][0] arr[2][1][1] arr[2][1][2] arr[2][1][3] arr[2][1][4]

  // declaration
  int arr4[2][5] = {
    { 0, 1, 2, 3, 4 },
    { 0, 1, 2, 3, 4 }
  };
  int arr5[2][3][2] = {
    {
      {0, 1},
      {0, 1},
      {0, 1}
    },
    {
      {0, 1},
      {0, 1},
      {0, 1}
    }
  };

  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      for (int k = 0; k < 2; k++)
      {
        printf("(%d, %d, %d) value is %d\n", i, j, k, arr5[i][j][k]);
      }
    }
  }

  return 0;
}
