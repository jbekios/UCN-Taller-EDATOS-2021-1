//
// Created by jbekios on 11/10/21.
//

#include <iostream>
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"

#include "include/FaceDetector.hpp"
#include "include/ImageCoding.hpp"

using namespace std;
using namespace cv;

int main( )
{
    cout << "Para salir del programa presione ESC o q(uit)." << endl;

    Mat image;

    image = imread("data/caras.jpg", IMREAD_COLOR);

    FaceDetector fdetector;
    ImageCoding icoding;

    auto facesMarkers = fdetector.detectFaceRectangles(image);

    Scalar color(0, 0, 255);

    Mat cropColor;
    Mat imageGray;
    Mat resizedDown;

    // Codifico las caras detectadas
    icoding.setImage(image);
    auto faceCodingGray = icoding.codeGray(facesMarkers, true, Size(60,60));

    // Muestro las caras codificadas
    for(const auto &cf : faceCodingGray){
        imshow("Imagen Codificida", cf);
        waitKey(0);
    }

    // Comparar las distancias entre imágenes
    Mat img1 = faceCodingGray[0];
    int sum = 1;
    for(const auto &cf : faceCodingGray){
        double dist = norm(img1, cf,NORM_L2);
        cout << "Comparación imagen 1 con imagen " << sum << ":" << dist << endl;
        sum++;
    }

    //Muestro las caras encontradas en la imaggen original
    for(const auto &fm : facesMarkers){
        rectangle(image, fm, color, 4);
    }

    // Mostrar la imagen con las marcas (rectángulos) indicando la posición de la cara
    imshow( "Detected Face", image );

    // Esperar hasta presionar la tecla ESC
    while(true){
        int pressKey = waitKey(100);
        if (pressKey == 27 || pressKey == 113) break;
    }

    destroyAllWindows();

    return 0;
}


