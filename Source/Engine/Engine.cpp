#include "../Engine/Source/Engine.h"
#include "Renderer/Renderer.h"
#include "Input/InputSystem.h"
#include "Core/Audio/AudioSystem.h"

namespace blood {

	Engine& GetEngine() {
		static Engine engine;
		return engine;
	}

	bool Engine::Initialize() {
		m_renderer = std::make_unique<blood::Renderer>();
		m_renderer->Initialize();
		m_renderer->CreateWindow("Game", 1980, 1224);

		m_input = std::make_unique<blood::InputSystem>();
		m_input->Initialize();

		m_audio = std::make_unique<blood::AudioSystem>();
		m_audio->Initialize();
		return true;
	}
	void Engine::Shutdown() {
		m_audio->Shutdown();
		m_input->ShutDown();//fix this when I figure out where my audio system is.
		m_renderer->Shutdown();
	}
	void Engine::Update() {
		m_input->Update();
		m_audio->Update();
		time.Tick();
	}



}