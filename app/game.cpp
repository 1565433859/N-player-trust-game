#include<vector>
#include<unordered_set>
#include<iostream>
#include"global.h"
#include"game.h"
#include"para.h"
#include"RandFunc.h"

using namespace std;

//void interact() {
//	for (int i = 0; i < N; i++) {
//		vector<int>nums(players[i].weight+1, 0);
//		vector<unordered_set<int>>type_set(3);
//		vector<int>type_num(3, 0);
//		double inveset_num = 0;
//		type_num[players[i].type]++;
//		type_set[players[i].type].insert(i);
//		for (int j = 0; j < players[i].weight;j++) {
//			int index = players[i].neighbor[j];
//			type_num[players[index].type]++;
//			type_set[players[index].type].insert(index);
//		}
//
//		if (type_num[2] == 0 || type_num[2] == (players[i].weight + 1)) {
//			continue;
//		}
//
//		inveset_num = pow((double)type_num[0] / (players[i].weight + 1-type_num[2]), fac);
//
//		/*if (ge((double)type_num[0] / (players[i].weight + 1 - type_num[2]), act_stra))inveset_num = fund;
//		else inveset_num = 0;*/
//
//		for (int j = 0; j < 3; j++) {
//			for (auto const index : type_set[j]) {
//				if (j == 0)players[index].profit = players[index].profit + ((double)inveset_num * Rt * type_num[2]  ) / (players[i].weight + 1 - type_num[2]);
//				if (j == 1)players[index].profit = players[index].profit + ((double)inveset_num * Ru * type_num[2] ) / (players[i].weight + 1 - type_num[2]);
//				else players[index].profit = players[index].profit + (Rt * type_num[0] * (double)inveset_num) / (players[i].weight + 1 - type_num[2]) - inveset_num;
//			}
//		}
//	}
//
//}

void interact() {
	for (int i = 0; i < N; i++) {
		if (players[i].weight == 0)continue;
		vector<int>nums(players[i].weight + 1, 0);
		vector<unordered_set<int>>type_set(3);
		vector<int>type_num(3, 0);
		double inveset_num = 0;
		type_num[players[i].type]++;
		type_set[players[i].type].insert(i);
		for (int j = 0; j < players[i].weight; j++) {
			int index = players[i].neighbor[j];
			type_num[players[index].type]++;
			type_set[players[index].type].insert(index);
		}

		if (type_num[2] == 0 || type_num[2] == (players[i].weight + 1)) {
			continue;
		}

		inveset_num = pow((double)type_num[0] / (players[i].weight + 1), fac);

		/*if (ge((double)type_num[0] / (players[i].weight + 1), act_stra))inveset_num = fund;
		else inveset_num = 0;*/

		if (players[i].type == 0)players[i].profit += ((double)inveset_num * Rt * type_num[2]) / (players[i].weight + 1 - type_num[2]);
		else if (players[i].type == 1)players[i].profit += ((double)inveset_num * Ru * type_num[2]) / (players[i].weight + 1 - type_num[2]);
		else  players[i].profit += ((Rt * type_num[0] * (double)inveset_num) / (players[i].weight + 1 - type_num[2]) - inveset_num);
						
	}

}

void update_strategy() {
	vector<Player>off_players;
	off_players = players;
	//cout << "max_type = "<<max_type << "  min_type = " << min_type << endl;
	
	for (int i = 0; i < N; i++) {
		if (players[i].weight == 0)continue;
		int be_simu = get_Neighbor(i);
		if (players[i].profit >= players[be_simu].profit)continue;
		double pro_change = (players[be_simu].profit - players[i].profit) / (max_profit - min_profit);
		if (ge(pro_change, get_prob())) {
			players[i].type = off_players[be_simu].type;
		}
	}
	
	for (int i = 0; i < N; i++) {
		players[i].profit = 0;
	}
}
