#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int animalArray[4][5];
char *strAnimal[10];
int checkAnimal[4][5];

void initAnimalArray();
void initAnimalName();

void shuffleAnimal();

int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);

void printAnimals();
void printQuestion();

int foundAll();

int main(void)
{
  // 10 마리의 서로 다른 동물 카드가 두 장이 있다.
  // 사용자로부터 두 개의 입력값을 받아서 같은 동물 찾아서 카드 뒤집기
  // 모든 동물 쌍을 찾으면 게임 종료
  // 총 실패 횟수 알려주기
  srand(time(NULL));

  initAnimalArray();
  initAnimalName();

  shuffleAnimal();

  int failCnt = 0;

  while (1)
  {
    int sel1 = 0;
    int sel2 = 0;

    printAnimals();
    printQuestion();
    printf("select 2 cards that you wnat to turn up.\n");
    scanf("%d %d", &sel1, &sel2);

    if (sel1 == sel2)
      continue;

    int firstSel_x = conv_pos_x(sel1);
    int firstSel_y = conv_pos_y(sel1);
    int secondSel_x = conv_pos_x(sel2);
    int secondSel_y = conv_pos_y(sel2);

    if (
      ( checkAnimal[firstSel_x][firstSel_y] == 0
      &&
      checkAnimal[secondSel_x][secondSel_y] == 0 )
      &&
      (animalArray[firstSel_x][firstSel_y] == animalArray[secondSel_x][secondSel_y])
    )
    {
      printf("\n\nGOOD! We'v found %s!\n\n", strAnimal[animalArray[firstSel_x][firstSel_y]]);
      checkAnimal[firstSel_x][firstSel_y] = 1;
      checkAnimal[secondSel_x][secondSel_y] = 1;
    }
    else
    {
      printf("\n\nWRONG! or already unfolded card(s) included.\n\n");
      printf("%d : %s\n", sel1, strAnimal[animalArray[firstSel_x][firstSel_y]]);
      printf("%d : %s\n", sel2, strAnimal[animalArray[secondSel_x][secondSel_y]]);
      printf("\n\n");

      failCnt++;
    }

    if (foundAll() == 1)
    {
      printf("\n\n Congratulation! all DONE! \n");
      printf("Fail Count: %d\n", failCnt);
      break;
    }
  }

  return 0;
}

void initAnimalArray()
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      animalArray[i][j] = -1;
    }
  }
}

void initAnimalName()
{
  strAnimal[0] = "Monkey";
  strAnimal[1] = "Cat";
  strAnimal[2] = "Elephant";
  strAnimal[3] = "Tiger";
  strAnimal[4] = "Dog";
  strAnimal[5] = "Pig";
  strAnimal[6] = "Lion";
  strAnimal[7] = "Alpaca";
  strAnimal[8] = "Giraffe";
  strAnimal[9] = "Deer";
}

void shuffleAnimal()
{
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      int position = getEmptyPosition();
      int x = conv_pos_x(position);
      int y = conv_pos_y(position);

      animalArray[x][y] = i;
    }
  }
}
int getEmptyPosition()
{
  while (1)
  {
    int randPosition = rand() % 20;

    int x = conv_pos_x(randPosition);
    int y = conv_pos_y(randPosition);

    if (animalArray[x][y] == -1)
    {
      return randPosition;
    }
  }
  
  return 0; // int 반환해야 해서. 큰 의미 없다
}
int conv_pos_x(int x)
{
  return x / 5;
}
int conv_pos_y(int y)
{
  return y % 5;
}

void printAnimals()
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      printf("%8s", strAnimal[animalArray[i][j]]);
    }
    printf("\n");
  }
}
void printQuestion()
{
  printf("\n\n(Problem)\n\n");
  int seq = 0;

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      // 맞췄으면 동물 이름 보여주기
      if (checkAnimal[i][j] != 0)
      {
        printf("%8s", strAnimal[animalArray[i][j]]);
      }
      // 아직 정답을 못 맞췄으면 뒷면이 나와야 한다.
      else
      {
        printf("%8d", seq);
      }
      seq++;
    }
    printf("\n");
  }
}

int foundAll()
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      if (checkAnimal[i][j] == 0)
        return 0;
    }
  }

  return 1;
}