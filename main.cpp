//
// Created by jbekios on 11/10/21.
//

#include <iostream>
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"

#include "include/FaceDetector.hpp"

using namespace std;
using namespace cv;

int main( )
{
    cout << "Pasé" << endl;
    Mat image;


    image = imread("data/caras.jpg", IMREAD_COLOR);


    FaceDetector fdetector;

    auto markersFaces = fdetector.detectFaceRectangles(image);

    Scalar color(0, 0, 255);
    for(const auto &mf : markersFaces){
        rectangle(image, mf, color, 4);
    }

    // Mostrar la imagen con las marcas (rectángulos) indicando la posición de la cara
    imshow( "Detected Face", image );
    cout << "Pasé2" << endl;

    // Esperar hasta presionar la tecla ESC
    if (waitKey(0) == 27);

    destroyAllWindows();

    return 0;
}


