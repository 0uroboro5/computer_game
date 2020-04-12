#include "stdafx.h"
#include "CEvelation.h"

CEvelation::CEvelation()	
{
	
}
CEvelation::~CEvelation()
{
}
/////////////////////////////////�¹�ֵ////////////////////////////////////////////

//���ڴ����λ�ø���ֵ�ĳ�������
/*
const int White_Pawn_Pre_Value_A[10][10] =
{
	{ 0, 400, 0, 400, 0, 400, 0, 400, 0, 400 },
	{ 200, 0, 200, 0, 200, 0, 200, 0, 200, 0 },
	{ 0, 180, 0, 180, 0, 180, 0, 180, 0, 210 },//�����ı߱�15��ֵ�ϸ�
	{ 160, 0, 160, 0, 160, 0, 160, 0, 160, 0 },
	{ 0, 150, 0, 150, 0, 150, 0, 150, 0, 150 },
	{ 120, 0, 140, 0, 140, 0, 140, 0, 140, 0 },//����26��36��46��35��45  Value-20
	{ 0, 130, 0, 130, 0, 130, 0, 130, 0, 110 },
	{ 100, 0, 120, 0, 120, 0, 120, 0, 120, 0 },
	{ 0, 110, 0, 110, 0, 110, 0, 110, 0, 90 },
	{ 80, 0, 100, 0, 100, 0, 100, 0, 100, 0 },
}; 
const int Black_Pawn_Pre_Value_A[10][10] =
{
	{ 0, 100, 0, 100, 0, 100, 0, 100, 0, 80 },
	{ 90, 0, 110, 0, 110, 0, 110, 0, 110, 0 },//����5��15��25��6��16   Value-20
	{ 0, 120, 0, 120, 0, 120, 0, 120, 0, 100 },
	{ 110, 0, 130, 0, 130, 0, 130, 0, 130, 0 },
	{ 0, 140, 0, 140, 0, 140, 0, 140, 0, 120 },
	{ 150, 0, 150, 0, 150, 0, 150, 0, 150, 0 },
	{ 0, 160, 0, 160, 0, 160, 0, 160, 0, 160 },
	{ 210, 0, 180, 0, 180, 0, 180, 0, 180, 0 },//�����ı߱�36��ֵ�ϸ�
	{ 0, 190, 0, 190, 0, 190, 0, 190, 0, 190 },
	{ 400, 0, 400, 0, 400, 0, 400, 0, 400, 0 },
};
*/
const int White_Pawn_Pre_Value_B[10][10] =
{
	//1   2   3   4   5   6    7   8   9   10
	{ 0, 400, 0, 400, 0, 400, 0, 400, 0, 400 },//1
	{ 200, 0, 200, 0, 200, 0, 200, 0, 200, 0 },//2
	{ 0, 180, 0, 190, 0, 190, 0, 190, 0, 210 },//3   //�����ı߱�15��ֵ�ϸ�
	{ 160, 0, 180, 0, 180, 0, 180, 0, 160, 0 },//4
	{ 0, 150, 0, 175, 0, 175, 0, 175, 0, 150 },//5
	{ 120, 0, 170, 0, 170, 0, 170, 0, 140, 0 },//6      //����26��36��46��35��45  Value-20
	{ 0, 130, 0, 160, 0, 160, 0, 130, 0, 110 },//7
	{ 100, 0, 140, 0, 140, 0, 140, 0, 120, 0 },//8
	{ 0, 110, 0, 110, 0, 110, 0, 110, 0, 90 }, //9
	{ 70, 0, 100, 0, 100, 0, 100, 0, 100, 0 }, //10
};
const int Black_Pawn_Pre_Value_B[10][10] =
{
	// 1   2   3   4   5   6    7   8   9   10
	{ 0, 100, 0, 100, 0, 100, 0, 100, 0, 70 }, //1
	{ 90, 0, 110, 0, 110, 0, 110, 0, 110, 0 }, //2   //����5��15��25��6��16   Value-20
	{ 0, 120, 0, 140, 0, 140, 0, 140, 0, 100 },//3
	{ 110, 0, 160, 0, 160, 0, 160, 0, 130, 0 },//4
	{ 0, 140, 0, 170, 0, 170, 0, 170, 0, 120 },//5
	{ 150, 0, 175, 0, 175, 0, 175, 0, 150, 0 },//6
	{ 0, 160, 0, 180, 0, 180, 0, 180, 0, 160 },//7
	{ 210, 0, 190, 0, 190, 0, 190, 0, 180, 0 },//8       //�����ı߱�36��ֵ�ϸ�
	{ 0, 200, 0, 200, 0, 200, 0, 200, 0, 200 },//9
	{ 400, 0, 400, 0, 400, 0, 400, 0, 400, 0 },//10
};

//���㵱ǰ������ÿ�����ĸ���ֵ
int CEvelation::Get_Pawn_Pre_Value(int x, int y, int position[10][10])
{
	/*int Count_W=0;
	int Count_B=0;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(position[i][j]==WHITE||position[i][j]==W_KING)
			{
					Count_W++;
			}	
			if(position[i][j]==BLACK||position[i][j]==B_KING)
			{
					Count_B++;
			}
		}
	}
	if(Count_W>10||Count_B>10)
	{
		if (position[x][y] == WHITE)
			return White_Pawn_Pre_Value_A[x][y];
		if (position[x][y] == BLACK)
			return Black_Pawn_Pre_Value_A[x][y];
	}
	else
	{
	*/
		if (position[x][y] == WHITE)
			return White_Pawn_Pre_Value_B[y][x];
		if (position[x][y] == BLACK)
			return Black_Pawn_Pre_Value_B[y][x];
	return 0;
}

//�����жϵ�ǰ�����Ƿ��ڱ�������״̬
int CEvelation::Is_Guard_Pos(int x, int y, int position[10][10])
{
	switch (position[x][y])
	{
	case WHITE:
	{
		if (x == 1 || x == 8)
		{
			if ((x == 1) && (position[x - 1][y + 1] == WHITE) && (position[x + 1][y + 1] == WHITE) && 
				(position[x + 2][y + 2] == WHITE))//�߽�λ���γ�˫�������γɷ���
				return 1;
			if ((x == 8) && (position[x - 1][y + 1] == WHITE) && (position[x - 2][y + 2] == WHITE) &&
				(position[x + 1][y + 1] == WHITE))
				return 1;
		}
		else
			if (((position[x - 1][y + 1] == WHITE) && (position[x - 2][y + 2] == WHITE)) &&
				((position[x + 1][y + 1] == WHITE) && (position[x + 2][y + 2] == WHITE)))//�м�λ���γ������������ɷ���
				return 1;
		return 0;
	}
	case BLACK:
	{
		if (x == 1 || x == 8)
		{
			if ((x == 1) && (position[x - 1][y - 1] == BLACK) && (position[x + 1][y - 1] == BLACK) && 
				(position[x + 2][y - 2] == BLACK))//�߽�λ���γ�˫�������γɷ���
				return 1;
			if ((x == 8) && (position[x - 1][y - 1] == BLACK) && (position[x - 2][y - 2] == BLACK) &&
				(position[x + 1][y - 1] == BLACK))
				return 1;
		}
		else
			if (((position[x - 1][y - 1] == BLACK) && (position[x - 2][y - 2] == BLACK)) &&
				((position[x + 1][y - 1] == BLACK) && (position[x + 2][y - 2] == BLACK)))//�м�λ���γ������������ɷ���
				return 1;
		return 0;
	}
	case W_KING:
	{
		if (x == 1 || x == 8)//�߽����
		{
			if ((x == 1) && (position[x - 1][y + 1] == W_KING) && (position[x + 1][y + 1] == WHITE) && 
				(position[x + 2][y + 2] == WHITE))
				return 1;//����Ϊ��������Ϊ˫��
			if ((x == 8) && (position[x - 1][y + 1] == WHITE) && (position[x - 2][y + 2] == WHITE) && 
				(position[x + 1][y + 1] == W_KING))
				return 1;//����Ϊ��������Ϊ˫��
		}
		else
			if (((position[x - 1][y + 1] == W_KING) && (position[x - 2][y + 2] == WHITE)) &&
				((position[x + 1][y + 1] == W_KING) && (position[x + 2][y + 2] == WHITE)))//���¡����¾�Ϊ������ϱ���
				return 1;
		return 0;
	}
	case B_KING:
	{
		if (x == 1 || x == 8)
		{
			if ((x == 1) && (position[x - 1][y - 1] == B_KING) && (position[x + 1][y + 1] == BLACK) &&
				(position[x + 2][y + 2] == BLACK))
				return 1;//����Ϊ��������Ϊ˫��
			if ((x == 8) && (position[x + 1][y - 1] == B_KING) && (position[x - 1][y - 1] == BLACK) &&
				(position[x - 2][y - 2] == BLACK))
				return 1;//����Ϊ��������Ϊ˫��
		}
		else
			if (((position[x - 1][y - 1] == B_KING) && (position[x - 2][y - 2] == WHITE)) &&
				((position[x + 1][y - 1] == B_KING) && (position[x + 2][y - 2] == WHITE)))//���ϡ�����Ϊ�������

				return 1;
		return 0;
	}
	}
	return 0;
}

//�жϵ�ǰ�����Ƿ񱻶Է�������в
int CEvelation::Is_Attack_Pos(int x, int y, int position[10][10], int Type)
{
	int i = 2;
	int j = 2;
	if (Is_Guard_Pos(x, y, position))
		return 0;
	else
	{
		switch (position[x][y])
		{
		case WHITE:
		{
			if ((position[x - 1][y - 1] == BLACK|| (position[x - 1][y - 1] == B_KING)) &&
				(position[x + 1][y + 1] == EMPTY) && Type == 1)//���ϱ�����в
				return 1;
			if ((position[x - 1][y + 1] == BLACK || (position[x - 1][y + 1] == B_KING)) && (position[x + 1][y - 1] == EMPTY)
				&& Type == 1)//���ϱ�����в
				return 1;
			if ((position[x + 1][y - 1] == BLACK || (position[x + 1][y - 1] == B_KING)) && (position[x - 1][y + 1] == EMPTY) && Type == 1)//���±�����в
				return 1;
			if ((position[x + 1][y + 1] == BLACK || (position[x + 1][y + 1] == B_KING)) && (position[x - 1][y - 1] == EMPTY) && Type == 1)//���±�����в
				return 1;
			/*while((x - i >= 0) && (y - j >= 0))*/
			if((position[x - i][y - j] == B_KING) && position[x - 1][y - 1] == 0 &&(position[x + 1][y + 1] == EMPTY) && 
				Type == 1)//���������ڵ�����в
				return 1;
			else
				if(position[x - 1][y - 1] == EMPTY)//�������λ��Ϊ��
				{
					while ((x - i >= 0) && (y - j >= 0))//�������Ϸ������λ��
					{
						if ((position[x - i][y - j] == B_KING) && (position[x + 1][y + 1] == EMPTY) && Type == 1)//���ϱ�����в
							return 1;
						else
							if(position[x - i][y - j] == BLACK)//������Ϸ�ͨ�����ڶԷ��ı�
								break;
							else//�����ظ÷����������λ��
							{
								i++;
								j++;
							}
					}
				}
				i=2;
				j=2;
			if((position[x - 1][y + 1] == B_KING) && (position[x + 1][y - 1] == EMPTY) && Type == 1)//�����·���������в
				return 1;
			else
				if(position[x - 1][y + 1] == EMPTY)//�������λ��Ϊ��
				{
					while ((x - i >= 0) && (y + j <= 9))//�����÷��������λ��
					{
						if ((position[x - i][y + j] == B_KING) && (position[x + 1][y - 1] == EMPTY) && Type == 1)//���±�����в
							return 1;
						else
							if(position[x - i][y + j] == BLACK)//�����·����ڶԷ���
								break;
							else//���������÷������������λ��
							{
								i++;
								j++;
							}
					}
				}
				i=2;
				j=2;
			if((position[x + 1][y - 1] == B_KING) && (position[x - 1][y + 1] == EMPTY) && Type == 1)//���Ϸ�������λ������в
				return 1;
			else
				if(position[x + 1][y - 1] == EMPTY)//���Ϸ�����λ��Ϊ�ո�
				{
					while ((x + i <= 9) && (y - j >= 0))//�������Ϸ��������λ��
					{
						if ((position[x + i][y - j] == B_KING) && (position[x - 1][y + 1] == EMPTY) && Type == 1)//���ϱ�����в
							return 1;
						else
							if(position[x + i][y - j] == BLACK)//�����Ϸ�������λ�ó��ֶԷ���ʱ
								break;
							else//�����������Ϸ����λ��
							{
								i++;
								j++;
							}
					}
				}
				i=2;
				j=2;
			if((position[x + 1][y + 1] == B_KING) && (position[x - 1][y - 1] == EMPTY) && Type == 1)//���·�����������в
				return 1;
			else
				if(position[x + 1][y + 1] == EMPTY)//���·�����λ���ǿո�
				{
					while ((x + i <= 9) && (y + j <= 9))//�����ո��÷�������������λ��
					{
						if ((position[x + i][y + j] == B_KING) && (position[x - 1][y - 1] == EMPTY) && Type == 1)//���±�����в
							return 1;
						else
							if(position[x + i][y + j] == BLACK)//�ڸ÷����ϴ��ڲ����ڵĶԷ���
								break;
							else//���������÷������λ��
							{
								i++;
								j++;
							}
					}
				}
			return 0;
		}
		case BLACK:
		{
			if ((position[x - 1][y - 1] == WHITE||(position[x - 1][y - 1] == W_KING)) && (position[x + 1][y + 1] == EMPTY) && Type == 2)//���ϱ�����в
				return 1;
			if ((position[x - 1][y + 1] == WHITE || (position[x - 1][y + 1] == W_KING)) && (position[x + 1][y - 1] == EMPTY) && Type == 2)//���ϱ�����в
				return 1;
			if ((position[x + 1][y - 1] == WHITE || (position[x + 1][y - 1] == W_KING)) && (position[x - 1][y + 1] == EMPTY) && Type == 2)//���±�����в
				return 1;
			if ((position[x + 1][y + 1] == WHITE || (position[x + 1][y + 1] == W_KING)) && (position[x - 1][y - 1] == EMPTY) && Type == 2)//���±�����в
				return 1;
			if((position[x - i][y - j] == W_KING) && position[x - 1][y - 1] == 0 &&(position[x + 1][y + 1] == EMPTY) && Type == 2)//���������ڵ�����в
				return 1;
			else
				if(position[x - 1][y - 1] == EMPTY)//�������λ��Ϊ��
				{
					while ((x - i >= 0) && (y - j >= 0))//�������Ϸ������λ��
					{
						if ((position[x - i][y - j] == W_KING) && (position[x + 1][y + 1] == EMPTY) && Type == 2)//���ϱ�����в
							return 1;
						else
							if(position[x - i][y - j] == WHITE)//������Ϸ�ͨ�����ڶԷ��ı�
								break;
							else//�����ظ÷����������λ��
							{
								i++;
								j++;
							}
					}
				}
				i=2;
				j=2;
			if((position[x - 1][y + 1] == W_KING) && (position[x + 1][y - 1] == EMPTY) && Type == 2)//�����·���������в
				return 1;
			else
				if(position[x - 1][y + 1] == EMPTY)//�������λ��Ϊ��
				{
					while ((x - i >= 0) && (y + j <= 9))//�����÷��������λ��
					{
						if ((position[x - i][y + j] == W_KING) && (position[x + 1][y - 1] == EMPTY) && Type == 2)//���±�����в
							return 1;
						else
							if(position[x - i][y + j] == WHITE)//�����·����ڶԷ���
								break;
							else//���������÷������������λ��
							{
								i++;
								j++;
							}
					}
				}
				i=2;
				j=2;
			if((position[x + 1][y - 1] == W_KING) && (position[x - 1][y + 1] == EMPTY) && Type == 2)//���Ϸ�������λ������в
				return 1;
			else
				if(position[x + 1][y - 1] == EMPTY)//���Ϸ�����λ��Ϊ�ո�
				{
					while ((x + i <= 9) && (y - j >= 0))//�������Ϸ��������λ��
					{
						if ((position[x + i][y - j] == W_KING) && (position[x - 1][y + 1] == EMPTY) && Type == 2)//���ϱ�����в
							return 1;
						else
							if(position[x + i][y - j] == WHITE)//�����Ϸ�������λ�ó��ֶԷ���ʱ
								break;
							else//�����������Ϸ����λ��
							{
								i++;
								j++;
							}
					}
				}
				i=2;
				j=2;
			if((position[x + 1][y + 1] == W_KING) && (position[x - 1][y - 1] == EMPTY) && Type == 2)//���·�����������в
				return 1;
			else
				if(position[x + 1][y + 1] == EMPTY)//���·�����λ���ǿո�
				{
					while ((x + i <= 9) && (y + j <= 9))//�����ո��÷�������������λ��
					{
						if ((position[x + i][y + j] == W_KING) && (position[x - 1][y - 1] == EMPTY) && Type == 2)//���±�����в
							return 1;
						else
							if(position[x + i][y + j] == WHITE)//�ڸ÷����ϴ��ڲ����ڵĶԷ���
								break;
							else//���������÷������λ��
							{
								i++;
								j++;
							}
					}
				}
			return 0;
		}
		case W_KING:
		{
			if ((position[x - 1][y - 1] == BLACK||(position[x - 1][y - 1] == B_KING)) && (position[x + 1][y + 1] == EMPTY) && Type == 1)//���ϱ�����в
				return 1;
			if ((position[x - 1][y + 1] == BLACK || (position[x - 1][y + 1] == B_KING)) && (position[x + 1][y - 1] == EMPTY) && Type == 1)//���ϱ�����в
				return 1;
			if ((position[x + 1][y - 1] == BLACK || (position[x + 1][y - 1] == B_KING)) && (position[x - 1][y + 1] == EMPTY) && Type == 1)//���±�����в
				return 1;
			if ((position[x + 1][y + 1] == BLACK || (position[x + 1][y + 1] == B_KING)) && (position[x - 1][y - 1] == EMPTY) && Type == 1)//���±�����в
				return 1;
			if((position[x - i][y - j] == B_KING) && position[x - 1][y - 1] == EMPTY &&(position[x + 1][y + 1] == EMPTY) && Type == 1)//���������ڵ�����в
				return 1;
			else
				if(position[x - 1][y - 1] == EMPTY)//�������λ��Ϊ��
				{
					while ((x - i >= 0) && (y - j >= 0))//�������Ϸ������λ��
					{
						if ((position[x - i][y - j] == B_KING) && (position[x + 1][y + 1] == EMPTY) && Type == 1)//���ϱ�����в
							return 1;
						else
							if(position[x - i][y - j] == BLACK)//������Ϸ�ͨ�����ڶԷ��ı�
								break;
							else//�����ظ÷����������λ��
							{
								i++;
								j++;
							}
					}
				}
				i=2;
				j=2;
			if((position[x - 1][y + 1] == B_KING) && (position[x + 1][y - 1] == EMPTY) && Type == 1)//�����·���������в
				return 1;
			else
				if(position[x - 1][y + 1] == EMPTY)//�������λ��Ϊ��
				{
					while ((x - i >= 0) && (y + j <= 9))//�����÷��������λ��
					{
						if ((position[x - i][y + j] == B_KING) && (position[x + 1][y - 1] == EMPTY) && Type == 1)//���±�����в
							return 1;
						else
							if(position[x - i][y + j] == BLACK)//�����·����ڶԷ���
								break;
							else//���������÷������������λ��
							{
								i++;
								j++;
							}
					}
				}
				i=2;
				j=2;
			if((position[x + 1][y - 1] == B_KING) && (position[x - 1][y + 1] == EMPTY) && Type == 1)//���Ϸ�������λ������в
				return 1;
			else
				if(position[x + 1][y - 1] == EMPTY)//���Ϸ�����λ��Ϊ�ո�
				{
					while ((x + i <= 9) && (y - j >= 0))//�������Ϸ��������λ��
					{
						if ((position[x + i][y - j] == B_KING) && (position[x - 1][y + 1] == EMPTY) && Type == 1)//���ϱ�����в
							return 1;
						else
							if(position[x + i][y - j] == BLACK)//�����Ϸ�������λ�ó��ֶԷ���ʱ
								break;
							else//�����������Ϸ����λ��
							{
								i++;
								j++;
							}
					}
				}
				i=2;
				j=2;
			if((position[x + 1][y + 1] == B_KING) && (position[x - 1][y - 1] == EMPTY) && Type == 1)//���·�����������в
				return 1;
			else
				if(position[x + 1][y + 1] == EMPTY)//���·�����λ���ǿո�
				{
					while ((x + i <= 9) && (y + j <= 9))//�����ո��÷�������������λ��
					{
						if ((position[x + i][y + j] == B_KING) && (position[x - 1][y - 1] == EMPTY) && Type == 1)//���±�����в
							return 1;
						else
							if(position[x + i][y + j] == BLACK)//�ڸ÷����ϴ��ڲ����ڵĶԷ���
								break;
							else//���������÷������λ��
							{
								i++;
								j++;
							}
					}
				}
			return 0;
		}
		case B_KING:
		{
			if ((position[x - 1][y - 1] == WHITE||(position[x - 1][y - 1] == W_KING)) && (position[x + 1][y + 1] == EMPTY) && Type == 2)//���ϱ�����в
				return 1;
			if ((position[x - 1][y + 1] == WHITE || (position[x - 1][y + 1] == W_KING)) && (position[x + 1][y - 1] == EMPTY) && Type == 2)//���ϱ�����в
				return 1;
			if ((position[x + 1][y - 1] == WHITE || (position[x + 1][y - 1] == W_KING)) && (position[x - 1][y + 1] == EMPTY) && Type == 2)//���±�����в
				return 1;
			if ((position[x + 1][y + 1] == WHITE || (position[x + 1][y + 1] == W_KING)) && (position[x - 1][y - 1] == EMPTY) && Type == 2)//���±�����в
				return 1;
			if((position[x - i][y - j] == W_KING) && (position[x - 1][y - 1] == EMPTY )&& (position[x + 1][y + 1] == EMPTY) && Type == 2)//���������ڵ�����в
				return 1;
			else
				if(position[x - 1][y - 1] == EMPTY)//�������λ��Ϊ��
				{
					while ((x - i >= 0) && (y - j >= 0))//�������Ϸ������λ��
					{
						if ((position[x - i][y - j] == W_KING) && (position[x + 1][y + 1] == EMPTY) && Type == 2)//���ϱ�����в
							return 1;
						else
							if(position[x - i][y - j] == WHITE)//������Ϸ�ͨ�����ڶԷ��ı�
								break;
							else//�����ظ÷����������λ��
							{
								i++;
								j++;
							}
					}
				}
				i=2;
				j=2;
			if((position[x - 1][y + 1] == W_KING) && (position[x + 1][y - 1] == EMPTY) && Type == 2)//�����·���������в
				return 1;
			else
				if(position[x - 1][y + 1] == EMPTY)//�������λ��Ϊ��
				{
					while ((x - i >= 0) && (y + j <= 9))//�����÷��������λ��
					{
						if ((position[x - i][y + j] == W_KING) && (position[x + 1][y - 1] == EMPTY) && Type == 2)//���±�����в
							return 1;
						else
							if(position[x - i][y + j] == WHITE)//�����·����ڶԷ���
								break;
							else//���������÷������������λ��
							{
								i++;
								j++;
							}
					}
				}
				i=2;
				j=2;
			if((position[x + 1][y - 1] == W_KING) && (position[x - 1][y + 1] == EMPTY) && Type == 2)//���Ϸ�������λ������в
				return 1;
			else
				if(position[x + 1][y - 1] == EMPTY)//���Ϸ�����λ��Ϊ�ո�
				{
					while ((x + i <= 9) && (y - j >= 0))//�������Ϸ��������λ��
					{
						if ((position[x + i][y - j] == W_KING) && (position[x - 1][y + 1] == EMPTY) && Type == 2)//���ϱ�����в
							return 1;
						else
							if(position[x + i][y - j] == WHITE)//�����Ϸ�������λ�ó��ֶԷ���ʱ
								break;
							else//�����������Ϸ����λ��
							{
								i++;
								j++;
							}
					}
				}
				i=2;
				j=2;
			if((position[x + 1][y + 1] == W_KING) && (position[x - 1][y - 1] == EMPTY) && Type == 2)//���·�����������в
				return 1;
			else
				if(position[x + 1][y + 1] == EMPTY)//���·�����λ���ǿո�
				{
					while ((x + i <= 9) && (y + j <= 9))//�����ո��÷�������������λ��
					{
						if ((position[x + i][y + j] == W_KING) && (position[x - 1][y - 1] == EMPTY) && Type == 2)//���±�����в
							return 1;
						else
							if(position[x + i][y + j] == WHITE)//�ڸ÷����ϴ��ڲ����ڵĶԷ���
								break;
							else//���������÷������λ��
							{
								i++;
								j++;
							}
					}
				}
			return 0;
		}
		default:
			return 0;
		}
	}
}

//���㵱ǰ���ӵ�����
int CEvelation::Fiexiblity_Count(int x, int y, int position[10][10])
{
	int Fiexible_Num = 0;
	int i = 1;
	int j = 1;
	switch (position[x][y])
	{
	case WHITE://�ױ�
	{
		if (x>0&&position[x - 1][y - 1] == EMPTY)//�������
			Fiexible_Num++;
		if (x<9&&position[x - 1][y + 1] == EMPTY)//�������
			Fiexible_Num++;
	}
	break;
	case BLACK://�ڱ�
	{
		if (x>0&&position[x + 1][y - 1] == EMPTY)//�������
			Fiexible_Num++;
		if (x<9&&position[x + 1][y + 1] == EMPTY)//�������
			Fiexible_Num++;
	}
	break;
	case W_KING://����
	{
		while ((x - i >= 0) && (y - j >= 0))
		{
			if ((position[x - i][y - j] == EMPTY))//�������
			{
				Fiexible_Num++;
				i++;
				j++;
			}
			else
				break;
		}
		i=1;
		j=1;
		while ((x - i >= 0) && (y + j <= 9))
		{
			if ((position[x - i][y + j] == EMPTY))//�������
			{
				Fiexible_Num++;
				i++;
				j++;
			}
			else
				break;
		}
		i=1;
		j=1;
		while ((x + i <= 9) && (y - j >= 0))
		{
			if ((position[x + i][y - j] == EMPTY))//�������
			{
				Fiexible_Num++;
				i++;
				j++;
			}
			else
				break;
		}
		i=1;
		j=1;
		while ((x + i <= 9) && (y + j <= 9))
		{
			if ((position[x + i][y + j] == EMPTY))//�������
			{
				Fiexible_Num++;
				i++;
				j++;
			}
			else
				break;
		}
	}
	break;
	case B_KING://����
	{
		while ((x - i >= 0) && (y - j >= 0))
		{
			if ((position[x - i][y - j] == EMPTY))//�������
			{
				Fiexible_Num++;
				i++;
				j++;
			}
			else
				break;
		}
		i=1;
		j=1;
		while ((x - i >= 0) && (y + j <= 9))
		{
			if ((position[x - i][y + j] == EMPTY))//�������
			{
				Fiexible_Num++;
				i++;
				j++;
			}
			else
				break;
		}
		i=1;
		j=1;
		while ((x + i <= 9) && (y - j >= 0))
		{
			if ((position[x + i][y - j] == EMPTY))//�������
			{
				Fiexible_Num++;
				i++;
				j++;
			}
			else
				break;
		}
		i=1;
		j=1;
		while ((x + i <= 9) && (y + j <= 9))
		{
			if ((position[x + i][y + j] == EMPTY))//�������
			{
				Fiexible_Num++;
				i++;
				j++;
			}
			else
				break;
		}
	}
	break;
	}
	return Fiexible_Num;
}

//���㵱ǰ�����Ƿ��ھ���Ǳ�ڳ���λ��
int CEvelation::Is_Being_King(int x,int y,int position[10][10],int Type)//�߼�δ��
{
	switch (position[x][y])
	{
	case WHITE:
		{
			if(x==0&&y==3)
			{
			if(position[1][0]==EMPTY&&position[0][1]==EMPTY&&position[2][1]==EMPTY
				&&position[1][2]==EMPTY&&position[3][0]!=B_KING)
					return 1;
			}
			if(x==1&&y==2)
			{
				if(!Is_Attack_Pos(x,y,position,Type)&&position[1][0]==EMPTY)
					return 1;
			}
			if(x==8&&y==3)
			{
				if(!Is_Attack_Pos(x,y,position,Type)&&position[7][0]==EMPTY&&position[9][0]==EMPTY)
					return 1;
			}
			if(x==9&&y==2)
			{
				if(position[8][1]!=2&&position[7][0]==EMPTY&&position[9][0]==EMPTY)
					return 1;
			}
			return 0;
		}
	case BLACK:
		{
			if(x==9&&y==6)
			{
			if(position[8][7]==EMPTY&&position[7][8]==EMPTY&&position[9][8]==EMPTY
				&&position[8][9]==EMPTY&&position[6][9]!=W_KING)
					return 1;
			}
			if(x==8&&y==7)
			{
				if(!Is_Attack_Pos(x,y,position,Type)&&position[8][9]==EMPTY)
					return 1;
			}
			if(x==1&&y==6)
			{
				if(!Is_Attack_Pos(x,y,position,Type)&&position[0][9]==EMPTY&&position[2][9]==EMPTY)
					return 1;
			}
			if(x==0&&y==7)
			{
				if(position[1][8]!=1&&position[0][9]==EMPTY&&position[2][9]==EMPTY)
					return 1;
			}
			return 0;
		}
	default:
		break;
	}
	return 0;
}

double CEvelation::Eval(int position[10][10], int Type)
{
	return 0.0;
}

double CEvelation::Eval(int position[10][10], int Type,int Step)
{
	//�趨�����Ļ�����ֵ
	int WHITE_Basic_Value = 100;
	int BLACK_Basic_Value = 100;
	int W_KING_Basic_Value = 800;
	int B_KING_Basic_Value = 800;
	
	//�趨�ڡ���˫�����ܼ�ֵ�ĳ�ʼֵ
	double n_WHITE_Value = 0;
	double n_BLACK_Value = 0;
	//������ֵָ������ĳ�ʼ��:
	double W_Pos_Value=0;//�׷�λ�ø���ֵ
	double W_Fiexiblity_Value=0;//�׷�����
	double W_Attack_Value=0;//�׷���в
	double W_Guard_Value=0;//�׷�����
	double W_Being_King_Value=0;//�׷�Ǳ�ڳ���λ�ý���
	double B_Pos_Value=0;//�׷�λ�ø���ֵ
	double B_Fiexiblity_Value=0;//�׷�����
	double B_Attack_Value=0;//�׷���в
	double B_Guard_Value=0;//�׷�����
	double B_Being_King_Value=0;//�׷�Ǳ�ڳ���λ�ý���
	//ɨ�����̶Ե�ǰ��������ӵļ�ֵ���м���
	for (int i = 0; i <= 9; i++)
		for (int j = 0; j <= 9; j++)
		{
		if (position[i][j] != EMPTY)//��ǰ�������ӵ������
		{
			switch (position[i][j])
			{
			case WHITE:
			{
				//һ�������ġ�λ�ø���ֵ�������ܼ�ֵ
				W_Pos_Value += Get_Pawn_Pre_Value(i, j, position);
				//���������ӵġ����ȡ������ܼ�ֵ
				W_Fiexiblity_Value += (Fiexiblity_Count(i, j, position)*0.1*WHITE_Basic_Value);
				//����������Լ������ӡ�����������ֵ���ϻ�����ֵ��0.1
				if (Is_Guard_Pos(i, j, position))
					W_Guard_Value += (0.5*WHITE_Basic_Value);
				//�ġ�������Է�����в������ֵ��ȥ���������ֵ��һ��
				if (Is_Attack_Pos(i, j, position, Type))
					W_Attack_Value -= (0.7*WHITE_Basic_Value);
				//�塢�߱�������Ǳ������λ�á��ı����н���
				if(Is_Being_King(i,j,position,Type))
					W_Being_King_Value +=100;
				break;
			}
			case BLACK:
			{
				//һ�������ġ�λ�ø���ֵ�������ܼ�ֵ
				B_Pos_Value += Get_Pawn_Pre_Value(i, j, position);
				//���������ӵġ����ȡ������ܼ�ֵ
				B_Fiexiblity_Value += (Fiexiblity_Count(i, j, position)*0.1*BLACK_Basic_Value);
				//����������Լ������ӡ�����������ֵ���ϻ�����ֵ��0.1
				if (Is_Guard_Pos(i, j, position))
					B_Guard_Value += (0.5*BLACK_Basic_Value);
				//�ġ�������Է�����в������ֵ��ȥ���������ֵ��һ��
				if (Is_Attack_Pos(i, j, position, Type))
					B_Attack_Value -= (0.7*BLACK_Basic_Value);
				//�塢�߱�������Ǳ������λ�á��ı����н���
				if(Is_Being_King(i,j,position,Type))
					B_Being_King_Value +=100;
				break;
			}
			case W_KING:
			{
				//һ�������ġ�λ�ø���ֵ�������ܼ�ֵ
				W_Pos_Value += W_KING_Basic_Value;
				//���������ӵġ����ȡ������ܼ�ֵ
				W_Fiexiblity_Value += (Fiexiblity_Count(i, j, position)*0.1*W_KING_Basic_Value);
				//����������Լ������ӡ�����������ֵ���ϻ�����ֵ��0.1
				if (Is_Guard_Pos(i, j, position))
					W_Guard_Value += (0.5*W_KING_Basic_Value);
				//�ġ�������Է�����в������ֵ��ȥ���������ֵ��һ��
				if (Is_Attack_Pos(i, j, position, Type))
					W_Attack_Value -= (0.7*W_KING_Basic_Value);
				break;
			}
			case B_KING:
			{
				//һ�������ġ�λ�ø���ֵ�������ܼ�ֵ
				B_Pos_Value += B_KING_Basic_Value;
				//���������ӵġ����ȡ������ܼ�ֵ
				B_Fiexiblity_Value += (Fiexiblity_Count(i, j, position)*0.1*W_KING_Basic_Value);
				//����������Լ������ӡ�����������ֵ���ϻ�����ֵ��0.1
				if (Is_Guard_Pos(i, j, position))
					B_Guard_Value += (0.5*W_KING_Basic_Value);
				//�ġ�������Է�����в������ֵ��ȥ���������ֵ��һ��
				if (Is_Attack_Pos(i,j,position,Type))
					B_Attack_Value -= (0.7*W_KING_Basic_Value);
				break;
			}
			}
		}
		}
		//��ʼ����ָ���Ȩ�ز���
	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	int parameter[5];
	if (Step > 40)
	{
		 parameter[0] = 4;
		 parameter[1] = 1; 
		 parameter[2] = 6;
		 parameter[3] = 6;
		 parameter[4] = 0;
	}
	else
	{
		parameter[0] = 4;
		parameter[1] = 1;
		parameter[2] = 5;
		parameter[3] = 5;
		parameter[4] = 3;
	}
		//int parameter[5] = { 4,1,5,5,3 };
	//�ۺϼ�����ڡ���˫�����ܼ�ֵ
		//            ��һ����       λ�ø���ֵ  �ڶ�����       ����         ��������       ��в           ���ĸ���       ����          �������       Ǳ�ڳ�������
		n_WHITE_Value=parameter[0]*W_Pos_Value+parameter[1]*W_Fiexiblity_Value+parameter[2]*W_Attack_Value+parameter[3]*W_Guard_Value+parameter[4]*W_Being_King_Value;
		n_BLACK_Value=parameter[0]*B_Pos_Value+parameter[1]*B_Fiexiblity_Value+parameter[2]*B_Attack_Value+parameter[3]*B_Guard_Value+parameter[4]*B_Being_King_Value;
	//���ù�ֵ���ĵĳ�ʼ��ֵ
		Tree++;
		if(Tree%1000==0)
			::PostMessage(AfxGetMainWnd()->m_hWnd,UPDATE_TREE,0,Tree);
	if (Type % 2 == 1)
		return n_BLACK_Value - n_WHITE_Value;
	else
		return n_WHITE_Value - n_BLACK_Value;
}
//double CEvelation::Eval(int position[10][10], int Type)//ԭʼ��ֵϵͳ
//{
//	//�趨�����Ļ�����ֵ
//	int WHITE_Basic_Value = 100;
//	int BLACK_Basic_Value = 100;
//	int W_KING_Basic_Value = 800;
//	int B_KING_Basic_Value = 800;
//
//
//	//�趨�ڡ���˫�����ܼ�ֵ�ĳ�ʼֵ
//	double n_WHITE_Value = 0;
//	double n_BLACK_Value = 0;
//	//������ֵָ������ĳ�ʼ��:
//	double W_Pos_Value = 0;//�׷�λ�ø���ֵ
//	double W_Fiexiblity_Value = 0;//�׷�����
//	double W_Attack_Value = 0;//�׷���в
//	double W_Guard_Value = 0;//�׷�����
//	double W_Being_King_Value = 0;//�׷�Ǳ�ڳ���λ�ý���
//	double B_Pos_Value = 0;//�׷�λ�ø���ֵ
//	double B_Fiexiblity_Value = 0;//�׷�����
//	double B_Attack_Value = 0;//�׷���в
//	double B_Guard_Value = 0;//�׷�����
//	double B_Being_King_Value = 0;//�׷�Ǳ�ڳ���λ�ý���
//								  //ɨ�����̶Ե�ǰ��������ӵļ�ֵ���м���
//	for (int i = 0; i <= 9; i++)
//		for (int j = 0; j <= 9; j++)
//		{
//			if (position[i][j] != EMPTY)//��ǰ�������ӵ������
//			{
//				switch (position[i][j])
//				{
//				case WHITE:
//				{
//					//һ�������ġ�λ�ø���ֵ�������ܼ�ֵ
//					W_Pos_Value += Get_Pawn_Pre_Value(i, j, position);
//					//���������ӵġ����ȡ������ܼ�ֵ
//					W_Fiexiblity_Value += (Fiexiblity_Count(i, j, position)*0.1*WHITE_Basic_Value);
//					//����������Լ������ӡ�����������ֵ���ϻ�����ֵ��0.1
//					if (Is_Guard_Pos(i, j, position))
//						W_Guard_Value += (0.5*WHITE_Basic_Value);
//					//�ġ�������Է�����в������ֵ��ȥ���������ֵ��һ��
//					if (Is_Attack_Pos(i, j, position, Type))
//						W_Attack_Value -= (0.6*WHITE_Basic_Value);
//					//�塢�߱�������Ǳ������λ�á��ı����н���
//					if (Is_Being_King(i, j, position, Type))
//						W_Being_King_Value += 100;
//					break;
//				}
//				case BLACK:
//				{
//					//һ�������ġ�λ�ø���ֵ�������ܼ�ֵ
//					B_Pos_Value += Get_Pawn_Pre_Value(i, j, position);
//					//���������ӵġ����ȡ������ܼ�ֵ
//					B_Fiexiblity_Value += (Fiexiblity_Count(i, j, position)*0.1*BLACK_Basic_Value);
//					//����������Լ������ӡ�����������ֵ���ϻ�����ֵ��0.1
//					if (Is_Guard_Pos(i, j, position))
//						B_Guard_Value += (0.5*BLACK_Basic_Value);
//					//�ġ�������Է�����в������ֵ��ȥ���������ֵ��һ��
//					if (Is_Attack_Pos(i, j, position, Type))
//						B_Attack_Value -= (0.6*BLACK_Basic_Value);
//					//�塢�߱�������Ǳ������λ�á��ı����н���
//					if (Is_Being_King(i, j, position, Type))
//						B_Being_King_Value += 100;
//					break;
//				}
//				case W_KING:
//				{
//					//һ�������ġ�λ�ø���ֵ�������ܼ�ֵ
//					W_Pos_Value += W_KING_Basic_Value;
//					//���������ӵġ����ȡ������ܼ�ֵ
//					W_Fiexiblity_Value += (Fiexiblity_Count(i, j, position)*0.1*W_KING_Basic_Value);
//					//����������Լ������ӡ�����������ֵ���ϻ�����ֵ��0.1
//					if (Is_Guard_Pos(i, j, position))
//						W_Guard_Value += (0.5*W_KING_Basic_Value);
//					//�ġ�������Է�����в������ֵ��ȥ���������ֵ��һ��
//					if (Is_Attack_Pos(i, j, position, Type))
//						W_Attack_Value -= (0.6*W_KING_Basic_Value);
//					break;
//				}
//				case B_KING:
//				{
//					//һ�������ġ�λ�ø���ֵ�������ܼ�ֵ
//					B_Pos_Value += B_KING_Basic_Value;
//					//���������ӵġ����ȡ������ܼ�ֵ
//					B_Fiexiblity_Value += (Fiexiblity_Count(i, j, position)*0.1*W_KING_Basic_Value);
//					//����������Լ������ӡ�����������ֵ���ϻ�����ֵ��0.1
//					if (Is_Guard_Pos(i, j, position))
//						B_Guard_Value += (0.5*W_KING_Basic_Value);
//					//�ġ�������Է�����в������ֵ��ȥ���������ֵ��һ��
//					if (Is_Attack_Pos(i, j, position, Type))
//						B_Attack_Value -= (0.6*W_KING_Basic_Value);
//					break;
//				}
//				}
//			}
//		}
//	//��ʼ����ָ���Ȩ�ز���
//	int parameter[5] = { 4,1,5,5,3 };
//	//�ۺϼ�����ڡ���˫�����ܼ�ֵ
//	//            ��һ����       λ�ø���ֵ  �ڶ�����       ����         ��������       ��в           ���ĸ���       ����          �������       Ǳ�ڳ�������
//	n_WHITE_Value = parameter[0] * W_Pos_Value + parameter[1] * W_Fiexiblity_Value + parameter[2] * W_Attack_Value + parameter[3] * W_Guard_Value + parameter[4] * W_Being_King_Value;
//	n_BLACK_Value = parameter[0] * B_Pos_Value + parameter[1] * B_Fiexiblity_Value + parameter[2] * B_Attack_Value + parameter[3] * B_Guard_Value + parameter[4] * B_Being_King_Value;
//	//���ù�ֵ���ĵĳ�ʼ��ֵ
//	Tree++;
//	if (Tree % 1000 == 0)
//		::PostMessage(AfxGetMainWnd()->m_hWnd, UPDATE_TREE, 0, Tree);
//	if (Type % 2 == 1)
//		return n_BLACK_Value - n_WHITE_Value;
//	else
//		return n_WHITE_Value - n_BLACK_Value;
//}

CString CEvelation::MFC_Eval(int position[10][10], int Type)
{
	Tree=0;
	//�趨�����Ļ�����ֵ
	int WHITE_Basic_Value = 100;
	int BLACK_Basic_Value = 100;
	int W_KING_Basic_Value = 800;
	int B_KING_Basic_Value = 800;
	
	//�趨�ڡ���˫�����ܼ�ֵ�ĳ�ʼֵ
	double n_WHITE_Value = 0;
	double n_BLACK_Value = 0;
	//������ֵָ������ĳ�ʼ��:
	double W_Pos_Value=0;//�׷�λ�ø���ֵ
	double W_Fiexiblity_Value=0;//�׷�����
	double W_Attack_Value=0;//�׷���в
	double W_Guard_Value=0;//�׷�����
	double W_Being_King_Value=0;//�׷�Ǳ�ڳ���λ�ý���
	double B_Pos_Value=0;//�׷�λ�ø���ֵ
	double B_Fiexiblity_Value=0;//�׷�����
	double B_Attack_Value=0;//�׷���в
	double B_Guard_Value=0;//�׷�����
	double B_Being_King_Value=0;//�׷�Ǳ�ڳ���λ�ý���
	//ɨ�����̶Ե�ǰ��������ӵļ�ֵ���м���
	for (int i = 0; i <= 9; i++)
		for (int j = 0; j <= 9; j++)
		{
		if (position[i][j] != EMPTY)//��ǰ�������ӵ������
		{
			switch (position[i][j])
			{
			case WHITE:
			{
				//һ�������ġ�λ�ø���ֵ�������ܼ�ֵ
				W_Pos_Value += Get_Pawn_Pre_Value(i, j, position);
				//���������ӵġ����ȡ������ܼ�ֵ
				W_Fiexiblity_Value += (Fiexiblity_Count(i, j, position)*0.1*WHITE_Basic_Value);
				//����������Լ������ӡ�����������ֵ���ϻ�����ֵ��0.1
				if (Is_Guard_Pos(i, j, position))
					W_Guard_Value += (0.5*WHITE_Basic_Value);
				//�ġ�������Է�����в������ֵ��ȥ���������ֵ��һ��
				if (Is_Attack_Pos(i, j, position, Type))
					W_Attack_Value -= (0.6*WHITE_Basic_Value);
				//�塢�߱�������Ǳ������λ�á��ı����н���
				if(Is_Being_King(i,j,position,Type))
					W_Being_King_Value +=100;
				break;
			}
			case BLACK:
			{
				//һ�������ġ�λ�ø���ֵ�������ܼ�ֵ
				B_Pos_Value += Get_Pawn_Pre_Value(i, j, position);
				//���������ӵġ����ȡ������ܼ�ֵ
				B_Fiexiblity_Value += (Fiexiblity_Count(i, j, position)*0.1*BLACK_Basic_Value);
				//����������Լ������ӡ�����������ֵ���ϻ�����ֵ��0.1
				if (Is_Guard_Pos(i, j, position))
					B_Guard_Value += (0.5*BLACK_Basic_Value);
				//�ġ�������Է�����в������ֵ��ȥ���������ֵ��һ��
				if (Is_Attack_Pos(i, j, position, Type))
					B_Attack_Value -= (0.6*BLACK_Basic_Value);
				//�塢�߱�������Ǳ������λ�á��ı����н���
				if(Is_Being_King(i,j,position,Type))
					B_Being_King_Value +=100;
				break;
			}
			case W_KING:
			{
				//һ�������ġ�λ�ø���ֵ�������ܼ�ֵ
				W_Pos_Value += W_KING_Basic_Value;
				//���������ӵġ����ȡ������ܼ�ֵ
				W_Fiexiblity_Value += (Fiexiblity_Count(i, j, position)*0.1*W_KING_Basic_Value);
				//����������Լ������ӡ�����������ֵ���ϻ�����ֵ��0.1
				if (Is_Guard_Pos(i, j, position))
					W_Guard_Value += (0.5*W_KING_Basic_Value);
				//�ġ�������Է�����в������ֵ��ȥ���������ֵ��һ��
				if (Is_Attack_Pos(i, j, position, Type))
					W_Attack_Value -= (0.6*W_KING_Basic_Value);
				break;
			}
			case B_KING:
			{
				//һ�������ġ�λ�ø���ֵ�������ܼ�ֵ
				B_Pos_Value += B_KING_Basic_Value;
				//���������ӵġ����ȡ������ܼ�ֵ
				B_Fiexiblity_Value += (Fiexiblity_Count(i, j, position)*0.1*W_KING_Basic_Value);
				//����������Լ������ӡ�����������ֵ���ϻ�����ֵ��0.1
				if (Is_Guard_Pos(i, j, position))
					B_Guard_Value += (0.5*W_KING_Basic_Value);
				//�ġ�������Է�����в������ֵ��ȥ���������ֵ��һ��
				if (Is_Attack_Pos(i,j,position,Type))
					B_Attack_Value -= (0.6*W_KING_Basic_Value);
				break;
			}
			}
		}
		}
		//��ʼ����ָ���Ȩ�ز���
		float parameter[5]={4.0,1.0,5.0,5.0,3.0};
		n_WHITE_Value=parameter[0]*W_Pos_Value+parameter[1]*W_Fiexiblity_Value+parameter[2]*W_Attack_Value+parameter[3]*W_Guard_Value+parameter[4]*W_Being_King_Value;
		n_BLACK_Value=parameter[0]*B_Pos_Value+parameter[1]*B_Fiexiblity_Value+parameter[2]*B_Attack_Value+parameter[3]*B_Guard_Value+parameter[4]*B_Being_King_Value;
		CString Eval_Mess;
		if(W_Attack_Value!=0)W_Attack_Value=-W_Attack_Value;
		if(B_Attack_Value!=0)B_Attack_Value=-B_Attack_Value;
		Eval_Mess.Format(
			"�׷��ܷ�:%05.f  λ��:%05.f  ���:%05.f  ��в:-%06.f  ����:%05.f  ����:%.0f\r\n�ڷ��ܷ�:%05.f  λ��:%05.f  ���:%05.f  ��в:-%05.f  ����:%05.f  ����:%.0f\r\n",
			n_WHITE_Value,
			parameter[0]*W_Pos_Value,
			parameter[1]*W_Fiexiblity_Value,
			parameter[2]*W_Attack_Value,
			parameter[3]*W_Guard_Value,
			parameter[4]*W_Being_King_Value,
			n_BLACK_Value,
			parameter[0]*B_Pos_Value,
			parameter[1]*B_Fiexiblity_Value,
			parameter[2]*B_Attack_Value,
			parameter[3]*B_Guard_Value,
			parameter[4]*B_Being_King_Value);
		return Eval_Mess;
}