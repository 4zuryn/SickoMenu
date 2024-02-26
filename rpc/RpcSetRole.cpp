#include "pch-il2cpp.h"
#include "_rpc.h"
#include "game.h"
#include "utility.h"

RpcSetRole::RpcSetRole(PlayerControl* player, RoleTypes__Enum role)
{
	this->Player = player;
	this->Role = role;
}

void RpcSetRole::Process()
{
	if (Player == nullptr) return;

	PlayerControl_RpcSetRole(Player, Role, NULL);
}

SetRole::SetRole(RoleTypes__Enum role)
{
	this->Role = role;
}

void SetRole::Process()
{
	PlayerControl_SetRole(*Game::pLocalPlayer, Role, NULL);
	RoleManager_SetRole(Game::RoleManager.GetInstance(), *Game::pLocalPlayer, Role, NULL);
}