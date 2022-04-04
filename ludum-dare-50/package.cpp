#include "globals.h"

void packageFactory::generateTheHouses()
{
	/*
	-Alvin - metal roof
-Allen - tall shingle roof
-Maggie - flowers in the front
-Margie - extra windows
-Leonardo - tower
-Pablo - house with deck
-Stu - house on piers
-Stewart - house with balcony
-Terry - boat
-Torance - on a large hill
-Quinn - on a short hill
-Benjamin - vertical siding
-Laura - shingled siding
-Liam - animal pen
-Jakob - schoolhouse
	*/
	details mock;
	mock.curName = "Alvin";
	mock.curHouse = "Metal Roof";
	mock.rewardCash = 16;
	mock.houseIndex = 11;
	customerList.push_back(mock);

	mock.curName = "Allen";
	mock.curHouse = "Tall Shingle Roof";
	mock.rewardCash = 9;
	mock.houseIndex = 7;
	customerList.push_back(mock);

	mock.curName = "Maggie";
	mock.curHouse = "Flowers In Front";
	mock.rewardCash = 21;
	mock.houseIndex = 0;
	customerList.push_back(mock);

	mock.curName = "Margie";
	mock.curHouse = "Extra Windows";
	mock.rewardCash = 16;
	mock.houseIndex = 12;
	customerList.push_back(mock);

	mock.curName = "Leonardo";
	mock.curHouse = "Tower";
	mock.rewardCash = 11;
	mock.houseIndex = 10;
	customerList.push_back(mock);

	mock.curName = "Pablo";
	mock.curHouse = "House with Deck";
	mock.rewardCash = 40;
	mock.houseIndex = 9;
	customerList.push_back(mock);

	mock.curName = "Stu";
	mock.curHouse = "House on Piers";
	mock.rewardCash = 16;
	mock.houseIndex = 5;
	customerList.push_back(mock);

	mock.curName = "Terry";
	mock.curHouse = "Boat House";
	mock.rewardCash = 12;
	mock.houseIndex = 4;
	customerList.push_back(mock);

	mock.curName = "Torance";
	mock.curHouse = "Regular Yellow";
	mock.rewardCash = 40;
	mock.houseIndex = 8;
	customerList.push_back(mock);

	mock.curName = "Quinn";
	mock.curHouse = "Regular Red";
	mock.rewardCash = 11;
	mock.houseIndex = 2;
	customerList.push_back(mock);

	mock.curName = "Jakob";
	mock.curHouse = "School";
	mock.rewardCash = 19;
	mock.houseIndex = 3;
	customerList.push_back(mock);

	mock.curName = "Wally";
	mock.curHouse = "Courier Office";
	mock.rewardCash = 0;
	mock.houseIndex = 6;
	customerList.push_back(mock);


}