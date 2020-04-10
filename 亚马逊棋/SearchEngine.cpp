#include"SearchEngine.h"


//��CurPosition���в���
void MakeMove(CHESSMOVE* move)//ģ������
{
	CurPosition[move->From.x][move->From.y] = EMPTY;
	CurPosition[move->To.x][move->To.y] = move->ChessID;//�����巽���Ѿ��ҵ�����Ե����巽,���߿��Խ���ϳ����д��
	CurPosition[move->Bar.x][move->Bar.y] = BARRIER;
}

void UnMakeMove(CHESSMOVE* move)
{
	CurPosition[move->Bar.x][move->Bar.y] = EMPTY;
	CurPosition[move->To.x][move->To.y] = EMPTY;
	CurPosition[move->From.x][move->From.y] = move->ChessID;
}