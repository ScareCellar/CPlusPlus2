#include "SpaceGame.h"
#include "Core/Math/Vector2.h"
#include "Renderer/Model.h"
#include "Renderer/Renderer.h"
#include "Player.h"
#include "Engine.h"
#include "Core/Random.h"
#include "Input/InputSystem.h"
#include "../Game/Game/GameData.h"
#include "../Game/Enemy.h"

#include <vector>

bool SpaceGame::Initialize()
{
    m_scene = std::make_unique<Scene>();

    //make enemies
    return true;
}

void SpaceGame::Update(float dt) {
    //m_scene->Update(dt);
    switch (m_gamestate)
    {
    case SpaceGame::GameState::Initialize:
        m_gamestate = GameState::StartGame;
        break;
    case SpaceGame::GameState::Title:
        if (blood::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_SPACE)) m_gamestate = GameState::StartGame;
        break;
    case SpaceGame::GameState::StartGame:
        m_score = 0;
        m_lives = 3;
        m_gamestate = GameState::StartRound;
        break;
    case SpaceGame::GameState::StartRound:
    {
        // create player
        std::shared_ptr<blood::Model> model = std::make_shared<blood::Model>(GameData::drillPoints, blood::vec3{ 1.0f, 1.0f, 0.0f });
        blood::Transform transform{ blood::vec2{ blood::GetEngine().GetRenderer().GetWidth() * 0.5f, blood::GetEngine().GetRenderer().GetHeight() * 0.5f }, 0, 20 };
        auto player = std::make_unique<Player>(transform, model);
        player->speed = 1000.0f;
        player->rotationRate = 30.0f;
        player->damping = 10.0f;
        player->name = "player";
        player->tag = "player";

        m_scene->AddActor(std::move(player));
        m_gamestate = GameState::Game;
    }
    break;
    case SpaceGame::GameState::Game:
        m_enemySpawnTimer -= dt;
        if (m_enemySpawnTimer <= 0) {
            m_enemySpawnTimer = 4;

            // create enemies
            std::shared_ptr<Model> enemyModel = std::make_shared<blood::Model>(GameData::drillPoints, vec3{ random::getReal(), random::getReal(), random::getReal() });
            Transform transform{ vec2{ random::getReal() * GetEngine().GetRenderer().GetWidth(), random::getReal() * GetEngine().GetRenderer().GetHeight() }, 0, 10 };
            std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(transform, enemyModel);
            enemy->damping = 0.2f;
            enemy->speed = (random::getReal() * 800) + 500;
            enemy->tag = "enemy";
            m_scene->AddActor(std::move(enemy));
        }
        break;
    case SpaceGame::GameState::PlayerDead:
        break;
    case SpaceGame::GameState::GameOver:
        break;
    
        
    }
    m_scene->Update(dt);
}

void SpaceGame::Draw() {
    m_scene->Draw(GetRenderer());
}

void SpaceGame::Shutdown() {

}


