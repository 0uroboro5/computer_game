#include "stdafx.h"
#include "makeNowMoves.h"
#include<cstdlib>
bool makeNowMoves::BING_FOUR_DIRECTION_CAN_EAT(int nowX,int nowY) 
{		
	if(((board[nowX+directions[0][0]][nowY+directions[0][1]]==3-nowColor||board[nowX+directions[0][0]]
		[nowY+directions[0][1]]==3-nowColor+2)&&board[nowX+2*directions[0][0]][nowY+2*directions[0][1]]
		==EMPTY&&nowX+2*directions[0][0]>=0&&nowX+2*directions[0][0]<10&&nowY+2*directions[0][1]>=0&&
		nowY+2*directions[0][1]<10)||
		((board[nowX+directions[1][0]][nowY+directions[1][1]]==3-nowColor||board[nowX+directions[1][0]]
		   [nowY+directions[1][1]]==3-nowColor+2)&&board[nowX+2*directions[1][0]][nowY+2*directions[1]
		   [1]]==EMPTY&&nowX+2*directions[1][0]>=0&&nowX+2*directions[1][0]<10&&nowY+2*directions[1][1]>=0&&
		   nowY+2*directions[1][1]<10)||
	   ((board[nowX+directions[2][0]][nowY+directions[2][1]]==3-nowColor||board[nowX+directions[2][0]]
		   [nowY+directions[2][1]]==3-nowColor+2)&&board[nowX+2*directions[2][0]][nowY+2*directions[2]
		   [1]]==EMPTY&&nowX+2*directions[2][0]>=0&&nowX+2*directions[2][0]<10&&nowY+2*directions[2][1]>=0&&
		   nowY+2*directions[2][1]<10)||
	   ((board[nowX+directions[3][0]][nowY+directions[3][1]]==3-nowColor||board[nowX+directions[3][0]]
		   [nowY+directions[3][1]]==3-nowColor+2)&&board[nowX+2*directions[3][0]][nowY+2*directions[3][1]]==EMPTY&&
		   nowX+2*directions[3][0]>=0&&nowX+2*directions[3][0]<10&&nowY+2*directions[3][1]>=0&&nowY+2*directions[3][1]<10))
		return true;
	else 
		return false;
}

makeNowMoves::makeNowMoves(void)//��ʼ������
{
	int i,j;
	for(j=0;j<10;j++)
		for(i=0;i<10;i++)
			board[i][j]=EMPTY;
	for(j=0;j<5;j++)
		for(i=0;i<10;i++)
			if((i+j)%2==0)
				board[i][j]=WHITE;
	for(j=6;j<=9;j++)
		for(i=0;i<10;i++)
			if((i+j)%2==0)
				board[i][j]=BLACK;
}


makeNowMoves::~makeNowMoves(void)
{
}


void makeNowMoves::copy(int Color,int Board[][10])//��ȡ��ǰ��������Ϣ���͵�ǰ�����ӷ���ÿ�������з�
{													//����Ҫ��ʼ��theBestEatNum��nowTheNumberOfMove
	for(int j=0;j<10;j++)
		for(int i=0;i<10;i++)
		board[i][j]=Board[i][j];
	nowColor=Color;
	theBestEatNum=0;
	nowTheNumberOfMove=0;
}


int makeNowMoves::allMove(int board[][10],MOVE movesCoutainer[200],int Color)
{
	//Sleep(10);
	copy(Color,board);
	for(int j=0;j<10;j++)
		for(int i=0;i<10;i++)
		{
			int nowX=i;
			int nowY=j;
			
			
			//�����߷�����
			if(board[i][j]==nowColor)//�����ǰ�����Ǳ�
			{
				nowTheMove.Kind=nowColor;
				if(BING_FOUR_DIRECTION_CAN_EAT(nowX,nowY))
				{
					nowTheMove.move_star_x=nowX;
					nowTheMove.move_star_y=nowY;
					makeNowBingMove(i,j,0,movesCoutainer);//���ɵ�ǰ���ܳԵ��з�
				}
				else//��������ܳ��ڿ����
				{
					if(theBestEatNum==0&&board[nowX+directions[nowColor-1][0]][nowY+directions[nowColor-1][1]]==EMPTY&&(nowX+directions[nowColor-1][0])<10&&(nowX+directions[nowColor-1][0])>=0&&(nowY+directions[nowColor-1][1])<10&&(nowY+directions[nowColor-1][1])>=0)//�����ǰ����ָ
					{																								  //���£��������ǰ��������
						nowTheMove.move_star_x=nowX;
						nowTheMove.move_star_y=nowY;
						nowTheMove.move_stop_x=nowX+directions[nowColor-1][0];
						nowTheMove.move_stop_y=nowY+directions[nowColor-1][1];
						nowTheMove.eatHowMany=0;

						//cout<<nowTheNumberOfMove<<endl;
						//if(nowTheNumberOfMove>=50)
						//{
						//	cout<<"�����A��"<<nowTheNumberOfMove<<endl;
						//	system("pause");
						//}


						movesCoutainer[nowTheNumberOfMove]=nowTheMove;
						nowTheNumberOfMove++;
					}
					if(theBestEatNum==0&&board[nowX+directions[nowColor+1][0]][nowY+directions[nowColor+1][1]]==EMPTY&&(nowX+directions[nowColor+1][0])<10&&(nowX+directions[3][0])>=0&&(nowY+directions[nowColor+1][1])<10&&(nowY+directions[nowColor+1][1])>=0)
					{
						nowTheMove.move_star_x=nowX;
						nowTheMove.move_star_y=nowY;
						nowTheMove.move_stop_x=nowX+directions[nowColor+1][0];
						nowTheMove.move_stop_y=nowY+directions[nowColor+1][1];
						nowTheMove.eatHowMany=0;

						////cout<<nowTheNumberOfMove<<endl;
						//if(nowTheNumberOfMove>=50)
						//{
						//	cout<<"�����B��"<<nowTheNumberOfMove<<endl;
						//	system("pause");
						//}

						movesCoutainer[nowTheNumberOfMove]=nowTheMove;
						nowTheNumberOfMove++;

					}
				}
			}
		//������߷�����
		if(board[i][j]==nowColor+2)//�����ǰ����������
				{
					nowTheMove.Kind=nowColor+2;
					nowTheMove.move_star_x=nowX;
					nowTheMove.move_star_y=nowY;
					if(KING_FOUR_DIRECTION_CAN_EAT(nowX,nowY))
					{
						makeNowKingMove(i,j,0,movesCoutainer);//���ɵ�ǰ�����з�
					}
					else
					{	
						int recordTheX=nowTheMove.move_star_x=nowX;
						int recordTheY=nowTheMove.move_star_y=nowY;
						int howLong=0;
						//���ж���������ܲ����ߣ�if������ô�����������˼						
						for(int k=0;k<4;k++)
						{
							if(theBestEatNum==0&&board[nowX+directions[k][0]][nowY+directions[k][1]]==EMPTY&&nowX+directions[k][0]>=0&&nowX+directions[k][0]<10&&nowY+directions[k][1]>=0&&nowY+directions[k][1]<10)
							{
								while(board[nowX+directions[k][0]][nowY+directions[k][1]]==EMPTY&&nowX+directions[k][0]>=0&&nowX+directions[k][0]<10&&nowY+directions[k][1]>=0&&nowY+directions[k][1]<10)
								{
									nowTheMove.move_stop_x=nowX+directions[k][0];
									nowTheMove.move_stop_y=nowY+directions[k][1];
									howLong++;
									nowX+=directions[k][0];
									nowY+=directions[k][1];
									nowTheMove.eatHowMany=0;

									//if(nowTheNumberOfMove>=50)
									//{
									//	cout<<"�����C��"<<nowTheNumberOfMove<<endl;
									//	system("pause");
									//}


									movesCoutainer[nowTheNumberOfMove]=nowTheMove;
									nowTheNumberOfMove++;//�����λ�ü�һ���ƶ�����һ��λ�ã�
								}
								nowX=i;
								nowY=j;
							}
						}
					}
				}
			
			}
	//�����з��ĺ�����������
	return nowTheNumberOfMove;
}


void makeNowMoves::makeNowBingMove(int nowX,int nowY,int eatHowMany,MOVE movesCoutainer[200])//�����ʵ��ֻ�����˱��ܳԵ��з�
{
//	eatHowMany=0;
//	nowTheMove.Kind=nowColor;//ǰ��������������ˣ����ܸо�����������Ļ��о���������Ĺ��ܺ����ֲ�����
//	nowTheMove.move_star_x=nowX;
//	nowTheMove.move_star_y=nowY;
	int flagX=nowX;
	int flagY=nowY;
	int recordX,recordY;
	for(int i=0;i<4;i++)
	{
		if((board[nowX+directions[i][0]][nowY+directions[i][1]]==3-nowColor||board[nowX+directions[i][0]]
			[nowY+directions[i][1]]==3-nowColor+2)&&board[nowX+2*directions[i][0]][nowY+2*directions[i][1]]==EMPTY&&
			nowX+2*directions[i][0]>=0&&nowX+2*directions[i][0]<10&&nowY+2*directions[i][1]>=0&&nowY+2*directions[i][1]<10)
		{
			int record=board[nowX+directions[i][0]][nowY+directions[i][1]];//���λ�õ�״̬��Ҫ��¼
			board[nowX+directions[i][0]][nowY+directions[i][1]]=BAR;//����¼����״̬����Ϊ���ϣ�����ͨ���ô����壬�����
			nowTheMove.eatKind[eatHowMany]=record;
			recordX=nowTheMove.eatPoint[eatHowMany][0]=nowX+directions[i][0];
			recordY=nowTheMove.eatPoint[eatHowMany][1]=nowY+directions[i][1];
			nowX=nowX+2*directions[i][0];
			nowY=nowY+2*directions[i][1];
			nowTheMove.move_stop_x=nowX;
			nowTheMove.move_stop_y=nowY;
			nowTheMove.eatHowMany=eatHowMany+1;
			if(BING_FOUR_DIRECTION_CAN_EAT(nowX,nowY))
			{
				makeNowBingMove(nowX,nowY,eatHowMany+1,movesCoutainer);
			}
			else
			{
				if(eatHowMany+1>theBestEatNum)//eatHowManyʵ���ϱ������ĵ�ǰ������Ҫ��1������Ҳ��������⣬�����ط�����ṹ��������鶨λ
				{
					nowTheNumberOfMove=0;//������о�֮ǰ�Ͳ��ó�ʼ���ˣ������أ�Ϊ�˱��հѳ�ʼ�����Ǹ����Ű�
					movesCoutainer[nowTheNumberOfMove]=nowTheMove;
					nowTheNumberOfMove++;//�����λ�ü�һ���ƶ�����һ��λ�ã�
					theBestEatNum=eatHowMany+1;
				}
				else if(eatHowMany+1==theBestEatNum)
				{
					
					
					//if(nowTheNumberOfMove>=50)
					//{
					//	cout<<"�����D��"<<nowTheNumberOfMove<<endl;
					//	system("pause");
					//}


					movesCoutainer[nowTheNumberOfMove]=nowTheMove;
					nowTheNumberOfMove++;//�����λ�ü�һ���ƶ�����һ��λ�ã�
				}
			}
			board[recordX][recordY]=record;//��������ϵĵط���ԭΪԭ����״̬
		}
		nowX=flagX;//�����껹ԭΪ������ӵ�ԭʼλ��
		nowY=flagY;//
	}
}


bool makeNowMoves::KING_FOUR_DIRECTION_CAN_EAT(int nowX,int nowY)
{
	int howManyDirectionsCanEat=0;
	int recordX=nowX;
	int recordY=nowY;
	for(int i=0;i<4;i++)
	{
		while(board[nowX+directions[i][0]][nowY+directions[i][1]]==EMPTY&&nowX+directions[i][0]>=0&&nowX+directions[i][0]<10&&nowY+directions[i][1]>=0&&nowY+directions[i][1]<10)
		{
			nowX+=directions[i][0];
			nowY+=directions[i][1];
		}
		nowX+=directions[i][0];
		nowY+=directions[i][1];
		if((board[nowX][nowY]==3-nowColor||board[nowX][nowY]==3-nowColor+2)&&board[nowX+directions[i][0]][nowY+directions[i][1]]==EMPTY&&nowX+directions[i][0]>=0&&nowX+directions[i][0]<10&&nowY+directions[i][1]>=0&&nowY+directions[i][1]<10)
			howManyDirectionsCanEat++;
		nowX=recordX;
		nowY=recordY;
	}
	if(howManyDirectionsCanEat)
		return true;
	else 
		return false;
}


void makeNowMoves::makeNowKingMove(int nowX,int nowY,int eatHowMany,MOVE movesCoutainer[200])
{
	int flagX=nowX;
	int flagY=nowY;
	int recordX;
	int recordY;
	int howLong;
	int record;
	for(int i=0;i<4;i++)//4���������ȷ�ϣ�
	{
		howLong=0;
		//�������������������4����������һ�������ܳԣ����Դ˴�����Ҫ��������ж�
		//���while���ж��������ϰ�֮ǰ������������ӣ��߽磬�Լ������ӣ��Է������ӣ��м����գ���¼��ǰ���ȸ�howLong
		while(board[nowX+directions[i][0]][nowY+directions[i][1]]==EMPTY&&nowX+directions[i][0]>=0&&nowX+directions[i][0]<10&&nowY+directions[i][1]>=0&&nowY+directions[i][1]<10)
		{
			nowX+=directions[i][0];
			nowY+=directions[i][1];
			howLong++;
		}
		//�����������������Ե�����
		if((board[nowX+directions[i][0]][nowY+directions[i][1]]==3-nowColor||board[nowX+directions[i][0]][nowY+directions[i][1]]==3-nowColor+2)&&board[nowX+2*directions[i][0]][nowY+2*directions[i][1]]==EMPTY&&nowX+2*directions[i][0]>=0&&nowX+2*directions[i][0]<10&&nowY+2*directions[i][1]>=0&&nowY+2*directions[i][1]<10)
		{
			//�Ƚ��Ե��ĵط���¼������ˢ�³�����BAR���з���������Ҫ��ԭ
			record=board[nowX+directions[i][0]][nowY+directions[i][1]];
			board[nowX+directions[i][0]][nowY+directions[i][1]]=BAR;
			nowTheMove.eatKind[eatHowMany]=record;
			nowTheMove.eatPoint[eatHowMany][0]=nowX+directions[i][0];
			nowTheMove.eatPoint[eatHowMany][1]=nowY+directions[i][1];
			nowX+=directions[i][0];
			nowY+=directions[i][1];
			recordX=nowX;
			recordY=nowY;
			howLong++;
			while(board[nowX+directions[i][0]][nowY+directions[i][1]]==EMPTY&&nowX+directions[i][0]>=0&&nowX+directions[i][0]<10&&nowY+directions[i][1]>=0&&nowY+directions[i][1]<10)
			{
				nowX+=directions[i][0];//ˢ�µ�ǰ����
				nowY+=directions[i][1];
				howLong++;//��¼�ô����λ�����Գ��ȣ�
				nowTheMove.move_stop_x=nowX;//��¼��ǰ���굱��Ŀǰ�з��յ�
				nowTheMove.move_stop_y=nowY;
				nowTheMove.eatHowMany=eatHowMany+1;//��¼��ǰ����������
				if(KING_FOUR_DIRECTION_CAN_EAT(nowX,nowY))
				{
					makeNowKingMove(nowX,nowY,eatHowMany+1,movesCoutainer);//���λ������ܳԵĻ��ݹ�һ�µ���һ��λ�ã�
				}
				else
				{
					if(eatHowMany+1>theBestEatNum)//���ɵĳ����������ڵ�������������
					{
						theBestEatNum=eatHowMany+1;
						nowTheNumberOfMove=0;//�����з���������λ��
						movesCoutainer[nowTheNumberOfMove]=nowTheMove;
						nowTheNumberOfMove++;//�ƶ�����һλ��
					}
					else if(eatHowMany+1==theBestEatNum)//�����˺͵�ǰһ���ĳ�������
					{
						
						
/*						if(nowTheNumberOfMove>=50)
						{
							cout<<"�����E��"<<nowTheNumberOfMove<<endl;
							system("pause");
						}
						
					*/	
						movesCoutainer[nowTheNumberOfMove]=nowTheMove;
						nowTheNumberOfMove++;//�ƶ�����һλ��
					}
				}
				//board[recordX][recordY]=record;//��ԭ�ϰ�Ϊԭ��
			}
			board[recordX][recordY]=record;//��ԭ�ϰ�Ϊԭ��
		}
		nowX=flagX;//�����껹ԭΪ������ӵ�ԭʼλ��
		nowY=flagY;
	}
}