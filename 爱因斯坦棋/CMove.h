#pragma once
#include "stdafx.h"
#include "CBoard.h"

#define MC_CONSTANT 2000														 //ģ�����

//��ͨ���ؿ���

void RandMove(Board &CB, int Piece);															 //�������
int GetMCWinner(Board &CB, int NextPlayer, int algorithm);                                       //ģ��
double GetMCEvalution(Board &CB, int NextPlayer, int times, int algorithm);				         //����
void MonteCarloMove(Board &CB, int Piece, int algorithm, stack<Move_Recording> &Recording);      //����

//////////////////////////////////////////////////////////////////////////////////////////////////

//��Ͼ������������ؿ���
void Rand_Best_Move(Board &CB, int Picece);										  //��������õľ������������

///////////////////////////////////////////////////////////////////////////////////////////////////
