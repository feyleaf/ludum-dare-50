#ifndef PACKAGE_H
#define PACKAGE_H

struct details
{
	sf::String curName;
	sf::String curHouse;
	int rewardCash;
	int houseIndex;
};

class packageFactory
{
public:
	void generateTheHouses();
	std::vector<details> customerList;


};

#endif//PACKAGE_H
