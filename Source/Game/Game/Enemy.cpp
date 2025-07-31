#include "Enemy.h"
#include "Renderer/Renderer.h"
#include "Core/Math/Vector2.h"
#include "Core/Audio/AudioSystem.h"
#include "Framework/Scene.h"
#include "Player.h"
#include "SpaceGame.h"
#include "GameData.h"
#include "Rocket.h"
#include "Renderer/ParticleSystem.h"
#include "../Engine/Engine.h"

void Enemy::Update(float dt) {
    bool playerSeen = false;

    Actor* player = scene->GetActorByName<Actor>("player");
    vec2 direction{ 1,1 };
    direction = player->m_transform.position - m_transform.position;

    direction.Normalized();
    blood::vec2 forward = blood::vec2{ 1,0 }.Rotate(blood::math::radToDeg(m_transform.rotation));
    float angle = blood::vec2::SignedAngleBetween(forward, direction);
    angle = blood::math::sign(angle);

    m_transform.rotation += blood::math::radToDeg(angle * 5 * dt);

    //angle = blood::math::radToDeg(blood::vec2::AngleBetween(forward, direction));
    if (angle < 30) {
        playerSeen = true;
    }
    



    vec2 force = direction * speed;
    velocity = force * dt;
    
    m_transform.position.x = math::wrap(m_transform.position.x, 0.0f, 1980.0f);
    m_transform.position.y = math::wrap(m_transform.position.y, 0.0f, 1224.0f);

    shootTimer -= dt;

    if (shootTimer <= 0) {
        std::shared_ptr<blood::Model> model = std::make_shared<blood::Model>(GameData::drillPoints, blood::vec3{ 1.0f, 1.0f, 0.0f });
        blood::Transform transform{ this->m_transform.position, this->m_transform.rotation, 10 };
        auto rocket = std::make_unique<Rocket>(transform, model);
        rocket->speed = 500.0f;
        rocket->lifespan = 5.0f;
        rocket->name = "rocket";
        rocket->tag = "enemy";
        shootTimer = 2.0f;
        scene->AddActor(std::move(rocket));
    }

    Actor::Update(dt);
}

void Enemy::OnCollision(Actor* other){
    if (other->tag == "player") {
        destroyed = true;
        scene->GetGame()->AddPoints(100);
        blood::GetEngine().GetAudio().PlaySound("bass");
        for (int i = 0; i < 100; i++) {
         /*   blood::Particle particle;
            particle.position = transform.position;
            particle.velocity = blood::vec2{ viper::random::getReal(-200.0f, 200.0f), viper::random::getReal(-200.0f, 200.0f) };
            particle.color = blood::vec3{ 1, 1, 1 };
            particle.lifespan = 2;

            blood::GetEngine().GetPS().AddParticle(particle);*/
        }
    }
}

void Enemy::Draw(Renderer& renderer) {
    Actor::Draw(renderer);
}

