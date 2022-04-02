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
	hudTexture.create(256, 96);
	textSize = 24;
	handFont.loadFromFile("handwriting1.ttf");
	inkyFont.loadFromFile("handwriting2.ttf");
	slabFont.loadFromFile("roboto-slab.ttf");
	initCountdown();
	initCash();
}

void gameClass::initCountdown()
{
	hudTimeLeft.setCharacterSize(textSize);
	hudTimeLeft.setFont(slabFont);
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
	hudCashEarned.setPosition(hudPosition + sf::Vector2f(0.0f, float(textSize * 1.15f)));

	money = 7654;
	gameClock.restart();
	cashString = "Cash Earned: $";
	hudCashEarned.setString(cashString + std::to_string(money));
}

void gameClass::updateHUD()
{
	updateCountdown();
	updateCash();
}

void gameClass::updateCountdown()
{
	hudTimeLeft.setFillColor(sf::Color::White);
	hudTimeLeft.setPosition(hudPosition);
	float timeLeft = deliveryCountdown - deliveryClock.getElapsedTime().asSeconds();
	iTimeLeft = int(timeLeft);
	if (iTimeLeft <= 0)
		hudTimeLeft.setFillColor(sf::Color::Red);
	hudTimeLeft.setString(timerString + std::to_string(iTimeLeft));
}

void gameClass::updateCash()
{
	hudCashEarned.setPosition(hudPosition + sf::Vector2f(0.0f, float(textSize * 1.15f)));
	hudCashEarned.setString(cashString + std::to_string(money));
}

void gameClass::renderHUD()
{
	hudTexture.clear(sf::Color(0,0,0,0));
	renderCountdown();
	renderCash();
	hudTexture.display();
}

void gameClass::renderCountdown()
{
	hudTimeLeft.setPosition(hudPosition);
	hudTexture.draw(hudTimeLeft);
}

void gameClass::renderCash()
{
	hudCashEarned.setPosition(hudPosition + sf::Vector2f(0.0f, float(textSize * 1.15f)));
	hudTexture.draw(hudCashEarned);
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
	headerString = "========Ticket========";
	nameString = "Benjamin";
	houseString = "Vertical Siding";
	rewardString = "Reward: $16";
	footerString = "-----------deliver-----------";
}

void gameClass::updateSlip()
{
	slipHeader.setString(headerString);
	slipFooter.setString(footerString);
	recipientName.setString(nameString);
	recipientHouse.setString(houseString);
	rewardText.setString(rewardString);
	slipHeader.setPosition(6.0f, 3.0f);
	slipFooter.setPosition(6.0f, 91.0f);
	recipientName.setPosition(10.0f, 16.0f);
	recipientHouse.setPosition(26.0f, 47.0f);
	rewardText.setPosition(10.0f, 67.0f);
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