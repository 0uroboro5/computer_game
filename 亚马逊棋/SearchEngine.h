#pragma once
#include"Data.h"
#include"MoveGenerator.h"
#include"EvaluateEngine.h"


extern int CurPosition[12][12];
extern CHESSMOVE BestMove;

///////��������//////
void MakeMove(CHESSMOVE* move);//����һ�������Ľṹ��ָ��
void UnMakeMove(CHESSMOVE* move);