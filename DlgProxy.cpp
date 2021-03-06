
// DlgProxy.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "haoduancaiji.h"
#include "DlgProxy.h"
#include "haoduancaijiDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ChaoduancaijiDlgAutoProxy

IMPLEMENT_DYNCREATE(ChaoduancaijiDlgAutoProxy, CCmdTarget)

ChaoduancaijiDlgAutoProxy::ChaoduancaijiDlgAutoProxy()
{
	EnableAutomation();

	// 为使应用程序在自动化对象处于活动状态时一直保持
	//	运行，构造函数调用 AfxOleLockApp。
	AfxOleLockApp();

	// 通过应用程序的主窗口指针
	//  来访问对话框。  设置代理的内部指针
	//  指向对话框，并设置对话框的后向指针指向
	//  该代理。
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(ChaoduancaijiDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(ChaoduancaijiDlg)))
		{
			m_pDialog = reinterpret_cast<ChaoduancaijiDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

ChaoduancaijiDlgAutoProxy::~ChaoduancaijiDlgAutoProxy()
{
	// 为了在用 OLE 自动化创建所有对象后终止应用程序，
	//	析构函数调用 AfxOleUnlockApp。
	//  除了做其他事情外，这还将销毁主对话框
	if (m_pDialog != nullptr)
		m_pDialog->m_pAutoProxy = nullptr;
	AfxOleUnlockApp();
}

void ChaoduancaijiDlgAutoProxy::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(ChaoduancaijiDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(ChaoduancaijiDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// 注意: 我们添加了对 IID_Ihaoduancaiji 的支持来支持类型安全绑定
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {75bfaf8d-9e1a-46e7-9819-6b8839d3390e}
static const IID IID_Ihaoduancaiji =
{0x75bfaf8d,0x9e1a,0x46e7,{0x98,0x19,0x6b,0x88,0x39,0xd3,0x39,0x0e}};

BEGIN_INTERFACE_MAP(ChaoduancaijiDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(ChaoduancaijiDlgAutoProxy, IID_Ihaoduancaiji, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 宏是在此项目的 pch.h 中定义的
// {dd7328f0-e3fa-47b0-872f-0b13be102692}
IMPLEMENT_OLECREATE2(ChaoduancaijiDlgAutoProxy, "haoduancaiji.Application", 0xdd7328f0,0xe3fa,0x47b0,0x87,0x2f,0x0b,0x13,0xbe,0x10,0x26,0x92)


// ChaoduancaijiDlgAutoProxy 消息处理程序
