#include"RandFunc.h"
#include<random>
#include"global.h"
#include"para.h"
#include<iostream>
double get_prob() {
	/*double random[100];
	for (int i = 0; i < 100; i++) {
		random[i] = rand() % 10000 / (double)10000;
	}
	return random[rand() % 100];*/
    return rand() % 10000 / (double)10000;
}

//轮盘赌概率选择一个连接的节点i
int RouletteWheelSelection(int size) {

    //产生一个[0,1)的随机值
    double prob = get_prob();
    double Probability_Total = 0;
    int Selection = 0;
    for (int i = 0; i < size; i++) {//SIZE是个体数量的大小
        Probability_Total = Probability_Total + players[i].chose_prob;
        if (Probability_Total >= prob) {
            Selection = i;
            break;
        }
    }
    return Selection;
}

int get_num() {
    return rand() % N;
}

int get_num(int size) {
    return rand() % size;
}

void get_Order(int& p1, int& p2) {
	p1 = get_num();
    while ((p2 = get_num()) == p1);
}

int get_Neighbor(int p1) {
	int index = get_num(players[p1].neighbor.size());
	return players[p1].neighbor[index];
}

void get_Type(int p1, int p2) {
	players[p1].type = get_num(2);
	players[p2].type = 1 - players[p1].type;
}

void disturb(int* a, int n) { //将数组打乱
	int index;
	int temp;
	for (int i = n - 1; i > 0; i--) {
		index = rand() % i;  //generate random index 0<=index<i
		if (i != index) {
			temp = a[i];
			a[i] = a[index];
			a[index] = temp;
		}
	}
}

void disturb2(vector<int> &a, int n) { //将数组打乱
	int index;
	int temp;
	for (int i = n - 1; i > 0; i--) {
		index = rand() % i;  //generate random index 0<=index<i
		if (i != index) {
			temp = a[i];
			a[i] = a[index];
			a[index] = temp;
		}
	}
}