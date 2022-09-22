#define rock '1'
#define scissor '2'
#define paper '3'
#define finish '4'

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
int main() {
	// 가위바위보 게임 업그레이드
	
	int user_choose = -1, computer_choose = -1;
	int user_win = 0, computer_win = 0;
	printf("========================\n");
	printf("\t가위바위보 게임\n");
	printf("========================\n\n");

	srand(time(NULL));

	while (1)
	{
		printf("1. 주먹 2. 가위 3. 보 4. 끝내기\n\n");
		user_choose = _getch();
		computer_choose = rand() % 3 + 1;
		switch (user_choose)
		{
		case rock:
			printf("당신은 주먹을 냈습니다.\n");
			if (computer_choose == 1)
			{
				printf("컴퓨터는 주먹을 냈습니다.\n");
				printf("비겼습니다.\n");
				break;
			}
			else if (computer_choose == 2)
			{
				printf("컴퓨터는 가위를 냈습니다.\n");
				printf("당신이 이겼습니다.\n");
				user_win++;
				break;
			}
			else if (computer_choose == 3)
			{
				printf("컴퓨터는 보를 냈습니다.\n");
				printf("당신이 졌습니다.\n");
				computer_win++;
				break;
			}
			
		case scissor:
			printf("당신은 가위를 냈습니다.\n");
			if (computer_choose == 1)
			{
				printf("컴퓨터는 주먹을 냈습니다.\n");
				printf("당신이 졌습니다.\n");
				computer_win++;
				break;
			}
			else if (computer_choose == 2)
			{
				printf("컴퓨터는 가위를 냈습니다.\n");
				printf("비겼습니다.\n");
				break;
			}
			else if (computer_choose == 3)
			{
				printf("컴퓨터는 보를 냈습니다.\n");
				printf("당신이 이겼습니다.\n");
				user_win++;
				break;
			}
			
		case paper:
			printf("당신은 보를 냈습니다.\n");
			if (computer_choose == 1)
			{
				printf("컴퓨터는 주먹을 냈습니다.\n");
				printf("당신이 이겼습니다.\n");
				user_win++;
				break;
			}
			else if (computer_choose == 2)
			{
				printf("컴퓨터는 가위를 냈습니다.\n");
				printf("당신이 졌습니다.\n");
				computer_win++;
				break;
			}
			else if (computer_choose == 3)
			{
				printf("컴퓨터는 보를 냈습니다.\n");
				printf("비겼습니다.\n");
				break;
			}
		case finish:
			break;
		default:
			printf("잘못된 입력입니다.");
			break;
		}

		if (user_choose == 4)
			break;

		if (user_win == 3)
		{
			printf("당신의 승리입니다. 축하합니다.\n");
			break;
		}
		else if (computer_win == 3)
		{
			printf("\n컴퓨터의 승리입니다. 분발하세요.\n");
			break;

		}
		else
		{
			printf("\n게임이 아직 끝나지 않았습니다.\n");
			printf("\n유저 승 : %d, 컴퓨터 승 : %d\n\n", user_win, computer_win);
		}
			
	}


	return 0;
}