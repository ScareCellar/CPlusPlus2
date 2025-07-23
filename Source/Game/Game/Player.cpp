#include "Player.h"
#include "Source/Engine.h"
#include "Input/InputSystem.h"
#include "Renderer/Renderer.h"


using namespace blood;

void Player::Update(float dt) {
    
    float speed = 200;
    float rotationRate = 100;
    float rotate = 0;
  
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_A)) rotate = -1;//100 * time.GetDeltaTime();
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_D)) rotate = +1;//100 * time.GetDeltaTime();

    m_transform.rotation += (rotate * rotationRate) * dt;

    //thrust
    float thrust = 0;
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_W)) thrust = -1;
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_S)) thrust = +1;

    vec2 direction{ 0,1 };
    vec2 force = direction.Rotate(math::degToRad(m_transform.rotation)) * thrust * speed;
    velocity += force * dt;

    Actor::Update(dt);
}
void Player::Draw(Renderer& renderer) {
    Actor::Draw(renderer);
}