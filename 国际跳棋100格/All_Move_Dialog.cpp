// All_Move_Dialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Sau_Engine.h"
#include "All_Move_Dialog.h"
#include "afxdialogex.h"


// CAll_Move_Dialog �Ի���

IMPLEMENT_DYNAMIC(CAll_Move_Dialog, CDialogEx)

CAll_Move_Dialog::CAll_Move_Dialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAll_Move_Dialog::IDD, pParent)
	,InitFinish(0)
{

}

CAll_Move_Dialog::~CAll_Move_Dialog()
{
}

void CAll_Move_Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_All_Move, Edit_All_Move);
}


BEGIN_MESSAGE_MAP(CAll_Move_Dialog, CDialogEx)
	ON_WM_SIZE()
	ON_MESSAGE(UpdateMoveDataMess, &CAll_Move_Dialog::OnUpdateMoveData)
END_MESSAGE_MAP()

// CAll_Move_Dialog ��Ϣ�������

void CAll_Move_Dialog::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	CWnd *pWnd;   
	pWnd = GetDlgItem(IDC_EDIT_All_Move);
	if(pWnd!=NULL)
	{	
		pWnd->SetWindowPos(0,0,0,cx-21,cy-23,SWP_NOZORDER | SWP_NOMOVE ); //�ѱ༭�ؼ��Ĵ�С��Ϊ(100,80)��λ�ò���
	}
	// TODO: �ڴ˴������Ϣ����������
}

afx_msg LRESULT CAll_Move_Dialog::OnUpdateMoveData(WPARAM wParam, LPARAM lParam)
{
	/*CFont m_Font;
	m_Font.CreateFont(0,0,0,0,  
		0,FALSE,FALSE,0,ANSI_CHARSET,  
		OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,  
		DEFAULT_QUALITY,FF_SWISS,(LPCTSTR)"Arial");//��������  
	Edit_All_Move.SetFont(&m_Font);*/
//	Edit_All_Move.SetSel(1); 
	Edit_All_Move.SetWindowText(_T("����	���	���	������	����\r\n"));
	MOVE *All_Move;
	All_Move=(MOVE*)lParam;
	CString All_Move_str;
	CString Temp_str;
	for(int i=0;i< (int)wParam;i++)
	{
		Temp_str.Format(_T("%2d"),i+1);
		All_Move_str+=Temp_str;
		Temp_str.Format(_T("	%2d"),(All_Move[i].move_star_x+All_Move[i].move_star_y*10)/2+1);
		All_Move_str+=Temp_str;
		Temp_str.Format(_T("	 %2d"),(All_Move[i].move_stop_x+All_Move[i].move_stop_y*10)/2+1);
		All_Move_str+=Temp_str;
		Temp_str.Format(_T("	 %2d "),All_Move[i].eatHowMany);
		All_Move_str+=Temp_str;

		for(int i=0;i<All_Move[i].eatHowMany;i++)
		{
			Temp_str.Format(_T("	%2d"),(All_Move[i].eatPoint[i][0]+All_Move[i].eatPoint[i][1]*10)/2+1);
			All_Move_str+=Temp_str;
	
		}
		Temp_str.Format(_T("\r\n"));
		All_Move_str+=Temp_str; 
	}
	Edit_All_Move.SetSel(-1);
	Edit_All_Move.ReplaceSel(All_Move_str);
	return 0;
}


