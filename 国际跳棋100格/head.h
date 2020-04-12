#pragma once

	const int directions[4][2]={{1,1},{1,-1},{-1,1},{-1,-1},};//���ÿ�������λ�ò��ܱ䣬�����Ǻ������ϰ������µ�˳��

	#define File_Path	"d:\\��ս��¼.txt"
	#define TIMER		1
	#define Blocked		1
	#define Open		2
	#define Chose		4
	#define Finish		8

	#define Flip		1
	#define Normal		0

	#define EMPTY		0
	#define WHITE		2
	#define BLACK		1
	#define W_KING		4
	#define B_KING		3
	#define BAR			5
	#define depthMax	9

	#define D_Pieces                        1
	#define D_Board                         2
	#define D_Prompt                        4

	#define Negascout                       1
	#define AlphaBeta                       2
	#define Minimax                         4

	#define Input							8
	#define Dele							16
	#define GetAllMove						32

	#define All_Move_Finish					1
	#define AI_Finish						1
	#define Human_Finish					2

	#define HvsH                            1
	#define HvsAI                           2	
	#define AIvsH                           4

	#define Err_Engine_AB					2
	#define Err_Engine_N					1
	#define Err_Engine_Check				4

	#define WM_MY_MESSAGE					WM_USER + 1
	#define UpdateMoveDataMess				WM_USER + 2
	#define Get_All_Move_Finish				WM_USER + 3
	#define Input_Depth_Time_Finish			WM_USER + 4
	#define UPDATE_TREE						WM_USER + 5
	typedef __int64 LONGLONG;
	typedef unsigned __int64 ULONGLONG;
	typedef int                 INT;
	typedef unsigned int        UINT;
	typedef long LONG;
	typedef unsigned char       BYTE;
	typedef __int64 LONGLONG;

	struct MOVE
	{
		int Kind;//��¼����;
		int move_star_x;//�������
		int move_star_y;
		int move_stop_x;//�յ�����
		int move_stop_y;
		int eatHowMany;//����������ͬʱҲ��eatHowMany�ĳ���
		int eatPoint[20][2];
		int eatKind[20];//��¼�Ե����ӵ�����
		double score;//���ã������ģ���п���������
	};

	struct MOVE_MESS
	{
		MOVE The_Good_Move;
		int Add_Mess;//������Ϣ
	};//�����̼߳䴫����Ϣ

	struct BOARD_MESS
	{
		int Board[10][10];
		int Color;
		int Add_Mess;//������Ϣͨ��������
	};//�����̼߳䴫����Ϣ

	/*struct MOVE_PT
	{
	
		POINT pt[10][20];
		int move_num;
		int eat_num[10];
		int i[10];
	
	};*/

	enum ENTRY_TYPE{ exact, lowerBound, UpperBound };//��ϣ���н����ϣ��ͻ��һ������	

	struct HASHITEM{
	LONGLONG checksum;
	double eval;
	short depth;
	ENTRY_TYPE enterType;
};//��ϣԪ�ؽṹ��

	struct HH_HASHITEM{
	LONGLONG checksum;	  //64λУ����
	double score;		  //��ʷ��
	short depth;
};//��ʷ��Ԫ�ؽṹ��(��ϣ)
	

