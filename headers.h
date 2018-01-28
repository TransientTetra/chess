#include "lib.h"

#ifndef STRUCT
#define STRUCT
#include "struct.h"
#endif
#include "draw.h"
#include "memory.h"
#include "logic.h"

#define SCREEN_WIDTH 300
#define SCREEN_HEIGHT 300
#define BLUE SDL_MapRGB(screen->format, 0x00, 0x00, 0xFF)
#define WHITE SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF)
#define RED SDL_MapRGB(screen->format, 0xFF, 0x00, 0x00)
#define GREEN SDL_MapRGB(screen->format, 0x00, 0xFF, 0x00)