#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

int main()
{
    Mat image;
    Mat imgray;
    image = imread("../share/lenna.jpeg", CV_LOAD_IMAGE_COLOR);   // Read the file

    cvtColor(image, imgray, CV_BGR2GRAY);

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    vector<Point2f> corners;

    goodFeaturesToTrack(imgray,corners,100,0.01,10,noArray(),3,false,0.04);

    for( int i = 0; i < corners.size(); i++ ){
        Vec3b color = image.at<Vec3b>(corners[i]);
        color[1]=255;
        color[2]=0;
        color[3]=0;
        image.at<Vec3b>(corners[i]) = color;
    }

    namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window", image );                   // Show our image inside it.

    waitKey(0);                                          // Wait for a keystroke in the window
    return 0;
}
