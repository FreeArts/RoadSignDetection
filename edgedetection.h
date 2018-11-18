#ifndef EDGEDETECTION_H
#define EDGEDETECTION_H

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

    void findTriangle();
    void findCircle();

private:
    void drawStuff();
    void drawAllTriangles(Mat& img, const vector< vector<Point> >& contours);
};

#endif // EDGEDETECTION_H
