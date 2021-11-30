//
// Created by jbekios on 11/10/21.
//

#include <iostream>
#include <string>
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"



#include "include/FaceDetector.hpp"
#include "include/ImageCoding.hpp"

#include "include/BinarySearchTree.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;


int main( )
{
    cout << "Para salir del programa presione ESC o q(uit)." << endl;

    vector<string> imagesStr;
    //TODO: Cargar todos los archivos del directorio automáticamente
    imagesStr.push_back("data/image-007.jpeg");
    imagesStr.push_back("data/image-008.jpeg");
    imagesStr.push_back("data/image-024.jpeg");
    imagesStr.push_back("data/image-025.jpeg");
    imagesStr.push_back("data/image-026.jpeg");
    imagesStr.push_back("data/image-046.jpeg");
    imagesStr.push_back("data/image-047.jpeg");

    cout << "imagesStr = { ";
    for (string n : imagesStr){
        cout << n << ", ";
    }
    cout << "};" << endl;

    // Leemos todas las caras de los archivos de imágenes y las insertamos en el árbol
    BinarySearchTree abb;
    FaceDetector fdetector;
    ImageCoding icoding;
    Mat image;
    Scalar color(0, 0, 255);

    cout << "COLOR";
    for (string im : imagesStr){
        cout << im << endl;
        image = imread(im, IMREAD_COLOR);
        auto facesMarkers = fdetector.detectFaceRectangles(image);

        // Codifico las caras detectadas
        icoding.setImage(image);
        auto faceCodingGray = icoding.codeGray(facesMarkers, true, Size(25,25));
        // Muestro las caras codificadas
        Mat colorImage;
        Mat newSize;
        // Muestro las caras detectadas en la imagen original
        int widthImageInGrayColor = 40;
        int posX = 10;
        for(const auto &cf : faceCodingGray){
            // Inserto la imagen en el arbol y obtengo el identificador
            abb.insert(cf);
            // Muestro la imagen codificada en la imagen original
            cvtColor(cf, colorImage, COLOR_GRAY2BGR);
            resize(colorImage, newSize, Size(widthImageInGrayColor,widthImageInGrayColor), INTER_LINEAR);
            newSize.copyTo(image(cv::Rect(posX, 10, newSize.cols, newSize.rows)));
            posX += widthImageInGrayColor + 10;
        }
        // Para ver caras detectadas
        //Muestro las caras encontradas en la imaggen original
        for(const auto &fm : facesMarkers){
            rectangle(image, fm, color, 4);
        }
        // Mostrar la imagen con las marcas (rectángulos) indicando la posición de la cara
        imshow( "Detected Face", image );

        waitKey(0);
    }

//    // Comparar las distancias entre imágenes
//    Mat img1 = faceCodingGray[0];
//    int sum = 1;
//    for(const auto &cf : faceCodingGray){
//        double dist = norm(img1, cf,NORM_L2); // Calcular la distancia euclidia
//        cout << "Comparación imagen 1 con imagen " << sum << ":" << dist << endl;
//        sum++;
//    }
//


    // Esperar hasta presionar la tecla ESC
    while(true){
        int pressKey = waitKey(100);
        if (pressKey == 27 || pressKey == 113) break;
    }

    destroyAllWindows();

    return 0;
}


