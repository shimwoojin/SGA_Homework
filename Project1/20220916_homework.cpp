#define rock '1'
#define scissor '2'
#define paper '3'
#define finish '4'

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
int main() {
	// ���������� ���� ���׷��̵�
	
	int user_choose = -1, computer_choose = -1;
	int user_win = 0, computer_win = 0;
	printf("========================\n");
	printf("\t���������� ����\n");
	printf("========================\n\n");

	srand(time(NULL));

	while (1)
	{
		printf("1. �ָ� 2. ���� 3. �� 4. ������\n\n");
		user_choose = _getch();
		computer_choose = rand() % 3 + 1;
		switch (user_choose)
		{
		case rock:
			printf("����� �ָ��� �½��ϴ�.\n");
			if (computer_choose == 1)
			{
				printf("��ǻ�ʹ� �ָ��� �½��ϴ�.\n");
				printf("�����ϴ�.\n");
				break;
			}
			else if (computer_choose == 2)
			{
				printf("��ǻ�ʹ� ������ �½��ϴ�.\n");
				printf("����� �̰���ϴ�.\n");
				user_win++;
				break;
			}
			else if (computer_choose == 3)
			{
				printf("��ǻ�ʹ� ���� �½��ϴ�.\n");
				printf("����� �����ϴ�.\n");
				computer_win++;
				break;
			}
			
		case scissor:
			printf("����� ������ �½��ϴ�.\n");
			if (computer_choose == 1)
			{
				printf("��ǻ�ʹ� �ָ��� �½��ϴ�.\n");
				printf("����� �����ϴ�.\n");
				computer_win++;
				break;
			}
			else if (computer_choose == 2)
			{
				printf("��ǻ�ʹ� ������ �½��ϴ�.\n");
				printf("�����ϴ�.\n");
				break;
			}
			else if (computer_choose == 3)
			{
				printf("��ǻ�ʹ� ���� �½��ϴ�.\n");
				printf("����� �̰���ϴ�.\n");
				user_win++;
				break;
			}
			
		case paper:
			printf("����� ���� �½��ϴ�.\n");
			if (computer_choose == 1)
			{
				printf("��ǻ�ʹ� �ָ��� �½��ϴ�.\n");
				printf("����� �̰���ϴ�.\n");
				user_win++;
				break;
			}
			else if (computer_choose == 2)
			{
				printf("��ǻ�ʹ� ������ �½��ϴ�.\n");
				printf("����� �����ϴ�.\n");
				computer_win++;
				break;
			}
			else if (computer_choose == 3)
			{
				printf("��ǻ�ʹ� ���� �½��ϴ�.\n");
				printf("�����ϴ�.\n");
				break;
			}
		case finish:
			break;
		default:
			printf("�߸��� �Է��Դϴ�.");
			break;
		}

		if (user_choose == 4)
			break;

		if (user_win == 3)
		{
			printf("����� �¸��Դϴ�. �����մϴ�.\n");
			break;
		}
		else if (computer_win == 3)
		{
			printf("\n��ǻ���� �¸��Դϴ�. �й��ϼ���.\n");
			break;

		}
		else
		{
			printf("\n������ ���� ������ �ʾҽ��ϴ�.\n");
			printf("\n���� �� : %d, ��ǻ�� �� : %d\n\n", user_win, computer_win);
		}
			
	}


	return 0;
}