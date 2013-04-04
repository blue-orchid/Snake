#include <windows.h>

#include "GameWndProc.h"
#include "resource.h"

//////////////////////////////////////////////////////////////////////////

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow )
{
	static TCHAR szGameName[] = TEXT( "Snake" );

	HWND		hwnd;
	MSG			msg;
	WNDCLASS	wndclass;

	wndclass.cbClsExtra		= 0;
	wndclass.cbWndExtra		= 0;
	wndclass.hbrBackground	= (HBRUSH) GetStockObject( BLACK_BRUSH );
	wndclass.hCursor		= LoadCursor( NULL, IDC_ARROW );
	wndclass.hIcon			= LoadIcon( hInstance, MAKEINTRESOURCE(IDI_ICON_GAME) );
	wndclass.hInstance		= hInstance;
	wndclass.lpfnWndProc	= WndProc;
	wndclass.lpszClassName	= szGameName;
	wndclass.lpszMenuName	= NULL;
	wndclass.style			= CS_HREDRAW | CS_VREDRAW;

	if( !RegisterClass(&wndclass) )
	{
		MessageBox( NULL, TEXT("������ע��ʧ��!"), TEXT("Ӧ�ó������"), MB_OK | MB_ICONERROR );
		return 0;
	}

	hwnd = CreateWindow(
		szGameName, TEXT("̰����"),
		WS_CAPTION | WS_SYSMENU,
		(int)((GetSystemMetrics(SM_CXSCREEN)-800)/2),
		(int)((GetSystemMetrics(SM_CYSCREEN)-600)/2),
		800, 600,
		NULL, NULL, hInstance, NULL
	);

	ShowWindow( hwnd, iCmdShow );
	UpdateWindow( hwnd );

	while( GetMessage( &msg, NULL, 0, 0 ) )
	{
		TranslateMessage( &msg );
		DispatchMessage( &msg );
	}

	return msg.wParam;
}

//////////////////////////////////////////////////////////////////////////
