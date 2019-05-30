#ifndef GUESS_MY_NUMBER_H_INCLUDED
#define GUESS_MY_NUMBER_H_INCLUDED

class Com
{
    int Number;
    int Guess;
    int Times;
    int low,high;
public:
    Com();
    ~Com();
    void setNumber(int);
    void setHigh(int);
    void setLow(int);
    int getNumber()const;
    int getGuess()const;
    int getTimes()const;
    void add_self();
    void Attempt();
};

class Player
{
    int myNumber;
    int myGuess;
    int myTimes;
public:
    Player();
    ~Player();
    void setMyGuess(int);
    int getMyNumber()const;
    int getMyGuess()const;
    int getMyTimes()const;
    void add_self();
};

void Guess_my_Number_single();

int Guess_my_Number();

int Guess_Your_Number();


#endif // GUESS_MY_NUMBER_H_INCLUDED
