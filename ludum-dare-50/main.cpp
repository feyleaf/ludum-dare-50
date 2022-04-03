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
	sf::Texture dogTex;
	sf::Texture postBoxTex;
	sf::Texture parcelTex;
	sf::Texture houseTex1;
	sf::Texture houseTex2;
	sf::Texture houseTex3;
	sf::Texture houseTex4;
	sf::Texture houseTex5;
	sf::Texture houseTex6;
	sf::Texture houseTex7;
	sf::Texture houseTex8;
	sf::Texture houseTex9;
	sf::Texture houseTex10;
	sf::Texture houseTex11;
	sf::Texture houseTex12;
	sf::Sprite wally;
	sf::Sprite dog;
	sf::Sprite postBox;
	sf::Sprite parcel;
	sf::Sprite house1;
	sf::Sprite house2;
	sf::Sprite house3;
	sf::Sprite tower;
	sf::Sprite house5;
	sf::Sprite house6;
	sf::Sprite house7;
	sf::Sprite house8;
	sf::Sprite school;
	sf::Sprite house10;
	sf::Sprite house11;
	sf::Sprite house12;
	float velocity = 0.0f;
	parcelTex.loadFromFile("parcel.png");
	dogTex.loadFromFile("dog.png");
	wallyTex.loadFromFile("wally-still.png");
	postBoxTex.loadFromFile("postbox.png");
	houseTex1.loadFromFile("house1-proto.png");
	houseTex2.loadFromFile("house2-proto.png");
	houseTex3.loadFromFile("house3-proto.png");
	houseTex4.loadFromFile("house4-tower-proto.png");
	houseTex5.loadFromFile("house5-proto.png");
	houseTex6.loadFromFile("house6-proto.png");
	houseTex7.loadFromFile("house7-proto.png");
	houseTex8.loadFromFile("house8-proto.png");
	houseTex9.loadFromFile("house9-school-proto.png");
	houseTex10.loadFromFile("house10-proto.png");
	houseTex11.loadFromFile("house11-proto.png");
	houseTex12.loadFromFile("house12-proto.png");
	wally.setTexture(wallyTex);
	wally.setOrigin(128.0f, 128.0f);
	//wally.setScale(0.5f, 0.5f);
	wally.setPosition(startx, 495.0f);
	dog.setTexture(dogTex);
	dog.setPosition(0, 0);
	dog.setOrigin(128.0f, 128.0f);
	parcel.setTexture(parcelTex);
	parcel.setPosition(startx + 100.0f, 535.0f);
	parcel.setScale(1.0f, 1.0f);
	postBox.setTexture(postBoxTex);
	postBox.setScale(2.0f, 2.0f);
	theView.setCenter(wally.getPosition().x, theView.getCenter().y);
	house1.setTexture(houseTex1);
	house1.setOrigin(256.0f, 256.0f);
	house3.setTexture(houseTex3);
	house3.setOrigin(256.0f, 256.0f);
	tower.setTexture(houseTex4);
	tower.setOrigin(256.0f, 256.0f);
	house2.setTexture(houseTex2);
	house2.setOrigin(256.0f, 256.0f);
	house5.setTexture(houseTex5);
	house5.setOrigin(256.0f, 256.0f);
	house6.setTexture(houseTex6);
	house6.setOrigin(256.0f, 256.0f);
	house7.setTexture(houseTex7);
	house7.setOrigin(256.0f, 256.0f);
	house8.setTexture(houseTex8);
	house8.setOrigin(256.0f, 256.0f);
	school.setTexture(houseTex9);
	school.setOrigin(256.0f, 256.0f);
	house10.setTexture(houseTex10);
	house10.setOrigin(256.0f, 256.0f);
	house11.setTexture(houseTex11);
	house11.setOrigin(256.0f, 256.0f);
	house12.setTexture(houseTex12);
	house12.setOrigin(256.0f, 256.0f);

	std::vector<house> positions;
	positions.push_back(house(256.0, house7));
	positions.push_back(house(935.0, house3));
	positions.push_back(house(1395.0, house2));
	positions.push_back(house(2075.0, school));
	positions.push_back(house(2675.0, house12));
	positions.push_back(house(3975.0, house11));
	positions.push_back(house(4975.0, house3));
	positions.push_back(house(5775.0, house6));
	positions.push_back(house(6675.0, house1));
	positions.push_back(house(7725.0, house10));
	positions.push_back(house(8875.0, tower));
	positions.push_back(house(9995.0, house2));
	positions.push_back(house(11075.0, house5));
	positions.push_back(house(12005.0, house12));
	positions.push_back(house(12975.0, house8));
	positions.push_back(house(13375.0, house6));
	positions.push_back(house(14475.0, tower));
	positions.push_back(house(15575.0, house3));

	//for the floating parcel functionality
	unsigned int index = 0;
	unsigned int climbs = 0;
	float minDist = 9000.0f;


	sf::RectangleShape ground(sf::Vector2f(villageLength+worldWidth, 300.0f));
	ground.setPosition(-worldWidth/2.0f, 420.0f);
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
			{
				if (event.key.code == sf::Keyboard::H)
					theGame.toggleDogChew();
				if (event.key.code == sf::Keyboard::Space)
				{
					if (calcDist(wally.getPosition(), parcel.getPosition()) < 80.0f)
					{
						if (theGame.isSeeking())
						{
							theGame.setCarrying();
							theGame.generateDetails();
							float dogx = float(rand() % int(villageLength));
							dog.setPosition(dogx, 500.0f);
						}
						else if (theGame.isCarrying())
						{
							theGame.setDropping();
							theGame.setFloatingParcelFlag(false);
						}
					}
				}
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
			}

		}


		//run updates
		if (velocity == 0.0f)
		{
			wally.setTextureRect(sf::IntRect(0, 0, 256, 256));
			if (sin(theGame.getGameTime()*3.0f) > 0)
				wally.setTextureRect(sf::IntRect(256, 0, 256, 256));
		}
		else
		{
			wally.setTextureRect(sf::IntRect(768, 0, 256, 256));
			if (sin(theGame.getGameTime()*6.0f) > 0.5f)
				wally.setTextureRect(sf::IntRect(1024, 0, 256, 256));
			if (sin(theGame.getGameTime()*6.0f) < -0.5f)
				wally.setTextureRect(sf::IntRect(512, 0, 256, 256));
		}
		float walx = wally.getPosition().x;
		float xpos = (wally.getPosition().x - theView.getCenter().x) + velocity;
		if (xpos > boundr || xpos < -boundr)
		{
			theView.move(velocity, 0.0f);
		}
		if (walx + velocity < villageLength && walx + velocity>0)
		{
			wally.move(velocity, 0.0f);
		}
		if (theGame.isCarrying())
		{
			float dogDist = calcDist(dog.getPosition(), wally.getPosition());
			if (dogDist < 390.0f && !theGame.isTheEncounter())
			{
				if (dogDist < 40.0)
				{
					theGame.setEncounter();
					theGame.activateDogChew();
				}
				sf::Vector2f direction = wally.getPosition() - dog.getPosition();
				dog.move(scalar(13.0f, normalVector(direction)));
			}
			parcel.setPosition(wally.getPosition());
			parcel.setScale(wally.getScale());
		}
		if (theGame.isDropping())
		{
			//here I need to find the closest post box
			//and float the parcel to it
			if (!theGame.getFloatingParcelFlag())
			{
				index = 0;
				minDist = 9000.0f;
				for (unsigned int i = 0; i < positions.size(); i++)
				{
					house tm = house(positions[i]);
					sf::Vector2f mailDoor = sf::Vector2f(tm.xp + 90.0f, 470.0f);
					float currentDist = calcDist(parcel.getPosition(), mailDoor);
					if (currentDist < minDist)
					{
						minDist = currentDist;
						index = i;
					}
				}
				theGame.setFloatingParcelFlag(true);
				climbs = 0;
			}
			if (theGame.getFloatingParcelFlag() && calcDist(parcel.getPosition(), sf::Vector2f(positions[index].xp + 112.0f, 490.0f)) > 4.0f)
			{
				climbs++;
				float iter = minDist / 24.0f;
				sf::Vector2f direction = sf::Vector2f(positions[index].xp + 112.0f, 490.0f) - parcel.getPosition();
				parcel.setScale(float(50-climbs) / 50.0f, float(50-climbs) / 50.0f);
				parcel.move(scalar(iter, normalVector(direction)));
			}
			else
			{
				if (index != theGame.getDropoffHouse())
					theGame.addStrike();
				else
					theGame.addCash();
				theGame.addDelivery();
				parcel.setTexture(parcelTex);
				parcel.setPosition(startx + 100.0f, 535.0f);
				parcel.setScale(1.0f, 1.0f);
				theGame.setFloatingParcelFlag(false);
				theGame.setSeeking();
			}
		}

		theGame.updateSlip();
		theGame.updateHUD();

		//draw to screen
		window.clear(sf::Color::Cyan);
		theGame.renderHUD();
		theGame.renderSlip();
		window.draw(ground);
		for(unsigned int i=0; i<positions.size(); i++)
		{
			house tm = house(positions[i]);
			tm.sp.setPosition(tm.xp, 280.0f);
			window.draw(tm.sp);
			postBox.setPosition(tm.xp + 40.0f, 460.0f);
			window.draw(postBox);
		}
		window.draw(parcel);
		window.draw(wally);
		window.draw(dog);
		theGame.drawHUD(window);
		theGame.drawPackageSlip(window);
		window.setView(theView);
		window.display();
	}

	return 0;
}