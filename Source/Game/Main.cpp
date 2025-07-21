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
#include "../Engine/Game/Actor.h"

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
        blood::Model* model = new Model{ points, {0,0,1} };

        std::vector<blood::Actor> actors;
        for (int i = 0; i < 20; i++) {

            blood::Transform transform = Transform({ random::getRandomFloat() * 1980 ,random::getRandomFloat() * 1224 }, math::halfPi / 2, (float)random::getRandomInt(101));
            actors.push_back({ transform, model });

        }
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

        for (Actor& actor : actors) {
            actor.Draw(renderer);
        }

        //update necessary systems
        audio.Update();
        input.Update();
        time.Tick();

        

        //play drum sounds
        /*if (input.GetKeyPressed(SDL_SCANCODE_Q)) audio.PlaySound("bass");
        if (input.GetKeyPressed(SDL_SCANCODE_W)) audio.PlaySound("snare");
        if (input.GetKeyPressed(SDL_SCANCODE_A)) audio.PlaySound("clap");
        if (input.GetKeyPressed(SDL_SCANCODE_E)) audio.PlaySound("close-hat");
        if (input.GetKeyPressed(SDL_SCANCODE_E)) audio.PlaySound("open-hat");*/

        /*if (input.GetKeyDown(SDL_SCANCODE_A)) transform.rotation -= 1 * time.GetDeltaTime();
        if (input.GetKeyDown(SDL_SCANCODE_D)) transform.rotation += 1 * time.GetDeltaTime();*/

        blood::vec2 direction{ 0,0 };
        if (input.GetKeyDown(SDL_SCANCODE_W)) direction.y = -1;//1000 * time.GetDeltaTime();
        if (input.GetKeyDown(SDL_SCANCODE_A)) direction.x = -1;//100 * time.GetDeltaTime();
        if (input.GetKeyDown(SDL_SCANCODE_S)) direction.y = 1;//100 * time.GetDeltaTime();
        if (input.GetKeyDown(SDL_SCANCODE_D)) direction.x = 1;//100 * time.GetDeltaTime();
        

        if (direction.LengthSqr() > 0) {
            direction = direction.Normalized();
            for (Actor& actor : actors) {
                actor.GetTransform().position += (direction * 200) * time.GetDeltaTime();
            }
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

