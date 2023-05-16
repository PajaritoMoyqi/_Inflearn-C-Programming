#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void p(int num);
void function_without_return();
int function_with_return();
void function_without_params();
void function_with_params(int a, int b, int c);
int apple(int total, int eaten);

int add(int inital_num, int other_num);
int sub(int inital_num, int other_num);
int div(int inital_num, int other_num);
int mul(int inital_num, int other_num);

int main(void)
{
  // calculator
  int num = 2;
  printf("number is %d.\n", num);

  num += 3;
  printf("number is %d.\n", num);

  num -= 2;
  printf("number is %d.\n", num);

  num *= 3;
  printf("number is %d.\n", num);

  num /= 3;
  printf("number is %d.\n", num);

  // we need function!
  num = 2;
  p(num);

  num += 3;
  p(num);

  num -= 2;
  p(num);

  num *= 3;
  p(num);

  num /= 3;
  p(num);

  /*
    함수의 형태:

    반환형 함수이름 (전달값)
    {
      함수 내용
    } 
  */

  // 반환값이 없는 함수
  function_without_return();

  // 반환값이 있는 함수
  int ret = function_with_return();
  p(ret);

  // 파라미터가 없는 함수
  function_without_params();

  // 파라미터가 있는 함수
  function_with_params(1, 3, 5);

  // 반환값과 파라미터가 다 있는 함수
  printf("If you %d apples out of %d, there would be %d apples lefted.\n", 2, 5, apple(5, 2));

  // real calculator
  int num2 = 10;
  num2 = add(num2, 10);
  p(num2);
  num2 = sub(num2, 5);
  p(num2);
  num2 = mul(num2, 3);
  p(num2);
  num2 = div(num2, 5);
  p(num2);

  return 0;
}

void p(int num)
{
  printf("number is %d.\n", num);
}
void function_without_return()
{
  printf("this function has no return value.\n");
}
int function_with_return()
{
  printf("this function has return value.\n");
  return 26;
}
void function_without_params()
{
  printf("this function has no parameters.\n");
}
void function_with_params(int a, int b, int c)
{
  printf("this function has parameter(s).\n");
  printf("Values are %d, %d, %d.\n", a, b, c);
}
int apple(int total, int eaten)
{
  printf("this function has both parameters and return value.\n");
  return total - eaten;
}

int add(int inital_num, int other_num)
{
  printf("adding ongoing...\n");
  return inital_num + other_num;
}
int sub(int inital_num, int other_num)
{
  printf("subtracting ongoing...\n");
  return inital_num - other_num;
}
int div(int inital_num, int other_num)
{
  printf("dividing ongoing...\n");
  return inital_num / other_num;
}
int mul(int inital_num, int other_num)
{
  printf("multiplying ongoing...\n");
  return inital_num * other_num;
}