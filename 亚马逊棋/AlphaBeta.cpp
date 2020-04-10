#include"AlphaBeta.h"
#include<windows.h>

int Step = 0;
int SearchDepth = 2;   //��������
int CurPosition[12][12] = { 0 };   //��ʵ�ʲ��������̸��Ƶ��������������Ͻ���ģ�����������
CHESSMOVE BestMove = { 0 };


void SearchAGoodMove(int Board[12][12])   //����һ��12*12�Ķ�ά����
{
	memcpy(CurPosition, Board, 144 * sizeof(int));   //���ƴ����Board���̵�CurPosition
	AlphaBeta(SearchDepth);    //��һ�������������õ��������
	MakeMove(&BestMove);
	memcpy(Board, CurPosition, 144 * sizeof(int));
	Step = 0;
}

double AlphaBeta(int depth, double alpha, double beta)
{
	double score = 0;   //������������
	int type = 0;
	if (JudgeWin(CurPosition) != 0)//�ֳ�ʤ��
	{
		return Evaluate();//��������ֵ
	}
	if (depth == 0)//����Ҷ�ӽڵ�
	{
		if ((SearchDepth - depth) % 2 == 0)//����ֵ���
		{
			if (mode == 1)
			{
				return Evaluate();
			}
			if (mode == 0)
			{
				return -Evaluate();
			}
		}
		else
		{
			if (mode == 1)
			{
				return -Evaluate();
			}
			if (mode == 0)
			{
				return Evaluate();
			}
			
		}
	}
	///////////�Ⱥ���ת��/////////
	Step = Step + 1;      //ÿ����һ�������ֽ�����һ��
	if (mode == 1)        //�������֣�����ִ��
	{
		if (Step % 2 == 1)//������
		{
			type = mode + 1;
		}
		else if (Step % 2 == 0)
		{
			type = mode;
			//MessageBox(NULL, "���ԣ�", "��ʾ", MB_OK);
		}
	}
	if (mode == 0)  //���Ժ���
	{
		if (Step % 2 == 0)  //������
		{
			type = mode+1;
		}
		else if (Step % 2 == 1)  //ż����
		{
			type = mode+2;
		}
	}
	/////////////////////////////
	int count = CreatePossibleMove(CurPosition, depth, type);  //��¼�����������������з��Ϲ���Ĳ���
	for (int i = 0; i < count; i++)
	{
		MakeMove(&MoveList[depth][i]);            //ģ�����壬��CurPosition��ģ��
		score = -AlphaBeta(depth -1, -beta, -alpha);   //�ݹ���������
		UnMakeMove(&MoveList[depth][i]);              //����ģ������
		if (score > alpha)
		{
			alpha = score;
			if (depth == SearchDepth)
			{
				BestMove = MoveList[depth][i];
			}
		}
		if (alpha >= beta)
		{
			break;
		}
	}
	return alpha;
}