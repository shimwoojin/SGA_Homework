#include <stdio.h>

int main() {

	/*
		����1
		��ø for�� ����Ͽ� ������ ����ϱ�
		1. 2�� ~9�ܱ��� ���
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
		����2
		���׸���(��ø for��)
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
		����3
		1. for���� �ϳ��� ����Ѵ�.
		2. ����ڷκ��� ������ �Է¹޾� �������� �´� ���簢���� ����Ѵ�.
	*/

	printf("����� ���� ���簢���� ���̸� �Է��Ͻÿ� : ");
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