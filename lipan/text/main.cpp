#include <iostream>
#include<cstdlib>
#include<ctime>
#include"Guess_my_number.h"


//游戏中的随机数种子全部使用当前时间

using namespace std;

//extern Player a;    //这两个类 在头文件中可以看到定义
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
        cout << "******Guess My Number******\n\n";  //简易用户界面
        cout << "1-自己玩\n";
        cout << "2-对战电脑\n\n";
        cout << "请选择:";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "你选择了自己玩.\n";
                Guess_my_Number_single();   //这个函数在Guess_my_Number.cpp中有定义
                break;
            case 2:
                cout << "你选择了对战电脑.\n";
                mytime = Guess_my_Number();     //同上
                comtime = Guess_Your_Number();  //同上
                if(mytime < comtime)            //判定胜利
                    cout << "恭喜你获胜了!\n\n";
                else
                    cout << "真可惜，下次一定能获胜。\n\n";
                break;
            default:cout << "非法输入!\n";
        }
sign:                                   //对应goto语句
        cout << "还想继续玩吗？(y/n):";
        cin >> again;

        switch(again)
        {
            case 'y':yes = true;break;
            case 'n':yes = false;break;
            default :cout << "错误的输入!\n\n";goto sign;
        }

    }while(yes);
}
*/
