#include "SpaceGame.h"
#include "Core/Math/Vector2.h"
#include "Renderer/Model.h"
#include "Player.h"


#include <vector>

bool SpaceGame::Initialize()
{
    std::vector<blood::vec2> points{
        { 0.25f, 0},
        { 0.1767766f, 0.1767766f},
        { 0, 0.25f},
        { -0.1767766f, 0.1767766f},
        { -0.25f, 0},
        { -1, 0},
        { -1, 1.75f},
        { -1.5, 1.75f},
        { -1.5, -0.75f},
        { -1, -0.75f},
        { -1, 0},
        { -1, -1},
        { 0, -2.5f},
        { 1, -1},
        { 1, -0.75f},
        { 1.5, -0.75f},
        { 1.5, 1.75f},
        { 1, 1.75f},
        { 1, 2},
        { -1, 2},
        { -1, -1},
        { 1, -1},
        { 1, 2},
        { 1, 0},
        { 0.25f, 0},
        { 0.1767766f, -0.1767766f},
        { 0, -0.25f},
        { -0.1767766f, -0.1767766f},
        { -0.25f, 0},
    };

    std::shared_ptr<blood::Model> model = std::make_shared<blood::Model>(points, blood::vec3{ 1,1,0 });

    


    //std::vector<std::unique_ptr<blood::Actor>> actors;
    for (int i = 0; i < 1; i++) {
        blood::Transform transform = blood::Transform({ 890 ,612 }, 0, 50);
        std::unique_ptr<Player> player = std::make_unique<Player>(transform, model);
        m_scene->AddActor(std::move(player));
    }
    return false;
}

void SpaceGame::Update() {

}

void SpaceGame::Draw() {

}

void SpaceGame::Shutdown() {

}


