#pragma once
#include<vector>
class Player {
public:
	double					profit;			//����ʱ���ۼ�����
	int						weight;			//��ǰ��Ķ����ͣ�Ҳ���Կ�����Ȩ��
	double					chose_prob;		//��ѡ�еĸ���
	int						type;			//ÿ������ʱ�ĸ����ɫ����Ϊ
	std::vector<int>		neighbor;
	Player();

	int action();
};