#pragma once
#include <SDL3/SDL.h>
#include <iostream>	

namespace blood
{
	class Renderer {
	public:
		Renderer() = default;

		bool Initialize();

		bool CreateWindow(const std::string name, int width, int height);

		void SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
		void Present();
		void Clear();
		void ShutDown();

		void SetColorFloat(float r, float g, float b, float a = 1.0f);

		void DrawLine(float x1, float y1, float x2, float y2);
		void DrawPoint(float x, float y);


	private:
		SDL_Window* m_window = nullptr;
		SDL_Renderer* m_renderer = nullptr;

	};
}