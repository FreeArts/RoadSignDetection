#ifndef EDGEDETECTION_H
#define EDGEDETECTION_H

#include <QString>

#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>
#include <iostream>

using namespace cv;
using namespace std;

class EdgeDetection
{
public:
    EdgeDetection();

    void findTriangle(QString src_path);
    void findCircle(QString src_path);
    void findStop(QString src_path);
private:
    void triangle();
    void drawAllTriangles(Mat& img, const vector< vector<Point> >& contours);

    void stop();
    void drawStopSign(Mat& img, const vector< vector<Point> >& contours);

};

#endif // EDGEDETECTION_H
