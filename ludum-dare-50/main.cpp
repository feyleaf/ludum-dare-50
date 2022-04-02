#include "globals.h"
/*
Ludum Dare 50
Benjamin C. Watt (feyleaf.com)
Theme: Delay the Inevitable
Working Title: "Deny the Illegible"
*/
int main()
{
	unsigned int width = 1028;
	sf::RenderWindow window(sf::VideoMode(width, 9*width/16), "Deny the Illegible");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Cyan);

	while (window.isOpen())
	{
		sf::Event event;

		window.clear();
		window.draw(shape);
		window.display();

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			window.draw(shape);
			window.display();
		}
	}

	return 0;
}