#ifndef OBJECTDETECTOR_H
#define OBJECTDETECTOR_H

#include <QString>

#include "edgedetection.h"
#include "colordetection.h"

class ObjectDetector
{
public:
    ObjectDetector();
    void run();

private:
    EdgeDetection edgeFinder;
    ColorDetection colorFinder;
};

#endif // OBJECTDETECTOR_H
