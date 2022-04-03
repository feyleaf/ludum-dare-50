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

	bool lookingForWork;
	bool onMission;
	bool theEncounter;
	bool hasEpiphany;
	bool droppingOffParcel;
	bool parcelSuccess;
	bool parcelFail;
	bool floatingParcelFlag;

	sf::Text hudCashEarned;
	sf::Text hudTimeLeft;
	sf::Text hudDeliveries;
	sf::Text hudStrikes;
	sf::Text hudInstructions;
	sf::String cashString;
	sf::String timerString;
	sf::String deliveryString;
	sf::String strikeString;
	sf::String instructionString;

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
	bool isSeeking();
	bool isCarrying();
	bool isDropping();
	void setSeeking();
	void setCarrying();
	void setDropping();
	void setFloatingParcelFlag(bool e);
	bool getFloatingParcelFlag();

	//HUD functionality
	void initHUD();
	void initCountdown();
	void initCash();
	void initDeliveries();
	void initStrikes();
	void instructions();

	void updateHUD();
	void updateCountdown();
	void updateCash();
	void updateDeliveries();
	void updateStrikes();
	void updateInstructions();

	void renderHUD();
	void renderCountdown();
	void renderCash();
	void renderDeliveries();
	void renderStrikes();
	void renderInstructions();

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