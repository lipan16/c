/*
 * sort.cpp
 *
 *  Created on: 2018��5��1��
 *      Author: asus
 */

template<class T>
int length(T& data) {//������ĳ���
	return sizeof(data) / sizeof(data[0]);
}

void BubSort(int a[],int len) { //ð������
	for (int i = 0; i < len; i++) {
		for (int j = i; j < len; j++) {
			if (a[i] > a[j]) {
				a[i] = a[i] + a[j];
				a[j] = a[i] - a[j];
				a[i] = a[i] - a[j];
			}
		}
	}
}

void SelSort(int a[], int n) { //ѡ������
	int k; //��¼��Сֵ���±�
	for (int i = 0; i < n; i++) {
		k = i;
		for (int j = i; j < n; j++) {
			if (a[k] > a[j])
				k = j; //��¼С���±�
		}
		if (k != i) { //�±겻��iʱ����������
			a[i] = a[i] + a[k];
			a[k] = a[i] - a[k];
			a[i] = a[i] - a[k];
		}
	}
}

void InsSort(int a[], int n) { //��������
	int j, key;
	for (int i = 0; i < n; i++) {
		key = a[i]; //��ǰ�������Ԫ��
		for (j = i - 1; j >= 0 && key < a[j]; j--)
			a[j + 1] = a[j]; //ǰ�����������д��Ԫ��������
		a[j + 1] = key; //����֮��ճ�����λ�ò��뵱ǰԪ��key
	}
}

/**
 ���ڱ���ֱ�Ӳ�������,����ĵ�һ��Ԫ�ز����ڴ洢��Ч����,��input[0]��Ϊ�ڱ������Ա����ж�input[j]�У������Ƿ�Խ��
 ��Ϊ��j--�Ĺ����У���j��С��0ʱ,�����input[0]��input[0]������бȽϣ����������ʱ��˵��λ��i֮ǰ�����ֶ���input[i]С
 λ��i�ϵ����ֲ���Ҫ�ƶ���ֱ�ӽ�����һ�ֵĲ���Ƚϡ�
 */
void InsWPSort(int a[], int n) {
	int i, j, b[n + 1]; //�������飬ԭ����0��Ԫ��Ԫ��,���ڱ���ֱ�Ӳ���0��Ԫ������
	for (i = 0; i < n; i++) {
		b[i + 1] = a[i];
	}
	for (i = 1; i < n + 1; i++) { //�ӵڶ������ݿ�ʼ����ǰ���Ԫ�رȽ�
		b[0] = b[i];
		for (j = i - 1; b[j] > b[0]; j--) {
			b[j + 1] = b[j];
			b[j] = b[0]; //a[j]һֱ���������Ԫ����������һ��
		}
	}
	for (i = 0; i < n; i++) { //���ص�ԭ����
		a[i] = b[i + 1];
	}
}

void BInsSort(int a[], int n) { //���ֲ���
	int i, j, t, low, high, mid;
	for (i = 1; i < n; i++) {
		t = a[i]; // ���浫ǰԪ��
		low = 0;
		high = i - 1;
		while (low <= high) // ��a[low...high]���۰������������λ��
		{
			mid = (low + high) / 2;
			if (a[mid] > t)  // ����м�Ԫ�رȵ�ǰԪ�ش󣬵�ǰԪ��Ҫ���뵽�м�Ԫ�ص����
				high = mid - 1;
			else
				// ����м�Ԫ�رȵ�ǰԪ��С����ǰԪ��Ҫ���뵽�м�Ԫ�ص��Ҳ�
				low = mid + 1;
		}
		for (j = i - 1; j > high; j--) // Ԫ�غ���
			a[j + 1] = a[j];
		a[high + 1] = t; //����
	}
}

void ShellSort(int a[], int n) { //ϣ������
	int gap, i, j; //gapΪ����
	for (gap = n / 2; gap > 0; gap /= 2) { //��������Ĳ���������gapÿ�μ��룬ֱ������1
		for (i = gap; i < n; i++) {
			for (j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap) { //�Ƚ����gapԶ������Ԫ�صĴ�С�����������������ε���
				a[j] = a[j] + a[j + gap];
				a[j + gap] = a[j] - a[j + gap];
				a[j] = a[j] - a[j + gap];
			}
		}
	}
}

/**
 ��������quick sort���������ַ����У� n ��Ԫ�ر��ֳ����Σ��飩�����left���Ҷ�right���ж�middle���жν�����һ��Ԫ�ء�
 ����и�Ԫ�ض�С�ڵ����ж�Ԫ�أ��Ҷ��и�Ԫ�ض����ڵ����ж�Ԫ�ء����left��right�е�Ԫ�ؿ��Զ�������
 ���Ҳ��ض�left��right�����������кϲ���ʹ�ÿ������򷽷���a[0:n-1]�����a[0:n-1]��ѡ��һ��Ԫ����Ϊmiddle��
 ��Ԫ��Ϊ֧������µ�Ԫ�طָ�Ϊ����left��right��ʹ��left�е�Ԫ�ض�С�ڵ���֧�㣬��right �е�Ԫ�ض����ڵ���֧��
 �ݹ��ʹ�ÿ������򷽷���left ��������ݹ��ʹ�ÿ������򷽷���right �����������ý��Ϊleft+middle+right
 */
void QuickSort(int a[], int l, int r) {
	int i = l, j = r, key = a[i];
	if (l < r) {
		while (i < j) {
			while (a[j] >= key && i < j) //���������ҵ�һ��С��key��ֵ
				j--;
			a[i] = a[j];
			while (a[i] <= key && i < j) //���������ҵ�һ������key��ֵ
				i++;
			a[j] = a[i];
		}
		a[i] = key;
		QuickSort(a, l, i - 1); //�ݹ����
		QuickSort(a, j + 1, r);
	}
}

/**
 �ѵĶ��� n ��Ԫ�ص����� {k1,k2,...,kn}���ҽ����������й�ϵʱ����Ϊ��:
 ki<=k2i     ki<=k2i+1     (i=1,2,...,n/2)��
 ki>=k2i     ki>=k2i+1     (i=1,2,...,n/2)
 ������˼·��
 ����������ѡ����������ϣ����������н��ɶѣ���ʼ�����ɣ������еĵ�һ��Ԫ�أ��Ѷ�Ԫ�أ���һ���������е����Ԫ�أ�
 ���������е����һ��Ԫ�ؽ����������г��ȼ�һ���ٽ����н��ɶѣ��ѵ������󣬶Ѷ�Ԫ�����������е����Ԫ�أ�
 �ٴν������������һ��Ԫ�ؽ������������г��ȣ������˹��̣�ֱ�����г���Ϊһ���������м�Ϊ���������
 */

void HeapAdjust(int a[], int s, int m);
void HeapSort(int a[], int n) {
	int i, temp;
	for (i = n / 2; i >= 0; i--) {
		HeapAdjust(a, i, n); //�����a[i]����������벿�ֵ����ֵ
	}
	for (i = n; i > 0; i--) {
		temp = a[0]; //�Ѹ�Ԫ�أ�ʣ��Ԫ���������Ǹ����ŵ���β ,��һ��ֻҪ��ʣ�µ����Ϳ�����
		a[0] = a[i];
		a[i] = temp;
		HeapAdjust(a, 0, i - 1);
	}
}

void HeapAdjust(int a[], int s, int m) { //�������гɶ�
	int j, rc;
	rc = a[s]; //���洦��Ԫ��
	for (j = 2 * s; j <= m; j *= 2) { //������Ԫ��
		if (j < m && a[j] < a[j + 1])
			j++; //ȡ�ϴ�ĺ��ӽڵ�
		if (rc >= a[j])
			break;
		a[s] = a[j]; //���ڵ�Ƚϴ�ĺ��ӽڵ���򻥻� ,��֤���ڵ�������ӽڵ㶼�󣨸��ڵ�洢��ǰ�棩
		s = j;
	}
	a[s] = rc; //�൱��a[j]=rc
}

/*
void getPosCount(int arr[], int length, int *posCount) { //�õ�����Ԫ��������������Ҽ�����λ������
	int max = arr[0], i;
	for (i = 0; i < length; i++) { //�ҵ������Ǹ�Ԫ�أ�ȷ��λ��
		if (max < arr[i])
			max = arr[i];
	}
	*posCount = 0;
	while (max) {
		max = max / 10;
		(*posCount)++; //λ����һ
	}
}

void RadixSort(int arr[], int length){ //��������
	int* temp[10]; //����Ͱ���� 0��9 ��10��
	int i, pos, tmp, posCount, element, elementNum, log = 1;

	for (element = 0; element < 10; element++) { //ÿ��Ͱ�����װlength��Ԫ�أ�Ԥ������Ԫ�ض���ͬһ����
		temp[element] = new int[length+1];//0�ŵ�Ԫ������Ÿ�Ͱ��һ���ж��ٸ�Ԫ��
		temp[element][0] = 0; //��ʼ��Ϊ0
	}
	getPosCount(arr, length, &posCount); //posCount���λ��

	for (pos = 0; pos < posCount; pos++) { //�Ӹ�λ �� ʮλ �� ��λ ��������������
		for (element = 0; element < length; element++) { //��Ԫ�طŵ�Ͱ��  ���䶯��
			tmp = ++temp[(arr[element] / log) % 10][0];//(arr[element] / log) % 10Ϊ�ҵ��Լ���Ӧ��Ͱ��tmp������һ
			temp[(arr[element] / log) % 10][tmp] = arr[element];//��Ԫ�ؼ��뵽Ͱ��
		}

		for (i = 0, element = 0; element < 10 && i < length; element++) {//��0~9��Ͱ�е�Ԫ�ش�����
			for (elementNum = 1; elementNum <= temp[element][0]; elementNum++)//��elementNUm������Ͱ�е�Ԫ�أ�0�ŵ�ԪΪ�ܵĸ���
				arr[i++] = temp[element][elementNum];//��Ԫ�����δ�����
			temp[element][0] = 0;//Ͱ��Ԫ�ؼ���������
		}
		log = log * 10;//�����һλ
	}
}*/


#define N 100

void RadixCountSort(int* npIndex, int nMax, int* A, int nLen) {
	int* pnCount = new int[nMax];//(int*) malloc(sizeof(int) * nMax);        //��������ĸ���
	int i = 0;
	for (i = 0; i < nMax; ++i)
		pnCount[i] = 0;
	for (i = 0; i < nLen; ++i)  //��ʼ����������
		++pnCount[npIndex[i]];
	for (i = 1; i < 10; ++i) //ȷ�������ڸ�λ�õĸ�����
		pnCount[i] += pnCount[i - 1];

	int * pnSort =new int[nLen];// (int*) malloc(sizeof(int) * nLen);    //�����ʱ����������
	for (i = nLen - 1; i >= 0; --i){    //i�Ǵ�nLen-1��0��˳������ģ���Ϊ��ʹ�����ȶ���
		--pnCount[npIndex[i]];
		pnSort[pnCount[npIndex[i]]] = A[i];
	}
	for (i = 0; i < nLen; ++i)      //������ṹ���뵽���ص������С�
		A[i] = pnSort[i];
}

void RadixSort(int* A, int nLen) { //��������
	int *ARadix =new int[nLen];// (int *) malloc(sizeof(int) * nLen);   //�����Ż����Ŀռ�
	int nRadixBase = 1, i;    //��ʼ����������Ϊ1
	int nIsOk = 0;         //�����������Ϊfalse
	while (nIsOk == 0)         //ѭ����ֱ���������
	{
		nIsOk = 1;
		nRadixBase *= 10;
		for (i = 0; i < nLen; ++i) {
			ARadix[i] = A[i] % nRadixBase;
			ARadix[i] /= nRadixBase / 10;
			if (ARadix[i] > 0)
				nIsOk = 0;
		}
		if (nIsOk == 1)        //������еĻ�����Ϊ0����Ϊ������ɣ������Ѿ��жϵ����λ�ˡ�
			break;
		RadixCountSort(ARadix, 10, A, nLen);
	}
}
