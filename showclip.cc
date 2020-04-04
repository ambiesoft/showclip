#include <Windows.h>

#include <string>

#include "../lsMisc/GetClipboardText.h"
#include "../lsMisc/CommandLineParser.h"

using namespace Ambiesoft;
using namespace std;

#define APPNAME L"showclip"

//int WinMain(
//		HINSTANCE hInst,
//		HINSTANCE hPrevInst,
//		LPSTR lpCmdLine,
//		int nShowCmd)
int main()
{
	CCommandLineParser parser;

	bool isutf8 = false;
	parser.AddOption(L"-utf8", 0, &isutf8, ArgEncodingFlags::ArgEncodingFlags_Default,
		L"Output is encoded with UTF8");
	
	bool isIgnoreError = false;
	parser.AddOption(L"-ige", 0, &isIgnoreError,ArgEncodingFlags::ArgEncodingFlags_Default,
		L"Show nothing and return 0 if error occured or the clipboard does not have texts");

	bool isShowHelp = false;
	parser.AddOption({ L"-h", L"/h", L"--help"}, 0, &isShowHelp, ArgEncodingFlags_Default,
		L"Show Help");
	
	bool isShowVersion = false;
	parser.AddOption({ L"-V", L"--version" }, 0, &isShowVersion, ArgEncodingFlags_Default,
		L"Show Version");

	bool isAddEnter = false;
	parser.AddOption({L"-ade"}, 0, &isAddEnter, ArgEncodingFlags_Default,
		L"Add enter if the clipboard text not end with 'Enter'");

	parser.Parse();

	if (parser.hadUnknownOption())
	{
		wcerr << L"Unknow option:" << parser.getUnknowOptionStrings() << endl;
		return 1;
	}

	if (isShowHelp)
	{
		wcout << parser.getHelpMessage() << endl;
		return 0;
	}
	if (isShowVersion)
	{
		cout << APPVERSION << endl;
		return 0;
	}
	wstring text;
	if(!GetClipboardText(NULL, text))
	{
		cerr << "Failed to get clipboard text" << endl;
		return 1;
	}

	if (isAddEnter)
	{
		if (text[text.size() - 1] != L'\n')
		{
			text += L"\n";
		}
	}

	if (isutf8)
	{
		string sUtf8 = toStdUtf8String(text);
		DWORD dummy;
		WriteFile(GetStdHandle(STD_OUTPUT_HANDLE),
			sUtf8.data(),
			sUtf8.size(),
			&dummy,
			NULL);
	}
	else
	{
		wcout << text;
	}
	// MessageBoxW(NULL,text.c_str(), APPNAME, 0);
	return 0;
}

