#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
  // array
  int subway_array[3];
  subway_array[0] = 30;
  subway_array[1] = 40;
  subway_array[2] = 50;

  for (int i = 0; i < 3; i++)
  {
    printf("There are %d people riding in subway car %d.\n", subway_array[i], i+1);
  }

  int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  for (int i = 0; i < 10; i++)
  {
    printf("%d\n", arr[i]);
  }

  // not initialized array
  int arr2[10];
  for (int i = 0; i < 10; i++)
  {
    printf("%d\n", arr2[i]); // 더미값 출력(컴퓨터마다 다른 값이 나옴)
  }

  // 아래와 같이는 실행되지 않음
  /*
    int size = 10;
    int arr3[size];
    // 배열 크기는 항상 상수로 선언해야 한다.
  */
  const int size = 10;
  int arr4[size];
  for (int i = 0; i < 10; i++)
  {
    printf("%d\n", arr4[i]);
  }

  int arr5[10] = { 1, 2 }; // 일부만 선언하면 그 뒤부터는 다 0이 들어간다.
  for (int i = 0; i < 10; i++)
  {
    printf("%d\n", arr5[i]);
  }

  int arr6[] = { 1, 2 }; // arr6[2]
  for (int i = 0; i < 2; i++)
  {
    printf("%d\n", arr6[i]);
  }

  float arr7[5] = { 1.0f, 2.0f, 3.0f };
  for (int i = 0; i < 5; i++)
  {
    printf("%.2f\n", arr7[i]);
  }

  return 0;
}