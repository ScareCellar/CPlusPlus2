#pragma once
#include <vector>
#include <memory>
#include "../Framework/Actor.h"

namespace blood{
	class Scene {
	public:
		Scene() = default;

		void Update(float dt);
		void Draw(class Renderer& renderer);

		void AddActor(std::unique_ptr<Actor> actor);

	private:
		std::vector<std::unique_ptr<Actor>> m_actors;
	};
}