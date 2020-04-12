// Move_History_Dialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Sau_Engine.h"
#include "Move_History_Dialog.h"
#include "afxdialogex.h"
#include "head.h"

// CMove_History_Dialog �Ի���

IMPLEMENT_DYNAMIC(CMove_History_Dialog, CDialogEx)

CMove_History_Dialog::CMove_History_Dialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMove_History_Dialog::IDD, pParent)
{
	InitFinish=0;
}

CMove_History_Dialog::~CMove_History_Dialog()
{
}

void CMove_History_Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_Move_His, Edit_Move_His);
}


BEGIN_MESSAGE_MAP(CMove_History_Dialog, CDialogEx)
	ON_WM_SIZE()
	ON_MESSAGE(UpdateMoveDataMess, &CMove_History_Dialog::OnUpdateMoveData)
END_MESSAGE_MAP()


// CMove_History_Dialog ��Ϣ�������


void CMove_History_Dialog::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	CWnd *pWnd;   
	pWnd = GetDlgItem(IDC_EDIT_Move_His);
	if(pWnd!=NULL)
	{	
		pWnd->SetWindowPos(0,0,0,cx-21,cy-23,SWP_NOZORDER | SWP_NOMOVE ); //�ѱ༭�ؼ��Ĵ�С��Ϊ(100,80)��λ�ò���
	}
	// TODO: �ڴ˴������Ϣ����������
}


afx_msg LRESULT CMove_History_Dialog::OnUpdateMoveData(WPARAM wParam, LPARAM lParam)
{
	
	if(InitFinish==0)
	{
		InitFinish=1;
		/*CFont m_Font;
		m_Font.CreateFont(0,0,0,0,  
			0,FALSE,FALSE,0,ANSI_CHARSET,  
			OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,  
			DEFAULT_QUALITY,FF_SWISS,(LPCTSTR)"Arial");//��������  
		Edit_Move_His.SetFont(&m_Font);*/
		Edit_Move_His.ReplaceSel(_T("����	���	���	������	����\r\n"));
	}

	MOVE *The_Move;
	The_Move=(MOVE*)lParam;
	CString Move_His_str;
	CString Temp_str;
	Temp_str.Format(_T("%2d"),wParam);
	Move_His_str+=Temp_str;
	Temp_str.Format(_T("	%2d"),(The_Move->move_star_x+The_Move->move_star_y*10)/2+1);
	Move_His_str+=Temp_str;
	Temp_str.Format(_T("	%2d"),(The_Move->move_stop_x+The_Move->move_stop_y*10)/2+1);
	Move_His_str+=Temp_str;
	Temp_str.Format(_T("	%2d "),The_Move->eatHowMany);
	Move_His_str+=Temp_str;

	for(int i=0;i<The_Move->eatHowMany;i++)
	{
		Temp_str.Format(_T("	%2d"),(The_Move->eatPoint[i][0]+The_Move->eatPoint[i][1]*10)/2+1);
		Move_His_str+=Temp_str;
	
	}
	Temp_str.Format(_T("\r\n"));
	Move_His_str+=Temp_str;
	Edit_Move_His.SetSel(-1); 
	Edit_Move_His.ReplaceSel(Move_His_str);
	return 0;
}
