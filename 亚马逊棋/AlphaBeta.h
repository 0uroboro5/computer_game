#pragma once
#include"Data.h"
#include"SearchEngine.h"
#include<string.h>

extern int SearchDepth;//�����������
extern int Step;//��¼�����߹��Ĳ���
extern int mode;

///////��������///////
void SearchAGoodMove(int Board[12][12]);
double AlphaBeta(int depth, double alpha=-INFI, double beta=INFI);//��������Ĭ�ϲ���alpha��beta