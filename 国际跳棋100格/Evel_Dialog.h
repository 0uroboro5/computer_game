#pragma once


// CEvel_Dialog �Ի���

class CEvel_Dialog : public CDialogEx
{
	DECLARE_DYNAMIC(CEvel_Dialog)

public:
	CEvel_Dialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEvel_Dialog();

// �Ի�������
	enum { IDD = IDD_DIALOG_EVEL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	CEdit Edit_Evel;
	BOOL InitFinish;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg LRESULT OnUpdateMoveData(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};
