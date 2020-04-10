#include "stdafx.h"
#include "Competition.h"

using namespace std;

void Match()
{
	srand((unsigned)time(NULL));						//���������
	int AI;												//AI��
	int Dice;											//����
	int win = 0;									    //ʤ����1���췽��-1��������
	int player;											//��ǰ���ӷ�
	while (1)
	{
		stack<Move_Recording> Recording;				//���̼�¼
		player = -1;						
		win = 0;										//ÿ�غϿ�ʼ��ʼʤ��
		int temp;										//�߼�ת����ʱ����
		system("cls");
		cout << "��ӭ��������֮ʯ\n" << endl;
		int BOARD[5][5] = { 0 };					    //��ʼ������
		print();
		cout << "����췽���Ӱڲ�:(1,1)(1,2)(1,3)(2,1)(2,2)(3,1)" << endl << "���磺��123456��" << endl;
		cin >> temp;
		int piece;
		for (int i = 6; i >0; i--)
		{
			piece = temp % 10;
			temp = (temp - piece) / 10;
			switch (i)
			{
			case 1:BOARD[0][0] = piece; break;
			case 2:BOARD[0][1] = piece; break;
			case 3:BOARD[0][2] = piece; break;
			case 4:BOARD[1][0] = piece; break;
			case 5:BOARD[1][1] = piece; break;
			case 6:BOARD[2][0] = piece; break;
			}
		}
		cout << "�����������Ӱڲ�:(5,5)(5,4)(5,3)(4,5)(4,4)(3,5)" << endl << "���磺��123456��" << endl;
		cin >> temp;
		for (int i = 6; i >0; i--)
		{
			piece = temp % 10;
			temp = (temp - piece) / 10;
			switch (i)
			{
			case 1:BOARD[4][4] = -piece; break;
			case 2:BOARD[4][3] = -piece; break;
			case 3:BOARD[4][2] = -piece; break;
			case 4:BOARD[3][4] = -piece; break;
			case 5:BOARD[3][3] = -piece; break;
			case 6:BOARD[2][4] = -piece; break;
			}
		}
		cout << "�� 0 ��AI�췽       �� 1 ��AI���� " << endl;
		cin >> AI;
		while (AI != 0 && AI != 1)
		{
			cout << "��ʲô��Ц�����������룺" << endl;
			cin >> AI;
		}
		AI = -(AI * 2 - 1);                  //1Ϊ�죬-1Ϊ��
		Board CB(BOARD);
		while (1)
		{
			CB.show();
			cout << "����������0������������岽��" << endl;
			cin >> temp;
			while (temp > CB.GetStep())
			{
				cout << "����ô���ص��峯?�������룡" << endl;
				cin >> temp;
			}
			if (temp % 2 == 1)
				player *= -1;
			CB.Regret_Game(Recording, temp);
			CB.show();
			CB.GameState();
			win = CB.Winner();
			if (win == 1)
			{
				cout << "�췽��ʤ����" << endl;
				system("pause");
				break;
			}
			else if (win == -1)
			{
				cout << "������ʤ����" << endl;
				system("pause");
				break;
			}
			else
			{
				player = player*-1;
				if (player == AI)
				{
					cout << "������Ϊ:" << endl;
					cin >> Dice;
					while (Dice < 1 || Dice>6)
					{
						cout << "Ƥ���������룡" << endl;
						cin >> Dice;
					}
					cout << "����س�ȷ��AI����" << endl;
					if (AI == 1)
						cout << "�췽";
					else
						cout << "����";
					cout << "AI����˼����..." << endl;
					MonteCarloMove(CB, AI*Dice, 1, Recording);
					system("pause");
				}
				else
				{
					if (player == 1)
						cout << "�췽";
					else
						cout << "����";
					cout << "���� �յ�(xy)" << endl << "���磺��1 22��" << endl;
					cin >> Dice >> temp;
					while (!CB.IsAlive(player*Dice) || temp < 11 || temp > 55 || temp % 10 == 0)
					{
						cout << "�㲻ҪϹ��÷����������룡" << endl;
						cin >> Dice >> temp;
					}
					Loc loc;
					loc.Set(temp / 10 - 1, temp % 10 - 1);
					Move_Recording temp;
					temp.Set(CB.GetPiece(player*Dice), loc, CB.GetPiece(loc));
					Recording.push(temp);
					CB.Move(loc, player*Dice);
				}
			}
		}
	}
}
