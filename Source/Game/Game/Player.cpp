#include "Player.h"
#include "Source/Engine.h"
#include "Input/InputSystem.h"
#include "Renderer/Renderer.h"


using namespace blood;

void Player::Update(float dt) {
    blood::vec2 direction{ 0,0 };
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_W)) direction.y = -1;//1000 * time.GetDeltaTime();
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_A)) direction.x = -1;//100 * time.GetDeltaTime();
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_S)) direction.y = 1;//100 * time.GetDeltaTime();
    if (GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_D)) direction.x = 1;//100 * time.GetDeltaTime();


    if (direction.LengthSqr() > 0) {
        direction = direction.Normalized();
        m_transform.position += (direction * 200) * dt;
    }
}
void Player::Draw(Renderer& renderer) {

}