#include <iostream>
#include<cstdlib>
#include<ctime>
#include"Guess_my_number.h"


//��Ϸ�е����������ȫ��ʹ�õ�ǰʱ��

using namespace std;

//extern Player a;    //�������� ��ͷ�ļ��п��Կ�������
//extern Com b;
/*

int main()
{
    bool yes = true;
    int choice;
    int mytime = 0,comtime = 0;
    char again = 'y';

    do
    {
        cout << "******Guess My Number******\n\n";  //�����û�����
        cout << "1-�Լ���\n";
        cout << "2-��ս����\n\n";
        cout << "��ѡ��:";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "��ѡ�����Լ���.\n";
                Guess_my_Number_single();   //���������Guess_my_Number.cpp���ж���
                break;
            case 2:
                cout << "��ѡ���˶�ս����.\n";
                mytime = Guess_my_Number();     //ͬ��
                comtime = Guess_Your_Number();  //ͬ��
                if(mytime < comtime)            //�ж�ʤ��
                    cout << "��ϲ���ʤ��!\n\n";
                else
                    cout << "���ϧ���´�һ���ܻ�ʤ��\n\n";
                break;
            default:cout << "�Ƿ�����!\n";
        }
sign:                                   //��Ӧgoto���
        cout << "�����������(y/n):";
        cin >> again;

        switch(again)
        {
            case 'y':yes = true;break;
            case 'n':yes = false;break;
            default :cout << "���������!\n\n";goto sign;
        }

    }while(yes);
}
*/
