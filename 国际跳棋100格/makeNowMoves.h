#pragma once
#include"head.h"
class makeNowMoves
{
public:
	makeNowMoves();//��ʼ����ǰ�з��������̣�
	~makeNowMoves();//��֪��ʲô�ã�ϰ�ߵĸ�������麯����
	//�����صĳ�Ա����
private:
	void copy(int Color,int board[10][10]);//��ȡ��ǰ���ӷ�������ǰ����
	void makeNowBingMove(int starX,int starY,int eatHowMany,MOVE movesCoutainer[200]);//���ɵ�ǰ����(��)���з�
	//������صĳ�Ա����
	void makeNowKingMove(int starX,int starY,int eatHowMany,MOVE movesCoutainer[200]);//���ɵ�ǰ����(��)���з�
	bool KING_FOUR_DIRECTION_CAN_EAT(int X,int Y);//������ж������ܲ��ܳ�
	bool BING_FOUR_DIRECTION_CAN_EAT(int X,int Y);
	MOVE nowTheMove;//�������ɵĽṹ�壬��������������뵽�з���¼��������
	int board[10][10];//��Ҫ�Ըþ��������з�
	int nowColor;//�Ը������������з�
	int theBestEatNum;//��¼����ʱ��ǰ�������������������Ա��ĺܿӰ������1�ͻ�����⣩
	int nowTheNumberOfMove;//�з��ļ�¼���ڼ���λ���ˣ�����ڽӿں����������ֵ����Ϊ�з�������
public:
	int allMove(int board[10][10],MOVE movesCoutainer[200],int Color);//�ӿں���
};

