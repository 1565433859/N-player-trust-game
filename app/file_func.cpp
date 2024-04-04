#include"FileFunc.h"
#include"global.h"
#include"para.h"
#include<iostream>
#include<fstream>


void get_degree_distribution() {
	ofstream outfile1("J:\\数据\\信任博弈\\图上的多人信任博弈_异质投资\\degree_distribution.txt", ios::trunc);
	if (outfile1.is_open() == false) {
		cout << "get_degree_distribution()中的degree_distribution.txt 文件打开失败!" << endl;
		return;
	}

	vector<int>degree(N,0);
	for (int i = 0; i < N; i++) {
		degree[players[i].weight]++;
	}
	for (int i = 0; i < N; i++) {
		outfile1 << degree[i] << endl;
	}
	outfile1.close();
}

void get_type_distribution() {
	ofstream outfile0("J:\\数据\\信任博弈\\图上的多人信任博弈_异质投资\\type_distribution.txt", ios::app);

	ofstream outfile1("J:\\数据\\信任博弈\\图上的多人信任博弈_异质投资\\type_t.txt", ios::app);
	ofstream outfile2("J:\\数据\\信任博弈\\图上的多人信任博弈_异质投资\\type_u.txt", ios::app);
	ofstream outfile3("J:\\数据\\信任博弈\\图上的多人信任博弈_异质投资\\type_i.txt", ios::app);
	if (outfile0.is_open() == false) {
		cout << "get_degree_distribution()中的degree_distribution.txt 文件打开失败!" << endl;
		return;
	}

	vector<int>type(3, 0);
	for (int i = 0; i < N; i++) {
		type[players[i].type]++;
	}
	sum_i = type[2];
	if (!is_first) {
		outfile0 << endl;
		outfile1 << endl;
		outfile2 << endl;
		outfile3 << endl;
	}
	is_first = false;
	outfile0 << type[0] << "  ";
	outfile0 << type[1] << "  ";
	outfile0 << type[2];
	outfile1 << type[0];
	outfile2 << type[1];
	outfile3 << type[2];
	outfile0.close();
	outfile1.close();
	outfile2.close();
	outfile3.close();
}

void set_xticks() {
	ofstream outfile1("J:\\数据\\信任博弈\\图上的多人信任博弈_异质投资\\xticks.txt", ios::trunc);
	if (outfile1.is_open() == false) {
		cout << "get_degree_distribution()中的degree_distribution.txt 文件打开失败!" << endl;
		return;
	}

	vector<int>type(3, 0);
	for (int i = 1; i <= x_ticks; i++) {
		outfile1 << endl << i;
	}
	outfile1.close();
}

void get_wealth() {
	ofstream outfile1("J:\\数据\\信任博弈\\图上的多人信任博弈_异质投资\\wealth.txt", ios::app);
	if (outfile1.is_open() == false) {
		cout << "get_degree_distribution()中的degree_distribution.txt 文件打开失败!" << endl;
		return;
	}

	double income = 0;
	for (int i = 0; i < N; i++) {
		income += players[i].profit;
	}
	if (!is_first2) {
		outfile1 << endl;
	}
	is_first2 = false;
	outfile1 << income;
	outfile1.close();
}

void get_aver_wealth() {

	double income[3] = { 0 };
	int count[3] = { 0 };
	for (int i = 0; i < N; i++) {
		income[players[i].type] += players[i].profit;
		count[players[i].type]++;
	}
	cout << "T_income = " << income[0] / count[0] << "  U_income = " << income[1] / count[1] << "  I_income = " << income[2] / count[2] << endl;
}