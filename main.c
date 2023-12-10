#include <stdio.h>
#include <SDL.h>
#include <stdlib.h>
#include <time.h>

// Window dimensions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main() {
    // Seed for random number generation
    srand(time(NULL));

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow("Guess the Number", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    // Main loop flag
    int quit = 0;

    // Event handler
    SDL_Event e;

    // Main game loop
    while (!quit) {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            // User quits the game
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
            // User presses a key
            else if (e.type == SDL_KEYDOWN) {
                // Check if the key is a number
                if (e.key.keysym.sym >= SDLK_0 && e.key.keysym.sym <= SDLK_9) {
                    // Convert the key to a number
                    guess = e.key.keysym.sym - SDLK_0;

                    // Increment the attempts
                    attempts++;

                    // Check if the guess is correct
                    if (guess == secretNumber) {
                        printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
                        quit = 1; // End the game
                    } else if (guess < secretNumber) {
                        printf("Try a higher number.\n");
                    } else {
                        printf("Try a lower number.\n");
                    }
                }
            }
        }

        // Clear the renderer
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // Draw text on the window
        SDL_Color textColor = {0, 0, 0, 255};
        char message[50];
        sprintf(message, "Guess the Number: %d Attempts", attempts);

        SDL_Surface* textSurface = TTF_RenderText_Solid(font, message, textColor);
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_Rect textRect = {10, 10, textSurface->w, textSurface->h};

        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

        // Present the renderer
        SDL_RenderPresent(renderer);
    }

    // Destroy window and renderer
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Quit SDL subsystems
    SDL_Quit();

    return 0;
}
