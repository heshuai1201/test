#include<iostream>
using namespace std;

class Dijkstra
{
public:
	Dijkstra() {
		for (size_t i = 0; i < 9; i++){
			for (int j = 0;j < 9; j++){
				weight[i][j] = 200;
			}
		}
		weight[0][1] = 4;
		weight[0][7] = 8;

		weight[1][7] = 11;
		weight[1][2] = 8;

		weight[2][3] = 7;
		weight[2][5] = 4;
		weight[2][8] = 2;

		weight[3][5] = 14;
		weight[3][4] = 9;

		weight[4][5] = 10;

		weight[6][5] = 2;
		weight[6][8] = 6;
		weight[6][7] = 1;

		weight[7][8] = 7;
		
		for (size_t i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (weight[i][j] != 200)
				{
					weight[j][i] = weight[i][j];
					if (i==j)
					{
						weight[i][j] = 0;
					}
				}
			}
		}
	}
	void  chushihua() {
		//0��ʼ
		for (int i = 0; i < 9; i++)
		{
			dist[i] =weight[0][i];
			is[i] = -1;//ȫ��û�з���
			if (dist[i]<200)
			{
				path[i] = 0;
			}
			else
			{
				path[i] = -1;
			}
		}
		is[0] = 1;//��ʼ�ڵ��ѷ���
		dist[0] = 0;
		int  minindex = 0;
		for (int i = 0; i < 9-1; i++)
		{
			//Ѱ��û�б����ʵģ���������dist������С
			minindex = semin();
			for (int j = 0;j<9; j++)
			{
				if (is[j]==-1 && weight[minindex][j]<200 && 
					(dist[minindex]+weight[minindex][j]<dist[j]))
				{
					dist[j] = dist[minindex] + weight[minindex][j];
					path[j] = minindex;
				}

			}
		}
	}
	int semin() {//��ǰ�������Сֵdist
		int  min = 100;
		int  index=0;
		for (int i = 0; i < 9; i++)
		{
			if (is[i]!=1)//δ����
			{
				if (dist[i]<min)
				{
					min = dist[i];
					index = i;
				}
			}
		}
		cout <<"��Сֵ" << min<<" "<<"�±�"<<index;
		getchar();
		is[index] = 1;
		return index;	
	}
	void  show() {
		for (int i = 0; i < 9; i++)
		{
			cout << dist[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < 9; i++)
		{
			cout << path[i]<<" ";
		}
		cout << endl;
	}

private:
	//5*5�ľ���
	int  weight[9][9];
	int  path[9];
	int	 dist[9];
	int  is[9];
};

int  main() {
	Dijkstra p;
	p.chushihua();
	p.show();
	return 0;
}