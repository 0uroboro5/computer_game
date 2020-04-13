// Function.h: interface for the Function class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FUNCTION_H__8FDE5B4D_B014_47EF_9866_3A5F052CA8BB__INCLUDED_)
#define AFX_FUNCTION_H__8FDE5B4D_B014_47EF_9866_3A5F052CA8BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define EDGE  9 //23		/*max # intersections on the edge of a go board*/

#define RESIGN (-2)	/*codes for resigning */
#define PASS (-1)	/* passing moves*/
#define BOTHPASS (-3)	/*code for both sides passed, game is over*/
#define FAIL (-4)            //���Ӵ���
#define COMPUTER_WIN   1000 //�����Ӯ�ˡ�
#define COMPUTER_LOS  -1000//��������ˡ�
#define COMPUTER_PASS -1//�����������
/*codes for players; and a code for something (e.g. a point on the board) */
/* which belongs to neither*///���Ӻ�ѡ�ִ���
#define BLACK 0
#define WHITE 1
#define EMPTY 2

/*flags in shape table entries for types of points*///��ڱ�׼����ģʽƥ��
#define F_BLACK 1	/*the point has a black stone*///(0001)B
#define F_WHITE 2	/*the point has a white stone*///(00010)B
#define F_EMPTY 4	/*the point is empty*///(0100)B
#define F_OFF   8	/*the point is off the board*///���ӵ�(1000)B//�߽��



typedef struct group
{
	int	color,	/*the color of stones in this group*/ //���ӵ���ɫ
	nliberties,	/*the number of liberties(����) that this group has*/
	nstones,	/*the number of stones in this group*/ //���������ӵ���Ŀ
	x, y;		/*one point in this group*/ //���ϵĵ�

} group;

/*a struct for holding information on every square of the board*/ //�洢�����ϵ�����
typedef int board[EDGE][EDGE];


class Function  
{
public:
	Function();
	virtual ~Function();

	int edge;		/*the number of intersections which we are using (a command line parameter)*/
	board theboard;	/*current position of stones on the board*/ //
	int mx,my;		// move of the game ����
	int *player;		// next player to play
	int ComputerColor;//�����������ɫ



	void SaveBoard();	//���ڱ��浱ǰ����
	void SaveScratch(int (*scratch)[EDGE],char *);//���ڱ���scratch��������ʹ�á�Liuc:2011-05-28

	void initgame();//��ʼ����Ϸ
	int nextmove();//�ж���һ������
	int nextmove(int x, int y);

	void movedone();
	int placestone(int x, int y, int p);//����
	
	void count(register int x, register int y,  register group *thisgroup,  board scratch,  int mark);//�������������

	
	void pattern1(int *u,  board masks, board movehere,int *patAdd,int);//ģʽƥ��
	void pattern(int *chosenx, int *choseny, int *urgency,  board movehere,int *patAdd);//��ģʽӳ���8����ʽ
	int mymove();//���������
	int enemymove();//��������
	void SetBoard(board scratch,int value);
	int judgement(int *ua,int x,int y,int p);//�ж�(x,y)�㴦�Ļ���
	int myloss(int x,int y,int p);//�ж�(x,y)���ӵ���Ӯ

};

#endif // !defined(AFX_FUNCTION_H__8FDE5B4D_B014_47EF_9866_3A5F052CA8BB__INCLUDED_)
