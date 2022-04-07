#include<iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
#include <bits/stdc++.h>
#include<stdlib.h>
using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];


void loadImage () {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Please enter file name of the image to process: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

void saveImage () {

    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

void f1_black_white() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

            if (image[i][j] > 127)
                image[i][j] = 255;
            else
                image[i][j] = 0;
        }
    }
}

void f2_invert() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

            image[i][j] = 255-image[i][j];

        }
    }
}

void f3_Merge() {

    char imageFileName2[100];

    cout<<"Enter the source image file name: ";
    cin >> imageFileName2;
    strcat (imageFileName2, ".bmp");
    readGSBMP(imageFileName2, image2);

    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            image[i][j] = (image[i][j] + image2[i][j])/2;
        }
    }
}

void f4_flip_h() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE/2; j++) {
            swap(image[i][j],image[i][(SIZE-1)-j]) ;
        }
    }
}

void f4_flip_v(){
    for (int i = 0; i < SIZE/2; i++){
        for (int j = 0; j < SIZE; j++){
            swap(image[i][j],image[(SIZE-1)-i][j]);
        }
    }
}

void f5_rotate() {
    for (int i = 0; i < SIZE / 2; i++) {
        for (int j = i; j < SIZE - i - 1; j++) {
            char helper = image[i][j];
            // Swap elements of each cycle
            // in clockwise direction by 90 degree
            image[i][j] = image[SIZE - 1 - j][i];
            image[SIZE - 1 - j][i] = image[SIZE - 1 - i][SIZE - 1 - j];
            image[SIZE - 1 - i][SIZE - 1 - j] = image[j][SIZE - 1 - i];
            image[j][SIZE - 1 - i] = helper;
        }
    }
}

void f6_Shrink() {

    int  min;
    cout<<"1-to shrink image dimension to 1/2:\n2-to shrink image dimension to 1/3:\n3-to shrink image dimension to 1/4:\n";
    cin >> min;
    min+=1;


    int row = 0;
    
    for (int i = 0; i < SIZE; i++) {
        int col = 0;
        for (int j = 0; j < SIZE; j++) {
            if (i > SIZE / min || j > SIZE / min) {
                image[i][j] = 255;

            } else
                image[i][j] = image[row][col];
            col += min;
        }
        row += min;
    }
}

int main() {
    char choose;
    int choose1,repeat;

    // main window
    while(choose!='0'){

        cout<<"Ahlan ya user ya habibi :)"<<endl;
        loadImage();

        cout<<"Please select a filter to apply or 0 to exit:\n"
            <<"     1- Black & White Filter\n"
            <<"     2- Invert Filter\n"
            <<"     3- Merge Filter\n"
            <<"     4- Flip Image\n"
            <<"     5- Rotate Image\n"
            <<"     6- Shrink Filter\n"
            <<"     0- Exit\n"
            <<"     >> ";cin>>choose;

        
        switch (choose)
        {
            // filter 1 : black & white
            case '1':
                f1_black_white();
                saveImage();
                break;

            // filter 2 : invert
            case '2':
                f2_invert();
                saveImage();
                break;

            // filter 3 : merge
            case '3':
                f3_Merge();
                saveImage();
                break;

            // filter 4 : flip
            case '4':
                char fl;
                f4:
                cout<<"\nFlip (h)orizontally or (v)ertically ?"
                "\n>> ";cin>>fl;
                if(fl=='h' || fl=='H'){f4_flip_h(); saveImage();}
                
                else if(fl=='v' || fl=='V'){f4_flip_v(); saveImage();}

                else{cout<<"wrong input please try again"; goto f4;}
                break;

            // filter 5 : rotate
            case '5':
            f5:
                cout<<"Rotate (90), (180) or (270) degrees?"<<endl
                    <<">> "; cin>>choose1;
                if(choose1==90){
                    f5_rotate();
                    saveImage();
                }

                else if (choose1==180) {
                    f5_rotate();
                    f5_rotate();
                    saveImage();
                }

                else if(choose1==270) {
                    f5_rotate();
                    f5_rotate();
                    f5_rotate();
                    saveImage();
                }

                else{cout<<"Wrong input please try again"; goto f5;}
                break;

            // filter 6 : shrink
            case '6':
                f6_Shrink();
                saveImage();
                break;

            default:
                cout<<"Wrong inpur please try again";
                break;
        }
        // clear screen
        system("CLS");
    }
    return 0;
}