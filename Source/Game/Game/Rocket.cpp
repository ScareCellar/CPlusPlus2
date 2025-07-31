#include "Rocket.h"
#include "Core/Math/MathUtils.h"




void Rocket::Update(float dt) {
	blood::vec2 force = blood::vec2{ 1,0 }.Rotate(blood::math::degToRad(m_transform.rotation)) * speed;
	velocity = force;
	
	lifespan -= dt;
	//if (lifespan <= 0) destroyed = true;

	Actor::Update(dt);
}

void Rocket::OnCollision(Actor* other){
	if (tag != other->tag) {
		destroyed = true;
	}
}
