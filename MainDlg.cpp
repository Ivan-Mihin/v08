#include "stdafx.h"
#include "v8.h"
#include "MainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MainDlg::MainDlg(CWnd* pParent) : CDialog(MainDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, listaFilmova);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnClickedButton2)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	listaFilmova.InsertColumn(0, _T("Title"), LVCFMT_LEFT, 140);
	listaFilmova.InsertColumn(1, _T("Year"), LVCFMT_CENTER, 50);
	listaFilmova.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	return TRUE;
}

void MainDlg::OnClickedButton1()
{
	CString imeFilma, godinaFilma;
	GetDlgItemText(IDC_EDIT1, imeFilma);
	GetDlgItemText(IDC_EDIT2, godinaFilma);

	if (imeFilma.IsEmpty() == false && godinaFilma.IsEmpty() == false) {
		int redovi = listaFilmova.GetItemCount();
		listaFilmova.InsertItem(redovi, imeFilma);
		listaFilmova.SetItemText(redovi, 1, godinaFilma);
	}
	SetDlgItemText(IDC_EDIT1, "");
	SetDlgItemText(IDC_EDIT2, "");
}

void MainDlg::OnClickedButton2()
{
	if (listaFilmova.GetNextItem(-1, LVNI_SELECTED) != -1)
		listaFilmova.DeleteItem(listaFilmova.GetNextItem(-1, LVNI_SELECTED));
}