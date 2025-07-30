#include "Enemy.h"
#include "Renderer/Renderer.h"
#include "Framework/Scene.h"
#include "Player.h"

void Enemy::Update(float dt) {
    Actor* player = scene->GetActorByName<Actor>("player");



    float speed = 200;
    float thrust = 1;


    vec2 direction{ 0,1 };
    vec2 force = direction.Rotate(math::degToRad(m_transform.rotation)) * thrust * speed;
    velocity += force * dt;
    //getWidth and GetHeight methods.
    m_transform.position.x = math::wrap(m_transform.position.x, 0.0f, 1224.0f);
    m_transform.position.y = math::wrap(m_transform.position.y, 0.0f, 1980.0f);

    Actor::Update(dt);
}

void Enemy::OnCollision(Actor* other){

}

void Enemy::Draw(Renderer& renderer) {

}

