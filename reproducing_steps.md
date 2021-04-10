# Steps for creating a project with CMFCToolBar (under Visual Studio 2019 Community Edition)

1.  Start Visual Studio, click on the "Create a new project" button.

2.  Select the "MFC App" template in the project template selection dialog and click the "Next" button.

3.  Set the "Project name" field to "CMFCToolBarPrj";
    set the "Location" field to where you want to create the project;
    set the flag "Place solution and project in the same directory";
    click the "Create" button.

4.  In the "MFC Application - Application Type Options" dialog set the next options:
    in the "Application type" tab set the "Application type" feild to "Multiple Documents", set the "Project style" field to "MFC standard" (the "Visual style and colors" field must be automatically set to "Windows Native/Default"; click the "Finish" button.
    (such settings are necessary for the following:
    The project's "App" class must be inherited from CWinAppEx (not CWinApp), the croject's "MainFrame" class must be inherited from CMDIFrameWndEx (not CFrameWnd))
    
    (Of course, it is possible to create a full-fledged Visual Studio like project (with file trees, etc.) but they are not necessary here, so we shall create a simple project as possible (nevertheless a commbobox in a full-fledged project also doesn't stretch across the bar)).
    
5.  In the opened VS project open the MainFrm.h file and change the line:
    ```
    CToolBar          m_wndToolBar;
    ```
    to 
    ```
    CMFCToolBar       m_wndToolBar;
    ```
   
6. In the opened VS project open the MainFrm.h file and delete the line:
    ```
    CStatusBar        m_wndStatusBar;
    ```
    
7.  Also in the MainFrm.h add the next next methods to the message map declaration:
    ```
    // Generated message map functions
    protected:
        ...
        afx_msg void OnUpdateComboBox(CCmdUI* pCmdUI);
        afx_msg LRESULT OnToolbarReset(WPARAM, LPARAM);
        ...
        DECLARE_MESSAGE_MAP()
    ```    
8.  Open the MainFrm.cpp file and add the next lines the the Message Map:
    ```
    BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWndEx)
        ON_WM_CREATE()
        ON_REGISTERED_MESSAGE(AFX_WM_RESETTOOLBAR, OnToolbarReset)
        ON_UPDATE_COMMAND_UI(ID_COMBOBOX, OnUpdateComboBox)
    END_MESSAGE_MAP()
    ```
    
9.  In the MainFrm.cpp add the next methods:
    ```
    LRESULT CMainFrame::OnToolbarReset(WPARAM wp, LPARAM)
    {
        UINT uiToolBarId = (UINT)wp;
        switch (uiToolBarId)
        {
        case IDR_MAINFRAME:
            int comboBoxWidth = 180;
            CMFCToolBarComboBoxButton comboBox(ID_COMBOBOX,
                GetCmdMgr()->GetCmdImage(ID_COMBOBOX, FALSE),
                CBS_DROPDOWNLIST | WS_VSCROLL | WS_CHILD | WS_VISIBLE | WS_TABSTOP,
                comboBoxWidth);

            comboBox.SetFlatMode(true);
            comboBox.SetStyle(TBBS_PRESSED | TBBS_WRAPPED);

            // initially fill
            comboBox.AddItem(_T("Item 01"));
            comboBox.AddItem(_T("Item 02"));
            comboBox.AddItem(_T("Item 03"));
            comboBox.SelectItem(0);

            // embed to the toolbar
            m_wndToolBar.ReplaceButton(ID_COMBOBOX, comboBox);

            break;
        }

        return 0;
    }
    ```
    
    and    
    ```
    void CMainFrame::OnUpdateComboBox(CCmdUI* pCmdUI) 
    {
        pCmdUI->Enable(TRUE);
    }
    ```
    
10. Open the MainFrm.cpp file and in CMainFrame::OnCreate change the lines:
    ```
    if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
    ```
    
    to
    ```
    if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC, CRect(1, 1, 1, 1), IDR_MAINFRAME) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
    ```
    
    then delete the next code:
    ```
    if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));
    ```
    
    and change the line:
    ```
    DockControlBar(&m_wndToolBar);
    ```
    
    to 
    ```
    DockPane(&m_wndToolBar);
    ```
    
11. Save all and close Visual Studio.

12. Open the "Resource.h" file in an ordinary text editor (Notepad, Notepad++, etc.) and after all lines with ID add the next line:
    ```
    #define ID_COMBOBOX                 132
    ```
    (The actual ID can be another, but it must be unique across Resource.h).
    Save changes and close the file.

13. Open the project .rc file in an ordinary text editor and change the lines:
    ```
    IDR_MAINFRAME TOOLBAR 16, 15
    BEGIN
        BUTTON      ID_FILE_NEW
        BUTTON      ID_FILE_OPEN
        BUTTON      ID_FILE_SAVE
        SEPARATOR
        BUTTON      ID_EDIT_CUT
        BUTTON      ID_EDIT_COPY
        BUTTON      ID_EDIT_PASTE
        SEPARATOR
        BUTTON      ID_FILE_PRINT
        BUTTON      ID_APP_ABOUT
    END
    ```
    
    to the next lines (the order of elements in important):
    ```
    IDR_MAINFRAME TOOLBAR 16, 15
    BEGIN
        BUTTON      ID_FILE_NEW
        BUTTON      ID_FILE_OPEN
        BUTTON      ID_FILE_SAVE
        SEPARATOR
        BUTTON      ID_EDIT_CUT
        BUTTON      ID_EDIT_COPY
        BUTTON      ID_EDIT_PASTE
        SEPARATOR
        BUTTON      ID_COMBOBOX
        BUTTON      ID_FILE_PRINT
        BUTTON      ID_APP_ABOUT
    END
    ```
    Save changes and close the file.
    
14. Open the "res\Toolbar.bmp" file in any graphic editor (Paint, Paint.NET, etc.)
    and insert an arbitrary pictogram (with size of 16 px by width and 15 px by height) (with arbitrary contents (for example a black rectangle)) between the 6-th and 7-th element (pictogram), so the whole bar image will be wider by 16 px.
    Save changes and close the file.
    
15. Open Visual Studio with the current project and build the project.
