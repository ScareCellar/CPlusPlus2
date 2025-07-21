#pragma once
#include"../../Engine/Framework/Game.h"

class SpaceGame : public blood::Game {
public:
	SpaceGame() = default;

	bool Initialize() override;

	void Update() override;
	void Draw() override;

	void Shutdown() override;

	
private:



};
