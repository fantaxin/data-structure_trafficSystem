
// MFCApplication5Dlg.h: 头文件
//

#pragma once;

// CMFCApplication5Dlg 对话框
class CMFCApplication5Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication5Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION5_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_departure;
	CComboBox m_destination;
	CString m_distance;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnCbnEditchangeCombo1();
	afx_msg void OnCbnKillfocusCombo1();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnCbnEditchangeCombo2();
	void DrowLine(vector<Line> vec,int);
	afx_msg void OnBnClickedButton4();
	CComboBox m_avoid;
	afx_msg void OnCbnSelchangeCombo3();
	afx_msg void OnCbnEditchangeCombo3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	CComboBox No_k;
	afx_msg void OnCbnSelchangeCombo4();
	afx_msg void OnCbnEditchangeCombo4();
};
