#pragma once
#include<vector>
double get_prob();
int RouletteWheelSelection(int size);
int get_num();
int get_num(int size);
void get_Order(int& p1, int& p2);
void disturb(int* a, int n);
int get_Neighbor(int p1);
void get_Type(int p1, int p2);
void disturb2(std::vector<int> &a, int n);