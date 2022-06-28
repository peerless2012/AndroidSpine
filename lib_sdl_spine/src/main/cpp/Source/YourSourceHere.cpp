#include <jni.h>
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <spine/spine.h>
#include <spine/Debug.h>
#include <spine/Log.h>
#include <spine-sdl.h>
#include <memory>
/**
* @Author ZhiMing.Wang
* @Email wangzhiming@pwrd.com
* @DateTime 2022/6/20 19:14
* @Version V1.0
* @Description 
*/

using namespace std;
using namespace spine;

static int done = 0;

static SDL_Window *window = NULL;

static SDL_Renderer *renderer = NULL;

static SDL_Texture *texture = NULL;

static int windowWidth = 0;

static int windowHeight = 0;

static int textureOffset = 0;

static SDL_Rect srcRect;

static SDL_Rect destRect;

/*
On android (in SDL) relative paths point to the root of the assets dir
On desktop we are assuming that the working dir is the location of the
executable (bin/<buildtype>). So assests are in ../../assets/.
*/
#if defined(__ANDROID__)
#define ASSET_PATH ""
#else
#define ASSET_PATH "../../assets/"
#endif

int init() {
    int width = 640;
    int height = 480;
    Uint32 flags = 0;
#if defined(__ANDROID__)
    flags |= SDL_WINDOW_FULLSCREEN;
#endif

    // init
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL init failed: %s", SDL_GetError());
        SDL_ClearError();
        return 0;
    }

    // create window
    window = SDL_CreateWindow("Demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);
    if (!window) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Creating window failed: %s", SDL_GetError());
        SDL_ClearError();
        return 0;
    }

    // create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Creating renderer failed: %s", SDL_GetError());
        SDL_ClearError();
        return 0;
    }

    // load bitmap texture
    const char *bitmap = ASSET_PATH "sdl.bmp";
    SDL_Surface *bitmapSurface = SDL_LoadBMP(bitmap);
    if (!bitmapSurface) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Load bitmap failed: %s", SDL_GetError());
        SDL_ClearError();
        return 0;
    }

    texture = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
    SDL_FreeSurface(bitmapSurface);
    if (!texture) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Creating texture failed: %s", SDL_GetError());
        SDL_ClearError();
        return 0;
    }

    srcRect.w = bitmapSurface->w;
    srcRect.h = bitmapSurface->h;

    SDL_Log("SDL finish init.");

    return 1;
}

void release() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }

    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }

    if (window) {
        SDL_DestroyWindow(window);
    }

    SDL_Quit();
}

void rendererFrame() {
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0xF6, 0xF6, 0xF6, 0xFF);
    SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
    SDL_RenderPresent(renderer);
    destRect.x += 5;
    if (destRect.x > windowWidth) {
        destRect.x = 0;
    }
}

int main(int argc, char* argv[]) {
    if (!init()) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Init error");
        release();
        return 0;
    }

    SDL_GetWindowSize(window, &windowWidth, &windowHeight);
    SDL_Log("SDL window width = %d, height = %d", windowWidth, windowHeight);
    destRect.w = windowWidth;
    destRect.h = windowHeight;

    while (!done) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT
            || event.key.keysym.scancode == SDL_SCANCODE_AC_BACK) {
                SDL_Log("SDL quite");
                done = 1;
            }
        }
        if (!done) {
            rendererFrame();
            SDL_Delay(16);
        }
    }

    release();

    return 0;
}