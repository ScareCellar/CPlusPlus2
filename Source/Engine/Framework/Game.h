#pragma once
#include <memory>
#include "Scene.h"

namespace blood {
	class Game {
	public:
		Game() = default;

		virtual bool Initialize() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;
		virtual void Shutdown() = 0;
		virtual std::unique_ptr<class Scene> GetScene() {
			return std::move(m_scene);
		};

	protected:
		std::unique_ptr<class Scene> m_scene;
	};
}