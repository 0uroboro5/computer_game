#pragma once
#include"head.h"
class CEvelation 
{
public:
	double Eval(int position[10][10], int Type);
	double Eval(int position[10][10], int Type, int Step);//�ӿ�
	CString MFC_Eval(int position[10][10], int Type);//������ʾ��ֵ����������
	CEvelation();
	~CEvelation();
	LONG Tree;
	int Get_Pawn_Pre_Value(int x, int y, int position[10][10]);
	int Is_Guard_Pos(int x, int y, int position[10][10]);
	int Is_Attack_Pos(int x, int y, int position[10][10], int Type);
	int Fiexiblity_Count(int x, int y, int position[10][10]);
	int Is_Being_King(int x,int y,int position[10][10],int Type);
};
