
// MFC_������ģ��Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMFC_������ģ��Dlg �Ի���
class CMFC_������ģ��Dlg : public CDialogEx
{
// ����
public:
	CMFC_������ģ��Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC__DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtn();
	CString m_StrCaption;
	CButton m_start;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
