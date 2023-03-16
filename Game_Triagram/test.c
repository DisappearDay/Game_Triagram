#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
#include <stdio.h>

void menu() {
	printf("************************************\n");
	printf("******  1. PLAY     0. EXIT  *******\n");
	printf("************************************\n");
}

void game() {

	char reg = 0;
	//棋盘大小
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	initboard(board,ROW,COL);
	//打印棋盘
	printboard(board,ROW,COL);
	//下棋
	while (1) {
		//玩家下棋
		Player(board, ROW, COL);
		printboard(board, ROW, COL);
		// 玩家赢
		reg = IsWin(board, ROW, COL);
		if (reg != 'C') {
			break;
		}
		//电脑下棋
		Computer(board, ROW, COL);
		printboard(board, ROW, COL);
		//电脑赢
		reg = IsWin(board, ROW, COL);
		if (reg != 'C') {
			break;
		}
	}
	if (reg == '*') {
		printf("玩家赢！\n");
	}
	else if (reg=='#') {
		printf("电脑赢！\n");
	}
	else printf("平局！\n");
		

}

void test() {
	srand((unsigned int)time(NULL));
	int opt = 0;
	int a = 0;
	do
	{
		menu();
		printf("输入您的选择 1|0—>:");
		
	    scanf(" %d", &opt);
		fflush(stdin);
		switch (opt)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (opt);

}

int main() {

	test();

	return 0;
}




