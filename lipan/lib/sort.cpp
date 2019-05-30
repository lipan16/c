/*
 * sort.cpp
 *
 *  Created on: 2018年5月1日
 *      Author: asus
 */

template<class T>
int length(T& data) {//算数组的长度
	return sizeof(data) / sizeof(data[0]);
}

void BubSort(int a[],int len) { //冒泡排序
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

void SelSort(int a[], int n) { //选择排序
	int k; //记录最小值得下标
	for (int i = 0; i < n; i++) {
		k = i;
		for (int j = i; j < n; j++) {
			if (a[k] > a[j])
				k = j; //记录小的下标
		}
		if (k != i) { //下标不是i时交换两个数
			a[i] = a[i] + a[k];
			a[k] = a[i] - a[k];
			a[i] = a[i] - a[k];
		}
	}
}

void InsSort(int a[], int n) { //插入排序
	int j, key;
	for (int i = 0; i < n; i++) {
		key = a[i]; //当前待插入的元素
		for (j = i - 1; j >= 0 && key < a[j]; j--)
			a[j + 1] = a[j]; //前面有序数组中大的元素往后移
		a[j + 1] = key; //后移之后空出来的位置插入当前元素key
	}
}

/**
 带哨兵的直接插入排序,数组的第一个元素不用于存储有效数据,将input[0]作为哨兵，可以避免判定input[j]中，数组是否越界
 因为在j--的过程中，当j减小到0时,变成了input[0]与input[0]自身进行比较，很明显这个时候说明位置i之前的数字都比input[i]小
 位置i上的数字不需要移动，直接进入下一轮的插入比较。
 */
void InsWPSort(int a[], int n) {
	int i, j, b[n + 1]; //辅助数组，原数组0单元有元素,带哨兵的直接插入0单元无数据
	for (i = 0; i < n; i++) {
		b[i + 1] = a[i];
	}
	for (i = 1; i < n + 1; i++) { //从第二个数据开始与它前面的元素比较
		b[0] = b[i];
		for (j = i - 1; b[j] > b[0]; j--) {
			b[j + 1] = b[j];
			b[j] = b[0]; //a[j]一直都是排序的元素中最大的那一个
		}
	}
	for (i = 0; i < n; i++) { //返回到原数组
		a[i] = b[i + 1];
	}
}

void BInsSort(int a[], int n) { //二分插入
	int i, j, t, low, high, mid;
	for (i = 1; i < n; i++) {
		t = a[i]; // 保存但前元素
		low = 0;
		high = i - 1;
		while (low <= high) // 在a[low...high]中折半查找有序插入的位置
		{
			mid = (low + high) / 2;
			if (a[mid] > t)  // 如果中间元素比但前元素大，当前元素要插入到中间元素的左侧
				high = mid - 1;
			else
				// 如果中间元素比当前元素小，但前元素要插入到中间元素的右侧
				low = mid + 1;
		}
		for (j = i - 1; j > high; j--) // 元素后移
			a[j + 1] = a[j];
		a[high + 1] = t; //插入
	}
}

void ShellSort(int a[], int n) { //希尔排序
	int gap, i, j; //gap为步长
	for (gap = n / 2; gap > 0; gap /= 2) { //设置排序的步长，步长gap每次减半，直到减到1
		for (i = gap; i < n; i++) {
			for (j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap) { //比较相距gap远的两个元素的大小，根据排序方向决定如何调换
				a[j] = a[j] + a[j + gap];
				a[j + gap] = a[j] - a[j + gap];
				a[j] = a[j] - a[j + gap];
			}
		}
	}
}

/**
 快速排序（quick sort）。在这种方法中， n 个元素被分成三段（组）：左段left，右段right和中段middle。中段仅包含一个元素。
 左段中各元素都小于等于中段元素，右段中各元素都大于等于中段元素。因此left和right中的元素可以独立排序，
 并且不必对left和right的排序结果进行合并。使用快速排序方法对a[0:n-1]排序从a[0:n-1]中选择一个元素作为middle，
 该元素为支点把余下的元素分割为两段left和right，使得left中的元素都小于等于支点，而right 中的元素都大于等于支点
 递归地使用快速排序方法对left 进行排序递归地使用快速排序方法对right 进行排序所得结果为left+middle+right
 */
void QuickSort(int a[], int l, int r) {
	int i = l, j = r, key = a[i];
	if (l < r) {
		while (i < j) {
			while (a[j] >= key && i < j) //从右向左找第一个小于key的值
				j--;
			a[i] = a[j];
			while (a[i] <= key && i < j) //从左向右找第一个大于key的值
				i++;
			a[j] = a[i];
		}
		a[i] = key;
		QuickSort(a, l, i - 1); //递归调用
		QuickSort(a, j + 1, r);
	}
}

/**
 堆的定义 n 个元素的序列 {k1,k2,...,kn}当且仅当满足下列关系时，称为堆:
 ki<=k2i     ki<=k2i+1     (i=1,2,...,n/2)或
 ki>=k2i     ki>=k2i+1     (i=1,2,...,n/2)
 堆排序思路：
 建立在树形选择排序基础上；将待排序列建成堆（初始堆生成）后，序列的第一个元素（堆顶元素）就一定是序列中的最大元素；
 将其与序列的最后一个元素交换，将序列长度减一；再将序列建成堆（堆调整）后，堆顶元素仍是序列中的最大元素，
 再次将其与序列最后一个元素交换并缩短序列长度；反复此过程，直至序列长度为一，所得序列即为排序后结果。
 */

void HeapAdjust(int a[], int s, int m);
void HeapSort(int a[], int n) {
	int i, temp;
	for (i = n / 2; i >= 0; i--) {
		HeapAdjust(a, i, n); //处理后，a[i]是这个数组后半部分的最大值
	}
	for (i = n; i > 0; i--) {
		temp = a[0]; //把根元素（剩下元素中最大的那个）放到结尾 ,下一次只要排剩下的数就可以啦
		a[0] = a[i];
		a[i] = temp;
		HeapAdjust(a, 0, i - 1);
	}
}

void HeapAdjust(int a[], int s, int m) { //构建排列成堆
	int j, rc;
	rc = a[s]; //保存处理元素
	for (j = 2 * s; j <= m; j *= 2) { //处理父亲元素
		if (j < m && a[j] < a[j + 1])
			j++; //取较大的孩子节点
		if (rc >= a[j])
			break;
		a[s] = a[j]; //父节点比较大的孩子节点大则互换 ,保证父节点比所有子节点都大（父节点存储在前面）
		s = j;
	}
	a[s] = rc; //相当于a[j]=rc
}

/*
void getPosCount(int arr[], int length, int *posCount) { //得到数组元素中最大数，并且计算其位数个数
	int max = arr[0], i;
	for (i = 0; i < length; i++) { //找到最大的那个元素，确定位数
		if (max < arr[i])
			max = arr[i];
	}
	*posCount = 0;
	while (max) {
		max = max / 10;
		(*posCount)++; //位数加一
	}
}

void RadixSort(int arr[], int length){ //基数排序
	int* temp[10]; //定义桶个数 0～9 共10个
	int i, pos, tmp, posCount, element, elementNum, log = 1;

	for (element = 0; element < 10; element++) { //每个桶最大能装length个元素，预防所有元素都是同一个数
		temp[element] = new int[length+1];//0号单元用来存放该桶中一共有多少个元素
		temp[element][0] = 0; //初始化为0
	}
	getPosCount(arr, length, &posCount); //posCount存放位数

	for (pos = 0; pos < posCount; pos++) { //从个位 ～ 十位 ～ 百位 。。。依次排序
		for (element = 0; element < length; element++) { //把元素放到桶里  分配动作
			tmp = ++temp[(arr[element] / log) % 10][0];//(arr[element] / log) % 10为找到自己对应的桶，tmp计数加一
			temp[(arr[element] / log) % 10][tmp] = arr[element];//把元素加入到桶中
		}

		for (i = 0, element = 0; element < 10 && i < length; element++) {//从0~9把桶中的元素串起来
			for (elementNum = 1; elementNum <= temp[element][0]; elementNum++)//用elementNUm来遍历桶中的元素，0号单元为总的个数
				arr[i++] = temp[element][elementNum];//把元素依次串起来
			temp[element][0] = 0;//桶中元素计数器清零
		}
		log = log * 10;//计算高一位
	}
}*/


#define N 100

void RadixCountSort(int* npIndex, int nMax, int* A, int nLen) {
	int* pnCount = new int[nMax];//(int*) malloc(sizeof(int) * nMax);        //保存计数的个数
	int i = 0;
	for (i = 0; i < nMax; ++i)
		pnCount[i] = 0;
	for (i = 0; i < nLen; ++i)  //初始化计数个数
		++pnCount[npIndex[i]];
	for (i = 1; i < 10; ++i) //确定不大于该位置的个数。
		pnCount[i] += pnCount[i - 1];

	int * pnSort =new int[nLen];// (int*) malloc(sizeof(int) * nLen);    //存放零时的排序结果。
	for (i = nLen - 1; i >= 0; --i){    //i是从nLen-1到0的顺序排序的，是为了使排序稳定。
		--pnCount[npIndex[i]];
		pnSort[pnCount[npIndex[i]]] = A[i];
	}
	for (i = 0; i < nLen; ++i)      //把排序结构输入到返回的数据中。
		A[i] = pnSort[i];
}

void RadixSort(int* A, int nLen) { //基数排序
	int *ARadix =new int[nLen];// (int *) malloc(sizeof(int) * nLen);   //申请存放基数的空间
	int nRadixBase = 1, i;    //初始化倍数基数为1
	int nIsOk = 0;         //设置完成排序为false
	while (nIsOk == 0)         //循环，直到排序完成
	{
		nIsOk = 1;
		nRadixBase *= 10;
		for (i = 0; i < nLen; ++i) {
			ARadix[i] = A[i] % nRadixBase;
			ARadix[i] /= nRadixBase / 10;
			if (ARadix[i] > 0)
				nIsOk = 0;
		}
		if (nIsOk == 1)        //如果所有的基数都为0，认为排序完成，就是已经判断到最高位了。
			break;
		RadixCountSort(ARadix, 10, A, nLen);
	}
}
