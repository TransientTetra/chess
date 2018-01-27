#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>

#include "struct.h"

#define SCREEN_WIDTH 300
#define SCREEN_HEIGHT 300
#define BLUE SDL_MapRGB(screen->format, 0x00, 0x00, 0xFF)
#define WHITE SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF)
#define RED SDL_MapRGB(screen->format, 0xFF, 0x00, 0x00)
#define GREEN SDL_MapRGB(screen->format, 0x00, 0xFF, 0x00)