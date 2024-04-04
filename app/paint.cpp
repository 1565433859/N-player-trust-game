#define _CRT_SECURE_NO_WARNINGS

#include<opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include"global.h"
#include"para.h"
using namespace std;
using namespace cv; //包含cv命名空间

cv::Scalar colors[] = { (0,255,0),(0,0,255),(255,0,0) };

void pain_image(Mat& image, int order, int colornum) {

    int x = order % 32;
    int y = order / 32;
    cv::Point pts[4];
    pts[0] = cv::Point(10 + x * 20, 10 + y * 20);
    pts[1] = cv::Point(30 + x * 20, 10 + y * 20);
    pts[2] = cv::Point(30 + x * 20, 30 + y * 20);
    pts[3] = cv::Point(10 + x * 20, 30 + y * 20);

    // 组织多边形数据
    const cv::Point* polygons[1] = { pts };
    int num_pts[] = { 4 };

    // 填充多边形
    if (colornum == 0)cv::fillPoly(image, polygons, num_pts, 1, cv::Scalar(0, 225, 0));
    else if(colornum==1)cv::fillPoly(image, polygons, num_pts, 1, cv::Scalar(0, 0, 255));
    else cv::fillPoly(image, polygons, num_pts, 1, cv::Scalar(255, 0, 0));
    
    

}

void paint(int order) {
    cv::Mat image(800, 800, CV_8UC3, cv::Scalar(255, 255, 255)); // 创建一个白色图像
    for (int i = 0; i < N; i++) {
        pain_image(image, i, players[i].type);
    }

    cv::imshow("filledRectangle", image);
    char file[140];
    sprintf(file, "J:\\数据\\信任博弈\\图上的多人信任博弈_异质投资\\不同图\\RE4\\异质投资\\异质指数0\\result7\\paint%d.png", order);
    imwrite(file, image);
    cv::waitKey(0);
    cv::destroyAllWindows();
}

