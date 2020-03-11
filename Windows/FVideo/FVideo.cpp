﻿
// FVideo.cpp: 定义应用程序的类行为。
//

#include "stdafx.h"
#include "FVideo.h"
#include "FVideoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFVideoApp

BEGIN_MESSAGE_MAP(CFVideoApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CFVideoApp 构造

CFVideoApp::CFVideoApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的 CFVideoApp 对象

CFVideoApp theApp;

// SDK 接口
rc_meeting* theMeeting = NULL;

#pragma comment(lib, "MeetingClientSdk")


// CFVideoApp 初始化

BOOL CFVideoApp::InitInstance()
{
	CWinApp::InitInstance();


	AfxEnableControlContainer();


	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
//	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	// 初始化SDK
	theMeeting = getMeeting();
	theMeeting->startup();

	CFVideoDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "警告: 对话框创建失败，应用程序将意外终止。\n");
		TRACE(traceAppMsg, 0, "警告: 如果您在对话框上使用 MFC 控件，则无法 #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS。\n");
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// 关闭SDK
	theMeeting->cleanup();

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}

