#pragma once

#include "../Engine/Framework/Actor.h"


class Rocket : public blood::Actor {
public:
	Rocket(blood::Transform& transform, std::shared_ptr<blood::Model> model) : Actor{transform, model} {};

	void Update(float dt);
	float speed;
private:
};