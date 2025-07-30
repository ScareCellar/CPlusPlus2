#include "Rocket.h"
#include "Core/Math/MathUtils.h"




void Rocket::Update(float dt) {
	blood::vec2 force = blood::vec2{ 1,0 }.Rotate(blood::math::degToRad(m_transform.rotation)) * speed;
	velocity = force;
	
	m_transform.position.x = blood::math::wrap(m_transform.position.x, 0.0f, 1980.0f);
	m_transform.position.y = blood::math::wrap(m_transform.position.y, 0.0f, 1224.0f);

	lifespan -= dt;
	//if (lifespan <= 0) destroyed = true;

	Actor::Update(dt);
}

void Rocket::OnCollision(Actor* other)
{
}
