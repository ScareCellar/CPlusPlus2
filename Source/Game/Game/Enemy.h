#pragma once
#include "../../Engine/Framework/Actor.h"
#include "../../Engine/Core/Math/Transform.h"

using namespace blood;

class Enemy : public Actor {
public:
	Enemy() = default;
	Enemy(const Transform& transform, std::shared_ptr<Model> model) :
		Actor{ transform, model } {
	};

	void Update(float dt) override;
	void Draw(Renderer& renderer) override;

	float speed;
	float rotationRate;
private:

};