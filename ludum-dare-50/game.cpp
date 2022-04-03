#include "globals.h"

gameClass::gameClass()
{
	initHUD();
}

gameClass::~gameClass()
{

}

void gameClass::initHUD()
{
	hudTexture.create(1256, 196);
	textSize = 24;
	handFont.loadFromFile("handwriting1.ttf");
	inkyFont.loadFromFile("handwriting2.ttf");
	slabFont.loadFromFile("roboto-slab.ttf");
	initCountdown();
	initCash();
	initDeliveries();
	initStrikes();
	instructions();
}

void gameClass::initCountdown()
{
	hudTimeLeft.setCharacterSize(textSize);
	hudTimeLeft.setFont(slabFont);
	hudTimeLeft.setFillColor(sf::Color::Black);
	hudTimeLeft.setPosition(hudPosition);
	deliveryCountdown = 100;
	deliveryClock.restart();
	timerString = "Time Left: ";
	hudTimeLeft.setString(timerString);
}

void gameClass::initCash()
{
	hudCashEarned.setCharacterSize(textSize);
	hudCashEarned.setFont(slabFont);
	hudCashEarned.setFillColor(sf::Color::Black);
	hudCashEarned.setPosition(hudPosition + sf::Vector2f(0.0f, float(int(textSize * 1.15f))));
	money = 0;
	gameClock.restart();
	cashString = "Cash Earned: $";
	hudCashEarned.setString(cashString + std::to_string(money));
}

void gameClass::initDeliveries()
{
	hudDeliveries.setCharacterSize(textSize);
	hudDeliveries.setFont(slabFont);
	hudDeliveries.setFillColor(sf::Color::Black);
	hudDeliveries.setPosition(hudPosition + scalar(2.0, sf::Vector2f(0.0f, float(int(textSize * 1.15f)))));
	numberOfDeliveries = 0;
	deliveryString = "Completed Deliveries: ";
	hudDeliveries.setString(deliveryString + std::to_string(numberOfDeliveries));
}

void gameClass::initStrikes()
{
	hudStrikes.setCharacterSize(textSize);
	hudStrikes.setFont(slabFont);
	hudStrikes.setFillColor(sf::Color::Red);
	hudStrikes.setPosition(hudPosition + scalar(3.0, sf::Vector2f(0.0f, float(int(textSize * 1.15f)))));
	numberOfStrikes = 0;
	strikeString = "Strikes: ";
	hudDeliveries.setString(strikeString + std::to_string(numberOfStrikes));
}

void gameClass::instructions()
{
	hudInstructions.setCharacterSize(textSize);
	hudInstructions.setFont(slabFont);
	hudInstructions.setFillColor(sf::Color::Black);
	hudInstructions.setPosition(228.0f, 44.0f);
	hudInstructions.setString("Left and Right with ARROW KEYS\nSPACE BAR to pick up & drop parcels\nESC to end abruptly");
}

void gameClass::updateHUD()
{
	updateCountdown();
	updateCash();
	updateDeliveries();
	updateStrikes();
	updateInstructions();
}

void gameClass::updateCountdown()
{
	hudTimeLeft.setFillColor(sf::Color::Black);
	hudTimeLeft.setPosition(hudPosition);
	float timeLeft = deliveryCountdown - deliveryClock.getElapsedTime().asSeconds();
	iTimeLeft = int(timeLeft);
	if (iTimeLeft <= 0)
		hudTimeLeft.setFillColor(sf::Color::Red);
	hudTimeLeft.setString(timerString + std::to_string(iTimeLeft));
}

void gameClass::updateCash()
{
	hudCashEarned.setPosition(hudPosition + sf::Vector2f(0.0f, float(int(textSize * 1.15f))));
	hudCashEarned.setString(cashString + std::to_string(money));
}

void gameClass::updateDeliveries()
{
	hudDeliveries.setPosition(hudPosition + scalar(2.0, sf::Vector2f(0.0f, float(int(textSize * 1.15f)))));
	hudDeliveries.setString(deliveryString + std::to_string(numberOfDeliveries));
}

void gameClass::updateStrikes()
{
	hudStrikes.setPosition(hudPosition + scalar(3.0, sf::Vector2f(0.0f, float(int(textSize * 1.15f)))));
	hudStrikes.setString(strikeString + std::to_string(numberOfStrikes));
}

void gameClass::updateInstructions()
{
	hudInstructions.setPosition(338.0f, 44.0f);
	float seconds = gameClock.getElapsedTime().asSeconds();
	if (seconds > 10.0f)
	{
		float till = ((15.0f - seconds)*255.0f)/5.0f;
		sf::Uint8 alpha = sf::Uint8(till);
		hudInstructions.setFillColor(sf::Color(0, 0, 0, till));
	}
}

void gameClass::renderHUD()
{
	hudTexture.clear(sf::Color(0,0,0,0));
	renderCountdown();
	renderCash();
	renderDeliveries();
	renderStrikes();
	renderInstructions();
	hudTexture.display();
}

void gameClass::renderCountdown()
{
	hudTimeLeft.setPosition(hudPosition);
	hudTexture.draw(hudTimeLeft);
}

void gameClass::renderCash()
{
	hudCashEarned.setPosition(hudPosition + sf::Vector2f(0.0f, float(int(textSize * 1.15f))));
	hudTexture.draw(hudCashEarned);
}

void gameClass::renderDeliveries()
{
	hudTexture.draw(hudDeliveries);
}

void gameClass::renderStrikes()
{
	if (numberOfStrikes > 0)
		hudTexture.draw(hudStrikes);
}

void gameClass::renderInstructions()
{
	if (gameClock.getElapsedTime().asSeconds() < 15.0f)
		hudTexture.draw(hudInstructions);
}

void gameClass::drawHUD(sf::RenderWindow& app)
{
	app.setView(app.getDefaultView());
	sf::Sprite ret;
	ret.setTexture(hudTexture.getTexture());
	app.draw(ret);
}

void gameClass::initSlip()
{
	dogChewed = false;
	dogChewMask.loadFromFile("dogchewmask.png");

	packSlipTex.loadFromFile("packslip.png");
	packSlip.setTexture(packSlipTex);
	packSlip.setPosition(0,0);
	packageSlip.create(256, 128);
	slipHeader.setFont(handFont);
	slipFooter.setFont(handFont);
	recipientName.setFont(handFont);
	recipientHouse.setFont(handFont);
	rewardText.setFont(handFont);
	slipHeader.setCharacterSize(20);
	slipFooter.setCharacterSize(20);
	recipientName.setCharacterSize(26);
	recipientHouse.setCharacterSize(22);
	rewardText.setCharacterSize(24);
	slipHeader.setFillColor(sf::Color(0,128,0,255));
	slipFooter.setFillColor(sf::Color(0, 128, 0, 255));
	recipientName.setFillColor(sf::Color(0,0,0,255));
	recipientHouse.setFillColor(sf::Color::Black);
	rewardText.setFillColor(sf::Color::Green);
	headerString = "Deliver Package To";
	nameString = " ";
	houseString = "House:  ";
	rewardString = "Reward: $ ";
	footerString = "Pickup from:";
}

void gameClass::updateSlip()
{
	slipHeader.setString(headerString);
	slipFooter.setString(footerString);
	recipientName.setString(nameString);
	recipientHouse.setString(houseString);
	rewardText.setString(rewardString);
	slipHeader.setPosition(16.0f, 3.0f);
	slipFooter.setPosition(16.0f, 91.0f);
	recipientName.setPosition(20.0f, 16.0f);
	recipientHouse.setPosition(26.0f, 47.0f);
	rewardText.setPosition(20.0f, 67.0f);
}

void gameClass::renderSlip()
{
	packageSlip.clear(sf::Color(0, 0, 0, 0));
	packageSlip.draw(packSlip);
	packageSlip.draw(slipFooter);
	packageSlip.draw(slipHeader);
	packageSlip.draw(recipientHouse);
	packageSlip.draw(recipientName);
	packageSlip.draw(rewardText);
	if (dogChewed)
	{
		sf::Texture tm = packageSlip.getTexture();
		sf::Image chewy = tm.copyToImage();
		for (int y = 0; y < dogChewMask.getSize().y; y++)
		{
			for (int x = 0; x < dogChewMask.getSize().x; x++)
			{
				if (dogChewMask.getPixel(x, y) == sf::Color(255,0,255,255))
					chewy.setPixel(x, y, sf::Color(0, 0, 0, 0));
			}
		}
		tm.loadFromImage(chewy);
		packageSlip.clear(sf::Color(0, 0, 0, 0));
		sf::Sprite xx;
		xx.setTexture(tm);
		packageSlip.draw(xx);
	}
	packageSlip.display();
}

float gameClass::getGameTime()
{
	return gameClock.getElapsedTime().asSeconds();
}

void gameClass::drawPackageSlip(sf::RenderWindow& app)
{
	app.setView(app.getDefaultView());
	sf::Sprite ret;
	ret.setTexture(packageSlip.getTexture());
	ret.setPosition(960, 15);
	app.draw(ret);
}

void gameClass::toggleDogChew()
{
	dogChewed = !dogChewed;
}

void gameClass::activateDogChew()
{
	dogChewed = true;
}

void gameClass::deactivateDogChew()
{
	dogChewed = false;
}

