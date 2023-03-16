#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void initboard(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col;j++) {
			board[i][j] = ' ';
		}
	}
}

// 

void printboard(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row;i++) {
		for (j = 0; j < col;j++) {
			printf(" %c ",board[i][j]);
			if (j < col - 1){
                printf("|");
			}
		}
		printf("\n");
		if (i<row-1) {
             for (j = 0; j < col;j++) {
				 printf("---");
				 if (j < col - 1) {
					 printf("|");
				 }
		     }
		}
		printf("\n");
		
	}
}



void Player(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	
	printf("玩家走：\n");
	while (1) {
		printf("请输入要下的坐标");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (board[x-1][y-1] == ' ') {
				board[x-1][y-1] = '*';
				break;
			}
			else {
				printf("该坐标已被占用\n");
			}
		}
		else printf("该坐标错误\n");
		
	}

}

void Computer(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走：\n");
	while (1) {
      x = rand() % row;
	  y = rand() % col;
	 if (board[x][y] == ' ') {
		  board[x][y] = '#';
		  break;
	 }
	}
}

int Isdogfall(char board[ROW][COL],int row,int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row;i++) {
		for (j = 0; j < col; j++) {
			if (board[i][i] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}

char  IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row;i++) {
		if (board[1][i] == board[2][i] && board[2][i] == board[0][i] && board[1][i] != ' ') {
			return board[1][i];
		}
	}
	for (j=0;j<col;j++)
	{
		if (board[j][1] == board[j][2]&& board[j][2] == board[j][0] && board[j][1] != ' ')
		{
			return board[j][1];
		}
	}

	if (board[1][1] == board[2][2] && board[2][2] == board[0][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1]&& board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//判断是否平局
	if (1 == Isdogfall(board,ROW,COL)) {
		return 'Q';
	}
	return 'C';
}
