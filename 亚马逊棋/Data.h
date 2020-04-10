#pragma once//��֤ͷ�ļ�ֻ������һ��

//�궨��
#define BLACKCHESS 2
#define WHITECHESS 1
#define BARRIER -1//�ϰ�
#define EMPTY 0
#define INFI 9999 //�����

extern int Board[12][12];//ȫ�ֱ���
extern int bufa[3][2];//�洢ÿ���Ĳ��������ڻ���
//extern int mode;//��Ϸģʽѡ��

typedef struct Pos//λ������ṹ��
{
	int x;
	int y;
}CHESSPOS;

typedef struct Move  //�����ṹ��
{
	int ChessID;//���巽
	double score;//�����÷�
	CHESSPOS From;
	CHESSPOS To;
	CHESSPOS Bar;
}CHESSMOVE;

////////////��������////////////////
void Show(int Board[12][12]);
void InitBoard(int Board[12][12]);
int Move(int firsthand, int Board[12][12], int bufa[3][2]);
int LegalMove(int x1, int y1, int x2, int y2, int Board[12][12]);
int JudgeWin(int Board[12][12]);
int Mode();