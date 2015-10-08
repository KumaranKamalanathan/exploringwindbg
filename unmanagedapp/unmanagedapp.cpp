// unmanagedapp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <string>

void LogMessage(std::wstring buff_data) {

	DWORD dwbw;
	HANDLE HND = CreateFile(
		L"LogInfo.log",
		GENERIC_WRITE,
		FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (HND == NULL) {
		wprintf(_T("%s"), L"Failed to CreateFile");
		wprintf(_T("%d"), GetLastError());
		return;
	}

	if (!WriteFile(HND,
		&buff_data[0],
		buff_data.length(),
		&dwbw,
		NULL))
	{
		wprintf(_T("%s"), L"Failed to WriteFile");
		wprintf(_T("%d"), GetLastError());
	}
}

int main()
{

	char st[] = "\\01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456";
	LogMessage(L"Start Logging");
	LogMessage(L"Stop Logging");
    return 0;
}

