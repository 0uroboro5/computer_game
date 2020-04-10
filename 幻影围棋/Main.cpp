//����汾		2017����� 
//���������������պ����ѧ���������Э���ܸ�������Ծ��ͳһ����
//��ӰΧ���鸺�����Ժ���ﾰ���������鿪��ά��
//�������Թ�����Դ����,�����ϳ�Աά�� 
//�������������й���ѧ����������Ĵ�������Э��
//��������ṩ����Э����÷�ʾ���ͼ�AI����˼·�������������иĽ����ƴ������
//��������ͽ����������Ǿ�����ϵ
//��Ծ��	QQ��836473734
//�Ժ���	QQ��1366160976
//�ﾰ		QQ��282940270
#ifndef	_MAIN_CPP_
#define	_MAIN_CPP_

#include "Define.h"
#include<iostream>
char undo_board[GRID_NUM][GRID_NUM];
char undo_board_know[GRID_NUM][GRID_NUM];
SPlayer undo_player[3];	

int main()
{
	char msg[100];
	int	numTi = 0;
	int	x,y;

	InitGame();
	while(1)
	{
		Sleep(50);
		fflush(stdin);
		Sleep(50);
		fflush(stdout);
		printf("���֣�'new' or 'quit'\n");
		scanf("%s",msg);  
		if (strcmp(msg,"quit") == 0)                                 //������Ϸ
		{	
			break;
		}
		else if (strcmp(msg,"new") == 0)                	         //��ʼ�����
		{
			InitGame();
			PrintBoard();
			printf("���ӣ�'black' or other\n");
			scanf("%s",msg);
			if (strcmp(msg,"black") == 0)                            //���msg��black���Լ��Ǻ���
			{
				chessColor = BLACK;
				SearchMove(&bestMove);
			    printf("-->%d %c",bestMove.x,bestMove.y+'@');        //���һ������з�
				printf("   ���ߣ�'m' or 'i'\n");
				while(1)
				{ 	
			           scanf("%s",msg);                              //��ȡ������Ϣ
				       if (strcmp(msg,"m") == 0)                     //�Լ��ϴ��ߵ�Ϊ�Ϸ��з�
					   {	     
					     board[bestMove.x][bestMove.y] = BLACK;
					     PrintBoard();
					     record();
				       	 player[BLACK].total++;
					     player[WHITE].total++;                      //  ////
                         printf("������'go' / 'take' / 'taked' / 'undo' / 'passed'\n");
					   }
					   else if (strcmp(msg,"go")==0)
					   {
						   if (SearchMove(&bestMove))
						   {
						      printf("-->%d %c",bestMove.x,bestMove.y+'@');     //�����з��ɹ�������ƽ̨ 
							  printf("   ���ߣ�'m' or 'i'\n");
						   }
						   else
						   {	   
						       printf("passed\n");                   //���ɹ����Լ�pass
						   }
					   }	   
				       else if (strcmp(msg,"i") == 0)                //�Լ��ϴ��ߵ�Ϊ�Ƿ��з�
					   {  
					      board[bestMove.x][bestMove.y] = WHITE;
					      PrintBoard();
					      player[WHITE].know++;
					      board_know[bestMove.x][bestMove.y] ++;     //  ???
					      if (SearchMove(&bestMove))
						  {
						     printf("-->%d %c",bestMove.x,bestMove.y+'@');      //�����з��ɹ�������ƽ̨
							 printf("   ���ߣ�'m' or 'i'\n");
						  }
					      else
						  {
						      printf("passed\n");			         //���ɹ����Լ�pass
						  }
					   }
				       else if (strcmp(msg,"take") == 0)            //�Լ�����,��ȡ������Ŀ
					   {
					      SMove moveList[81] ;
						  printf("������Ŀ��");
					      scanf("%d",&numTi);
					      player[WHITE].total -= numTi;
					      for(int k = 0 ; k < numTi ; k++)
						  {
                             printf("�������꣺");
						     Sleep(50);
						     fflush(stdin);
						     scanf("%d%d",&x,&y);
						     moveList[k].x = x;
						     moveList[k].y = y;
						  }
					      for(int i = 0 ; i < numTi ; i++)
						  {
							  board[moveList[i].x][moveList[i].y] = NOSTONE;
						  }
					      PrintBoard();
                          printf("������'go' / 'passed' / 'taked'\n");
					   }
			           else if (strcmp(msg,"taked") == 0)            //�Է�����,��ȡ������Ŀ
					   {					      
					      SMove moveList[81] ;
						  printf("��������Ŀ��");
					      scanf("%d",&numTi);
					      player[BLACK].total -= numTi;					      
					      for(int k = 0 ; k < numTi ; k++)
						  {
                             printf("���������꣺");
						     Sleep(50);
						     fflush(stdin);
						     scanf("%d %d",&x,&y);
						     moveList[k].x = x;
						     moveList[k].y = y;     
						     if (board[x-1][y] == NOSTONE)           //��������ӵı߽����̽�⣬����ǿգ��϶��ǶԷ�����
							 {
							     board[x-1][y] = WHITE;
							     player[WHITE].know++;
							 }
						     if (board[x+1][y] == NOSTONE)
							 {
							    board[x+1][y] = WHITE;
							    player[WHITE].know++;
							 }
						     if (board[x][y-1] == NOSTONE)
							 {
							    board[x][y-1] = WHITE;
							    player[WHITE].know++;
							 }
						     if (board[x][y+1] == NOSTONE)
							 {
							    board[x][y+1] = WHITE;
							    player[WHITE].know++;
							 } 
						  }
					      for(int i = 0 ; i< numTi ; i++)
						  {
						     board[moveList[i].x][moveList[i].y] = NOSTONE;
						  }
						  PrintBoard();
                          printf("������'go' / 'passed'\n");
					   }
			           else if (strcmp(msg,"passed") == 0)           //�Է�pass
					   {    
					     player[WHITE].know  = player[WHITE].total;
					   }
		               else if (strcmp(msg,"undo") == 0)
					   {
			               Undo();
                           printf("������'i' or 'm'\n");
					   }
		               else
					   {
			             printf("Error Input!!!\n");
			             PrintBoard();
					   }                       
                 } 
			}
			else
			{
				chessColor = WHITE;
				while(1)
				{
					scanf("%s",msg);
			        chessColor = WHITE;			                     //�Լ��ǰ���		    
				    if (strcmp(msg,"m") == 0)					     //�Լ��ϴ��ߵ�Ϊ�Ϸ��з�
					{
					   board[bestMove.x][bestMove.y] = WHITE;
					   PrintBoard();
					   record();
					   player[WHITE].total++;
					   player[BLACK].total++;
					   printf("������'go' / 'take' / 'taked' / 'undo' / 'passed'\n");
					}
				    else if (strcmp(msg,"go")==0)
					{
					   if (SearchMove(&bestMove))
					   {
					      printf("%d %c",bestMove.x,bestMove.y+'@');          //�����з��ɹ�������ƽ̨
						  printf("   ���ߣ�'m' or 'i'\n");
					   }
					   else                                          //���ɹ����Լ�pass
					   {
						   printf("passed\n");
					   }
					}
				    else if (strcmp(msg,"i") == 0)                   //�Լ��ϴ��ߵ�Ϊ�Ƿ��з�
					{	    
					    board[bestMove.x][bestMove.y] = BLACK;
                        PrintBoard();
					    player[BLACK].know++;
					    board_know[bestMove.x][bestMove.y] ++;
					    if (SearchMove(&bestMove))
						{
						    printf("%d %c",bestMove.x,bestMove.y+'@');          //�����з��ɹ�������ƽ̨
							printf("   ���ߣ�'m' or 'i'\n");
						}
					    else                                         //���ɹ����Լ�pass
						{  
						    printf("passed\n");
						}
					}
				    else if (strcmp(msg,"take") == 0)
					{
					    SMove moveList[81] ;                         //�Լ�����,��ȡ������Ŀ
						printf("������Ŀ��");
					    scanf("%d",&numTi);
					    player[BLACK].total -= numTi;
					    for(int k = 0 ; k < numTi ; k++)
						{
							printf("�������꣺");
						    Sleep(50);
						    fflush(stdin);							
						    scanf("%d%d",&x,&y);
						    moveList[k].x = x;
						    moveList[k].y = y;
						}
					    for(int i = 0 ; i < numTi ; i++)
						{
						    board[moveList[i].x][moveList[i].y] = NOSTONE;
						}
					                                                 //�Լ�֪������ҲӦ������
						PrintBoard();
                        printf("������'go' or 'passed' or 'taked'\n");
					}
				    else if (strcmp(msg,"taked") == 0)               //�Է�����,��ȡ������Ŀ
					{					    
					    SMove moveList[81] ;
						printf("��������Ŀ��");
					    scanf("%d",&numTi);
					    player[WHITE].total -= numTi;                //��ȡ�Լ����б������	    
					    for(int k = 0 ; k < numTi ; k++)
						{
							printf("���������꣺");
						    Sleep(50);
						    fflush(stdin);
						    scanf("%d%d",&x,&y);
						    moveList[k].x = x;
						    moveList[k].y = y;			    
						    if (board[x-1][y] == NOSTONE)            //��������ӵı߽����̽�⣬����ǿգ��϶��ǶԷ�����
							{
						     	board[x-1][y] = BLACK;
						    	player[BLACK].know++;
							}
						    if (board[x+1][y] == NOSTONE)
							{
						    	board[x+1][y] = BLACK;
						    	player[BLACK].know++;
							}
						    if (board[x][y-1] == NOSTONE)
							{
						    	board[x][y-1] = BLACK;
						    	player[BLACK].know++;
							}
						    if (board[x][y+1] == NOSTONE)
							{
							    board[x][y+1] = BLACK;
						    	player[BLACK].know++;
							}
						}
					    for(int i = 0 ; i < numTi ; i++)
						{
						    board[moveList[i].x][moveList[i].y] = NOSTONE;
						}
						PrintBoard();
                        printf("������'go' or 'passed'\n");
					}
				    else if (strcmp(msg,"passed") == 0)              //�Է�pass
					{	    
					    player[WHITE].know  = player[BLACK].total;
					}
		            else if (strcmp(msg,"undo") == 0)
					{
			             Undo();
						 printf("������'i' or 'm'\n");
					}
		            else
					{
			             printf("Error Input!!!\n");
			             PrintBoard();
					}

				 }
			}
		}
	}
	return 0;
}

void record()
{
	long i, j;
	for (i=1; i<10; i++)
	{
		for (j=1; j<10; j++)
		{
			undo_board[i][j] = board[i][j];
			undo_board_know[i][j] = board_know[i][j];
		}
	}
	for (i=0; i<3; i++){
		undo_player[i] = player[i];
	}
}

void Undo()
{
	long i, j;
	for (i=1; i<10; i++)
	{
		for (j=1; j<10; j++)
		{
			board[i][j] = undo_board[i][j];
			board_know[i][j] = undo_board_know[i][j];
		}
	}
	for (i=0; i<3; i++)
		player[i] = undo_player[i];
}


void InitGame()
{
	memset(player, 0, sizeof(player));
	memset(board, 0, sizeof(board));
	memset(board_know, 0, sizeof(board_know));
	memset(&bestMove, 0, sizeof(bestMove));
	for (long i = 0 ; i < 11 ; i++)
	{
		board[i][0] = BORDER;
		board[0][i] = BORDER;
		board[i][10] = BORDER;
		board[10][i] = BORDER;
	}
}

void PrintBoard()
{
	printf("  ");
	char ch='A';
	for(long j = 1 ; j < 10 ; j++)
	{
		printf("  %c%d",ch,j);
		ch++;
	}
    printf("%s","\n  �����Щ��Щ��Щ��Щ��Щ��Щ��Щ��Щ���\n");
	for (long i=0;i<9;i++)
	{
		printf("%d %s",i+1,"��");
		for(long j=0;j<9;j++)
		{
			if(board[i+1][j+1]==1)
				printf("%s","�w��");
			else if(board[i+1][j+1]==2)
				printf("%s","��");
			else
				printf("%s","  ��");
		}
		printf("%s","\n");
		if(i==8)
			printf("%s","  �����ة��ة��ة��ة��ة��ة��ة��ة���\n");
		else
			printf("%s","  �����੤�੤�੤�੤�੤�੤�੤�੤��\n");
	}
}


#endif
