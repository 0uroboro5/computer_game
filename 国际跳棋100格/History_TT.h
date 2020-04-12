

#pragma once
#include"head.h"
class CHistory_TT
{
public:
	CHistory_TT(void);
	~CHistory_TT(void);
	void InitializeHistoryTable();//������ʷ������ʼ��
	double LookUpHHTable(MOVE *move);//����ֵ��������
	void EnterHHTable(MOVE *move,int depth);//������ʷ��
	void qrs(MOVE *a,int depth, int left, int right);//��������
protected:
	LONGLONG Rand32();//����64λ�������//64->32
	LONG Rand16();	  //����32λ�������//32->16
private:
	UINT m_nHashKey16[4][10][10];	   //32λ������飬��������32λ��ϣֵ//32->16
	ULONGLONG m_ulHashKey32[4][10][10];//64λ������飬��������64λ��ϣֵ//64->32
	HH_HASHITEM *m_pHH;

};

