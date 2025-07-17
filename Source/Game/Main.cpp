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
#include "../Engine/Renderer/Model.h"

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

        //create model
        blood::Model model;
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
        
		renderer.Clear(); // Clear the screen

        renderer.SetColor(255, 255, 255, 255);

        //update necessary systems
        audio.Update();
        input.Update();

        

        //play drum sounds
        if (input.GetKeyPressed(SDL_SCANCODE_A)) audio.PlaySound("bass");
        if (input.GetKeyPressed(SDL_SCANCODE_S)) audio.PlaySound("snare");
        if (input.GetKeyPressed(SDL_SCANCODE_D)) audio.PlaySound("clap");
        if (input.GetKeyPressed(SDL_SCANCODE_Q)) audio.PlaySound("close-hat");
        if (input.GetKeyPressed(SDL_SCANCODE_E)) audio.PlaySound("open-hat");

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

