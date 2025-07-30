#pragma once
#include "../Core/Math/Transform.h"
#include "../Renderer/Model.h"
//#include "../Framework/Scene.h"
#include <memory>
#include <string>


namespace blood {
	class Actor {
	public:
		std::string name;
		std::string tag;

		vec2 velocity{ 0, 0 };
		float damping{ 10.0f };

		class Scene* scene{ nullptr };
	public:
		Actor() = default;
		Actor(const Transform& transform, std::shared_ptr<Model> model) : m_transform{ transform }, m_model{ model } {}

		virtual void Update(float dt);
		virtual void Draw(class Renderer& renderer);

		Transform& GetTransform() { return m_transform; }

	public:
		Transform m_transform;
		std::shared_ptr<Model> m_model;

		bool destroyed = false;

	};
}