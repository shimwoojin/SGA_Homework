//20220922_homework.cpp

#include <stdio.h>

void floor();

int main()
{
	floor();

	return 0;
}

void floor()
{
	// ���� floor �ϼ�
	// 1. �� ��, ȣ�� ��� �ο����� �Է¹���.
	// 2. �� ������ �� �ο��� ���
	// 3. �� ������ ȣ�� �ο��� ���
	// 4. ��� �ο��� ���
	// 
	// 4���̰� 3ȣ���� �ִ� ����Ʈ
	// -> �����Ұ� ������ �ǹ̸� �ش� ��,ȣ�� ����ִ� �ο���
	int floor[4][3] = { 0 };
	int num_people_floor[4] = {};
	int whole_people_floor = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d�� %dȣ�� ��� �ִ� �ο��� ����ΰ���? : ",i+1,j+1);
			scanf_s("%d", &floor[i][j]);
		}
	}
		
	for (int i = 0; i < 4; i++) // �� ������ �� �ο��� ����
	{
		for (int j = 0; j < 3; j++)
		{
			num_people_floor[i] += floor[i][j];
		}
	}

	for (int i = 0; i < 4; i++) //	�� ������ �� �ο��� ���
	{
		printf("%d���� �ο� : %d��\n", i + 1, num_people_floor[i]);
	}

	for (int i = 0; i < 4; i++) // �� ������ ȣ�� �ο��� ���
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d�� %dȣ : %d��\n", i + 1, j + 1, floor[i][j]);
		}
	}
	for (int i = 0; i < 4; i++) // �� ������ ȣ�� �ο��� ���
	{
		for (int j = 0; j < 3; j++)
		{
			whole_people_floor += floor[i][j];
		}
	}

	printf("�� ����Ʈ���� �� %d���� ����� ��� �ֽ��ϴ�.\n", whole_people_floor);
}