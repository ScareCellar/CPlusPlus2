#pragma once
#include <vector>
#include <list>
#include <memory>
#include "../Framework/Actor.h"
#include "../Core/StringHelper.h"

namespace blood{
	class Scene {
	public:
		Scene() = default;

		void Update(float dt);
		void Draw(class Renderer& renderer);

		void AddActor(std::unique_ptr<Actor> actor);
		
		template<typename T = Actor>
		T* GetActorByName(const std::string& name) {
			T* result;
			for (auto& actor : m_actors) {
				if (toLower(actor->name) == toLower(name)) {
					result = dynamic_cast<T*>(actor.get());
					return result;
				}
			}
			return nullptr;
		}

		template<typename T = Actor>
		std::vector<T> GetActorsByTag(const std::string& tag){
			std::vector<T> results;
			for (auto& actor : m_actors) {
				if (toLower(actor->tag) == toLower(tag)) {
					T* object = dynamic_cast<T*>(actor.get());
					if (object) {
						results.push_back(object);
					}
				}
			}
			return results;
		}
	private:
		std::list<std::unique_ptr<Actor>> m_actors;

	};
}