#pragma once

#include "../Engine/Framework/Actor.h"


class Rocket : public blood::Actor {
public:
	Rocket(blood::Transform& transform, std::shared_ptr<blood::Model> model) : Actor{transform, model} {};

	void Update(float dt);
	float speed{ 1000.0f };
	
	// Inherited via Actor
	void OnCollision(Actor* other) override;

private:
};