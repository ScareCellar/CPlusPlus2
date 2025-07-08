
/*
#include <iostream>
#include "../Engine/Core/Math/Math.h"
#include "../Engine/Core/Random.h"

//#define NAME "Cameron\n"

using namespace blood;
/*
int main()

{
	std::cout << NAME;
	std::cout << "Hello,World!\n";
	std::cout << math::pi << std::endl;
	//const float deg = blood::radToDeg(blood::pi);
	math::min(5, 3);
	math::clamp(2, 3, 4);

	for (int i = 0; i < 10; i++) {
		std::cout << random::getRandomFloat() << std::endl;
	}
} */

#include <SDL3/SDL.h>
#include <iostream>
#include <vector>
#include "../Engine/Core/Random.h"
#include "../Engine/Core/Math/Math.h"
#include "../Engine/Core/Math/Vector2.h"
#include "../Engine/Renderer/Renderer.h"

using namespace blood;

int main(int argc, char* argv[]) {
	blood::Renderer renderer;
    renderer.Init();
	// Initialize SDL  

    renderer.CreateWindow("testing", 1280, 1024);

    //SDL_Event e;

    bool quit = false;

    
    SDL_Event e;

    std::vector<vec2> stars;
    for (int i = 0; i < 100; i++) {
        stars.push_back(vec2(random::getRandomFloat() * 1280, random::getRandomFloat() * 1024));
    }

    // Define a rectangle
    SDL_FRect greenSquare{ 270, 190, 200, 200 };

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        } 

        renderer.SetColor(0, 0, 0, 255); // Set render draw color to black
		renderer.Clear(); // Clear the screen

        


		
        for (vec2 star : stars) {
            renderer.SetColor(random::getRandomInt(256), random::getRandomInt(256), random::getRandomInt(256), 255); // Set render draw color to random color
            renderer.DrawPoint(random::getRandomInt(1280) + random::getRandomFloat(), random::getRandomInt(1024) + random::getRandomFloat());
        }

        renderer.DrawLine(random::getRandomInt(1280) + random::getRandomFloat(), random::getRandomInt(1024) + random::getRandomFloat(), random::getRandomInt(1280) + random::getRandomFloat(), random::getRandomInt(1024) + random::getRandomFloat()); // Render a random line

        renderer.Present(); // Render the screen
    }

    renderer.ShutDown();

    return 0;
}

