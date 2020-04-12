
// Sau_EngineDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "head.h"

static UINT /*BASED_CODE*/ indicators[]=  
{ 
	IDS_STRING_PRO,
    IDS_STRING_NOTE, 
	IDS_STRING_ENGINE,
	IDS_STRING_TREE,
	IDS_STRING_OTHER,
	IDS_STRING_POINT
};  

// CSau_EngineDlg �Ի���
class CSau_EngineDlg : public CDialogEx
{
// ����
public:
	CSau_EngineDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SAU_ENGINE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
// ʵ��
protected:
	HICON m_hIcon;
	// ���ɵ���Ϣӳ�亯��
	//һЩ��ʼ��
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);//��֪��
	afx_msg HCURSOR OnQueryDragIcon();//��֪��

	//�����ػ�
	afx_msg void OnPaint();

	//
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	//�غϽ���ʱ�����˺���
	afx_msg LRESULT The_Move_Finish(WPARAM wParam, LPARAM lParam);

	afx_msg LRESULT OnInputDepthTimeFinish(WPARAM wParam, LPARAM lParam);

	afx_msg LRESULT OnGetAllMoveFinish(WPARAM wParam, LPARAM lParam);
	afx_msg void OnBoardUserDefined();
	afx_msg LRESULT OnUpdateTree(WPARAM wParam, LPARAM lParam);
	//�ı䴰��ʱ�����˺���
	afx_msg void OnSize(UINT nType, int cx, int cy);

	//����
	afx_msg void OnAbout();

	//�������ʱ�����˺���
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	//ѡ������ʱ�����˺���
	afx_msg void OnEngine_N();
	afx_msg void OnEngine_AB();
	afx_msg void OnEngine_M();

	//ѡ��ģʽʱ�����˺���
	afx_msg void OnMode_HvsAI();
	afx_msg void OnMode_AIvsH();
	afx_msg void OnMode_HvsH();

	//ѡ������Ϸʱ�����˺���
	afx_msg void OnNew_Game();

	//��������
	afx_msg void OnSpareInput();

	//�رճ���ʱ�����˺���
	afx_msg void OnClose();

	//���̷�ת
	afx_msg void OnBoardInverse();

	//ѡ��Negascout ʱ��
	afx_msg void OnTime1s();
	afx_msg void OnTime2s();
	afx_msg void OnTime5s();
	afx_msg void OnTime10s();
	afx_msg void OnTime15s();
	afx_msg void OnTime20s();

	//ѡ��AlphaBeta����
	afx_msg void OnFloor1();
	afx_msg void OnFloor3();
	afx_msg void OnFloor5();
	afx_msg void OnFloor7();
	afx_msg void OnFloor9();
	afx_msg void OnFloor11();

	//�����
	afx_msg void OnAllMove();
	afx_msg void OnMoveHistory();
	afx_msg void OnEvel();

	//�ļ�
	afx_msg void OnLoadSave();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	
	DECLARE_MESSAGE_MAP()
private:
	int d;//��¼���̸���С
	int Size_Prompt;//���ӱ�ǵĴ�С
	int Size_Pieces;//���ӵĴ�С
	int Engine;//��¼����
	int Mode;//��¼ģʽ
	int Progress;//����:�������->ѡ������->�������
	int SpareInput;//�Ƿ�ʹ�ñ�������  0���ǣ� -2���� �� -1���������
	int Color;//ִ�巽
	int Step;//����
	int Round;//����
	int Board[10][10];//��������
	int Time;//Negascout ʱ��
	int Floor;//AlphaBeta����
	int Computer_Color;
	int Human_Color;
	//����ѡ�����ӵ������ŷ�����
	int Prompt_Move_Num;
	//�����ŷ�����
	int Move_Num;
	//�����ͣ�ĳ���·�� 0Ϊ����
	int Mouse_Move;
	//1���̷�ת0Ϊ����
	int Is_Board_Inverse;
	//1�ŷ���ʷ��ʾ0Ϊ�ŷ���ʷ
	int Is_Move_History_Show;
	//1�����ŷ���ʾ0Ϊ�����ŷ�
	int Is_All_Move_Show;
	//1��ֵ��ʾ0��ֵ����ʾ
	int Is_Evel_Show;
	//
	int Is_Set_Board;
	//���������ŷ�
	MOVE All_Moves[200];
	//����ѡ�����ӵ������ŷ���������ã�
	MOVE Prompt_Move[20];

	CProgressCtrl m_Pro;
	CStatusBar m_Bar;
	CMenu m_Menu;
	CBitmap PiecesBmp;
	CBitmap BoardBmp;
	CDC BoardDC;
	CDC PiecesDC;
	CRect Board_Rect;
	CRect Mouse_Rect;
	CString Temp_Str;
	HWND Move_His_dghWnd;
	HWND All_Move_dghWnd;
	HWND Evel_dghWnd;
	//���ݴ��ڼ������̴�С
	void SetBoard(RECT rtBoard);
	//������Ч
	void PlayMySound(int i);
	//�ػ�
	void DrawChess(int type);
	//������
	void DrawPieces(CClientDC *dc);
	//������
	void DrawBoard(CClientDC *dc);
	//�����
	void DrawPrompt(CClientDC *dc);
	//��ʼ������
	void Init_Board(int Board[][10]);
	//��ȡAI�ŷ�
	void Get_Computer_Move();
	//AI��ʼ˼��
	void AI_Star(int Board[][10], int Color);
	//��������߼�
	int SToS(CPoint Mouse_Pt);
	//�����������
	int Spare_SToS(CPoint Mouse_Pt);
	//��ʾ
	void Show_The_Move(MOVE* TheMove);
	void Show_Evel();
	void Show_All_Move();
	//�ļ�
	MOVE Load_File(int Step, int Round);
	void Save_File(MOVE Move,int Step,int Round);
	void Input_Depth_Time(int Depth,double Time);
	void Get_All_Move();
	void ProgressStar();
	void Go_The_Move(MOVE The_Move);
	void Save_File(int Depth,double Time);
	void Save_File(int Color);
	void Set_Board(CPoint pt);
	int newxy(int star_x, int star_y);
public:
	afx_msg void On32847();
};
