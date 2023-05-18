#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int num1, int num2);
void swap_addr(int *num1, int *num2);
void changeArray(int *ptr);

int main(void)
{
  // pointer
  // 각 변수에 담긴 수는 각자의 집 비밀번호
  // Ahmed는 101호에, Khim은 102호에, Mathew는 103호에 산다(메모리 공간의 주소).
  int Ahmed = 1011;
  int Khim = 2023;
  int Mathew = 8086;

  printf("Ahmed's Address: %d, Password: %d\n", &Ahmed, Ahmed);
  printf("Khim's Address: %d, Password: %d\n", &Khim, Khim);
  printf("Mathew's Address: %d, Password: %d\n", &Mathew, Mathew);

  // 미션맨의 등장
  // 각 집에 방문하여 문에 적힌 암호를 확인한다.
  int *mission_man; // pointer variable
  mission_man = &Ahmed;
  printf("The address where mission man goes: %d, password: %d\n", mission_man, *mission_man);
  mission_man = &Khim;
  printf("The address where mission man goes: %d, password: %d\n", mission_man, *mission_man);
  mission_man = &Mathew;
  printf("The address where mission man goes: %d, password: %d\n", mission_man, *mission_man);

  mission_man = &Ahmed;
  *mission_man *= 3; // password changed
  printf("The address where mission man change password: %d, changed password: %d\n", mission_man, *mission_man);
  mission_man = &Khim;
  *mission_man *= 2; // password changed
  printf("The address where mission man change password: %d, changed password: %d\n", mission_man, *mission_man);
  mission_man = &Mathew;
  *mission_man /= 2; // password changed
  printf("The address where mission man change password: %d, changed password: %d\n", mission_man, *mission_man);

  // 스파이가 등장
  // 미션맨이 모르게 미션맨이 바꾼 암호에서 2를 빼라!
  int *spy = mission_man;
  spy = &Ahmed;
  *spy -= 2; // password changed
  printf("The address where spy change password: %d, changed password: %d\n", spy, *spy);
  spy = &Khim;
  *spy -= 2; // password changed
  printf("The address where spy change password: %d, changed password: %d\n", spy, *spy);
  spy = &Mathew;
  *spy -= 2; // password changed
  printf("The address where spy change password: %d, changed password: %d\n", spy, *spy);

  // 사회를 어지럽힌 미션맨과 스파이는 어디있나!
  printf("Mission man lives in %d\n", &mission_man);
  printf("Spy lives in %d\n", &spy);


  // with array
  int arr[3] = { 5, 10, 15 };
  int *ptr = arr;

  for (int i = 0; i < 3; i++)
  {
    printf("Array arr[%d]'s value: %d\n", i, arr[i]);
    printf("Pointer ptr[%d]'s value: %d\n", i, ptr[i]);
  }

  ptr[0] = 50;
  ptr[1] = 100;
  ptr[2] = 150;

  for (int i = 0; i < 3; i++)
  {
    printf("Array arr[%d]'s changed value: %d\n", i, arr[i]);
    printf("Pointer ptr[%d]'s changed value: %d\n", i, ptr[i]);
  }

  // 우린 이렇게도 쓸 수 있다.
  for (int i = 0; i < 3; i++)
  {
    // arr == arr 배열의 첫 번째 값의 주소와 동일 == &arr[0]
    printf("Array arr[%d]'s changed value: %d\n", i, *(arr + i));
    printf("Pointer ptr[%d]'s changed value: %d\n", i, *(ptr + i));
  }

  printf("The value of arr: %d\n", arr);
  printf("The address of arr[0]: %d\n", &arr[0]);

  printf("The value of the memory address where the value 'arr' points: %d\n", *arr); // *(arr + 0) 과 같다
  printf("The value of arr[0]: %d\n", *&arr[0]);

  // *& 는 아무것도 작성하지 않은 것과 같다. &는 주소를 가리키며 *는 해당 주소의 값을 가리키기 때문에, 서로 상쇄되어 없어진다.
  printf("The value of arr[0]: %d\n", *&*&*&*&*&*&*&*&*&*&*&*&*&arr[0]);
  printf("The value of arr[0]: %d\n", arr[0]);

  
  // swap value
  int a = 10;
  int b = 20;
  printf("Before swap function applied => a: %d, b: %d\n", a, b);
  printf("variable a address: %d\n", &a);
  printf("variable b address: %d\n", &b);

  swap(a, b);
  printf("After swap function applied => a: %d, b: %d\n", a, b);
  
  // 주소값을 넘겨보자.
  swap_addr(&a, &b);
  printf("After swap_addr function applied => a: %d, b: %d\n", a, b);


  // change array value
  int arr2[3] = { 10, 20, 30 };
  
  changeArray(arr2); // arr2 자체가 이미 주소라서 & 같은 거 붙일 이유가 읎제.
  for (int i = 0; i < 3; i++)
  {
    printf("%d\n", arr2[i]);
  }

  int arr3[3] = { 10, 20, 30 };
  
  changeArray(&arr3[0]); // 왜 인지 알겠쥬?
  for (int i = 0; i < 3; i++)
  {
    printf("%d\n", arr3[i]);
  }

  // scanf에서 &를 사용했던 이유를 알 수 있다.

  return 0;
}

void swap(int num1, int num2)
{
  printf("variable a in swap function address: %d\n", &num1);
  printf("variable b in swap function address: %d\n", &num2);
  int temp = num1;
  num1 = num2;
  num2 = temp;
  printf("In swap function => a: %d, b: %d\n", num1, num2);
}

void swap_addr(int *num1, int *num2) // int *num1; num1 = &a; int *num2; num2 = &b; 이렇게 된 상황이다.
{
  printf("variable a in swap function address: %d\n", &num1); // parameter라서 이들의 스택 내 공간은 그대로!
  printf("variable b in swap function address: %d\n", &num2); // 왜냐하면 swap 함수를 쓰고나서 사라진 그 공간 그대로 들어가 사용되고 있으니까.
  int temp = *num1;
  *num1 = *num2;
  *num2 = temp;
  printf("In swap function => a: %d, b: %d\n", *num1, *num2);
}

void changeArray(int *ptr)
{
  ptr[2] = 50;
}