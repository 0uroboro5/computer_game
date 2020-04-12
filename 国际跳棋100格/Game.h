#pragma once
#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include"head.h"
#include"Negascout_HH_TT.h"
using namespace std;
class Game//����
{
public:
	Game();
	~Game();
	CNegascout_HH_TT Computer;

	//��¼����
	int Error;
	//��������ŷ�
	MOVE Search_Good_Move(int board[][10],int Color,int Engine,int Step);
	//���������ŷ�
	int Search_All_Moves(int board[][10],MOVE *All_Moves,int Color);
	//���ŷ�����
	void Go_Move(int board[][10],MOVE The_Move);
	//��ȡ��ǰ�����ֵ
	CString Get_Evel(int board[][10],int Color);
	//�����ŷ�
	bool Check_Move(MOVE The_Move,MOVE AllMoves[],int move_num);
	//������ʱ�������ֵ
	void Input_Depth_Time(int Depth,double Time);
	
};
