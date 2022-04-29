#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class State
{
private:
	sf::RenderWindow* Window;
	vector<sf::Texture> textures;
	bool Quit;

public:
	State(sf::RenderWindow* Window);
	virtual ~State();

	const bool& GetQuit() const;
	virtual void CheckQuit();

	virtual void EndState() = 0;
	virtual void UpdateKeyBinds(const float &DT) = 0;
	virtual void Update(const float &DT) = 0;
	virtual void Render(sf::RenderTarget* Target = nullptr) = 0;   // This will work as k jo hm kaam kr rhy hn wo ksi specific target p krn (Parameterized) nahi to window p krn (Default)...
};

