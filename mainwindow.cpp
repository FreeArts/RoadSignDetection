#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>
#include <iostream>

#include "objectdetector.h"

using namespace cv;
using namespace std;

//---------------------------
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ObjectDetector detector;
    detector.run();
}


MainWindow::~MainWindow()
{
    delete ui;
}
//-----------------------
