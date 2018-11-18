#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>
#include <iostream>

using namespace cv;
using namespace std;

void drawStuff();
void drawAllTriangles(Mat&, const vector< vector<Point> >&);

Mat img_rgb,img_gray,canny_output,drawing;

int thresh = 100;
int max_thresh = 255;
//---------------------------
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    circule();
    triangle();

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::circule()
{

    Mat src, src_gray;

    /// Read the image
    //src = imread("/home/freeart/test/traffic-signs.jpg");
    src = imread("/home/freeart/test/triangle_circle.jpg");
    //imshow("original",src);

    cvtColor( src, src_gray, COLOR_BGR2GRAY );
    //imshow("gray?",src_gray);

    GaussianBlur( src_gray, src_gray, Size(9, 9), 3, 3 ); //???
    //imshow("gaus?",src_gray);

    vector<Vec3f> circles;
    HoughCircles( src_gray, circles, HOUGH_GRADIENT, 1, src_gray.rows/8, 200, 100, 0, 0 ); //???

    for( size_t i = 0; i < circles.size(); i++ )
      {
          Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
          int radius = cvRound(circles[i][2]);
          // circle center
          circle( src, center, 3, Scalar(0,255,0), -1, 8, 0 );
          // circle outline
          circle( src, center, radius, Scalar(0,0,255), 3, 8, 0 );
       }
    namedWindow( "Hough Circle Transform Demo", WINDOW_AUTOSIZE );
    imshow( "Hough Circle Transform Demo", src );

    waitKey(0);
}

void MainWindow::triangle()
{
    //img_rgb  = imread("/home/freeart/test/traffic-signs.jpg");
    img_rgb = imread("/home/freeart/test/triangle_circle.jpg");
    cvtColor(img_rgb,img_gray,COLOR_RGB2GRAY);
    imshow("InputImage",img_rgb);
    drawStuff();
    waitKey(0);
}
//-----------------------
void drawStuff(){
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;

    Canny( img_gray, canny_output, thresh, thresh*2, 3 ); //??
    imshow("Canny",canny_output);
    findContours( canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0) );
    drawing = Mat::zeros( canny_output.size(), CV_8UC3 );

    drawAllTriangles(drawing,contours);
    imshow("Triangles",drawing);
}

void drawAllTriangles(Mat& img, const vector< vector<Point> >& contours){
    vector<Point> approxTriangle;
    for(size_t i = 0; i < contours.size(); i++){
        approxPolyDP(contours[i], approxTriangle, arcLength(Mat(contours[i]), true)*0.05, true);
        if(approxTriangle.size() == 3){
            drawContours(img, contours, i, Scalar(0, 255, 255), FILLED); // fill GREEN
            vector<Point>::iterator vertex;
            for(vertex = approxTriangle.begin(); vertex != approxTriangle.end(); ++vertex){
                circle(img, *vertex, 3, Scalar(0, 0, 255), 1);
            }
        }
    }
}
