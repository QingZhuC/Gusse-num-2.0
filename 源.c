#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void menu()//开始菜单
{
	printf("###################################\n");
	printf("####      是否开始猜数字？     ####\n");
	printf("####          1.开始           ####\n");
	printf("####          0.结束           ####\n");
	printf("###################################\n");
}

void rule()//规则
{
	printf("规则如下：\n");
	printf("首先需要根据提示手动设置一个右边界\n");
	printf("然后由你来随便想一个1~n范围内的数（包括边界值）\n");
	printf("最后计算机来猜\n");
	printf("（不要输小数，输入范围是1~21亿）\n");
}
int times(int x)//最多需要次数
{
	int n = 0;
	while (pow(2, n) <= x)
		n++;
	return n;
}
int game(int left,long long right)//主体
{
	int chh = 0;//输入
	long long mid = (left + right) / 2;//中间值
	if (left <= right)//二分法
	{
		printf("是否是%d?\n1.猜大了\t2.猜小了\t3.猜对啦\n请输入:", mid);
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
			printf("不要乱搞啦，/remake吧\n");
			return 0;
		}
		
	}
	else
	{
		printf("\n呐，刚刚，你说谎了罢（恼）\n");
		return 0;
	}

}

int main()
{	
	int ch = 0;//输入
	do
	{
		int left = 1;//初始化左边界
		int right = 1;//初始化右边界
		menu();//开始菜单
		printf("请输入：");
		scanf("%d", &ch);
		switch (ch)//监测输入
		{
		case 1://游戏开始
			system("cls");//清屏
			rule();//规则
			printf("请输入右边界：");
			scanf("%d", &right);
			
			printf("\n最多需要%d次猜出这个数\n\n", times(right));
			printf("用了%d次\n", game(left, right));
			break;
		case 0://退出程序
			break;
		default://提示输入错误
			printf("输入有误！\n");
			break;
		}
	} while (ch);
	return 0;
}

