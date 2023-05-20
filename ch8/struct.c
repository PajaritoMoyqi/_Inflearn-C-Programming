#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct GameInfo
{
  char *name;
  int year;
  int price;
  char *company;
  struct GameInfo *friendGame;
};

typedef struct GameInformation { // 이름 지울 수도 있다
  char *name;
  int year;
  int price;
  char *company;
  struct GameInfo *friendGame;
} G_I;

int main(void)
{
  char *name = "Great Revolution";
  int year = 2017;
  int price = 100;
  char *company = "Your House";

  char *name2 = "Great Battle";
  int year2 = 2017;
  int price2 = 200;
  char *company2 = "My House";

  // 너무 지저분한데? struct를 쓰자!
  struct GameInfo gameinfo1;
  gameinfo1.name = "Great Revolution";
  gameinfo1.year = 2017;
  gameinfo1.price = 100;
  gameinfo1.company = "Your House";

  printf("%s, %d, $%d, %s\n", gameinfo1.name, gameinfo1.year, gameinfo1.price, gameinfo1.company);
  
  struct GameInfo gameinfo2 = {"Great Battle", 2017, 200, "My House"};
  printf("%s, %d, $%d, %s\n", gameinfo2.name, gameinfo2.year, gameinfo2.price, gameinfo2.company);

  // 구조체 배열
  struct GameInfo gameArray[2] = {
    {"Great Revolution", 2017, 100, "Your House"},
    {"Great Battle", 2017, 200, "My House"}
  };

  // 구조체 포인터
  struct GameInfo *gameptr;
  gameptr = &gameinfo1;
  printf("%s, %d, $%d, %s\n", (*gameptr).name, (*gameptr).year, (*gameptr).price, (*gameptr).company);
  
  // 위에건 불편한데?
  printf("%s, %d, $%d, %s\n", gameptr->name, gameptr->year, gameptr->price, gameptr->company);

  // 연관업체 게임 소개(구조체 안의 구조체)
  gameinfo1.friendGame = &gameinfo2;
  printf("%s, %d, $%d, %s\n", gameinfo1.friendGame->name, gameinfo1.friendGame->year, gameinfo1.friendGame->price, gameinfo1.friendGame->company);

  // typedef
  int i = 1;
  typedef int inttttt;
  typedef float floattttt;
  inttttt a = 1;
  floattttt b = 1.11;
  printf("int: %d, float: %d\n", a, b);

  typedef struct GameInfo GI;
  GI game1;
  game1.name = "Hola World";
  game1.year = 2020;
  game1.price = 400;
  game1.company = "Your House";

  G_I game2;
  game2.name = "Breaking";
  game2.year = 2023;
  game2.price = 50;
  game2.company = "My House";

  printf("%s, %d, $%d, %s\n", game1.name, game1.year, game1.price, game1.company);
  printf("%s, %d, $%d, %s\n", game2.name, game2.year, game2.price, game2.company);

  return 0;
}
