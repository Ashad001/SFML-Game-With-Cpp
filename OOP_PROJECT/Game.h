#pragma once

#include "GameState.h"   // Gamestate include state files.. states include all the header files

using namespace std;
class Game
{
private:
	// Attributes
	sf::RenderWindow* Window;
	sf::Event EVNT;
	sf::Clock DTClock;
	float DeltaTime;
	  
	stack<State*> states;          // We will simply push and pop states from the top // The current state should be the prior focus
		
	// Private Setters
	void SetWindow();
	void SetStates();             // Main should not have access of it...!
public:
	// Constructors / Destructors
	Game();
	virtual ~Game();

	// Public Functions / Setters
	void EndGame();          // But it has a better ending!!
	void UpdateEvents();
	void UpdateDT();
	void Update();
	void Render();
	void Run();

};