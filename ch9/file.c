#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 10000

int main(void)
{
  // fputs 문자열
  char line[MAX];
  FILE *file = fopen("./test.txt", "wb");
  if (file == NULL)
  {
    printf("fail to load file...");
    return 1;
  }
  
  fputs("Hola Mundo.\n", file);
  fputs("Bye bye.\n", file);

  fclose(file); // 저장 후 종료

  // fgets
  FILE *file_read = fopen("./test.txt", "rb");
  if (file_read == NULL)
  {
    printf("fail to load file...");
    return 1;
  }

  while (fgets(line, MAX, file_read) != NULL)
  {
    printf("%s", line);
  }
  fclose(file_read);

  // fprintf 문자열이 아니라 포맷에 맞춰서 입력하고 싶을 때 쓴다
  int num[6] = { 0, 0, 0, 0, 0, 0 };
  int bonus = 0;
  char str1[MAX];
  char str2[MAX];

  FILE *file_lotto = fopen("./lotto.txt", "wb");
  if (file_lotto == NULL)
  {
    printf("fail to load file...");
    return 1;
  }

  fprintf(file_lotto, "%s %d %d %d %d %d %d\n", "number: ", 1, 2, 3, 4, 5, 6);
  fprintf(file_lotto, "%s %d\n", "bonus: ", 7);

  fclose(file_lotto);
  
  // fscanf
  FILE *file_lotto_read = fopen("./lotto.txt", "rb");
  if (file_lotto_read == NULL)
  {
    printf("fail to load file...");
    return 1;
  }

  fscanf(file_lotto_read, "%s %d %d %d %d %d %d", str1, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
  printf("%s %d %d %d %d %d %d\n", str1, num[0], num[1], num[2], num[3], num[4], num[5]);
  fscanf(file_lotto_read, "%s %d\n", str2, &bonus);
  printf("%s %d", str2, bonus);

  fclose(file_lotto_read);

  return 0;
}