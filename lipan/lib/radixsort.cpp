/*
 * radixsort.cpp
 *
 *  Created on: 2018年5月1日
 *      Author: asus
 */



/*
 * RadixSort.cpp
 *
 *  Created on: 2018年4月9日
 *      Author: asus
 */


/*
#include <stdio.h>
#include <stdlib.h>

#define N 100
int RadixCountSort(int* npIndex, int nMax, int* A, int nLen);
int RadixSort(int* A, int nLen);//基数排序

int main()
{
    int i=0,j;
    int A[N];
    printf("----------------------基数排序-------------------------\n\n");
    printf("请输入你要排序的个数：");
    scanf("%d",&j);
    if(j==0)
        return 0;
    printf("请输入的%d个整数：",j);
    for(i=0; i<j; i++)
        scanf("%d",&A[i]);

    RadixSort(A,j);
    printf("基数排序法排序后：\n");
    for (i = 0;i < j;i++)
        printf("%d ",A[i]);
    printf("\n");
    return 0;
}

int RadixCountSort(int* npIndex, int nMax, int* A, int nLen)
{
    int* pnCount=(int*)malloc(sizeof(int)* nMax);        //保存计数的个数
    int i=0;
    for (i=0; i<nMax; ++i)
        pnCount[i]=0;
    for (i=0; i<nLen; ++i)  //初始化计数个数
        ++pnCount[npIndex[i]];
    for (i=1; i<10; ++i) //确定不大于该位置的个数。
        pnCount[i] +=pnCount[i-1];

    int * pnSort =(int*)malloc(sizeof(int) * nLen);    //存放零时的排序结果。
    for (i=nLen-1; i>=0; --i)//i是从nLen-1到0的顺序排序的，是为了使排序稳定。
    {
        --pnCount[npIndex[i]];//确定确定不大于该数的个数，--表示个数减一，表示为从0开始算
        pnSort[pnCount[npIndex[i]]]=A[i];//把A[i]的值写在对应的桶里，实现一次排序
    }
    for (i=0; i<nLen; ++i)      //把排序结构输入到返回的数据中。
        A[i] = pnSort[i];

    free(pnSort);   //释放
    free(pnCount);
    return 1;
}

int RadixSort(int* A, int nLen)//基数排序
{
    int *ARadix=(int *)malloc(sizeof(int) *nLen);//申请存放基数的空间
    int nRadixBase=1,i;    //初始化倍数基数为1
    int nIsOk=0;         //设置完成排序为false
    while (nIsOk==0)//循环，直到排序完成
    {
        nIsOk=1;
        nRadixBase *=10;
        for (i=0; i<nLen; ++i)
        {
            ARadix[i] = A[i] % nRadixBase;
            ARadix[i] /= nRadixBase/10;
            if (ARadix[i]>0)
                nIsOk=0;
        }
        if (nIsOk==1)        //如果所有的基数都为0，认为排序完成，就是已经判断到最高位了。
            break;
        RadixCountSort(ARadix, 10, A, nLen);
    }
    free(ARadix);
    return 1;
}
*/

