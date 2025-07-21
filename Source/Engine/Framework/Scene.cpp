#include "Scene.h"
#include "../Renderer/Renderer.h"
#include "Actor.h"


namespace blood {

	void Scene::Update(float dt) {

	}
	void Scene::Draw(Renderer& renderer) {
		for (auto& actor : m_actors) {
			actor->Draw(renderer);
		}
	}
	void Scene::AddActor(std::unique_ptr<Actor> actor){
		m_actors.push_back(std::move(actor));
	}
}