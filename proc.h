#pragma once

#include <vector>
#include <windows.h>
#include <TlHelp32.h>

DWORD GetProcId(const CHAR* procName);

uintptr_t GetModuleBaseAddress(DWORD procId, const CHAR* modName);

//Uncomment in External Cheats
//uintptr_t FindDMAAddr(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets);