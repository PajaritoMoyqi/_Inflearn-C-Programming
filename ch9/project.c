#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h> // strcmp()
#include <conio.h> // getch()

#define MAX 10000

int main(void)
{
  // 비밀번호 받아서 저장
  // 맞는 경우 일기를 가져와서 보여준다
  // 틀리면 경고 메시지를 표시하고 종료한다
  char line[MAX]; // 파일에서 불러온 내용을 저장
  char contents[MAX]; // 일기장
  char password[20];
  char c; // 비밀번호 입력 시 키값 확인용 (비번 마스킹)
  
  printf("Welcome to Secret Diary.\n");
  printf("Set your password: ");

  int idx = 0;
  while (1)
  {
    c = getch(); // enter를 입력하지 않아도 동작한다. 키 입력시 바로바로 동작
    if (c == 13) // enter
    {
      password[idx] = '\n';
      break;
    }
    else
    {
      printf("*");
      password[idx] = c;
    }
    idx++;
  }

  printf("\n\nchecking password...\n\n");
  if (strcmp(password, "abcd\n") == 0) // 비밀번호 일치한다면,
  {
    printf("You are allowed to come in Secret Diary.\n");
    char *fileName = "./SecretDiary.txt";
    FILE *file = fopen(fileName, "a+b"); // 파일 없으면 생성, 있으면 append

    if (file == NULL)
    {
      printf("fail to load...\n");
      return 1;
    }

    while (fgets(line, MAX, file) != NULL)
    {
      printf("%s", line);
    }

    printf("\n\n Welcome to Secret Diary FILE! If you want exit, enter 'EXIT'.\n\n");

    while (1)
    {
      scanf("%[^\n]", contents); // 개행 문자를 만나기 전까지 다 불러와라
      getchar(); // flush 처리(buffer의 enter 문자를 없앤다는 뜻)

      if (strcmp(contents, "EXIT") == 0)
      {
        printf("Exit Secret Diary.\n");
        break;
      }
      fputs(contents, file);
      fputs("\n", file); // 위에서 enter를 무시했으니 다시!
    }

    fclose(file);
  }
  else
  {
    printf("You're not allowed person! Get out!\n");
  }

  return 0;
}