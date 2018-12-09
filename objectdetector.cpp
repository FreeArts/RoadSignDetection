#include "objectdetector.h"

ObjectDetector::ObjectDetector()
{

}

void ObjectDetector::run()
{
    edgeFinder.findCircle("/home/freeart/git/RoadSignDetection/traffic-signs.jpg");
    edgeFinder.findTriangle("/home/freeart/git/RoadSignDetection/traffic-signs.jpg");
    edgeFinder.findStop("/home/freeart/git/RoadSignDetection/stop.jpg");

    colorFinder.findredCircule("/home/freeart/git/RoadSignDetection/traffic-signs.jpg");
    colorFinder.findredCircule("/home/freeart/git/RoadSignDetection/stop.jpg");
}
