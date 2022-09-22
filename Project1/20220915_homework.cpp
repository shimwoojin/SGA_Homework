#include <stdio.h>

/*
	1. %c를 띄어쓰지 않았을 때 가끔 안 되는 이유
	- %c를 이용하여 문자를 하나씩 입력받게 되면 입력버퍼에서 차례대로 가져와서 입력하게 되는데
	- 이 때 공백문자나 널 문자가 있게 되면 이것이 입력받은 것으로 처리됨
	- %c 앞에 띄어쓰기를 해주면 버퍼의 이런 값들이 비워지게 되고 새 값을 받을 수 있음.

	(해결방법) -> scanf를 하기 전에 fflush(stdin)을 사용하여 입력버퍼를 비우면 됨
*/

/*
	2. 버퍼 조사
	- 장치와 장치 간의 데이터 전송을 할 때 완충작용을 하기 위한 임시 데이터 저장 공간
	- 키보드 -> 입력버퍼 -> cpu 순으로 입력버퍼에 키보드 입력 값을 모아 전달해줌
*/

/*
	3. 가위바위보 게임 만들기
	- 코드 참조
*/

#define rock 1
#define scissor 2
#define paper 3


int main() {
		// 가위바위보 게임

	int computer_scissor = 2;
	int user_choose;
	printf("========================\n");
	printf("\t가위바위보 게임\n");
	printf("========================\n\n");


	while (1)
	{
		printf("1. 주먹 2. 가위 3. 보 4. 끝내기\n");
		scanf_s("%d", &user_choose);

		switch (user_choose)
		{
		case 1:
			printf("당신은 주먹을 냈습니다.\n");
			printf("컴퓨터는 가위를 냈습니다.\n");
			printf("당신이 이겼습니다.");
			break;
		case 2:
			printf("당신은 가위를 냈습니다.\n");
			printf("컴퓨터는 가위를 냈습니다.\n");
			printf("비겼습니다.");
			break;
		case 3:
			printf("당신은 보를 냈습니다.\n");
			printf("컴퓨터는 가위를 냈습니다.\n");
			printf("당신이 졌습니다.");
			break;
		case 4:
			break;
		default:
			printf("잘못된 입력입니다.");
			break;
		}

		if (user_choose == 4)
			break;

	}


	return 0;
}
