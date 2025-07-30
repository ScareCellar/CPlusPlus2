#include "Scene.h"
#include "../Renderer/Renderer.h"
#include "../Core/StringHelper.h"


namespace blood {

	void Scene::Update(float dt) {
		for (auto& actor : m_actors) {
			if (actor->destroyed) actor->~Actor();
			actor->Update(dt);
		}
	}

	void Scene::Draw(Renderer& renderer) {
		for (auto& actor : m_actors) {
			actor->Draw(renderer);
		}
	}
	void Scene::AddActor(std::unique_ptr<Actor> actor){
		actor->scene = this;
		m_actors.push_back(std::move(actor));
	}
	
	
}