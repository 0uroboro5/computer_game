#pragma once
#include "afxwin.h"


// CMove_History_Dialog �Ի���

class CMove_History_Dialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMove_History_Dialog)

public:
	CMove_History_Dialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMove_History_Dialog();
// �Ի�������
	enum { IDD = IDD_DIALOG_MOVE_HIS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CEdit Edit_Move_His;
	BOOL InitFinish;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg LRESULT OnUpdateMoveData(WPARAM wParam, LPARAM lParam);
};
