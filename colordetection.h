#ifndef COLORDETECTION_H
#define COLORDETECTION_H

#include <QString>
#include <QObject>

#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>
#include <iostream>

class ColorDetection
{
public:
    ColorDetection();
    void findredCircule(QString picturePath);

private:

};

#endif // COLORDETECTION_H
