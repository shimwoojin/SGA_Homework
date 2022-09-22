#include <stdio.h>

int main() {

	/*
		과제1
		중첩 for문 사용하여 구구단 출력하기
		1. 2단 ~9단까지 출력
	*/

	for (int i = 2; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			printf("%d x %d = %d\n", i, j, i * j);
		}
		printf("\n\n");
	}

	/*
		과제2
		별그리기(중첩 for문)
	*/

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - i; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i <= j)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}

	/*
		과제3
		1. for문을 하나만 사용한다.
		2. 사용자로부터 정수를 입력받아 정수값에 맞는 정사각형을 출력한다.
	*/

	printf("만들고 싶은 정사각형의 길이를 입력하시오 : ");
	int length_square = 0;
	int _enter = 0;
	scanf_s("%d", &length_square);
	while (1)
	{

		for (int i = 0; i < length_square; i++)
		{
			printf("*");
		}
		printf("\n");
		_enter++;
		if (_enter == length_square)
			break;
	}

	return 0;
}
