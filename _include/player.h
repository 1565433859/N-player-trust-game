#pragma once
#include<vector>
class Player {
public:
	double					profit;			//博弈时的累计收益
	int						weight;			//当前点的度数和，也可以看成是权重
	double					chose_prob;		//被选中的概率
	int						type;			//每代博弈时的个体角色，分为
	std::vector<int>		neighbor;
	Player();

	int action();
};