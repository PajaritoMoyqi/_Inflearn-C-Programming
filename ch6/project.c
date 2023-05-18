#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int level;
int fishArray[6];
int *cursor;

void initData();
void printFishes();
void decreseWater(long elapsedTime);
int checkFishAlive();

int main(void)
{
  // 물고기 6마리가 각각의 어항에 살고 있다.
  // 물이 다 증발하기 전에 클릭을 눌러서 어항에 물을 주세요.
  long startTime = 0;
  long totalElapsedTime = 0;
  long prevElapsedTime = 0; // 직전 경과 시간

  int num; // 몇 번 어항에 물을 주는가 - 사용자 입력
  initData();  

  cursor = fishArray; // 배열처럼 curso pointer 변수를 쓸 수 있다

  startTime = clock(); // 현재 시간을 millisecond 단위로 반환한다
  while (1)
  {
    printFishes();
    printf("what fishbowl you gonna put more water?\n");
    scanf("%d", &num);

    // input check
    if (num < 1 || num > 6)
    {
      printf("Input value is wrong...\n");
      continue;
    }

    // 총 경과시간
    totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
    printf("total elapsed time: &ld sec\n", totalElapsedTime);

    // 직전에 물을 준 시간
    prevElapsedTime = totalElapsedTime - prevElapsedTime;
    printf("most recently elapsed time: %ld sec\n", prevElapsedTime);

    // 어항 물 증발
    decreseWater(prevElapsedTime);

    // 사용자의 입력으로 어항에 물을 줌
    // 어항의 물이 0이면 물을 주지 않는다
    if (cursor[num - 1] < 0)
    {
      printf("number %d fish already dead...\n", num);
    }
    // 어항의 물을 주고 결과는 100을 넘을 수 없다.
    else if (cursor[num - 1] + 1 <= 100)
    {
      printf("put water into the number %d fishbowl.\n", num);
      cursor[num - 1] += 1;
    }

    // level up 여부 결정 (20초에 한 번씩 level up)
    if (totalElapsedTime / 20 > level - 1)
    {
      level++;
      printf("Level up! Now the environment level is %d.\n", level);
      if (level == 5)
      {
        printf("MAX LEVEL. GAME DONE.\n");
        exit(0);
      }
    }

    // 물고기가 죽었는지 살았는지 확인하기
    if (checkFishAlive() == 0)
    {
      printf("All fishes are gone...\n");
      exit(0);
    }
    else
    {
      printf("Still Alive!\n");
    }

    prevElapsedTime = totalElapsedTime; // 다음 루프의 계산을 위해
  }

  return 0;
}

void initData()
{
  level = 1;
  for (int i = 0; i < 6; i++)
  {
    fishArray[i] = 100; // 어항의 최대 물높이
  }
}

void printFishes()
{
  printf("number %3d number %3d number %3d number %3d number %3d number %3d\n", 1, 2, 3, 4, 5, 6);
  for (int i = 0; i < 6; i++)
  {
    printf("    %4d    ", fishArray[i]);
  }
  printf("\n\n");
}

void decreseWater(long elapsedTime)
{
  for (int i = 0; i < 6; i++)
  {
    fishArray[i] -= (level * 3 * (int)elapsedTime);
    if (fishArray[i] < 0)
    {
      fishArray[i] = 0;
    }
  }
}

int checkFishAlive()
{
  for (int i = 0; i < 6; i++)
  {
    if (fishArray[i] > 0)
    {
      return 1;
    }
  }
  return 0;
}