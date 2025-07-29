#include "Player.h"
#include "Engine.h"
#include "Input/InputSystem.h"
#include "Renderer/Renderer.h"
#include "../Game/GameData.h"
#include "Framework/Actor.h"
#include "../Engine/Renderer/Model.h"
#include "Framework/Scene.h"
#include "../Game/Game/Rocket.h"


using namespace blood;

void Player::Update(float dt) {
    //1980, 1224
    
    float rotate = 0;
  
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_A)) rotate = -1;//100 * time.GetDeltaTime();
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_D)) rotate = +1;//100 * time.GetDeltaTime();

    m_transform.rotation += (rotate * rotationRate) * dt;

    //thrust
    float thrust = 0;
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_W)) thrust = +1;
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_S)) thrust = -1;

    vec2 direction{ 1,0 };
    vec2 force = direction.Rotate(math::degToRad(m_transform.rotation)) * thrust * speed;
    velocity += force * dt;

    m_transform.position.x = math::wrap(m_transform.position.x, 0.0f, 1980.0f);
    m_transform.position.y = math::wrap(m_transform.position.y, 0.0f, 1224.0f);
    
    if (blood::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_SPACE)) {
        std::shared_ptr<blood::Model> model = std::make_shared<blood::Model>(GameData::drillPoints, blood::vec3{ 1.0f, 1.0f, 0.0f });
        blood::Transform transform{ this->m_transform.position, this->m_transform.rotation, 10 };
        auto rocket = std::make_unique<Rocket>(transform, model);
        rocket->speed = 1000.0f;
        //player->rotationRate = 30.0f;
        rocket->damping = 10.0f;
        rocket->name = "rocket";
        rocket->tag = "player";

        scene->AddActor(std::move(rocket));
    }

    Actor::Update(dt);
}
void Player::Draw(Renderer& renderer) {
    Actor::Draw(renderer);
}