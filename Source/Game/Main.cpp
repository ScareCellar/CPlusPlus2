//#include <SDL3/SDL.h>
#include <iostream>
#include <vector>
#include <fmod.hpp>


#include "../Engine/Core/Random.h"
#include "../Engine/Core/Math/Math.h"
#include "../Engine/Core/Math/Vector2.h"
#include "../Engine/Renderer/Renderer.h"
#include "../Engine/Input/InputSystem.h"
#include "../Engine/Core/Audio/AudioSystem.h" 
#include "../Engine/Core/Math/Vector3.h"

using namespace blood;

int main(int argc, char* argv[]) {
    //create systems
	    // create renderer system 
	    blood::Renderer renderer;
        renderer.Init();
        renderer.CreateWindow("testing", 1980, 1224);

        //create audio system
        blood::AudioSystem audio;

        //create input system
        blood::InputSystem input;
        input.Initialize();
    //end system creation


    bool quit = false;

    SDL_Event e;




    //initialize sounds
    audio.AddSound("bass.wav", "bass");
    audio.AddSound("snare.wav", "snare");
    audio.AddSound("clap.wav", "clap");
    audio.AddSound("close-hat.wav", "close-hat");
    audio.AddSound("open-hat.wav", "open-hat");
    

    //create stars
    /*std::vector<vec2> stars;
    for (int i = 0; i < 100; i++) {
        stars.push_back(vec2(random::getRandomFloat() * 1280, random::getRandomFloat() * 1024));
    }*/

    std::vector<vec2> dragDrawnPoints;
    std::vector<std::vector<vec2>> drawnLines;

    vec2 lineToolStartPos{ 0,0 };
    vec2 lineToolEndPos{ 0,0 };

    //std::vector<vec2> speed = Vector2<blood::vec2>(40, 0);
    //blood::vec2 speed{ -140.0f, 0.0f };



    //main loop
    while (!quit) {
        
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        } 

        //draw
        blood::vec3 color(1, 1, 0);

        renderer.SetColorFloat(color.r, color.g, color.b);
        //renderer.SetColor(0, 0, 0, 255); // Set render draw color to black
		renderer.Clear(); // Clear the screen

        renderer.SetColor(255, 255, 255, 255);
        audio.Update();
        input.Update();

        if (input.GetKeyDown(SDL_SCANCODE_A)) {
            std::cout << "pressed\n";
        }

        if (input.GetKeyPressed(SDL_SCANCODE_F)) {
            renderer.Clear();
            dragDrawnPoints.clear();
            drawnLines.clear();
        }

        if (input.GetMouseButtonDown(blood::InputSystem::MouseButton::Left)) {
            //std::cout << "LMB pressed!\n";
        }

        blood::vec2 mouse = input.GetMousePosition();
        //std::cout << mouse.x << ", " << mouse.y << std::endl;


        //code to draw points by dragging
        if (input.GetMouseButtonDown(blood::InputSystem::MouseButton::Left)) {

            dragDrawnPoints.push_back(vec2(mouse.x, mouse.y));
        }
        else if (input.GetMouseButtonReleased(blood::InputSystem::MouseButton::Left)) {
            dragDrawnPoints.push_back(vec2(0, 0));
        }

        //renderer.SetColor(random::getRandomInt(256), random::getRandomInt(256), random::getRandomInt(256), 255);

        for (int i = 0; i < dragDrawnPoints.size(); i++ ) {
            if (i != 0) {
                if (dragDrawnPoints[i - 1].x != 0 && dragDrawnPoints[i - 1].y != 0 && dragDrawnPoints[i].x != 0 && dragDrawnPoints[i].y != 0) {
                    renderer.DrawLine(dragDrawnPoints[i].x, dragDrawnPoints[i].y, dragDrawnPoints[i-1].x, dragDrawnPoints[i-1].y);
                    renderer.SetColor(random::getRandomInt(256), random::getRandomInt(256), random::getRandomInt(256), 255);
                    //renderer.SetColor(255, 255, 255, 255);
                }
            }
        }
		

        //code for drawing a single straight line in one random color using right click
        // currently crashes the application, so that's fun
        if (input.GetMouseButtonDown(blood::InputSystem::MouseButton::Right)) {
            if (input.GetMouseButtonPressed(blood::InputSystem::MouseButton::Right)) {
                lineToolStartPos = input.GetMousePosition();
            }
            renderer.DrawLine(lineToolStartPos.x, lineToolStartPos.y, input.GetMousePosition().x, input.GetMousePosition().y);
        }

        if (input.GetMouseButtonReleased(blood::InputSystem::MouseButton::Right)) { 
            lineToolEndPos = input.GetMousePosition(); 
            std::vector<vec2> drawnLine{ lineToolStartPos, lineToolEndPos };
            drawnLines.push_back(drawnLine);
        }

        ////draw finalized line
        for (int i = 0; i < drawnLines.size(); i++) {
            renderer.DrawLine(drawnLines[i][0].x, drawnLines[i][0].y, drawnLines[i][1].x, drawnLines[i][1].y);

        }

        //for (vec2 star : stars) {
        //    renderer.SetColor(random::getRandomInt(256), random::getRandomInt(256), random::getRandomInt(256), 255); // Set render draw color to random color
        //    renderer.DrawPoint(star.x,star.y);
        //}


        //for (vec2 star : stars) {
        //    renderer.SetColor(random::getRandomInt(256), random::getRandomInt(256), random::getRandomInt(256), 255); // Set render draw color to random color
        //    renderer.DrawLine(random::getRandomInt(1280) + random::getRandomFloat(), random::getRandomInt(1024) + random::getRandomFloat(), random::getRandomInt(1280) + random::getRandomFloat(), random::getRandomInt(1024) + random::getRandomFloat()); // Render a random line            
        //}

        //play drum sounds
        if (input.GetKeyPressed(SDL_SCANCODE_A)) {
            audio.PlaySound("bass");
        }



        //shutdown when user presses escape button
        if (input.GetKeyDown(SDL_SCANCODE_ESCAPE)) {
            break;
        }
        

        renderer.Present(); // Render the screen
    }

    //shutdown systems
    renderer.ShutDown();
    audio.Shutdown();
    input.ShutDown();

    return 0;
}

