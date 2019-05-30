#include<iostream>
#include<cstdlib>
#include<ctime>
#include"Guess_my_number.h"

Player::Player() // @suppress("Class members should be properly initialized")
{
    srand(static_cast<unsigned int>(time(0)));
    myNumber = rand() % 100 + 1;                //1-100生成一个数
    myTimes = 0;
}

Player::~Player(){}

void Player::setMyGuess(int a){myGuess=a;}

int Player::getMyNumber()const{return myNumber;}

int Player::getMyGuess()const{return myGuess;}

int Player::getMyTimes()const{return myTimes;}

void Player::add_self(){myTimes++;}            //自加
