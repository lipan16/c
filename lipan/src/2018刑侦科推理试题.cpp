/*
 * 2018�������������.cpp
 *
 *  Created on: 2018��4��13��
 *      Author: asus
 */



//��˼·��array[0]-array[9]����1-10��,1-4����ѡ��A-D
//main����ɸѡ������Ŀ����ѡ��Ŀ����ԣ����ֱ����function2-function10�������飬���ʵľ�����
//�𰸣�B,C,A,C,A,C,D,A,B,A

/*
#include <iostream>
using namespace std;

int function2(int array[10]);
int function3(int array[10]);
int function4(int array[10]);
int function5(int array[10]);
int function6(int array[10]);
int function7(int array[10], int A, int B, int C, int D);
int function8(int array[10]);
int function9(int array[10]);
int function10(int array[10], int A, int B, int C, int D);

int main() {
	int array[10] = { 0 };

	for (array[1] = 1; array[1] <= 4; ++array[1]) {
		for (array[4] = 1; array[4] <= 4; ++array[4]) {
			if (function2(array) != 0){//function2����2��5������
				for (array[2] = 1; array[2] <= 4; ++array[2]) {
					for (array[3] = 1; array[3] <= 4; ++array[3]) {
						for (array[5] = 1; array[5] <= 4; ++array[5]) {
							if (function3(array) != 0){ //function3����2��3��4��6��������ֻ����3��4��6�⣩
								for (array[6] = 1; array[6] <= 4; ++array[6]){
									for (array[7] = 1; array[7] <= 4;++array[7]) {
										for (array[8] = 1; array[8] <= 4;++array[8]) {
											if (function5(array) != 0){ //function5����4��5��7��8��9��������ֻ����7��8��9�⣩
												for (array[0] = 1;array[0] <= 4;++array[0]) {
													for (array[9] = 1;array[9] <= 4;++array[9]) {
														if (function9(array)!= 0) {//function9����1��2��5��6��9��10��������ֻ����1��10�⣩
															if (function4(array)!= 0) {
																if (function6(array)!= 0) {
																	if (function8(array)!= 0) {
																		//��ͳ��1-10����A-D�ĸ���
																		//Ϊʲô��������ܷ�������������Ϊ���ڵ�10����Ҳ���õ���
																		int	A =0,B = 0,C = 0,D =0; //����A-D��ָѡ��A-D���Եĸ���
																		for (int i =0;i< 10;++i) {
																			switch (array[i]) {
																				case 1: A = A + 1;break;
																				case 2: B = B + 1;break;
																				case 3: C = C + 1;break;
																				case 4: D = D + 1;break;
																			}
																		}
																		if (function7(array,A,B,C,D)!= 0) {
																			if (function10(array,A,B,C,D)!= 0) {
																				cout<< "----------2018����������������----------"<< endl<< endl;
																				for (int i =0;i< 10;++i) {
																					switch (array[i]) {
																					case 1:
																						cout << "��"<< i + 1<< "��Ĵ��� "<< "A"<< endl;
																						break;
																					case 2:
																						cout << "��" << i + 1 << "��Ĵ��� " << "B" << endl;
																						break;
																					case 3:
																						cout << "��" << i + 1 << "��Ĵ��� " << "C" << endl;
																						break;
																					case 4:
																						cout << "��" << i + 1 << "��Ĵ��� " << "D" << endl;
																						break;
																					}
																				}
																				cout<< endl;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

int function2(int array[10]) {
	switch (array[1]) {
	case 1:
		if (array[4] == 3)
			return array[10];
		break;
	case 2:
		if (array[4] == 4)
			return array[10];
		break;
	case 3:
		if (array[4] == 1)
			return array[10];
		break;
	case 4:
		if (array[4] == 2)
			return array[10];
		break;
	}
	return 0;
}

int function3(int array[10]) {
	switch (array[2]) {
	case 1: {
		if ((array[2] != array[5]) & (array[2] != array[1]) & (array[2] != array[3]))
			return array[10];
		else
			return 0;
	}
	case 2: {
		if ((array[5] != array[2]) & (array[5] != array[1])
				& (array[5] != array[3]))
			return array[10];
		else
			return 0;
	}
	case 3: {
		if ((array[1] != array[2]) & (array[1] != array[5])
				& (array[1] != array[3]))
			return array[10];
		else
			return 0;
	}
	case 4: {
		if ((array[3] != array[2]) & (array[3] != array[5])
				& (array[3] != array[1]))
			return array[10];
		else
			return 0;
	}
	}
	return 0;
}

int function5(int array[10]) {
	switch (array[4]) {
	case 1: {
		if (array[7] == array[4])
			return array[10];
		else
			return 0;
	}
	case 2: {
		if (array[3] == array[4])
			return array[10];
		else
			return 0;
	}
	case 3: {
		if (array[8] == array[4])
			return array[10];
		else
			return 0;
	}
	case 4: {
		if (array[6] == array[4])
			return array[10];
		else
			return 0;
	}
	}
	return 0;
}

int function9(int array[10]) {
	bool judge1, judge2;
	if (array[0] == array[5])
		judge1 = true;
	else
		judge1 = false;

	switch (array[8]) {
	case 1: {
		if (array[5] == array[4])
			judge2 = true;
		else
			judge2 = false;

		if (judge1 != judge2)
			return array[10];
		else
			return 0;
	}
	case 2: {
		if (array[9] == array[4])
			judge2 = true;
		else
			judge2 = false;

		if (judge1 != judge2)
			return array[10];
		else
			return 0;
	}
	case 3: {
		if (array[1] == array[4])
			judge2 = true;
		else
			judge2 = false;

		if (judge1 != judge2)
			return array[10];
		else
			return 0;
	}
	case 4: {
		if (array[8] == array[4])
			judge2 = true;
		else
			judge2 = false;

		if (judge1 != judge2)
			return array[10];
		else
			return 0;
	}
	}
	return 0;
}

int function4(int array[10]) {
	switch (array[3]) {
	case 1: {
		if (array[0] == array[4])
			return array[10];
		else
			return 0;
	}
	case 2: {
		if (array[1] == array[6])
			return array[10];
		else
			return 0;
	}
	case 3: {
		if (array[0] == array[8])
			return array[10];
		else
			return 0;
	}
	case 4: {
		if (array[5] == array[9])
			return array[10];
		else
			return 0;
	}
	}
	return 0;
}

int function6(int array[10]) {
	switch (array[5]) {
	case 1: {
		if ((array[1] == array[7]) & (array[3] == array[7]))
			return array[10];
		else
			return 0;
	}
	case 2: {
		if ((array[0] == array[7]) & (array[5] == array[7]))
			return array[10];
		else
			return 0;
	}
	case 3: {
		if ((array[2] == array[7]) & (array[9] == array[7]))
			return array[10];
		else
			return 0;
	}
	case 4: {
		if ((array[4] == array[7]) & (array[8] == array[7]))
			return array[10];
		else
			return 0;
	}
	}
	return 0;
}

int function8(int array[10]) {
	//����ĸ�������ڣ�ѡ��A��D���������,ֻ��һ��
	switch (array[7]) {
	case 1: {
		switch (array[0]) {
		case 1:
			if (array[6] == 2)
				return 0;
		case 4:
			if (array[6] == 3)
				return 0;
		default: {
			if ((array[6] != array[0] - 1) & (array[6] != array[0] + 1))
				return array[10];
			else
				return 0;
		}
		}
		break;
	}
	case 2: {
		switch (array[0]) {
		case 1:
			if (array[4] == 2)
				return 0;
		case 4:
			if (array[4] == 3)
				return 0;
		default: {
			if ((array[4] != array[0] - 1) & (array[4] != array[0] + 1))
				return array[10];
			else
				return 0;
		}
		}
		break;
	}
	case 3: {
		switch (array[0]) {
		case 1:
			if (array[1] == 2)
				return 0;
		case 4:
			if (array[1] == 3)
				return 0;
		default: {
			if ((array[1] != array[0] - 1) & (array[1] != array[0] + 1))
				return array[10];
			else
				return 0;
		}
		}
		break;
	}
	case 4: {
		switch (array[0]) {
		case 1:
			if (array[9] == 2)
				return 0;
		case 4:
			if (array[9] == 3)
				return 0;
		default: {
			if ((array[9] != array[0] - 1) & (array[9] != array[0] + 1))
				return array[10];
			else
				return 0;
		}
		}
	}
	}
	return 0;
}

int function7(int array[10], int A, int B, int C, int D) {
	switch (array[6]) {
	case 1: {
		if ((C <= A) & (C <= B) & (C <= D))
			return array[10];
		else
			return 0;
	}
	case 2: {
		if ((B <= A) & (B <= C) & (B <= D))
			return array[10];
		else
			return 0;
	}
	case 3: {
		if ((A <= B) & (A <= C) & (A <= D))
			return array[10];
		else
			return 0;
	}
	case 4: {
		if ((D <= A) & (D <= B) & (D <= C))
			return array[10];
		else
			return 0;
	}
	}
	return 0;
}

int function10(int array[10], int A, int B, int C, int D) {
	//�нӵ�7��ı���A-D�������ǰ���С��������
	int a[4] = { A, B, C, D }, tmp;

	for (int j = 1; j <= 4; ++j)   //j�����ڲ�ѭ��,��4��
			{
		for (int i = 0; i < 3; ++i) {
			if (a[i] >= a[i + 1]) {
				tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
			}
		}
	}
	int difference = a[3] - a[0];

	switch (array[9]) {
	case 1: {
		if (difference == 3)
			return array[10];
		else
			return 0;
	}
	case 2: {
		if (difference == 2)
			return array[10];
		else
			return 0;
	}
	case 3: {
		if (difference == 4)
			return array[10];
		else
			return 0;
	}
	case 4: {
		if (difference == 1)
			return array[10];
		else
			return 0;
	}
	}
	return 0;
}
*/
