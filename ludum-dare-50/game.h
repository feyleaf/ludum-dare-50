#ifndef GAME_H
#define GAME_H

class gameClass
{
	//HUD stuff
	sf::RenderTexture hudTexture;

	sf::Font handFont;
	sf::Font inkyFont;
	sf::Font slabFont;

	sf::Vector2f hudPosition;
	int textSize;
	int deliveryCountdown;
	int money;
	int iTimeLeft;
	int numberOfDeliveries;
	int numberOfStrikes;

	sf::Text hudCashEarned;
	sf::Text hudTimeLeft;
	sf::String cashString;
	sf::String timerString;

	sf::Clock deliveryClock;
	sf::Clock gameClock;

	//package handling members
	sf::RenderTexture packageSlip;

	sf::Texture packSlipTex;
	sf::Sprite packSlip;
	unsigned int levelOfDistortion;
	bool dogChewed;
	sf::Image dogChewMask;
	sf::Text slipHeader;
	sf::Text recipientName;
	sf::Text recipientHouse;
	sf::Text rewardText;
	sf::Text slipFooter;
	sf::String headerString;
	sf::String nameString;
	sf::String houseString;
	sf::String rewardString;
	sf::String footerString;


public:
	gameClass();
	~gameClass();

	float getGameTime();
	//HUD functionality
	void initHUD();
	void initCountdown();
	void initCash();

	void updateHUD();
	void updateCountdown();
	void updateCash();

	void renderHUD();
	void renderCountdown();
	void renderCash();

	//packing slip functionality
	void initSlip();
	void updateSlip();
	void renderSlip();

	void drawHUD(sf::RenderWindow& app);
	void drawPackageSlip(sf::RenderWindow& app);

	void toggleDogChew();
	void activateDogChew();
	void deactivateDogChew();

};

#endif//GAME_H