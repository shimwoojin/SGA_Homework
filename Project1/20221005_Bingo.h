#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#define BINGO_SIZE 5
#define COMPLETE 5
#define CHECK_NUMBER 0

int Make_ShuF_Board(int board[BINGO_SIZE][BINGO_SIZE]);
void PrintBoard(int board[BINGO_SIZE][BINGO_SIZE]);
int sel_number();
void check_num(int board[BINGO_SIZE][BINGO_SIZE], int sel_number);
int check_bingo(int board[BINGO_SIZE][BINGO_SIZE]);


int Make_ShuF_Board(int board[BINGO_SIZE][BINGO_SIZE]) 
{
	srand(time(NULL));

	int num = 0;
	for (int y = 0; y < BINGO_SIZE; y++)
		for (int x = 0; x < BINGO_SIZE; x++)
			board[y][x] = ++num;

	for (int i = 0; i < 200; i++)
	{
		int a = rand() % BINGO_SIZE;
		int b = rand() % BINGO_SIZE;
		int c = rand() % BINGO_SIZE;
		int d = rand() % BINGO_SIZE;

		int temp = board[a][b];
		board[a][b] = board[c][d];
		board[c][d] = temp;
	}

	return 0;
}

void PrintBoard(int  board[BINGO_SIZE][BINGO_SIZE])
{
	for (int y = 0; y < BINGO_SIZE; y++)

	{
		for (int x = 0; x < BINGO_SIZE; x++)
		{
			if (board[y][x] == CHECK_NUMBER)
				printf("%2c\t", '#');
			else
				printf("%2d\t", board[y][x]);
		}
		printf("\n");
	}
}

int check_bingo(int  board[BINGO_SIZE][BINGO_SIZE])
{
	//������ ���� üũ
	int prev_bing_count = 0;
	int bingo_count = 0;
	//������ üũ
	for (int y = 0; y < BINGO_SIZE; y++)

	{
		bool check = true;
		for (int x = 1; x < BINGO_SIZE; x++)
			check = check && board[y][0] == board[y][x];
		if (check == true) bingo_count++;

	}

	//������ üũ
	for (int x = 0; x < BINGO_SIZE; x++)

	{
		bool check = true;
		for (int y = 1; y < BINGO_SIZE; y++)
			check = check && board[0][x] == board[y][x];
		if (check == true) bingo_count++;

	}

	//�밢�� \ üũ
	{
		bool check = true;
		for (int index = 1; index < BINGO_SIZE; index++)
			check = check && board[0][0] == board[index][index];

		if (check == true)bingo_count++;
	}

	//�밢�� / üũ
	{
		bool check = true;
		int y = BINGO_SIZE - 1;
		int x = 0;
		for (int index = 0; index < BINGO_SIZE; index++)
			check = check && board[y--][x++] == CHECK_NUMBER;

		if (check == true)bingo_count++;
	}

	//���� ���� üũ
	if (prev_bing_count < bingo_count)
	{
		printf("%d�� ����!\n", bingo_count);
		prev_bing_count = bingo_count;

	}

	return bingo_count;

}

inline int sel_number()
{
	int sel_number = 0; //����ڰ� ������ ��ȣ
	//�Է�
	do
	{
		printf("�Է� : ");
		scanf_s("%d", &sel_number);
	} while (sel_number<1 || sel_number>pow(BINGO_SIZE, 2));

	return sel_number;
}

void check_num(int board[BINGO_SIZE][BINGO_SIZE], int sel_number)
{
	//�Է¹��� ���� �����ǿ� üũ
	for (int y = 0; y < BINGO_SIZE; y++)
	{
		for (int x = 0; x < BINGO_SIZE; x++)
		{
			if (board[y][x] == sel_number) board[y][x] = CHECK_NUMBER;
		}
	}

}