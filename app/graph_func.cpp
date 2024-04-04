#include<unordered_set>
#include<fstream>
#include<iostream>
#include"GraphFunc.h"
#include"para.h"
#include"global.h"
#include"player.h"
#include"RandFunc.h"
using namespace std;

void init_graph() {
	int type_num[4] = {0};
	vector<int>order(N);
	for (int i = 0; i < N; i++) {
		order[i] = i;
		Player pl;
		pl.type = get_num(3);
		players.push_back(pl);
	}
	disturb2(order, N);
	for (int i = 0; i < 256; i++) {
		players[order[i]].type = 0;
	}
	for (int i = 256; i <563; i++) {
		players[order[i]].type = 2;
	}
	for (int i = 563; i < 1024; i++) {
		players[order[i]].type = 1;
	}
	

	ifstream infile("SF6.txt");
	if (infile.is_open()) {
		int index1, index2;
		while (infile>>index1>>index2) {
			players[index1].weight++;
			players[index1].neighbor.push_back(index2);
			players[index2].neighbor.push_back(index1);
			players[index2].weight++;
			sum_degree += 2;
			Graph[index1][index2] = 1;
			Graph[index2][index1] = 1;
		}
	}
	int a = 10;
	
}

void create_Random_Graph(){
	for (int i = 0; i < N; i++) {
		Player pl;
		pl.type = get_num(3);
		players.push_back(pl);
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			double prob = get_prob();
			if (ge(prob, rand_m)) {
				players[i].weight++;
				players[j].weight++;
				sum_degree += 2;
				Graph[i][j] = 1;
				Graph[j][i] = 1;
				players[i].neighbor.push_back(j);
				players[j].neighbor.push_back(i);
			}
		}
		/*if (players[i].weight == 0) {
			int order;
			while ((order = rand() % m0) != i);
			Graph[i][order] = 1;
			Graph[order][i] = 1;
			players[i].weight++;
			players[order].weight++;
			sum_degree += 2;
		}*/
	}
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (players[i].weight < 4) {
			for (int j = 0; j < N; j++) {
				if (Graph[i][j] == 0 && i != j) {
					Graph[i][j] = 1;
					Graph[j][i] = 1;
					players[i].neighbor.push_back(j);
					players[j].neighbor.push_back(i);
					players[i].weight++;
					players[j].weight++;
					count++;
				}
			}
		}
	}
	cout << count << endl;
}


void create_Graph() {
	init_graph();
	
	for (int i = m0; i < N; i++) {
		unordered_set<int>add_set;
		for (int j = 0; j < m; j++) {
			int m1;
			while (1) {
				m1 = RouletteWheelSelection(i);
				if (add_set.count(m1) == 0) {
					add_set.insert(m1);
					break;
				}
			}
			Graph[i][m1] = 1;
			Graph[m1][i] = 1;
			players[i].neighbor.push_back(m1);
			players[m1].neighbor.push_back(i);
			players[i].weight++;
			players[m1].weight++;
			sum_degree += 2;
		}
		update_weight(i + 1);
	}

	int count = 0;
	for (int i = 0; i < N; i++) {
		int j = 0;
		while (players[i].weight < 4) {
			for (; j < N; j++) {
				if (Graph[i][j] == 0 && i != j) {
					Graph[i][j] = 1;
					Graph[j][i] = 1;
					players[i].neighbor.push_back(j);
					players[j].neighbor.push_back(i);
					players[i].weight++;
					players[j].weight++;
					count++;
				}
			}
		}
	}
	//cout << count << endl;
}

void update_weight(int size) {
	for (int i = 0; i < size; i++) {
		players[i].chose_prob = players[i].weight / (double)sum_degree;
	}
}