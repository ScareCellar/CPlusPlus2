#include <SDL3/SDL.h>
#include <iostream>
#include <vector>
#include "../Engine/Core/Random.h"
#include "../Engine/Core/Math/Math.h"
#include "../Engine/Core/Math/Vector2.h"
#include "../Engine/Renderer/Renderer.h"
#include "../Engine/Input/InputSystem.h"

using namespace blood;

int main(int argc, char* argv[]) {
	// Initialize SDL  
	blood::Renderer renderer;
    renderer.Init();

    renderer.CreateWindow("testing", 1280, 1024);

    //SDL_Event e;

    bool quit = false;

    SDL_Event e;


    //create stars
    /*std::vector<vec2> stars;
    for (int i = 0; i < 100; i++) {
        stars.push_back(vec2(random::getRandomFloat() * 1280, random::getRandomFloat() * 1024));
    }*/

    std::vector<vec2> drawnPoints;

    //std::vector<vec2> speed = Vector2<blood::vec2>(40, 0);
    //blood::vec2 speed{ -140.0f, 0.0f };

    blood::InputSystem input;
    input.Initialize();


    //main loop
    while (!quit) {
        
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        } 

        //draw
        renderer.SetColor(0, 0, 0, 255); // Set render draw color to black
		renderer.Clear(); // Clear the screen

        renderer.SetColor(255, 255, 255, 255);
        //audio->Update();
        input.Update();

        if (input.GetKeyDown(SDL_SCANCODE_A)) {
            std::cout << "pressed\n";
        }

        if (input.GetKeyPressed(SDL_SCANCODE_F)) {
            std::cout << "F key pressed!" << std::endl;
        }

        if (input.GetMouseButtonDown(blood::InputSystem::MouseButton::Left)) {
            //std::cout << "LMB pressed!\n";
        }

        blood::vec2 mouse = input.GetMousePosition();
        //std::cout << mouse.x << ", " << mouse.y << std::endl;

        if (input.GetMouseButtonDown(blood::InputSystem::MouseButton::Left)) {
            drawnPoints.push_back(vec2(mouse.x, mouse.y));
        }
        else if (input.GetMouseButtonReleased(blood::InputSystem::MouseButton::Left)) {
            drawnPoints.push_back(vec2(0, 0));
        }

        renderer.SetColor(random::getRandomInt(256), random::getRandomInt(256), random::getRandomInt(256), 255);

        for (int i = 0; i < drawnPoints.size(); i++ ) {
            if (i != 0) {
                if (drawnPoints[i-1].x != 0 && drawnPoints[i-1].y != 0 && drawnPoints[i].x != 0 && drawnPoints[i].y != 0) {
                    renderer.DrawLine(drawnPoints[i].x, drawnPoints[i].y, drawnPoints[i-1].x, drawnPoints[i-1].y);
                    //renderer.SetColor(random::getRandomInt(256), random::getRandomInt(256), random::getRandomInt(256), 255);
                }
            }
        }
		
        //for (vec2 star : stars) {
        //    renderer.SetColor(random::getRandomInt(256), random::getRandomInt(256), random::getRandomInt(256), 255); // Set render draw color to random color
        //    renderer.DrawPoint(star.x,star.y);
        //}


        //for (vec2 star : stars) {
        //    renderer.SetColor(random::getRandomInt(256), random::getRandomInt(256), random::getRandomInt(256), 255); // Set render draw color to random color
        //    renderer.DrawLine(random::getRandomInt(1280) + random::getRandomFloat(), random::getRandomInt(1024) + random::getRandomFloat(), random::getRandomInt(1280) + random::getRandomFloat(), random::getRandomInt(1024) + random::getRandomFloat()); // Render a random line            
        //}


        renderer.Present(); // Render the screen
    }

    renderer.ShutDown();

    return 0;
}

