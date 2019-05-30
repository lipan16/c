/*
 * fun.cpp
 *
 *  Created on: 2018Äê4ÔÂ24ÈÕ
 *      Author: asus
 */


unsigned long long fun(int i){
	if(i==0)
		return 1;
	else
		return i*fun(i-1);
}

int func(){
	return 10;
}
