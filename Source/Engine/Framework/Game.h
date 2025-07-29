#pragma once
#include <memory>
#include "Scene.h"
#include "../Core/Time.h"

namespace blood {
	class Game {
	public:
		Game() = default;

		virtual bool Initialize() = 0;
		virtual void Update(float dt) = 0;
		virtual void Draw() = 0;
		virtual void Shutdown() = 0;
		virtual std::unique_ptr<class Scene> GetScene() {
			return std::move(m_scene);
		};

	protected:
		int m_score = 0;
		int m_lives = 0;
		std::unique_ptr<class Scene> m_scene;
	};
}