#define _CRT_SECURE_NO_DEPRECATE
#include <fstream>
#include<iostream>
#include<stdio.h>
using namespace std;
int main(int argc, char* argv[])
{

	int m, n;
	FILE* fp1;
	FILE* fp2;
	m = atoi(argv[2]);//命令行输入的第三个参数：宫格阶级
	n = atoi(argv[4]);//命令行输入的第五个参数：待解答盘面数目
	//cin >> m >> n;

	//以文本只读方式打开intput.txt
	fp1 = fopen("input.txt", "r");
	if (fp1 == NULL) //打开文件失败
		return -1;
	//打开output.txt，并立即关闭，目的：清空文本内容
	fp2 = fopen("output.txt", "w");
	if (fp2 == NULL) //打开文件失败
		return -1;
	fclose(fp2);//关闭文件
	int i, j, k, num, w, p, q;
	int sudoku[10][10];
	int sign[4] = { 0 };//存放行列中已经出现的数，例如：某行或列出现3，则sign[3]=1
	fp2 = fopen("output.txt", "a");
	for (num = 0; num < n; num++)
	{
		//输入表盘的二维数组
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < m; j++)
			{
				fscanf(fp1, "%d", &sudoku[i][j]);
				//cin >> sudoku[i][j];
			}

		}
		while (1)
		{
			w = 0;
			//判断表盘中是否还有未填数的空格
			for (i = 0; i < m; i++)
			{
				for (j = 0; j < m; j++)
				{
					if (sudoku[i][j] == 0)
					{
						w++;
					}

				}
			}
			if (w == 0)//表示表盘已经填完
			{
				break;
			}
			for (i = 0; i < m; i++)
			{
				for (j = 0; j < m; j++)
				{
					if (sudoku[i][j] != 0)
						continue;
					//若该空格为填入，则进行行列遍历，找到已出现的数
					if (sudoku[i][j] == 0)
					{
						//行遍历
						for (q = 0; q < 3; q++)
						{
							if (sudoku[i][q] != 0)
							{
								sign[sudoku[i][q]] = 1;
							}
						}
						//列遍历
						for (q = 0; q < 3; q++)
						{
							if (sudoku[q][j] != 0)
							{
								sign[sudoku[q][j]] = 1;
							}
						}
						p = 0;//p用于记录该空格的候选数数量
						for (q = 1; q < 4; q++)
						{
							if (sign[q] == 0)//表示该空格所在行列中均没有q
							{
								p++;
								k = q;
							}
						}
					}
					if (p == 1)
					{
						sudoku[i][j] = k;
					}
					//初始化sign[]
					for (q = 0; q < 4; q++)
					{
						sign[q] = 0;
					}
				}
			}

		}
		//输出完整表盘
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				fprintf(fp2, "%d ", sudoku[i][j]);
				if (j == 2)
					fprintf(fp2, "\n");
			}
		}
		fprintf(fp2, "\n");
	}
	return 0;
}