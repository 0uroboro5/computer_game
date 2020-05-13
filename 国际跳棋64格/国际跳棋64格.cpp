//代码版本		2017年国赛 
//本代码由沈阳航空航天大学计算机博弈协会总负责人王跃霖统一调控
//国际跳棋组负责人黄倩所带博弈组开发维护
//本代码适用于中国大学生计算机博弈大赛交互协议
//本代码仅提供交互协议的用法示范和简单AI博弈思路，开发者需自行改进完善代码参赛
//如有意见和建议请与我们尽早联系
//王跃霖	QQ：836473734
//黄倩		QQ：2505649975
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

int a[8][8];             //����
int player = 1;				//player=1Ϊ�׷�  player=-1 Ϊ�ڷ�
int state = 0;				//state=0 Ϊ���ӿɳ�   ��1 Ϊ���ӱس�
int record[100][2];			//��¼�س�·��
int record1[20][2];         //��ʱ��¼�س�·��
int length;                  //�سԵĳ���
int length1;				//��ʱ��¼�سԵĳ���
int count;                   //�سԵ��м������

// ���º���ֻ��find �����е��ã�������Щ����������á�
//----------------------------------------------------------------
void Soilder(int, int);
void King(int, int);
void SoilderLeftUp(int, int);
void SoilderRightUp(int, int);
void SoilderLeftDown(int, int);
void SoilderRightDown(int, int);
void KingLeftUp(int, int);
void KingLeftDown(int, int);
void KingRightUp(int, int);
void KingRightDown(int, int);
//-----------------------------------------------------------------

void draw();                //������
void start();				//��ʼʱ ���в���
void go();				//����
void change();	        //�ڰ��彻��λ��		
void change1();
void find();            //�� �Ƿ��бسԵ�����
void findlongest();     //�ҵ��س��г��������ĳԷ�

int main()
{
	start();
	draw();
}

void start()
{
	a[0][1] = -1;	a[0][3] = -1;	a[0][5] = -1;	a[0][7] = -1;
	a[1][0] = -1;   a[1][2] = -1;   a[1][4] = -1;   a[1][6] = -1;
	a[2][1] = -1;   a[2][3] = -1;   a[2][5] = -1;   a[2][7] = -1;
	a[3][0] = 0;   a[3][2] = 0;   a[3][4] = 0;   a[3][6] = 0;
	a[4][1] = 0;   a[4][3] = 0;   a[4][5] = 0;	 a[4][7] = 0;
	a[5][0] = 1;   a[5][2] = 1;   a[5][4] = 1;   a[5][6] = 1;
	a[6][1] = 1;   a[6][3] = 1;   a[6][5] = 1;   a[6][7] = 1;
	a[7][0] = 1;   a[7][2] = 1;   a[7][4] = 1;   a[7][6] = 1;
}

void draw()
{
	printf("������������������������������������������\n ");
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (a[i][j] == 1)
				printf("| �� ");
			if (a[i][j] == -1)
				printf("| �� ");
			if (a[i][j] == 0)
				printf("|    ");
			if (a[i][j] == 2)
				printf("| �� ");
			if (a[i][j] == -2)
				printf("| �� ");
		}
		printf("|  %d\n������������������������������������������\n ", i+1);
	}
	printf("  1    2    3    4    5    6     7    8   \n\n\n");
	if (player==1)
	find();
	if (player == -1)
	change();
}

void change()
{
	int b[4][8];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 8; j++)
		{
			b[i][j] = a[i][j];
			a[i][j] = -a[7 - i][7 - j];
			a[7 - i][7 - j] = -b[i][j];
		}
	find();
}

void change1()
{
	int b[4][8];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 8; j++)
		{
			b[i][j] = a[i][j];
            a[i][j] = -a[7 - i][7 - j];
			a[7 - i][7 - j] = -b[i][j];
}
	draw();
}

void go()
{
	if (player == 1)
		printf("��׷����� ��ʽΪ�� ");
	else
		printf("��ڷ����� ��ʽΪ�� ");

	if (state == 0)      //���� ��
	{
		int X1, Y1, X2, Y2, k;
		printf("\n  X1���㣩Y1���ո�X2���㣩Y2     �磨1.1 2.2��\n\n");
		scanf("%d.%d %d.%d", &X1, &Y1, &X2, &Y2);

		X1 = X1 - 1;
		Y1 = Y1 - 1;
		X2 = X2 - 1;
		Y2 = Y2 - 1;

		if (player == -1)            // ����λ��
		{
			X1 = 7 - X1;
			Y1 = 7 - Y1;
			X2 = 7 - X2;
			Y2 = 7 - Y2;
		}


		if (X1 >= 0 && X1 < 8 && Y1 >= 0 && Y1 < 8 && X2 >= 0 && X2 < 8 && Y2 >= 0 && Y2 < 8 && a[X2][Y2] == 0 && (a[X1][Y1] == 1 || a[X1][Y1] == 2))
		{
			if (a[X1][Y1] == 1 && X2 == X1 - 1 && (Y2 == Y1 + 1 || Y2 == Y1 - 1))        //����
			{
				a[X1][Y1] = 0;
				a[X2][Y2] = 1;
			}

			else if (a[X1][Y1] == 2 && (X1 -X2==Y1-Y2 || X1-X2==Y2-Y1))															//����
			{
				if (X1 < X2)
				{
					int X = X1;
					X1 = X2;
					X2 = X;
				}

				k = 0;
				for (int K=1;K<X1-X2;K++)
					{
						if (a[X2+K][Y2+K] != 0)
						{
							k = k + 1;
						}
					}

				if (k != 0)
				{
					printf("����������.\n");
					go();
				}
				else
				{
					a[X1][Y1] = 0;
					a[X2][Y2] = 2;
				}
			}

			else
			{
				printf("���������룺");
				go();
			}

		}
		else
		{
			printf("���������룺");
			go();
		}
	}

	if (state == 1)   //�س�
	{
		int N;
		printf("��������ţ�\n");
		for (int i = 1; i <= count; i++)
		{
			printf("%d.  ", i);
			printf("%d.", record[(length + 1)*(i-1)][0] + 1);
			printf("%d.", record[(length + 1)*(i-1)][1] + 1);
			for (int j = 1; j <= length; j++)
			{
				printf("----%d.", record[(length + 1)*(i - 1) + j][0] + 1);
				printf("%d", record[(length + 1)*(i - 1) + j][1] + 1);
			}
			printf("\n");
		}

		scanf("%d", &N);
		if (N > count)
		{
			printf("���������룺\n");
			go();
		}
		else
		{
			if (player == -1)
				for (int k = 0; k <= (length + 1)*(count - 1) + length; k++)
				{
					record[k][0] = 7 - record[k][0];
					record[k][1] = 7 - record[k][1];
				}

			if (a[record[(length + 1)*(N - 1)][0]][record[(length + 1)*(N - 1)][1]] == 1) //�����
				{
					a[record[(length + 1)*(N - 1)][0]][record[(length + 1)*(N - 1)][1]] = 0;
					a[record[(length + 1)*(N - 1) + length][0]][record[(length + 1)*(N - 1) + length][1]] = 1;
					for (int j = 1; j <= length; j++)
						{
							a[(record[(length + 1)*(N - 1) + (j - 1)][0] + record[(length + 1)*(N - 1) + j][0]) / 2][(record[(length + 1)*(N - 1) + (j - 1)][1] + record[(length + 1)*(N - 1) + j][1]) / 2] = 0;
						}
				}

			else if (a[record[(length + 1)*(N - 1)][0]][record[(length + 1)*(N - 1)][1]] == 2)         //�����
				{
					a[record[(length + 1)*(N - 1)][0]][record[(length + 1)*(N - 1)][1]] = 0;
					a[record[(length + 1)*(N - 1) + length][0]][record[(length + 1)*(N - 1) + length][1]] = 2;
					for (int j = 1; j <= length; j++)
					{
						if (record[(length + 1)*(N - 1) + (j - 1)][0] > record[(length + 1)*(N - 1) + j][0] && record[(length + 1)*(N - 1) + (j - 1)][1] > record[(length + 1)*(N - 1) + j][1])
						{       //���µ����� ��λ
							int temp;
							temp=record[(length + 1)*(N - 1) + (j - 1)][0];
							record[(length + 1)*(N - 1) + (j-1)][0] = record[(length + 1)*(N - 1) + j][0];
							record[(length + 1)*(N - 1) + j][0] = temp;

							temp = record[(length + 1)*(N - 1) + (j - 1)][1];
							record[(length + 1)*(N - 1) + (j - 1)][1] = record[(length + 1)*(N - 1) + j][1];
							record[(length + 1)*(N - 1) + j][1] = temp;
						}
						else if (record[(length + 1)*(N - 1) + (j - 1)][0] > record[(length + 1)*(N - 1) + j][0] && record[(length + 1)*(N - 1) + (j - 1)][1] < record[(length + 1)*(N - 1) + j][1])
						{       //���µ����� ��λ;
							int temp;
							temp = record[(length + 1)*(N - 1) + (j - 1)][0];
							record[(length + 1)*(N - 1) + (j - 1)][0] = record[(length + 1)*(N - 1) + j][0];
							record[(length + 1)*(N - 1) + j][0] = temp;

							temp = record[(length + 1)*(N - 1) + (j - 1)][1];
							record[(length + 1)*(N - 1) + (j - 1)][1] = record[(length + 1)*(N - 1) + j][1];
							record[(length + 1)*(N - 1) + j][1] = temp;
						}

						if (record[(length + 1)*(N - 1) + (j - 1)][0] < record[(length + 1)*(N - 1) + j][0] && record[(length + 1)*(N - 1) + (j - 1)][1] < record[(length + 1)*(N - 1) + j][1])
						{		//���ϵ����� + +

							for (int k = 1; k < record[(length + 1)*(N - 1) + j][0] - record[(length + 1)*(N - 1) + (j - 1)][0]; k++)
							{
								if (a[(record[(length + 1)*(N - 1) + (j - 1)][0]) + k][record[(length + 1)*(N - 1) + (j - 1)][1] + k] == -1 || a[(record[(length + 1)*(N - 1) + (j - 1)][0]) + k][record[(length + 1)*(N - 1) + (j - 1)][1] + k] == -2)
								{
									a[(record[(length + 1)*(N - 1) + (j - 1)][0]) + k][record[(length + 1)*(N - 1) + (j - 1)][1] + k] = 0;
									break;
								}

							}
						}
						else if (record[(length + 1)*(N - 1) + (j - 1)][0] < record[(length + 1)*(N - 1) + j][0] && record[(length + 1)*(N - 1) + (j - 1)][1] > record[(length + 1)*(N - 1) + j][1])
						{		//���ϵ�����   + -
							for (int k = 1; k < record[(length + 1)*(N - 1) + j][0] - record[(length + 1)*(N - 1) + (j - 1)][0]; k++)
							{
								if (a[(record[(length + 1)*(N - 1) + (j - 1)][0]) + k][record[(length + 1)*(N - 1) + (j - 1)][1] - k] == -1 || a[(record[(length + 1)*(N - 1) + (j - 1)][0]) + k][record[(length + 1)*(N - 1) + (j - 1)][1] - k] == -2)
								{
									a[(record[(length + 1)*(N - 1) + (j - 1)][0]) + k][record[(length + 1)*(N - 1) + (j - 1)][1] - k] = 0;
									break;
								}

							}
						}
					}
				}
		}
	}
	

	for (int i = 0; i < 100; i++)                       //��ԭ��¼
		for (int j = 0; j < 2; j++)
			record[i][j] = 0;
	length = 0;
	count = 0;

	for (int j = 1; j <= 7; j++)                           //����
		if (a[0][j] == 1)
			a[0][j] = 2;

	int number = 0;                                //������һ�����Ӹ���
	for (int i = 0; i <= 7; i++)
		for (int j = 0; j <= 7; j++)
			if (a[i][j] == -1 || a[i][j] == -2)
				number = number + 1;

	if (number == 0)
	{
		printf("����");
		if (player == 1)
			printf("�׷�ʤ");
		else if (player == -1)
			printf("�ڷ�ʤ");
		system("pause");
	}

	else
	{
		player = -player;
		if (player == -1)
			draw();
		else
			change1();
	}
}

void find()
{
	state = 0;

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if (a[i][j] == 1)
			{
				for (int i1 = 0; i1 < 20; i1++)
					for (int j1=0; j1 < 2; j1++)
						record1[i1][j1] = 0;
				length1 = 0;

				record1[0][0] = i;
				record1[0][1] =j;
				Soilder(i, j);
			}
		}

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if (a[i][j] == 2)
			{
				for (int i1 = 0; i1 < 20; i1++)
					for (int j1 = 0; j1 <= 2; j1++)
						record1[i1][j1] = 0;
				length1 = 0;

				record1[0][0] = i;
				record1[0][1] = j;
				King(i, j);
			}
		}
		go();
}

void findlongest()
{
	if (length1 > length)
	{
		length = length1;
		count = 1;

		if (player == -1)
		{
			record[0][0] = 7 - record1[0][0];
			record[0][1] = 7 - record1[0][1];
		}
		else
		{
			record[0][0] = record1[0][0];
			record[0][1] = record1[0][1];
		}

		for (int i = 1; i <= length; i++)
		{
			record[i][0] = record1[i][0];
			record[i][1] = record1[i][1];
		}
	}

	else if (length1 == length)
	{
		if (player == -1)
		{
			record[(length + 1)*count][0] = 7-record1[0][0];
			record[(length + 1)*count][1] = 7-record1[0][1];
		}
		else
		{
			record[(length + 1)*count][0] = record1[0][0];
			record[(length + 1)*count][1] = record1[0][1];
		}

		for (int i = 1; i <=length; i++)
		{
			record[(length + 1)*count + i][0] = record1[i][0];
			record[(length + 1)*count + i][1] = record1[i][1];
		}
		count = count + 1;
	}
	length1 = length1 - 1;
}

void Soilder(int i, int j)
{
	if (i < 2)
	{
		if (j <= 1)
		{
			if ((a[i + 1][j + 1] == -1 || a[i + 1][j + 1] == -2) && a[i + 2][j + 2] == 0)
			{
				SoilderRightDown(i, j);
				findlongest();
			}
		}
		else if (j > 1 && j < 6)
		{
			if ((a[i + 1][j + 1] == -1 || a[i + 1][j + 1] == -2) && a[i + 2][j + 2] == 0)
			{
				SoilderRightDown(i, j);
				findlongest();
			}
			if ((a[i + 1][j - 1] == -1 || a[i + 1][j - 1] == -2) && a[i + 2][j - 2] == 0)
			{
				SoilderLeftDown(i, j);
				findlongest();
			}
		}
		else
		{
			if ((a[i + 1][j - 1] == -1 || a[i + 1][j - 1] == -2) && a[i + 2][j - 2] == 0)
			{
				SoilderLeftDown(i, j);
				findlongest();
			}
		}
	}

	else if (i >= 2 && i <= 5)
	{
		if ((j == 0 || j == 1))
		{
			if ((a[i - 1][j + 1] == -1 || a[i - 1][j + 1] == -2) && a[i - 2][j + 2] == 0)
			{
				SoilderRightUp(i, j);
				findlongest();
			}

			if ((a[i + 1][j + 1] == -1 || a[i + 1][j + 1] == -2) && a[i + 2][j + 2] == 0)
			{
				SoilderRightDown(i, j);
				findlongest();
			}
		}

		else if (j > 1 && j < 6)
		{
			if ((a[i - 1][j - 1] == -1 || a[i - 1][j - 1] == -2) && a[i - 2][j - 2] == 0)
			{
				SoilderLeftUp(i, j);
				findlongest();
			}
			if ((a[i - 1][j + 1] == -1 || a[i - 1][j + 1] == -2) && a[i - 2][j + 2] == 0)
			{
				SoilderRightUp(i, j);
				findlongest();
			}
			if ((a[i + 1][j - 1] == -1 || a[i + 1][j - 1] == -2) && a[i + 2][j - 2] == 0)
			{
				SoilderLeftDown(i, j);
				findlongest();
			}
			if ((a[i + 1][j + 1] == -1 || a[i + 1][j + 1] == -2) && a[i + 2][j + 2] == 0)
			{
				SoilderRightDown(i, j);
				findlongest();
			}
		}

		else if ((j == 6 || j == 7))
		{
			if ((a[i - 1][j - 1] == -1 || a[i - 1][j - 1] == -2) && a[i - 2][j - 2] == 0)
			{
			
			SoilderLeftUp(i, j);
			findlongest();
			}
			if ((a[i + 1][j - 1] == -1 || a[i + 1][j - 1] == -2) && a[i + 2][j - 2] == 0)
			{
				SoilderLeftDown(i, j);
				findlongest();
			}
		}
	}

	else
	{
		if (j <= 1)
		{
			if ((a[i - 1][j + 1] == -1 || a[i - 1][j + 1] == -2) && a[i - 2][j + 2] == 0)
			{
				SoilderRightUp(i, j);
				printf("SoilderRightUp\n");
				findlongest();
			}
		}
		else if (j > 1 && j < 6)
		{
			if ((a[i - 1][j + 1] == -1 || a[i - 1][j + 1] == -2) && a[i - 2][j + 2] == 0)
			{
				SoilderRightUp(i, j);
				printf("SoilderRightUp\n");
				findlongest();
			}
			if ((a[i - 1][j - 1] == -1 || a[i - 1][j - 1] == -2) && a[i - 2][j - 2] == 0)
			{
				SoilderLeftUp(i, j);
				printf("SoilderLeftUp\n");
				findlongest();
			}
		}
		else
		{
			if ((a[i - 1][j - 1] == -1 || a[i - 1][j - 1] == -2) && a[i - 2][j - 2] == 0)
			{
				SoilderLeftUp(i, j);
				printf("SoilderLeftUp\n");
				findlongest();
			}
		}
	}
}

void SoilderLeftUp(int i, int j)
{
	length1 = length1 + 1;
	record1[length1][0] = i - 2;
	record1[length1][1] = j - 2;

	if (player == -1)
	{
		record1[length1][0] = 7 - (i - 2);
		record1[length1][1] = 7 - (j - 2);
	}

	int k;
	a[i][j] = 0;
	k = a[i - 1][j - 1];
	a[i - 1][j - 1] = 0;
	a[i - 2][j - 2] = 1;
	state = 1;                                     //�ı�״̬
	Soilder(i - 2, j - 2);

	a[i][j] = 1;									  //��ԭ
	a[i - 1][j - 1] = k;
	a[i - 2][j - 2] = 0;
}

void SoilderRightUp(int i, int j)
{
	length1 = length1 + 1;
	record1[length1][0] = i - 2;
	record1[length1][1] = j + 2;

	if (player == -1)
	{
		record1[length1][0] = 7 - (i - 2);
		record1[length1][1] = 7 - (j + 2);
	}

	int k;
	a[i][j] = 0;
	k = a[i - 1][j + 1];
	a[i - 1][j + 1] = 0;
	a[i - 2][j + 2] = 1;
	state = 1;                                          //�ı�״̬
	Soilder(i - 2, j + 2);

	a[i][j] = 1;                                        //��ԭ
	a[i - 1][j + 1] = k;
	a[i - 2][j + 2] = 0;
}

void SoilderLeftDown(int i, int j)
{
	length1 = length1 + 1;
	record1[length1][0] = i + 2;
	record1[length1][1] = j - 2;

	if (player == -1)
	{
		record1[length1][0] = 7 - (i + 2);
		record1[length1][1] = 7 - (j - 2);
	}

	int k;
	a[i][j] = 0;
	k = a[i + 1][j - 1];
	a[i + 1][j - 1] = 0;
	a[i + 2][j - 2] = 1;
	state = 1;                                     //�ı�״̬
	Soilder(i + 2, j - 2);

	a[i][j] = 1;									  //��ԭ
	a[i + 1][j - 1] = k;
	a[i + 2][j - 2] = 0;
}

void SoilderRightDown(int i, int j)
{
	length1 = length1 + 1;
	record1[length1][0] = i + 2;
	record1[length1][1] = j + 2;

	if (player == -1)
	{
		record1[length1][0] = 7 - (i + 2);
		record1[length1][1] = 7 - (j + 2);
	}

	int k;
	a[i][j] = 0;
	k = a[i + 1][j + 1];
	a[i + 1][j + 1] = 0;
	a[i + 2][j + 2] = 1;
	state = 1;                                          //�ı�״̬
	Soilder(i + 2, j + 2);

	a[i][j] = 1;                                        //��ԭ
	a[i + 1][j + 1] = k;
	a[i + 2][j + 2] = 0;
}

void King(int i, int j)
{
	if (i < 2)
	{
		if (j < 2)
			KingRightDown(i, j);
		else if (j < 6)
		{
			KingLeftDown(i, j);
			KingRightDown(i, j);
		}
		else
			KingLeftDown(i, j);
	}

	else if (i < 6)
	{
		if (j < 2)
		{
			KingRightUp(i, j);
			KingRightDown(i, j);
		}
		else if (j < 6)
		{
			KingLeftUp(i, j);
			KingRightUp(i, j);
			KingLeftDown(i, j);
			KingRightDown(i, j);
		}
		else
		{
			KingLeftUp(i, j);
			KingLeftDown(i, j);
		}
	}

	else
	{
		if (j < 2)
			KingRightUp(i, j);
		else if (j < 6)
		{
			KingLeftUp(i, j);
			KingRightUp(i, j);
		}
		else
			KingLeftUp(i, j);
	}
}

void KingLeftUp(int i, int j)
{
	for(int k=1;i-k>=1 && j-k>=1;k++)
		if ((a[i - k][j - k] == -1 || a[i - k][j - k] == -2) && a[i - k - 1][j - k - 1] == 0)
		{
			a[i][j] = 0;
			int i1 = i - k;                            //a[i1][j1]�Ǳ��Ե���
			int j1 = j - k;
			k = a[i1][j1];
			a[i1][j1] = 0;

			for (int k1 = 1; i1 - k1 >= 0 && j1 - k1 >= 0; k1++)
				if (a[i1 - k1][j1 - k1] == 0)
				{
					
					int i2 = i1 - k1;
					int j2 = j1 - k1;
					a[i2][j2] = 2;

					length1 = length1 + 1;
					record1[length1][0] = i2;
					record1[length1][1] = j2;
					if (player == -1)
					{
						record1[length1][0] = 7 - i2;
						record1[length1][1] = 7 - j2;
					}

					state = 1;                          //�ı�״̬
					King(i2, j2);

					a[i2][j2] = 0;

					findlongest();
				}
			a[i][j] = 2;						//��ԭ
			a[i1][j1] = k;
		break;
		}
}

void KingLeftDown(int i, int j)
{
	for (int k = 1; i + k <= 6 && j - k >= 1; k++)
		if ((a[i + k][j - k] == -1 || a[i + k][j - k] == -2) && a[i + k + 1][j - k - 1] == 0)
		{
			a[i][j] = 0;
			int i1 = i + k;                            //a[i1][j1]�Ǳ��Ե���
			int j1 = j - k;
			k = a[i1][j1];
			a[i1][j1] = 0;

			for (int k1 = 1; i1 + k1 <=7 && j1 - k1 >= 0; k1++)
				if (a[i1 + k1][j1 - k1] == 0)
				{

					int i2 = i1 + k1;
					int j2 = j1 - k1;
					a[i2][j2] = 2;

					length1 = length1 + 1;
					record1[length1][0] = i2;
					record1[length1][1] = j2;
					if (player == -1)
					{
						record1[length1][0] = 7 - i2;
						record1[length1][1] = 7 - j2;
					}

					state = 1;                          //�ı�״̬
					King(i2, j2);

					a[i2][j2] = 0;

					findlongest();
				}
			a[i][j] = 2;						//��ԭ
			a[i1][j1] = k;
			break;
		}

}

void KingRightUp(int i, int j)
{
	for (int k = 1; i - k >= 1 && j + k <= 6; k++)
		if ((a[i - k][j + k] == -1 || a[i - k][j + k] == -2) && a[i - k - 1][j + k + 1] == 0)
		{
			a[i][j] = 0;
			int i1 = i - k;                            //a[i1][j1]�Ǳ��Ե���
			int j1 = j + k;
			k = a[i1][j1];
			a[i1][j1] = 0;

			for (int k1 = 1; i1 - k1 >= 0 && j1 + k1 <= 7; k1++)
				if (a[i1 - k1][j1 + k1] == 0)
				{

					int i2 = i1 - k1;
					int j2 = j1 + k1;
					a[i2][j2] = 2;

					length1 = length1 + 1;
					record1[length1][0] = i2;
					record1[length1][1] = j2;
					if (player == -1)
					{
						record1[length1][0] = 7 - i2;
						record1[length1][1] = 7 - j2;
					}

					state = 1;                          //�ı�״̬
					King(i2, j2);

					a[i2][j2] = 0;

					findlongest();
				}
			a[i][j] = 2;						//��ԭ
			a[i1][j1] = k;
			break;
		}
}

void KingRightDown(int i, int j)
{
	for (int k = 1; i + k <= 6 && j + k <=6; k++)
		if ((a[i + k][j + k] == -1 || a[i + k][j + k] == -2) && a[i + k + 1][j + k + 1] == 0)
		{
			a[i][j] = 0;
			int i1 = i + k;                            //a[i1][j1]�Ǳ��Ե���
			int j1 = j + k;
			k = a[i1][j1];
			a[i1][j1] = 0;

			for (int k1 = 1; i1 + k1 <=7 && j1 + k1 <=7; k1++)
				if (a[i1 + k1][j1 + k1] == 0)
				{

					int i2 = i1 + k1;
					int j2 = j1 + k1;
					a[i2][j2] = 2;

					length1 = length1 + 1;
					record1[length1][0] = i2;
					record1[length1][1] = j2;
					if (player == -1)
					{
						record1[length1][0] = 7 - i2;
						record1[length1][1] = 7 - j2;
					}

					state = 1;                          //�ı�״̬
					King(i2, j2);

					a[i2][j2] = 0;            //��ԭ

					findlongest();
				}
			a[i][j] = 2;						//��ԭ
			a[i1][j1] = k;
			break;
		}
}
