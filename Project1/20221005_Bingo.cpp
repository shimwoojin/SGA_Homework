// Bingo.cpp

/*
	빙고판
	빙고판 크기
	승리 조건(빙고 횟수)
	// 빙고판 세팅
	- 1~25 순서대로 값을 2차원 배열에 넣어줌
	- 임의의 인덱스 값을 2개 받아서 서로 스왑해줌
	// 빙고 번호 입력
	- 빙고 번호를 입력받음
	- 빙고판에서 받은 번호를 찾아 체크해줌
	//빙고 체크
	//승리 조건 체크
*/
#include "20221005_Bingo.h"



int main()
{
	//==================================================
	//게임 세팅
	//==================================================
	int board[BINGO_SIZE][BINGO_SIZE] = {}; //빙고 보드판
	int bingo_count = 0;
	int prev_bing_count = 0;
	Make_ShuF_Board(board);

	//===========================================
	//메인 게임 
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
			printf("승리!\n");
			break;
		}

	} //while
	return 0;
}
