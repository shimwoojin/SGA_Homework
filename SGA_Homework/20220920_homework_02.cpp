#include <stdio.h>

int make_square(int);

int main()
{
	int sq_length = 0;
	printf("����� ���� ���簢���� ũ�⸦ �Է��Ͻÿ� : ");
	scanf_s("%d", &sq_length);
	make_square(sq_length);
	return 0;
}

int make_square(int sq_length)
{
	
	for (int i = 0; i < sq_length; i++)
	{
		for (int j = 0; j < sq_length; j++)
			printf("��");
		printf("\n");
	}
	return sq_length*sq_length;
}
