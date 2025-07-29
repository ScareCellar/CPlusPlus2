#pragma once
#include "Core/Time.h"
#include <memory>

namespace blood {
	class Renderer;
	class InputSystem;
	class AudioSystem;
	class Engine {
	public:
		Engine() = default;

		bool Initialize();
		void Update();
		void Shutdown();

		void Draw();

		Renderer& GetRenderer() { return *m_renderer; }
		AudioSystem& GetAudio() { return *m_audio; }
		InputSystem& GetInput() { return *m_input; }
		Time GetTime() { return time; }


	private:
		Time time;
		std::unique_ptr<Renderer> m_renderer;
		std::unique_ptr<InputSystem> m_input;
		std::unique_ptr<AudioSystem> m_audio;
	};

	Engine& GetEngine();
	inline Renderer& GetRenderer() { return GetEngine().GetRenderer(); }
}
