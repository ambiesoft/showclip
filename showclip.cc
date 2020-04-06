#include <Windows.h>

#include <string>

#include "../lsMisc/GetClipboardText.h"
#include "../lsMisc/CommandLineParser.h"

using namespace Ambiesoft;
using namespace std;

#define APPNAME L"showclip"

int WinMain(
		HINSTANCE hInst,
		HINSTANCE hPrevInst,
		LPSTR lpCmdLine,
		int nShowCmd)
{
	CCommandLineParser parser;

	bool isutf8 = false;
	parser.AddOption(L"-utf8", 0, &isutf8);
	parser.Parse();

	wstring text;
	if(!GetClipboardText(NULL, text))
	{
		cerr << "Failed to get clipboard text" << endl;
		return 1;
	}

	MessageBoxW(NULL,text.c_str(), APPNAME, 0);
	return 0;
}

