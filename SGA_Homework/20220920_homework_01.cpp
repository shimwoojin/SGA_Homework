#include <stdio.h>
#include <math.h>

int _pow(int, int);
int get_int();
int main()
{
	int x = get_int();
	int y = get_int();
	
	printf("%d�� %d���� = %d",x,y,_pow(x,y));


	return 0;
}

int _pow(int x, int y)
{
	return pow(x, y);
}

int get_int()
{
	int num;
	printf("���ڸ� �Է��� �ּ��� : ");
	scanf_s("%d", &num);

	return num;
}