#pragma once
#include"makeNowMoves.h"
#include"CEvelation.h"
#include"head.h"
class CSearchengine: 
	public makeNowMoves,
	public CEvelation
{
public:
	CSearchengine();
	~CSearchengine();
	void copy(int board[10][10], int Color);
	void goAMove(int board[10][10],MOVE aMove);//��һ���з��ĺ���
	void goBack(int board[10][10],MOVE aMove);//����һ���ĺ���
	int IsGameOver();										  //�ж��Ƿ����
	bool KING_FOUR_DIRECTION_CAN_EAT(int X, int Y, int Color);//������ж������ܲ��ܳ�
	bool BING_FOUR_DIRECTION_CAN_EAT(int X, int Y, int Color);//�жα��ܲ��ܳ�
	bool IsBingCanMove(int X, int Y, int Color);			  //�жϱ��ܲ�����
	bool IsKingCanMove(int X, int Y, int Color);			  //�ж����ܲ�����
protected:
	MOVE PossibleMoves[20][150];							//�з�����
	//MOVE **PossibleMoves; 

	int nowColor;					 						  //��ǰ���ӷ�
	int board[10][10];										  //������Ϣ
	clock_t timeStart;
	clock_t timeStop;
	MOVE theBestMove;
	MOVE BestMove;
	
};
