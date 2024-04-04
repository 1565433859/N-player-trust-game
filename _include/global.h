#pragma once
#include<vector>
#include<functional>
#include"player.h"
using namespace std;

extern vector<vector<int>>	 Graph;
extern vector<Player>		 players;
extern greater_equal<double> ge;			//比较器
extern int					 sum_degree;	//度数和
extern int					 x_ticks;
extern int					 sum_i;			//cc策略个体数量
extern bool					 is_first;
extern bool					 is_first2;
extern double				 min_profit;
extern double				 max_profit;