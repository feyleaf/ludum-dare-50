#include "globals.h"
/*
Ludum Dare 50
Benjamin C. Watt (feyleaf.com)
Theme: Delay the Inevitable
Working Title: "Deny the Illegible"
*/
int main()
{
	unsigned int width = 1280;
	sf::RenderWindow window(sf::VideoMode(width, 9*width/16), "Deny the Illegible", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(120);
	sf::Texture wallyTex;
	sf::Sprite wally;
	float velocity = 0.0f;
	wallyTex.loadFromFile("wally-proto.png");
	wally.setTexture(wallyTex);
	wally.setOrigin(128.0f, 128.0f);
	wally.setScale(0.5f, 0.5f);
	wally.setPosition(600.0f, 475.0f);

	sf::RectangleShape ground(sf::Vector2f(1280.0f, 200.0f));
	ground.setPosition(0.0f, 520.0f);
	ground.setFillColor(sf::Color::Yellow);
	while (window.isOpen())
	{
		sf::Event event;
		sf::Keyboard input;

		window.clear();
		window.draw(ground);
		window.draw(wally);
		window.display();
		if (input.isKeyPressed(sf::Keyboard::Key::Right))
		{
			if (velocity < 0.0f) velocity = 0.0f;
			wally.setScale(-0.5f, 0.5f);
			if (velocity<11.0f) velocity += 0.65f;
		}
		else if (input.isKeyPressed(sf::Keyboard::Key::Left))
		{
			if (velocity > 0.0f) velocity = 0.0f;
			wally.setScale(0.5f, 0.5f);
			if (velocity>-11.0f) velocity += -0.65f;
		}
		else
		{
			velocity = 0.0f;
		}

		while (window.pollEvent(event))
		{
			window.clear();
			if (event.type == sf::Event::Closed)
				window.close();
			if (wally.getPosition().x+velocity < 1280 && wally.getPosition().x+velocity>0)
			{
				wally.move(velocity, 0.0f);
			}
			window.draw(ground);
			window.draw(wally);
			window.display();
		}
	}

	return 0;
}