#include<vector>
#include<functional>
#include<random>
#include<fstream>
#include<iostream>
#include"para.h"
#include"player.h"
#include"GraphFunc.h"
#include"FileFunc.h"
#include"game.h"
#include"paint.h"
using namespace std;

vector<vector<int>>Graph(N,vector<int>(N,0));
vector<Player>players;
int sum_degree = 0;
int sum_i;
greater_equal<double>ge;
int x_ticks=0;
bool is_first=true;
bool is_first2=true;
double min_profit = -1;
double max_profit = Ru * ((double)sum_degree/N) * 1;


int main() {
	
	srand((unsigned)time(NULL));
	ofstream outfile1("J:\\数据\\信任博弈\\图上的多人信任博弈_异质投资\\type_distribution.txt", ios::trunc);
	ofstream outfile2("J:\\数据\\信任博弈\\图上的多人信任博弈_异质投资\\type_i.txt", ios::trunc);
	ofstream outfile3("J:\\数据\\信任博弈\\图上的多人信任博弈_异质投资\\type_t.txt", ios::trunc);
	ofstream outfile4("J:\\数据\\信任博弈\\图上的多人信任博弈_异质投资\\type_u.txt", ios::trunc);
	ofstream outfile5("J:\\数据\\信任博弈\\图上的多人信任博弈_异质投资\\wealth.txt", ios::trunc);
	//create_Random_Graph();
	//create_Graph();
	init_graph();
	get_type_distribution();
	int count = 0;
	//paint(count++);
	for (int i = 1; i <= r_num; i++) {
		sum_i = 0;
		interact();

		get_wealth();

		update_strategy();

		get_type_distribution();
		//if (i == 10 || i == 100 || i == 500 || i == 5000)paint(count++);

		x_ticks++;
		if (sum_i ==0||sum_i==N) {
			for (int j = i + 1; j <= r_num; j++) {
				//if (j == 10 || j == 100 || j == 500 || j == 5000)paint(count++);
				get_wealth();
				get_type_distribution();
			}
			break;
		}


		/*if (sum_i == 0) {
			cout << sum_i << endl;
			break;
		}*/

	}
	//cout << sum_i;
	ofstream outfile8("J:\\数据\\信任博弈\\图上的多人信任博弈_异质投资\\test.txt", ios::trunc);
	set_xticks();
	return 0;
}
