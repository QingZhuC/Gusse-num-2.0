#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void menu()//��ʼ�˵�
{
	printf("###################################\n");
	printf("####      �Ƿ�ʼ�����֣�     ####\n");
	printf("####          1.��ʼ           ####\n");
	printf("####          0.����           ####\n");
	printf("###################################\n");
}

void rule()//����
{
	printf("�������£�\n");
	printf("������Ҫ������ʾ�ֶ�����һ���ұ߽�\n");
	printf("Ȼ�������������һ��1~n��Χ�ڵ����������߽�ֵ��\n");
	printf("�����������\n");
	printf("����Ҫ��С�������뷶Χ��1~21�ڣ�\n");
}
int times(int x)//�����Ҫ����
{
	int n = 0;
	while (pow(2, n) <= x)
		n++;
	return n;
}
int game(int left,long long right)//����
{
	int chh = 0;//����
	long long mid = (left + right) / 2;//�м�ֵ
	if (left <= right)//���ַ�
	{
		printf("�Ƿ���%d?\n1.�´���\t2.��С��\t3.�¶���\n������:", mid);
		scanf("%d", &chh);
		switch (chh)
		{
		case 1:
			return 1 + game(left, mid - 1);
		case 2:
			return 1 + game(mid + 1, right);
		case 3:
			return 1;
		default:
			printf("��Ҫ�Ҹ�����/remake��\n");
			return 0;
		}
		
	}
	else
	{
		printf("\n�ţ��ոգ���˵���˰գ��գ�\n");
		return 0;
	}

}

int main()
{
	
	int ch = 0;//����
	do
	{
		int left = 1;//��ʼ����߽�
		int right = 1;//��ʼ���ұ߽�
		menu();//��ʼ�˵�
		printf("�����룺");
		scanf("%d", &ch);
		switch (ch)//�������
		{
		case 1://��Ϸ��ʼ
			system("cls");//����
			rule();//����
			printf("�������ұ߽磺");
			scanf("%d", &right);
			
			printf("\n�����Ҫ%d�β³������\n\n", times(right));
			printf("����%d��\n", game(left, right));
			break;
		case 0://�˳�����
			break;
		default://��ʾ�������
			printf("��������\n");
			break;
		}
	} while (ch);
}

