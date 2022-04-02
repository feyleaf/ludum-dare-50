#include "globals.h"
/*
Ludum Dare 50
Benjamin C. Watt (feyleaf.com)
Theme: Delay the Inevitable
Working Title: "Deny the Illegible"

Side scrolling running courier.
Screen will only hold 1-2 buildings at a time.
Camera follows the player (Wally) along a margin push
  (when touching a certain margin [golden ratio?] the camera starts to move in that direction.
  Otherwise stays in place.)
Cash is rewarded on successful delivery.
Delivery customers will give strikes for unsuccessful delivery.
The core mechanic will start to ramp up to "inevitable" by having more and more obfuscated/garbled instructions over time.
The "moment" is where a dog appears, chews the delivery slip and makes it only partially readable.
From there, slips will become wet, smudged, misspelled, or faded.
Toward the "inevitable" end, the instructions will be downright disgusting.
*/

//struct for the vector list of house positions and styles
struct house
{
	float xp;
	sf::Sprite sp;
	house(float x, const sf::Sprite& s) { xp = x; sp = s; }
};

//main routine
int main()
{
	gameClass theGame;
	unsigned int width = 1280;
	float worldWidth = 1280.0f;
	float villageLength = 16384.0f;
	float startx = villageLength / 2.0f;
	float phi = 1.618f;
	float boundr = (worldWidth/2.0f) / phi;
	//float boundl = worldWidth - boundr;
	sf::RenderWindow window(sf::VideoMode(width, 9*width/16), "Deny the Illegible");
	window.setFramerateLimit(30);
	sf::View theView;
	theView = window.getDefaultView();
	sf::Texture wallyTex;
	sf::Texture houseTex1;
	sf::Texture houseTex2;
	sf::Sprite wally;
	sf::Sprite house1;
	sf::Sprite house2;
	float velocity = 0.0f;
	wallyTex.loadFromFile("wally-still.png");
	houseTex1.loadFromFile("house1-proto.png");
	houseTex2.loadFromFile("house2-proto.png");
	wally.setTexture(wallyTex);
	wally.setOrigin(128.0f, 128.0f);
	//wally.setScale(0.5f, 0.5f);
	wally.setPosition(startx, 495.0f);
	theView.setCenter(wally.getPosition().x, theView.getCenter().y);
	house1.setTexture(houseTex1);
	house1.setOrigin(256.0f, 256.0f);
	house1.setPosition(0.0f, 280.0f);
	house2.setTexture(houseTex2);
	house2.setOrigin(256.0f, 256.0f);
	house2.setPosition(villageLength/2.0f, 280.0f);

	std::vector<house> positions;
	positions.push_back(house(75.0, house1));
	positions.push_back(house(375.0, house1));
	positions.push_back(house(475.0, house2));
	positions.push_back(house(775.0, house1));
	positions.push_back(house(2075.0, house2));
	positions.push_back(house(2275.0, house2));
	positions.push_back(house(3375.0, house1));
	positions.push_back(house(4475.0, house2));
	positions.push_back(house(5575.0, house1));
	positions.push_back(house(6675.0, house1));
	positions.push_back(house(7775.0, house2));
	positions.push_back(house(8875.0, house1));
	positions.push_back(house(9975.0, house2));
	positions.push_back(house(11075.0, house2));
	positions.push_back(house(12275.0, house2));
	positions.push_back(house(13375.0, house1));
	positions.push_back(house(14475.0, house2));
	positions.push_back(house(15575.0, house1));



	sf::RectangleShape ground(sf::Vector2f(villageLength, 300.0f));
	ground.setPosition(0.0f, 420.0f);
	ground.setFillColor(sf::Color::Yellow);

	theGame.initSlip();



	while (window.isOpen())
	{
		sf::Event event;
		sf::Keyboard input;

		//get input
		if (input.isKeyPressed(sf::Keyboard::Key::Right))
		{
			if (velocity < 0.0f) velocity = 0.0f;
			wally.setScale(-1.0f, 1.0f);
			if (velocity < 17.0f) velocity += 0.65f;
		}
		else if (input.isKeyPressed(sf::Keyboard::Key::Left))
		{
			if (velocity > 0.0f) velocity = 0.0f;
			wally.setScale(1.0f, 1.0f);
			if (velocity > -17.0f) velocity += -0.65f;
		}
		else
		{
			velocity = 0.0f;
		}

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
				if (event.key.code == sf::Keyboard::H)
					theGame.toggleDogChew();
		}


		//run updates
		wally.setTextureRect(sf::IntRect(0, 0, 256, 256));
		if (sin(theGame.getGameTime()*3.0f) > 0)
			wally.setTextureRect(sf::IntRect(256, 0, 256, 256));
		float walx = wally.getPosition().x;
		float xpos = (wally.getPosition().x - theView.getCenter().x) + velocity;
		if ((xpos > boundr || xpos < -boundr))// && xpos<villageLength && xpos>0)
			theView.move(velocity, 0.0f);
		if (walx + velocity < villageLength && walx + velocity>0)
		{
			wally.move(velocity, 0.0f);
		}

		theGame.updateSlip();
		theGame.updateHUD();

		//draw to screen
		window.clear();
		theGame.renderHUD();
		theGame.renderSlip();
		window.draw(ground);
		for(unsigned int i=0; i<positions.size(); i++)
		{
			house tm = house(positions[i]);
			tm.sp.setPosition(tm.xp, 280.0f);
			window.draw(tm.sp);
		}
		window.draw(wally);
		theGame.drawHUD(window);
		theGame.drawPackageSlip(window);
		window.setView(theView);
		window.display();
	}

	return 0;
}