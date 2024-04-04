#define _CRT_SECURE_NO_WARNINGS

#include<opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include"global.h"
#include"para.h"
using namespace std;
using namespace cv; //����cv�����ռ�

cv::Scalar colors[] = { (0,255,0),(0,0,255),(255,0,0) };

void pain_image(Mat& image, int order, int colornum) {

    int x = order % 32;
    int y = order / 32;
    cv::Point pts[4];
    pts[0] = cv::Point(10 + x * 20, 10 + y * 20);
    pts[1] = cv::Point(30 + x * 20, 10 + y * 20);
    pts[2] = cv::Point(30 + x * 20, 30 + y * 20);
    pts[3] = cv::Point(10 + x * 20, 30 + y * 20);

    // ��֯���������
    const cv::Point* polygons[1] = { pts };
    int num_pts[] = { 4 };

    // �������
    if (colornum == 0)cv::fillPoly(image, polygons, num_pts, 1, cv::Scalar(0, 225, 0));
    else if(colornum==1)cv::fillPoly(image, polygons, num_pts, 1, cv::Scalar(0, 0, 255));
    else cv::fillPoly(image, polygons, num_pts, 1, cv::Scalar(255, 0, 0));
    
    

}

void paint(int order) {
    cv::Mat image(800, 800, CV_8UC3, cv::Scalar(255, 255, 255)); // ����һ����ɫͼ��
    for (int i = 0; i < N; i++) {
        pain_image(image, i, players[i].type);
    }

    cv::imshow("filledRectangle", image);
    char file[140];
    sprintf(file, "J:\\����\\���β���\\ͼ�ϵĶ������β���_����Ͷ��\\��ͬͼ\\RE4\\����Ͷ��\\����ָ��0\\result7\\paint%d.png", order);
    imwrite(file, image);
    cv::waitKey(0);
    cv::destroyAllWindows();
}

