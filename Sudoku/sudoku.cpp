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
	m = atoi(argv[2]);//����������ĵ���������������׼�
	n = atoi(argv[4]);//����������ĵ���������������������Ŀ
	//cin >> m >> n;

	//���ı�ֻ����ʽ��intput.txt
	fp1 = fopen("input.txt", "r");
	if (fp1 == NULL) //���ļ�ʧ��
		return -1;
	//��output.txt���������رգ�Ŀ�ģ�����ı�����
	fp2 = fopen("output.txt", "w");
	if (fp2 == NULL) //���ļ�ʧ��
		return -1;
	fclose(fp2);//�ر��ļ�
	int i, j, k, num, w, p, q;
	int sudoku[10][10];
	int sign[4] = { 0 };//����������Ѿ����ֵ��������磺ĳ�л��г���3����sign[3]=1
	fp2 = fopen("output.txt", "a");
	for (num = 0; num < n; num++)
	{
		//������̵Ķ�ά����
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
			//�жϱ������Ƿ���δ�����Ŀո�
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
			if (w == 0)//��ʾ�����Ѿ�����
			{
				break;
			}
			for (i = 0; i < m; i++)
			{
				for (j = 0; j < m; j++)
				{
					if (sudoku[i][j] != 0)
						continue;
					//���ÿո�Ϊ���룬��������б������ҵ��ѳ��ֵ���
					if (sudoku[i][j] == 0)
					{
						//�б���
						for (q = 0; q < 3; q++)
						{
							if (sudoku[i][q] != 0)
							{
								sign[sudoku[i][q]] = 1;
							}
						}
						//�б���
						for (q = 0; q < 3; q++)
						{
							if (sudoku[q][j] != 0)
							{
								sign[sudoku[q][j]] = 1;
							}
						}
						p = 0;//p���ڼ�¼�ÿո�ĺ�ѡ������
						for (q = 1; q < 4; q++)
						{
							if (sign[q] == 0)//��ʾ�ÿո����������о�û��q
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
					//��ʼ��sign[]
					for (q = 0; q < 4; q++)
					{
						sign[q] = 0;
					}
				}
			}

		}
		//�����������
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