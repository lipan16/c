/*
 * radixsort.cpp
 *
 *  Created on: 2018��5��1��
 *      Author: asus
 */



/*
 * RadixSort.cpp
 *
 *  Created on: 2018��4��9��
 *      Author: asus
 */


/*
#include <stdio.h>
#include <stdlib.h>

#define N 100
int RadixCountSort(int* npIndex, int nMax, int* A, int nLen);
int RadixSort(int* A, int nLen);//��������

int main()
{
    int i=0,j;
    int A[N];
    printf("----------------------��������-------------------------\n\n");
    printf("��������Ҫ����ĸ�����");
    scanf("%d",&j);
    if(j==0)
        return 0;
    printf("�������%d��������",j);
    for(i=0; i<j; i++)
        scanf("%d",&A[i]);

    RadixSort(A,j);
    printf("�������������\n");
    for (i = 0;i < j;i++)
        printf("%d ",A[i]);
    printf("\n");
    return 0;
}

int RadixCountSort(int* npIndex, int nMax, int* A, int nLen)
{
    int* pnCount=(int*)malloc(sizeof(int)* nMax);        //��������ĸ���
    int i=0;
    for (i=0; i<nMax; ++i)
        pnCount[i]=0;
    for (i=0; i<nLen; ++i)  //��ʼ����������
        ++pnCount[npIndex[i]];
    for (i=1; i<10; ++i) //ȷ�������ڸ�λ�õĸ�����
        pnCount[i] +=pnCount[i-1];

    int * pnSort =(int*)malloc(sizeof(int) * nLen);    //�����ʱ����������
    for (i=nLen-1; i>=0; --i)//i�Ǵ�nLen-1��0��˳������ģ���Ϊ��ʹ�����ȶ���
    {
        --pnCount[npIndex[i]];//ȷ��ȷ�������ڸ����ĸ�����--��ʾ������һ����ʾΪ��0��ʼ��
        pnSort[pnCount[npIndex[i]]]=A[i];//��A[i]��ֵд�ڶ�Ӧ��Ͱ�ʵ��һ������
    }
    for (i=0; i<nLen; ++i)      //������ṹ���뵽���ص������С�
        A[i] = pnSort[i];

    free(pnSort);   //�ͷ�
    free(pnCount);
    return 1;
}

int RadixSort(int* A, int nLen)//��������
{
    int *ARadix=(int *)malloc(sizeof(int) *nLen);//�����Ż����Ŀռ�
    int nRadixBase=1,i;    //��ʼ����������Ϊ1
    int nIsOk=0;         //�����������Ϊfalse
    while (nIsOk==0)//ѭ����ֱ���������
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
        if (nIsOk==1)        //������еĻ�����Ϊ0����Ϊ������ɣ������Ѿ��жϵ����λ�ˡ�
            break;
        RadixCountSort(ARadix, 10, A, nLen);
    }
    free(ARadix);
    return 1;
}
*/

