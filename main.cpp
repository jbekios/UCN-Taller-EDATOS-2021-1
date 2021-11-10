//
// Created by jbekios on 11/10/21.
//

#include <iostream>
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"

#include <stdio.h>

using namespace std;
using namespace cv;

int main( )
{
    Mat image;
    Mat image_gray;
    image = imread("data/caras.jpg", IMREAD_COLOR);

    CascadeClassifier face_cascade;

    face_cascade.load( "classifiers/haarcascade_frontalface_alt.xml" );

    // Detect faces
    std::vector<Rect> faces;
    cvtColor(image, image_gray, COLOR_BGR2GRAY);
    equalizeHist(image_gray, image_gray);
    face_cascade.detectMultiScale( image_gray, faces, 1.05, 4, 0|CASCADE_SCALE_IMAGE, Size(50, 50) );

    for( int i = 0; i < faces.size(); i++ ){
        Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
        //ellipse( image, center, Size( faces[i].width/2, faces[i].height/2), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
        rectangle(image,Point (faces[i].x,faces[i].y),Point (faces[i].x+faces[i].width, faces[i].y+faces[i].height),Scalar(255,0,255),4,8,0);
    }

    imshow( "Detected Face", image );

    waitKey(0);
    return 0;
}


