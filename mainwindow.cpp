#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>
#include <iostream>

#include "edgedetection.h"

using namespace cv;
using namespace std;

//---------------------------
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    EdgeDetection work;
    ui->setupUi(this);

    work.findCircle();
    work.findTriangle();
    work.findStop();
}


MainWindow::~MainWindow()
{
    delete ui;
}
//-----------------------
