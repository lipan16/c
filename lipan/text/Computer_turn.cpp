#include<iostream>
#include<cstdlib>
#include<ctime>
#include"Guess_my_number.h"

Com::Com() // @suppress("Class members should be properly initialized")
{
    srand(static_cast<unsigned int>(time(0)));
    Times = 0;
    high=100;
    low=0;
}

Com::~Com(){}

void Com::setNumber(int a){Number=a;}

void Com::setHigh(int a){high=a;}

void Com::setLow(int a){low=a;}

int Com::getNumber()const{return Number;}

int Com::getGuess()const{return Guess;}

int Com::getTimes()const{return Times;}

void Com::add_self(){Times++;}

void Com::Attempt(){Guess = rand() % (high-low) + low;}     //电脑的计算方法:在范围内随机生成数 不断逼近
