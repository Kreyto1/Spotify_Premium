// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "Modify.h"

BOOL APIENTRY DllMain (HMODULE hModule,
					   DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	DisableThreadLibraryCalls (hModule);
	std::wstring_view procname = GetCommandLine ();
	// only Spotify process - this help avoid false positive
	if (std::wstring_view::npos != procname.find (L"Spotify.exe")) {
		switch (ul_reason_for_call)
		{
		case DLL_PROCESS_ATTACH:
			if (std::wstring_view::npos == procname.find (L"--type=")) {
				// Enable developer - main process
				CreateThread (NULL, NULL, Developer, NULL, 0, NULL);
				// block ads request - main process
				CreateThread (NULL, NULL, KillAds, NULL, 0, NULL);
				// block banner - main process
				CreateThread(NULL, NULL, KillBanner, NULL, 0, NULL);
			}
			
			break;
		}
	}
	return TRUE;
}

