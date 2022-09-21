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
	// 과제 floor 완성
	// 1. 각 층, 호에 사는 인원수를 입력받음.
	// 2. 각 층마다 총 인원수 출력
	// 3. 각 층마다 호의 인원수 출력
	// 4. 모든 인원수 출력
	// 
	// 4층이고 3호까지 있는 아파트
	// -> 각원소가 가지는 의미를 해당 층,호에 살고있는 인원수
	int floor[4][3] = { 0 };
	int num_people_floor[4] = {};
	int whole_people_floor = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d층 %d호에 살고 있는 인원은 몇명인가요? : ",i+1,j+1);
			scanf_s("%d", &floor[i][j]);
		}
	}
		
	for (int i = 0; i < 4; i++) // 각 층마다 총 인원수 저장
	{
		for (int j = 0; j < 3; j++)
		{
			num_people_floor[i] += floor[i][j];
		}
	}

	for (int i = 0; i < 4; i++) //	각 층마다 총 인원수 출력
	{
		printf("%d층의 인원 : %d명\n", i + 1, num_people_floor[i]);
	}

	for (int i = 0; i < 4; i++) // 각 층마다 호의 인원수 출력
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d층 %d호 : %d명\n", i + 1, j + 1, floor[i][j]);
		}
	}
	for (int i = 0; i < 4; i++) // 전체 아파트의 사람 계산
	{
		for (int j = 0; j < 3; j++)
		{
			whole_people_floor += floor[i][j];
		}
	}

	printf("이 아파트에는 총 %d명의 사람이 살고 있습니다.\n", whole_people_floor); // 전체 아파트의 사람 출력
}
