// dllmain.cpp : Defines the entry point for the DLL application.
//precompiled headers
#include "pch.h"
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <iostream>
#include <cstdio>
#include <Windows.h>
#include <MinHook.h>
#include <TlHelp32.h>
#include "proc.h"
#include "mem.h"
#include "PlayerStruct.h"


#if _WIN64 
#pragma comment(lib, "libMinHook.x64.lib")
#else
#pragma comment(lib, "libMinHook.x86.lib")
#endif


//Hooks

//PlayerUpdate
void(__fastcall* PlayerUpdate_o)(DWORD*, DWORD*);
void __stdcall PlayerUpdate_hook(DWORD* __this, DWORD* methodinfo) {    
   if (GetAsyncKeyState(VK_NUMPAD5 & 1)) {
        std::cout << "I'm alive!" << std::endl;
    }



    return PlayerUpdate_o(__this, methodinfo);
}

void(__fastcall* KillPlayer_o)(DWORD*, bool, DWORD*);
void __stdcall KillPlayer_hook(DWORD* __this, bool deathbool, DWORD* methodinfo) {
    
    deathbool = true;
    std::cout << "Lol Ghost Stupid" << std::endl;


    return KillPlayer_o(__this, deathbool, methodinfo);
}

struct ConsoleManageStruct
{
    FILE* f;

    void CreateConsole() {
        AllocConsole();
        freopen_s(&f, "CONOUT$", "w", stdout);
    }

    void DestroyConsole() {
        fclose(f);
        FreeConsole();
    }
};


//Initialize Minhook
int init(uintptr_t modBase) {
    MH_STATUS init_status = MH_Initialize();
    if (init_status == MH_OK) {
        std::cout << "Injection Successful at: \"" << modBase << "\"" << std::endl;
        return 0;
    }
    else {
        return 1;
    }
}

//Main Function
DWORD WINAPI HackThread(HMODULE hModule) {
    //Init vars
    uintptr_t moduleBase = (uintptr_t)GetModuleHandle("GameAssembly.dll");
    ConsoleManageStruct ConsoleManageHandle;
    Player_o PlayerStruct;

    //Sanity Vars
    uintptr_t InsanityAddr = mem::FindDMAAddr(moduleBase + 0x052E4E18, { 0xB8, 0x8, 0xB0, 0x28, 0xC0, 0x30 });
    float* InsanityVar = (float*)(InsanityAddr);
    *InsanityVar = 0;
    bool bSanityNop = false;

    //Kill Function Vars
    bool deathbool = false;



    //Init functions
    ConsoleManageHandle.CreateConsole();
    if (init(moduleBase) == 1) {
        //On MH_Initialize failure
        ConsoleManageHandle.DestroyConsole();
        FreeLibraryAndExitThread(hModule, 1);
        return 1;
    }


    if (MH_CreateHook(reinterpret_cast<LPVOID*>(moduleBase + 0x9B0EE0), &KillPlayer_hook, (LPVOID*)(&KillPlayer_o)) != MH_OK) {
        ConsoleManageHandle.DestroyConsole();
        FreeLibraryAndExitThread(hModule, 1);
        return 1;
    } else {
        std::cout << "Hooked KillPlayer function" << std::endl;
    }
    

    //MH_CreateHook(reinterpret_cast<LPVOID*>(moduleBase + 0x9BAD90), &PlayerUpdate_hook, (LPVOID*)(&PlayerUpdate_o));
    //MH_EnableHook(reinterpret_cast<LPVOID*>(moduleBase + 0x9BAD90));

    while (true) {
        if (GetAsyncKeyState(VK_END) & 1) {
            break;
        }

        if (GetAsyncKeyState(VK_NUMPAD1) & 1) {
            InsanityAddr = mem::FindDMAAddr(moduleBase + 0x052E4E18, { 0xB8, 0x8, 0xB0, 0x28, 0xC0, 0x30 });
            InsanityVar = (float*)(InsanityAddr);
            std::cout << "Sanity Value: " << 100 - *InsanityVar << std::endl;

        }

        if (GetAsyncKeyState(VK_NUMPAD2) & 1) {

            *InsanityVar = 0;
        
        }

        if (GetAsyncKeyState(VK_NUMPAD3) & 1) {

            if (bSanityNop == false) {
                std::cout << "NOP Activated" << std::endl;
                mem::Nop((BYTE*)(moduleBase + 0x9EA69E), 5);
                mem::Nop((BYTE*)(moduleBase + 0x9EA702), 5);
                bSanityNop = true;
            }
            else {
                std::cout << "NOP Deactivated" << std::endl;
                mem::Patch((BYTE*)(moduleBase + 0x9EA69E), (BYTE*)"\xF3\x0F\x11\x73\x30", 5);
                mem::Patch((BYTE*)(moduleBase + 0x9EA702), (BYTE*)"\xF3\x0F\x11\x73\x30", 5);
                bSanityNop = false;
            }

        }

        if (GetAsyncKeyState(VK_NUMPAD4) & 1) {

            if (deathbool == false) {
                MH_EnableHook(reinterpret_cast<LPVOID*>(moduleBase + 0x9B0EE0));
                std::cout << "Invincibility ON!" << std::endl;
                deathbool = true;
            }
            else {
                MH_DisableHook(reinterpret_cast<LPVOID*>(moduleBase + 0x9B0EE0));
                std::cout << "Invincibility OFF!" << std::endl;
                deathbool = false;
            }
        }

        if (GetAsyncKeyState(VK_NUMPAD5) & 1) {
            PlayerStruct.RevivePlayer();
            std::cout << "Revived Player" << std::endl;
        }
    }

    //Exit functions
    ConsoleManageHandle.DestroyConsole();
    MH_Uninitialize();
    FreeLibraryAndExitThread(hModule, 0);
    return 0;
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        //New thread creation
        CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HackThread, hModule, 0, nullptr));
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}