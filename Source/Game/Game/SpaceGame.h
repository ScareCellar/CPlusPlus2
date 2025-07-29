#pragma once
#include"../../Engine/Framework/Game.h"

class SpaceGame : public blood::Game {
public:

	enum class GameState {
		Initialize,
		Title,
		StartGame,
		StartRound,
		Game,
		PlayerDead,
		GameOver
	};

public:
	SpaceGame() = default;

	bool Initialize() override;

	void Update(float dt) override;
	void Draw() override;

	void Shutdown() override;

	
private:
	GameState m_gamestate = GameState::Initialize;

	float m_enemySpawnTimer{ 0 };
};
