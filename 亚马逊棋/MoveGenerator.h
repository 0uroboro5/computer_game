#pragma once

#include"Data.h"

extern CHESSMOVE MoveList[8][2500];     //���Դ洢����,�ṹ������
extern int MoveCount;       //��¼��������
extern int Offset[8][2];      //����ƫ�������򻯴���

/////////////////////��������////////////////////////////
void InitOffset();
int CreatePossibleMove(int Board[12][12],int depth,int Side);//�������̣���Ⱥ����巽
void CreatePossibleBar(int Board[12][12], int depth, int Side, int FromX, int FromY, int ToX, int ToY);
