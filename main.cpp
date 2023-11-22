#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include "glm/glm.hpp"

//define window dimensions
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const float GLOBAL_ANIMATION_SPEED = 1.0f;

//define SDL Window related variables
SDL_Window* window = NULL;
SDL_Renderer* windowRenderer = NULL;
SDL_Event currentEvent;

bool quit = false;

int mouseX, mouseY;

Uint64 startTime, endTime, elapsedTime;

struct Rectangle {
    glm::vec2 center;
    int width;
    int height;
    glm::vec2 direction;
    float speed = 0.1f;
    glm::vec3 color = glm::vec3(0.0f, 255.0f, 0.0f);

    SDL_Rect getSDLRect() {
        SDL_Rect rect;

        rect.x = center.x - width / 2.0f;
        rect.y = center.y - height / 2.0f;
        rect.w = width;
        rect.h = height;

        return rect;
    }
};

Rectangle r;

std::vector<Rectangle> enemies;

bool squareIsBlue = false;

void initRectangles() {

    r.center.x = 200.0f;
    r.center.y = 200.0f;
    r.width = 50;
    r.height = 50;

    enemies.push_back(r);

    r.center.x = 500.0f;
    r.center.y = 400.0f;
    r.width = 50;
    r.height = 50;
    r.speed = 0.2f;
    r.color = glm::vec3(255.0f, 0.0f, 0.0f);

    enemies.push_back(r);
}

void animate() {

    for (auto& enemy : enemies) {
        enemy.direction = glm::normalize(glm::vec2(mouseX, mouseY) - enemy.center);
        enemy.center += GLOBAL_ANIMATION_SPEED * elapsedTime * enemy.speed * enemy.direction;
    }
}

bool initWindow() {

    bool success = true;

    //Try to initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) {

        std::cout << "SDL initialization failed" << std::endl;
        success = false;

    }
    else {

        //Try to create the window
        window = SDL_CreateWindow(
            "Hello SDL2 Window!",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            WINDOW_WIDTH,
            WINDOW_HEIGHT,
            SDL_WINDOW_SHOWN);

        if (window == NULL) {

            std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
            success = false;

        }
        else {

            // Create a renderer for the current window
            windowRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

            if (windowRenderer == NULL) {

                std::cout << "Failed to create the renderer: " << SDL_GetError() << std::endl;
                success = false;

            }
            else {

                //Set background color
                SDL_SetRenderDrawColor(windowRenderer, 255, 255, 255, 255);

                //Apply background color
                SDL_RenderClear(windowRenderer);
            }
        }
    }

    return success;
}

void processEvents() {

    //Check for events in queue
    SDL_PollEvent(&currentEvent);

    //User requests quit
    if (currentEvent.type == SDL_QUIT) {

        quit = true;
    }

    //Mouse event -> pressed button
    if (currentEvent.type == SDL_MOUSEBUTTONDOWN) {

        if (currentEvent.button.button == SDL_BUTTON_LEFT) {

            SDL_GetMouseState(&mouseX, &mouseY);
            std::cout << "Mouse left click => " << "x: " << mouseX << ", y: " << mouseY << std::endl;
        }

        if (currentEvent.button.button == SDL_BUTTON_RIGHT) {

            SDL_GetMouseState(&mouseX, &mouseY);
            std::cout << "Mouse right click => " << "x: " << mouseX << ", y: " << mouseY << std::endl;
        }
    }

    //Mouse event -> mouse movement
    if (currentEvent.type == SDL_MOUSEMOTION) {

        SDL_GetMouseState(&mouseX, &mouseY);

        if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON_LMASK) {

            SDL_GetMouseState(&mouseX, &mouseY);
            std::cout << "Mouse move while left clicking => " << "x: " << mouseX << ", y: " << mouseY << std::endl;
        }

        if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON_RMASK) {

            SDL_GetMouseState(&mouseX, &mouseY);
            std::cout << "Mouse move while right clicking => " << "x: " << mouseX << ", y: " << mouseY << std::endl;
        }
    }

    //Keyboard event
    if (currentEvent.type == SDL_KEYDOWN) {

        switch (currentEvent.key.keysym.sym) {

        case SDLK_UP:
            break;

        case SDLK_DOWN:
            break;

        case SDLK_LEFT:           
            break;

        case SDLK_RIGHT:            
            break;

        case SDLK_r:
            break;

        case SDLK_s:
            break;

        case SDLK_ESCAPE:

            quit = true;
            break;

        default:
            break;
        }
    }
}

void drawRectangles() {

    for (auto enemy : enemies) {

        SDL_SetRenderDrawColor(windowRenderer, enemy.color.r, enemy.color.g, enemy.color.b, 255);
        SDL_Rect tmpR = enemy.getSDLRect();
        SDL_RenderFillRect(windowRenderer, &tmpR);
    }
}

void drawFrame() {

    //Clear the background
    SDL_SetRenderDrawColor(windowRenderer, 255, 255, 255, 255);
    SDL_RenderClear(windowRenderer);

    //Draw scene
    drawRectangles();


    //Update window
    SDL_RenderPresent(windowRenderer);
}

void processMovement() {

    /*const Uint8* state = SDL_GetKeyboardState(nullptr);

    if (state[SDL_SCANCODE_RIGHT]) {

        r.center.x += 0.1f;
    }

    if (state[SDL_SCANCODE_LEFT]) {

        r.center.x -= 0.1f;
    } 

    if (state[SDL_SCANCODE_UP]) {

        r.center.y -= 0.1f;
    }

    if (state[SDL_SCANCODE_DOWN]) {

        r.center.y += 0.1f;
    }*/
}

void cleanup() {

    //Clear enemies
    enemies.clear();

    //Destroy renderer
    if (windowRenderer) {

        SDL_DestroyRenderer(windowRenderer);
        windowRenderer = NULL;
    }

    //Destroy window
    if (window) {

        SDL_DestroyWindow(window);
        window = NULL;
    }

    //Quit SDL
    SDL_Quit();
}

Uint32 callback(Uint32 interval, void* name) {

    if (squareIsBlue) {

        enemies.at(0).color = glm::vec3(0.0f, 255.0f, 0.0f);
        squareIsBlue = false;
    } else {
        enemies.at(0).color = glm::vec3(0.0f, 0.0f, 255.0f);
        squareIsBlue = true;
    }

    return 1000;
}

int main(int argc, char* argv[]) {

    //Initialize window
    if (!initWindow()) {

        std::cout << "Failed to initialize" << std::endl;
        return -1;
    }

    initRectangles();

    SDL_TimerID timerID = SDL_AddTimer(1000, callback, nullptr);

    //Game loop
    while (!quit) {

        startTime = SDL_GetTicks64();

        processMovement();
        processEvents();
        drawFrame();
        animate();

        endTime = SDL_GetTicks64();
        elapsedTime = endTime - startTime;
    }

    SDL_RemoveTimer(timerID);

    cleanup();
    return 0;
}
