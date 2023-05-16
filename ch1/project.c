#define _CRT_SECURE_NO_WARNINGS // 코드의 최상단에 해당 코드를 정의해두면 scanf 오류가 나지 않는다. scanf_s(강의에서 사용)보다는 이 방법이 더 나음(컴파일 문제).
#include <stdio.h>

int main(void)
{
  // 경찰관의 조서 작성 프로젝트
  // 이름, 나이, 몸무게, 키, 범죄명

  char name[256];
  printf("What's your name, f*****g i***t.");
  scanf("%s", name, sizeof(name));

  int fakeAge, realAge;
  printf("Then, age?");
  scanf("%d", &fakeAge);
  printf("You lier. Tell your real age, you, the i****e.");
  scanf("%d", &realAge);

  float weight;
  printf("How much do you weigh you s****d b*****d?");
  scanf("%f", &weight);

  double height;
  printf("How tall?");
  scanf("%lf", &height);

  char reason[256];
  printf("Last question. What did you do wrong?");
  scanf("%s", reason, sizeof(reason));

  printf("\n\n--- Suspect Info ---\n\n");
  printf("Name: %s\nAge: %d\nWeight: %.2f\nHeight: %.2lf\nReason: %s\n", name, realAge, weight, height, reason);

  return 0;
}