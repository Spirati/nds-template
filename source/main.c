#define DEBUG true

#pragma region Includes
#include <nds.h>
#include <filesystem.h>
#include <nds/ndstypes.h>
#include <nds/arm9/sprite.h>
#include <nds/arm9/video.h>
#include <nds/arm9/console.h>
#include <stdio.h>

#pragma endregion Includes

void debug(void) {
    consoleDebugInit(DebugDevice_NOCASH);
}

int main(void) {
    #pragma region Init
    videoSetMode(MODE_5_2D); // 2 static + 2 ext
    videoSetModeSub(MODE_0_2D); // 4 static
    vramSetBankA(VRAM_A_MAIN_SPRITE);
    vramSetBankB(VRAM_B_MAIN_BG_0x06000000);
    vramSetBankD(VRAM_D_SUB_SPRITE);
    oamInit(&oamMain, SpriteMapping_1D_32, false);
    oamInit(&oamSub, SpriteMapping_1D_32, false);

    if(DEBUG) debug();
    #pragma endregion Init

    #pragma region MainLoop
    while(1) {
        swiWaitForVBlank();
        oamUpdate(&oamMain);
        oamUpdate(&oamSub);
    }
    #pragma endregion MainLoop

    return 0;
}