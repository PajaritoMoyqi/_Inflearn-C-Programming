#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
  char *name;
  int age;
  char *character;
  int level;
} CAT;

int collection[5] = { 0, 0, 0, 0, 0 };
CAT cats[5]; // 전체 고양이 리스트

void initCats();
void printCat(int selected);
int checkCollection();

int main(void)
{
  // 5마리의 고양이가 있고
  // 랜덤으로 고양이를 뽑는데(중복 가능)
  // 모든 고양이를 수집하면 되는 게임!
  srand(time(NULL));

  initCats();

  while (1)
  {
    printf("What is your choice?\n");
    getchar();

    int selected = rand() % 5;
    printCat(selected);

    collection[selected] = 1;

    int collectAll = checkCollection();
    if (collectAll)
    {
      break;
    }
  }

  return 0;
}

void initCats()
{
  cats[0].name = "Lapu";
  cats[0].age = 5;
  cats[0].character = "calm";
  cats[0].level = 1;

  cats[1].name = "Cropiano";
  cats[1].age = 2;
  cats[1].character = "fierce";
  cats[1].level = 2;

  cats[2].name = "Abdahab";
  cats[2].age = 1;
  cats[2].character = "sleepy";
  cats[2].level = 3;

  cats[3].name = "Coco";
  cats[3].age = 5;
  cats[3].character = "noisy";
  cats[3].level = 4;

  cats[4].name = "Ponti";
  cats[4].age = 6;
  cats[4].character = "hungry";
  cats[4].level = 5;
}

void printCat(int selected)
{
  printf("name: %s\n", cats[selected].name);
  printf("age: %d\n", cats[selected].age);
  printf("character: %s\n", cats[selected].character);
  printf("level: ");
  for (int i = 0; i < cats[selected].level; i++)
  {
    printf("%s", "*");
  }
  printf("\n\n");
}

int checkCollection()
{
  int collectAll = 1;

  printf("you have ");
  for (int i = 0; i < 5; i++)
  {
    if (collection[i] == 0)
    {
      printf("%10s ", "empty box");
      collectAll = 0;
    }
    else
    {
      printf("%10s ", cats[i].name);
    }
  }
  printf("\n\n");

  if (collectAll)
  {
    printf("Congratulation!!!!\n");
  }

  return collectAll;
}