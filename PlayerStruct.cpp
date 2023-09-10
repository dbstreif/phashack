#include "pch.h"
#include "PlayerStruct.h"

uintptr_t moduleBase = (uintptr_t)GetModuleHandle("GameAssembly.dll");

void Player_o::RevivePlayer()
{
	typedef void(*Player_oRevivePlayer_o)(Player_o*);
	Player_oRevivePlayer_o Player_oRevivePlayer = (Player_oRevivePlayer_o)reinterpret_cast<LPVOID>(moduleBase + 0x9B11C0);
	Player_oRevivePlayer(this);
}
