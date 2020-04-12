#pragma once
#include"head.h"
class CTranspositionTable
{
public:
	CTranspositionTable();
	~CTranspositionTable();
	void EnterHashTable(ENTRY_TYPE entry_type, double eval, short depth);
	//����ǰ�ڵ��ֵ�����ϣ��
	double LookUpHashTable(double alpha, double beta, double depth);			//��ѯ��ϣ���е�ǰ�ڵ�����
	void Hash_UnMakeMove(MOVE* move, int CurPosition[10][10]);
	//���������߷��Ĺ�ϣֵ����ԭ���߹�֮ǰ��
	void Hash_MakeMove(MOVE* move, int CurPosition[10][10]);		//���������߷������������µĹ�ϣֵ
	void CalculateInitHashKey(int CurPosition[10][10]);				//����������̵Ĺ�ϣֵ
	void InitializeHashKey();										//��ʼ��������飬������ϣ��
public:
	LONGLONG Rand64();												//����64λ�������
	LONG Rand32();													//����32λ�������
private:
	UINT m_nHashKey32[4][10][10];		 //32λ������飬��������32λ��ϣֵ
	ULONGLONG m_ulHashKey64[4][10][10];	 //64λ������飬��������64λ��ϣֵ
	HASHITEM *m_pTT;					 //�û���ͷָ��
	UINT m_HashKey32;				     //32λ��ϣֵ
	LONGLONG m_HashKey64;			     //64λ��ϣֵ
};

