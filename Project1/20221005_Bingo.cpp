// Bingo.cpp

/*
	������
	������ ũ��
	�¸� ����(���� Ƚ��)
	// ������ ����
	- 1~25 ������� ���� 2���� �迭�� �־���
	- ������ �ε��� ���� 2�� �޾Ƽ� ���� ��������
	// ���� ��ȣ �Է�
	- ���� ��ȣ�� �Է¹���
	- �����ǿ��� ���� ��ȣ�� ã�� üũ����
	//���� üũ
	//�¸� ���� üũ
*/
#include "20221005_Bingo.h"



int main()
{
	//==================================================
	//���� ����
	//==================================================
	int board[BINGO_SIZE][BINGO_SIZE] = {}; //���� ������
	int bingo_count = 0;
	int prev_bing_count = 0;
	Make_ShuF_Board(board);

	//===========================================
	//���� ���� 
	//===========================================

	while (true)
	{

		PrintBoard(board);
		int sel_num = sel_number();
		system("cls");
		check_num(board, sel_num);
		bingo_count = check_bingo(board);

		if (bingo_count >= COMPLETE)
		{
			printf("�¸�!\n");
			break;
		}

	} //while
	return 0;
}
