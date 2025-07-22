#pragma once
#include "Framework/Actor.h"
//#include "Core/Math/Transform.h"

using namespace blood;

class Player : public Actor {
public:
	Player() = default;
	Player(const Transform& transform, std::shared_ptr<Model> model) :
		Actor{ transform, model } {};

	void Update(float dt) override;
	void Draw(Renderer& renderer) override;
private:

};