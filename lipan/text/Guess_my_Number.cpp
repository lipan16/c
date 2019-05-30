#include<iostream>
#include<cstdlib>
#include<ctime>
#include"Guess_my_number.h"

using namespace std;

void Guess_my_Number_single()       //����ģʽ
{
    Player a;
    int n;
    do
    {
        cout << "Enter a number:";
        cin >> n;
        a.setMyGuess(n);
        a.add_self();

        if(a.getMyGuess() > a.getMyNumber())
        {
                cout << "High!\n\n";
                if(a.getMyGuess()-a.getMyNumber()<10)       //����������ֽӽ�ʱ ������ʾ ��ͬ
                    cout << "But almost there!\n\n";
        }
        else if(a.getMyGuess() < a.getMyNumber())
        {
                cout << "Low!\n\n";
                if(a.getMyNumber()-a.getMyGuess()<10)
                    cout << "But almost there!\n\n";
        }
        else
            cout << "Congratulations! You got it in " << a.getMyTimes() << " guesses!\n";
    }while(a.getMyGuess() != a.getMyNumber());
}

int Guess_my_Number()       //��ΪҪ����Ա�ʤ�� Ҫ�����������
{
    Player a;
    int n;
    do
    {
        cout << "Enter a number:";
        cin >> n;
        a.setMyGuess(n);
        a.add_self();

        if(a.getMyGuess() > a.getMyNumber())
        {
                cout << "High!\n\n";
                if(a.getMyGuess()-a.getMyNumber()<10)
                    cout << "But almost there!\n\n";
        }
        else if(a.getMyGuess() < a.getMyNumber())
        {
                cout << "Low!\n\n";
                if(a.getMyNumber()-a.getMyGuess()<10)
                    cout << "But almost there!\n\n";
        }
        else
            cout << "Congratulations! You got it in " << a.getMyTimes() << " guesses!\n\n";
    }while(a.getMyGuess() != a.getMyNumber());
    return(a.getMyTimes());
}


int Guess_Your_Number()                 //ͬ��
{
    Com b;
    srand(static_cast<unsigned int>(time(0)));
    int n;
    cout << "Enter a number:";
    cin >> n;
    b.setNumber(n);             //����Ҹ�������
    do
    {
        b.Attempt();
        b.add_self();
        if(b.getGuess() > b.getNumber())
            b.setHigh(b.getGuess());
        else if(b.getGuess() < b.getNumber())
            b.setLow(b.getGuess());
        else
            break;
    }while(b.getNumber() != b.getGuess());
    cout<<"Computer got it in " << b.getTimes() << " guesses\n\n";
    return(b.getTimes());
}
