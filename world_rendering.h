#pragma once

#include "stdafx.h"
#include "Misc.h"
#include "engine_render.h"

namespace engine_post_renderer {

	inline void engine_post_exec();

}
inline auto RobotoFont = UObject::FindObject<UFont>(skCrypt("Font Roboto.Roboto"));
inline BOOL(*LOS)(SDK::APlayerController* controller, SDK::AFortPlayerPawn* pawn, SDK::FVector* vp, bool alt) = nullptr;
inline BOOLEAN LineOFSightTo(SDK::APlayerController* controller, SDK::AFortPlayerPawn* pawn, SDK::FVector* vp) {
	return LOS(controller, pawn, vp, false);
}

inline uintptr_t(__fastcall* hookless)(void*, FVector*, FRotator*) = 0;
inline engine_render_t RetRendering;

inline bool World() {

	hk_renderbasics::gWorld = (UWorld*)(*(uintptr_t*)hk_renderbasics::UWorld_Offset);
	if (!hk_renderbasics::gWorld) return false;
	if (!hk_renderbasics::gWorld->OwningGameInstance) return false;
	if (!hk_renderbasics::gWorld->OwningGameInstance->LocalPlayers[0]) return false;
	if (!hk_renderbasics::gWorld->OwningGameInstance->LocalPlayers[0]->PlayerController) return false;

	hk_renderbasics::LocalPlayer = hk_renderbasics::gWorld->OwningGameInstance->LocalPlayers[0];
	hk_renderbasics::LocalController = hk_renderbasics::gWorld->OwningGameInstance->LocalPlayers[0]->PlayerController;

	if (hk_renderbasics::LocalController->AcknowledgedPawn) {
		world::bIsValid = true;
	}
	else {
		world::bIsValid = false;
	}

	return true;
}