#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2);
void success();
void fail();

int main(void)
{
  // 5개의 문이 있고, 각 문마다 점점 어려운 수식 퀴즈가 출제된다 (랜덤 정수)
  // 맞히면 다음 문으로 통과, 틀리면 실패

  srand(time(NULL));
  int count = 0;
  for (int i = 1; i <= 5; i++)
  {
    int num1 = getRandomNumber(i);
    int num2 = getRandomNumber(i);
    showQuestion(i, num1, num2);

    int answer;
    scanf("%d", &answer);

    if (answer == -1)
    {
      printf("program turned off.\n");
      exit(0); // 바로 모든 프로그램 종료
    }
    else if (answer == num1*num2)
    {
      success();
      count++;
    }
    else 
    {
      fail();
    }
  }

  printf("you got the answer of %d questions out of 5.\n", count);

  return 0;
}

int getRandomNumber(int level)
{
  return rand() % (level * 7) + 1;
}
void showQuestion(int level, int num1, int num2)
{
  printf("\n\n number %d. password question\n\n", level);
  printf("\n\t%d X %d = ?\n\n", num1, num2);
  printf("insert password >> \n");
}
void success()
{
  printf("GOOD!\n");
}
void fail()
{
  printf("YOU WRONG, SIR...\n");
}