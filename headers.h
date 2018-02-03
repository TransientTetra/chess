#include "lib.h"

#ifndef STRUCT
#define STRUCT
#include "struct.h"
#endif
#include "draw.h"
#include "memory.h"
#include "logic.h"

#define TILE 32
#define SCREEN_WIDTH 276
#define SCREEN_HEIGHT 276
#define BOARDX 10
#define BOARDY 10

#define PAWNX 0
#define PAWNY 0
#define KNIGHTX 32
#define KNIGHTY 0
#define BISHOPX 64
#define BISHOPY 0
#define ROOKX 0
#define ROOKY 32
#define QUEENX 32
#define QUEENY 32
#define KINGX 64
#define KINGY 32

#define WHITE_PIECE 0
#define BLACK_PIECE 1

#define NONE 0
#define	PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5
#define KING 6

#define BLUE SDL_MapRGB(screen->format, 0x00, 0x00, 0xFF)
#define WHITE SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF)
#define BLACK SDL_MapRGB(screen->format, 0x00, 0x00, 0x00)
#define RED SDL_MapRGB(screen->format, 0xFF, 0x00, 0x00)
#define GREEN SDL_MapRGB(screen->format, 0x00, 0xFF, 0x00)
#define ORANGE SDL_MapRGB(screen->format, 0xFF, 0x83, 0x00)
#define DARKBLUE SDL_MapRGB(screen->format, 0x00, 0x00, 0x66)
#define LIGHTBLUE SDL_MapRGB(screen->format, 0x33, 0x33, 0xFF)