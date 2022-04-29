#pragma once
#include "State.h"
class GameState : public State
{
private:
	
	// Workspace for player, enemies and all for a game!

public:
	GameState(sf::RenderWindow* Window);
	virtual ~GameState();

	void EndState();
	void UpdateKeyBinds(const float& DT);
	void Update(const float& DT);
	void Render(sf::RenderTarget* Target = nullptr);

};

