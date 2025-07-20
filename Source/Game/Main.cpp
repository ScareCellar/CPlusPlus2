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
#include "../Engine/Core/Time.h"

using namespace blood;

int main(int argc, char* argv[]) {


    //create systems
	    // create renderer system 
	    blood::Renderer renderer;
        renderer.Initialize();
        renderer.CreateWindow("Game", 1980, 1224);

        //create audio system
        blood::AudioSystem audio;
        audio.Initialize();

        //create input system
        blood::InputSystem input;
        input.Initialize();

        //create time
        blood::Time time;

        //create model
        std::vector<blood::vec2> points{
            { -5, -5 },
            {  5, -5 },
            {  5,  5 },
            { -5,  5 },
            { -5, -5 },
        };
        blood::Model model{ points, {0,0,1} };
    //end system creation


    bool quit = false;

    SDL_Event e;




    //initialize sounds
    audio.AddSound("test.wav", "test");
    audio.AddSound("bass.wav", "bass");
    audio.AddSound("snare.wav", "snare");
    audio.AddSound("clap.wav", "clap");
    audio.AddSound("close-hat.wav", "close-hat");
    audio.AddSound("open-hat.wav", "open-hat");
    

    audio.PlaySound("test");

    vec3 color(0, 0, 0);

    //main loop
    while (!quit) {
        
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        } 

        //draw
        renderer.SetColorFloat(color.r, color.g, color.b);
        
		renderer.Clear(); // Clear the screen

        model.Draw(renderer, input.GetMousePosition(), time.GetTime(), 5.0f);

        //update necessary systems
        audio.Update();
        input.Update();
        time.Tick();

        

        //play drum sounds
        if (input.GetKeyPressed(SDL_SCANCODE_Q)) audio.PlaySound("bass");
        if (input.GetKeyPressed(SDL_SCANCODE_W)) audio.PlaySound("snare");
        if (input.GetKeyPressed(SDL_SCANCODE_A)) audio.PlaySound("clap");
        if (input.GetKeyPressed(SDL_SCANCODE_E)) audio.PlaySound("close-hat");
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

