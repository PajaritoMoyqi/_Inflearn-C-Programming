#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
  // 아빠는 대머리 게임: 발모제 찾기
  srand(time(NULL));

  int answer;
  int treatment = rand() % 4; // 발모제 선택

  int cntShowBottle = 0; // 보여줄 병의 갯수
  int prevCntShowBottle = 0; // 앞 게임에서 보여준 병의 갯수

  int chance = 3;

  for (int i = 1; i <= chance; i++)
  {
    int bottle[4] = { 0, 0, 0, 0 };
    do {
      cntShowBottle = rand() % 2 + 2;
    } while (cntShowBottle == prevCntShowBottle);
    prevCntShowBottle = cntShowBottle;

    int isincluded = 0; // 발모제가 보여준 병 중 포함되었는가.

    printf("number %d try.\n", i);

    // 병 종류 선택
    for (int j = 0; j < cntShowBottle; j++)
    {
      int randBottle = rand() % 4;

      // 선택되지 않은 병이라면 선택 처리
      if (bottle[randBottle] == 0)
      {
        bottle[randBottle] = 1;
        if (randBottle == treatment)
        {
          isincluded = 1;
        }
      }
      else
      {
        j--;
      }
    }

    // 사용자에게 표시
    for (int k = 0; k < 4; k++)
    {
      if(bottle[k] == 1)
      {
        printf("number %d ", k + 1);
      }
    }
    printf("treatment is applied.\n");

    if (isincluded == 1)
    {
      printf("Success!\n");
    }
    else
    {
      printf("Fail!\n");
    }

    printf("press any key to continue...\n");
    getchar();
  }

  printf("What is real treatment?\n");
  scanf("%d", &answer);

  if (answer == treatment + 1)
  {
    printf("good job!\n");
  }
  else
  {
    printf("Unlucky. Real treatment is number %d treatment.\n", treatment + 1);
  }
  

  return 0;
}