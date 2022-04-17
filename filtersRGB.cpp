// FCAI – Programming 1 – 2022 - Assignment 3
// Program Name: filters.cpp
// Program Description: filters team task- this program make filters on photos
// Last Modification Date: 7/16/2022
// Author1 and ID and Group: Ahmed Mohamed Taha - 20210033 - Group A - S8
// Author2 and ID and Group: Doaa Mahdy Mohamed - 20210128 - Group A - S8
// Author3 and ID and Group: Omar Ayman Saad    - 20210261 - Group A - S8
// Purpose: training on 2D array

// libraries
#include<iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
#include <bits/stdc++.h>
#include<stdlib.h>

// initialize standard cpp
using namespace std;

// photos matrices variables
unsigned char image[SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE][RGB];
unsigned char image3[SIZE][SIZE];
// functions
int loadImage ();
void saveImage ();
void saveImage2 ();
void saveImage3 ();
void f1_black_white ();
void f2_invert ();
void f3_Merge ();
void f4_flip ();
void f5_darken_lighten ();
void f6_rotate ();
// void f7_Detect_Edges ();
void f8_Enlarge_Image ();
void f9_shrink ();
// void fa_mirror ();
void fb_Shuffle_Image ();
void fc_Blur_Image ();






int main() {
    char choose;

    // main window
    while(choose!='0'){

        cout<<"Ahlan ya user ya habibi :)\n";
        if(loadImage()==0){
            cout<<"please enter a valid file name without .bmp extention\n\n";
            continue;
            }
        
        cout<<"Please select a filter to apply or 0 to exit:\n"
            <<"     1- Black & White Filter                 \n"
            <<"     2- Invert Filter                        \n"
            <<"     3- Merge Filter                         \n"
            <<"     4- Flip Image                           \n"
            <<"     5- darken and lighten image             \n"
            <<"     6- Rotate Image                         \n"
            <<"     7- Detect Image Edges                   \n"
            <<"     8- Enlarge Image                        \n"
            <<"     9- Shrink Image                         \n"
            <<"     a- Mirror 1/2 Image                     \n"
            <<"     b- Shuffle Image                        \n"
            <<"     c- Blur Image                           \n"
            <<"     s- Save the image to a file             \n"
            <<"     0- Exit                                 \n"
            <<"     >> "; cin>>choose;

                
        switch (choose)
        {
//          filter 1 : black & white
            case '1':
                f1_black_white();
                saveImage3();
                break;

//          filter 2 : invert
            case '2':
                f2_invert();
                saveImage();
                break;

            /*
//          filter 3 : merge
            case '3':
                f3_Merge();
                saveImage();
                break;
            */

//          filter 4 : flip
            case '4':
            f4_flip();
            saveImage();
            break;

//          filter 5 : dareken or ligthen image
            case '5':
                f5_darken_lighten();
                saveImage();
                break;

//          filter 6 : rotate image
            case '6':
                f6_rotate();
                saveImage();
                break;

            /*
            case '7':
                f7_Detect_Edges();
                saveImage2();
                break;
            */

            /*
//          filter 8 : englarge image
            case '8':
                f8_Enlarge_Image();
                saveImage2();
                break;
            */

            /*
//          filter 9 : shrink image
            case '9':
                f9_shrink();
                saveImage();
                break;
            */

            /*
            case 'a':
                fa_mirror();
                saveImage();
                break;
            */

//          filter b : shuffle image
            case 'b':
                fb_Shuffle_Image();
                saveImage2();
                break;

//          filter c : blur image
            case 'c':
                fc_Blur_Image();
                saveImage2();
                break;

//          wrong input case
            default:
                cout<<"\nWrong inpur please try again\n";
                break;
        }
        // clear screen
        system("CLS");
    }
    return 0;
}








// functions
int loadImage () {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Please enter file name of the image to process: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    if (readRGBBMP(imageFileName, image)==1) {return 0;}
    return 1;
}

void saveImage () {

    char imageFileName[100];

    // Get gray scale image target file name
    cout << "\nEnter the target image file output name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);
}

void saveImage2 () {

    char imageFileName[100];

    // Get gray scale image target file name
    cout << "\nEnter the target image file output name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image2);
}

void saveImage3 () {

    char imageFileName[100];

    // Get gray scale image target file name
    cout << "\nEnter the target image file output name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image3);
}

void f1_black_white() {
//  loop in each pixel of image

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
    //          if pixel color above 127 (white dgrees) let it = 255 (solid white)
                if (image[i][j][0] > 127)
                    image3[i][j] = 255;
    //          else if pixel color under 127 (black dgrees) let it = 0 (solid black)
                else
                    image3[i][j] = 0;
            }
        }
        
}

void f2_invert() {
//  loop in each pixel of image    
    for(int k=0; k<RGB; k++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
    //          subtract 255 from each pixel to get the invert pixel color
                image[i][j][k] = 255-image[i][j][k];
            }
        }
    }
}

/*
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
*/

void f4_flip() {
    char fl;
//  return point if user enterd a wrong input
    f4:
    cout<<"\n\nFlip (h)orizontally or (v)ertically ?"
    "\n>> ";cin>>fl;

//  if user enterd h or H 
    if(fl=='h' || fl=='H'){

//      swap each pixel of image from the first pixel 
//      in each row by the last one in the same row.
        for(int k=0; k<RGB; k++){
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE/2; j++) {
                    swap(image[i][j][k],image[i][(SIZE-1)-j][k]);
                }
            }
        }    
    }

//  else if user enterd v or V
    else if(fl=='v' || fl=='V'){

//      swap each pixel of image from the first pixel
//      in each column by the last one in the same column.
        for(int k=0; k<RGB; k++){
            for (int i = 0; i < SIZE/2; i++){
                for (int j = 0; j < SIZE; j++){
                    swap(image[i][j][k],image[(SIZE-1)-i][j][k]);
                }
            }
        }
    }

//  else wrong input go to start point 
    else{cout<<"\nwrong input please try again\n"; goto f4;}

}

void f5_darken_lighten() {
    char ch;
//  return point if user enterd a wrong input
    f5:
    cout<<"\n\n>> (d)arken or (l)ighten?"
    "\n>> ";cin>>ch;

    switch(ch){
        case 'l':
        case 'L':
//          in lighten case increase each pixel < 205 by 50 and if the pixel > 205 let pixel eqaul 255 to avoid overload
            for(int k=0; k<RGB; k++){
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j< SIZE; j++){
                        if(image[i][j][k]<=205)
                        {image[i][j][k]+=50;}
                        else{image[i][j][k]=255;}
                    }
                }
            }
            break;

        case 'd':
        case 'D':
//          in darken case divide each pixel over 2 to get the half light
            for(int k=0; k<RGB; k++){
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j< SIZE; j++) 
                        image[i][j][k]/=2;
                }
            }
            break;        
        
        default:
            cout<<"invalid input";
            goto f5;
            break;
    }
}

void f6_rotate() {
    int choose1;
    f6:
    cout<<"\n\nRotate (90), (180) or (270) degrees?"<<endl
    <<">> "; cin>>choose1;

    if(choose1==90){
        for(int k=0; k<RGB; k++){
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = i; j < SIZE - i - 1; j++) {
    //              Store current pixel in helper variable 
                    char helper = image[i][j][k];

    //              Swap elements of each cycle
    //              in clockwise direction by 90 degree

    //              Move values from right to top
                    image[i][j][k] = image[SIZE - 1 - j][i][k];
    //              Move values from bottom to right
                    image[SIZE - 1 - j][i][k] = image[SIZE - 1 - i][SIZE - 1 - j][k];
    //              Move values from left to bottom
                    image[SIZE - 1 - i][SIZE - 1 - j][k] = image[j][SIZE - 1 - i][k];
    //              Assign helper to left
                    image[j][SIZE - 1 - i][k] = helper;
                }
            }
        }
    }

    else if (choose1==180) {    
//      in 180 degree we used the main algorithm of 90 degree two times to get 90+90 swap that equal 180 degree        
        for(int i=0; i<2; i++){
            for(int k=0; k<RGB; k++){
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = i; j < SIZE - i - 1; j++) {
                        char helper = image[i][j][k];
                        image[i][j][k] = image[SIZE - 1 - j][i][k];
                        image[SIZE - 1 - j][i][k] = image[SIZE - 1 - i][SIZE - 1 - j][k];
                        image[SIZE - 1 - i][SIZE - 1 - j][k] = image[j][SIZE - 1 - i][k];
                        image[j][SIZE - 1 - i][k] = helper;
                    }
                }
            }
        }
    }
                

    else if(choose1==270) {
//      in 270 degree we used the main algorithm of 90 degree three times to get 90+90+90 swap that equal 270 degree        
        for(int i=0; i<3; i++){
            for(int k=0; k<RGB; k++){
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = i; j < SIZE - i - 1; j++) {
                        char helper = image[i][j][k];
                        image[i][j][k] = image[SIZE - 1 - j][i][k];
                        image[SIZE - 1 - j][i][k] = image[SIZE - 1 - i][SIZE - 1 - j][k];
                        image[SIZE - 1 - i][SIZE - 1 - j][k] = image[j][SIZE - 1 - i][k];
                        image[j][SIZE - 1 - i][k] = helper;
                    }
                }
            }
        }
    }

    else{cout<<"invalid input please try again"; goto f6;}

}

// void f7_Detect_Edges(); { write code here }

/*
void f8_Enlarge_Image() {
    unsigned int choice, startX, startY;
    f8:
    cout<<"\n\n>> which quarter of the picture do you wish to enlarge?\n"
    ">> "; cin>>choice;
    switch (choice) {
        case 1:
            startX = startY = 0;
            break;

        case 2:
            startX = 0;
            startY = SIZE/2;
            break;

        case 3:
            startX = SIZE/2;
            startY = 0;
            break;

        case 4:
            startX = SIZE/2;
            startY = SIZE/2;
            break;

        default :
            cout<<"invalid input please try again";
            goto f8;
            break;

    }

    int row = 0;
    for(int k=startX; k<SIZE ; k++){
        int col =0 ;
        for (int i=startY ;i<SIZE ; i++){
            if (col>256) break;
            image2[row][++col] = image[k][i];
            if (col>256) break;
            image2[row][++col] = image[k][i];
        }

    
       for (int j =0 ;j<SIZE ;j++){
            image2[row+1][j]=image2[row][j];
        }
        row+=2;
        if  (row>256) break;
        }
}

void f9_shrink() {
    int  min;
    cout<<"\n\n1-to shrink image dimension to 1/2"
    <<"\n2-to shrink image dimension to 1/3"
    <<"\n3-to shrink image dimension to 1/4"
    <<"\n>> "; cin >> min;
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

*/

// void fa_mirror(); { write code here }

void fb_Shuffle_Image() {
    int x[4],startX,startY;

//  return point if user enterd a wrong input
    fb:

    cout<<"enter the order of quarters with a space"
    "\n>> ";cin>>x[0]>>x[1]>>x[2]>>x[3];

    for(int k=0; k<RGB; k++){
    //  make 4 loops to find start point in x axis and y axis in each value in array
        for(int i=0; i<4; i++){
                switch (x[i]) {
                case 1:
                    startX = startY = 0;
                    break;

                case 2:
                    startX = SIZE/2;
                    startY = 0;
                    break;

                case 3:
                    startX = 0;
                    startY = SIZE/2;
                    break;

                case 4:
                    startX = SIZE/2;
                    startY = SIZE/2;
                    break;
                default:
                    cout<<"invalid input";
                    goto fb;
                    break;
                    
                }
            int u=startX;
    //      in first loop fill the first quartile in new varaible from the original image using the start points 
            if(i==0){
                for(int i=0; i<SIZE/2; i++){
                    startX=u;
                    for(int j=0; j<SIZE/2; j++){
                            image2[i][j][k]=image[startY][startX][k];
                            startX++;
                    }
                    startY++;
                }

            }

    //      in second loop fill the second quartile in new varaible from the original image using the start points 
            else if(i==1){
                for(int i=0; i<SIZE/2; i++){
                    startX=u;
                    for(int j=SIZE/2; j<SIZE; j++){
                        image2[i][j][k]=image[startY][startX][k];
                        startX++;
                    }
                    startY++;
                }
                
            }

    //      in third loop fill the third quartile in new varaible from the original image using the start points         
            else if(i==2){
                for(int i=SIZE/2; i<SIZE; i++){
                    startX=u;
                    for(int j=0; j<SIZE/2; j++){
                        image2[i][j][k]=image[startY][startX][k];
                        startX++;
                    }
                    startY++;
                }
            }

    //      in fourth loop fill the fourth quartile in new varaible from the original image using the start points 
            else if(i==3){
                for(int i=SIZE/2; i<SIZE; i++){
                    startX=u;
                    for(int j=SIZE/2; j<SIZE; j++){
                        image2[i][j][k]=image[startY][startX][k];
                        startX++;
                    }
                    startY++;
                }
            
            }
        }
    }
}

void fc_Blur_Image() {
    int sum=0,avg,j=0,i=0;

    // fill new variable by the border from the main photo
    for(int k=0; k<RGB; k++){
        for(int i=0; i<SIZE; i++){
            for(int j=0; j<SIZE; j++){
                
                if(i==0 || j==0 || i==SIZE-1 || j==SIZE-1){
                    image2[i][j][k]=image[i][j][k];}

                else{
                    image2[i][j][k]=0;}
            }
        }

        j=0;
        i=0;
        avg=0;
        sum=0;
        while(true){
            //calculate avrage of each 3*3 neighbor pixels
            sum=image[i][j][k]+image[i][j+1][k]+image[i][j+2][k]+
            image[i+1][j][k]+image[i+1][j+1][k]+image[i+1][j+2][k]+
            image[i+2][j][k]+image[i+2][j+1][k]+image[i+2][j+2][k];

            avg=sum/9;

    //      assume each centered pixel in each 3*3 group equal to the avrage
            image2[i+1][j+1][k]=avg;

    //      reset avrage variable
            avg=0;

    //      condition to break the loop & increamnt
            if(i==253 && j==253){break;}
            else{i++;}
            if(i==254){i=0; j++;}

        }
    }
}