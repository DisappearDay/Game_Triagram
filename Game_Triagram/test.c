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
	//���̴�С
	char board[ROW][COL] = { 0 };
	//��ʼ������
	initboard(board,ROW,COL);
	//��ӡ����
	printboard(board,ROW,COL);
	//����
	while (1) {
		//�������
		Player(board, ROW, COL);
		printboard(board, ROW, COL);
		// ���Ӯ
		reg = IsWin(board, ROW, COL);
		if (reg != 'C') {
			break;
		}
		//��������
		Computer(board, ROW, COL);
		printboard(board, ROW, COL);
		//����Ӯ
		reg = IsWin(board, ROW, COL);
		if (reg != 'C') {
			break;
		}
	}
	if (reg == '*') {
		printf("���Ӯ��\n");
	}
	else if (reg=='#') {
		printf("����Ӯ��\n");
	}
	else printf("ƽ�֣�\n");
		

}

void test() {
	srand((unsigned int)time(NULL));
	int opt = 0;
	int a = 0;
	do
	{
		menu();
		printf("��������ѡ�� 1|0��>:");
		
	    scanf(" %d", &opt);
		fflush(stdin);
		switch (opt)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (opt);

}

int main() {

	test();

	return 0;
}




