#pragma once
#include "stdafx.h"
#include <queue>
#include <stack>
#include <stdlib.h> 
#define Red 1
#define Blue -1

using namespace std;

struct Loc
{
	int x;
	int y;
	inline void Set(int x, int y);
};

struct MovePiece
{
	Loc loc;
	int piece;
};

struct Move_Recording						//�����ƶ���Ϣ��¼
{
	Loc end_move_piece;						//�յ�
	Loc start_move_piece;					//���
	int covered_piece;						//�����ǵ���
	void Set(Loc start_move_piece, Loc end_move_piece, int covered_piece)
	{
		Move_Recording::start_move_piece = start_move_piece;
		Move_Recording::end_move_piece = end_move_piece;
		Move_Recording::covered_piece = covered_piece;
	}
};


class Board
{

public:
	Board(int arr[5][5]);								 //���캯��
	void show();										 //չʾ��ǰ����
	Loc GetPiece(int piece);							 //�õ�����λ��
	int GetPiece(Loc loc);								 //�õ���λ�õ�����ֵ
	inline int GetPieceFaction(int piece);				 //�ж�������Ӫ
	inline bool GetPieceLegality(Loc ploc);				 //�ж����ӺϷ���
	inline bool IsAlive(int piece);						 //������Ӵ��״̬
	int GetStep();										 //��õ�ǰִ�в���
	bool Is_Waning_Zone(Loc loc);						 //�ж��Ƿ�Ϊ���������룩
	int GetAllMoves(MovePiece* Moves, int Piece);		 //������е��߷�
	int GetLargerPiece(int Piece);						 //ת���Ŵ������
	int GetSmallerPiece(int Piece);						 //ת����С������
	int Winner();										 //�ж���Ӯ
	void Move(Loc nloc, int piece);						 //����
	double GameState();									 //��������

	void Regret_Game(stack<Move_Recording> &Recording, int step);                          //����

private:
	int step;				 //����
	int board[5][5];		 //5��5����
	int RedNum;				 //�췽������
	int BlueNum;			 //����������
	int RedState[7];         //�췽����״̬���±�0�������Ӵ��������±��1��6������״̬��
	int BlueState[7];        //��������״̬
};

void print();										     //��ӡ�հ���˹̹����

inline int RandDice()
{
	return rand() % 6 + 1;
}

