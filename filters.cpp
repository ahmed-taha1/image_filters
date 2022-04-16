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
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];

// functions
void loadImage ();
void saveImage ();
void saveImage2 ();
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
    int choose1;

    // main window
    while(choose!='0'){

        cout<<"Ahlan ya user ya habibi :)"<<endl;
        loadImage();

        cout<<"Please select a filter to apply or 0 to exit:\n"
            <<"     1- Black & White Filter\n"
            <<"     2- Invert Filter\n"
            <<"     3- Merge Filter\n"
            <<"     4- Flip Image\n"
            <<"     5- darken and lighten image\n"
            <<"     6- Rotate Image\n"
            <<"     7- Detect Image Edges\n"
            <<"     8- Enlarge Image\n"
            <<"     9- Shrink Image\n"
            <<"     a- Mirror 1/2 Image\n"
            <<"     b- Shuffle Image\n"
            <<"     c- Blur Image\n"
            <<"     s- Save the image to a file\n"
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
            f4_flip();
            saveImage();
            break;

            // filter 5 : rotate
            case '5':
                f5_darken_lighten();
                saveImage();
                break;

            // filter 6 : shrink
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

            case '8':
                f8_Enlarge_Image();
                saveImage2();
                break;

            case '9':
                f9_shrink();
                saveImage();
                break;
            
            /*
            case 'a':
                fa_mirror();
                saveImage();
                break;
            */

            case 'b':
                fb_Shuffle_Image();
                saveImage2();

            case 'c':
                fc_Blur_Image();
                saveImage();

            default:
                cout<<"Wrong inpur please try again";
                break;
        }
        // clear screen
        system("CLS");
    }
    return 0;
}









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

void saveImage2 () {

    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image2);
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

void f4_flip() {
       char fl;
        f4:
            cout<<"\nFlip (h)orizontally or (v)ertically ?"
            "\n>> ";cin>>fl;
            if(fl=='h' || fl=='H'){goto h;}    
            
            else if(fl=='v' || fl=='V'){goto v;}

            else{cout<<"wrong input please try again"; goto f4;}

        h:
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE/2; j++) {
            swap(image[i][j],image[i][(SIZE-1)-j]);
        }
    }

        v:
    for (int i = 0; i < SIZE/2; i++){
        for (int j = 0; j < SIZE; j++){
            swap(image[i][j],image[(SIZE-1)-i][j]);
        }
    }
}

void f5_darken_lighten() {
    char ch;
    f5:
    cout<<">> (d)arken or (l)ighten?"
    "\n>> ";cin>>ch;
    switch(ch){
        case 'l':
        case 'L':
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j< SIZE; j++){
                    if(image[i][j]<=205)
                    {image[i][j]+=50;}
                    else{image[i][j]=255;}
                }
            }
            break;

        case 'd':
        case 'D':
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j< SIZE; j++) 
                    image[i][j]/=2;
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
                cout<<"Rotate (90), (180) or (270) degrees?"<<endl
                    <<">> "; cin>>choose1;

                if(choose1==90){
                    for (int i = 0; i < SIZE / 2; i++) {
                        for (int j = i; j < SIZE - i - 1; j++) {
                            //Store current pixel in helper variable 
                            char helper = image[i][j];

                            // Swap elements of each cycle
                            // in clockwise direction by 90 degree

                            //Move values from right to top
                            image[i][j] = image[SIZE - 1 - j][i];
                            //Move values from bottom to right
                            image[SIZE - 1 - j][i] = image[SIZE - 1 - i][SIZE - 1 - j];
                            //Move values from left to bottom
                            image[SIZE - 1 - i][SIZE - 1 - j] = image[j][SIZE - 1 - i];
                            //Assign helper to left
                            image[j][SIZE - 1 - i] = helper;
                        }
                    }
                }

                else if (choose1==180) {
                    for(int i=0; i<2; i++){
                        for (int i = 0; i < SIZE / 2; i++) {
                            for (int j = i; j < SIZE - i - 1; j++) {
                                char helper = image[i][j];
                                image[i][j] = image[SIZE - 1 - j][i];
                                image[SIZE - 1 - j][i] = image[SIZE - 1 - i][SIZE - 1 - j];
                                image[SIZE - 1 - i][SIZE - 1 - j] = image[j][SIZE - 1 - i];
                                image[j][SIZE - 1 - i] = helper;
                            }
                        }
                    }
                }
                

                else if(choose1==270) {
                    for(int i=0; i<3; i++){
                        for (int i = 0; i < SIZE / 2; i++) {
                            for (int j = i; j < SIZE - i - 1; j++) {
                                char helper = image[i][j];
                                image[i][j] = image[SIZE - 1 - j][i];
                                image[SIZE - 1 - j][i] = image[SIZE - 1 - i][SIZE - 1 - j];
                                image[SIZE - 1 - i][SIZE - 1 - j] = image[j][SIZE - 1 - i];
                                image[j][SIZE - 1 - i] = helper;
                            }
                        }
                    }
                }

                else{cout<<"Wrong input please try again"; goto f6;}

}

// void f7_Detect_Edges(); { write code here }

void f8_Enlarge_Image() {
    unsigned int choice, startX, startY;
    f8:
    cout<<"\n>> which quarter of the picture do you wish to enlarge?\n"
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
            cout<<"invalid input.";
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
    cout<<"1-to shrink image dimension to 1/2\n2-to shrink image dimension to 1/3\n3-to shrink image dimension to 1/4\n>> ";
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

// void fa_mirror(); { write code here }

void fb_Shuffle_Image() {
    int x[4],startX,startY;
    fb:
    cout<<"enter the order of quarters with a space"
    "\n>> ";cin>>x[0]>>x[1]>>x[2]>>x[3];

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
        if(i==0){
            for(int i=0; i<SIZE/2; i++){
                startX=u;
                for(int j=0; j<SIZE/2; j++){
                    image2[i][j]=image[startY][startX];
                    startX++;
                }
                startY++;
            }

        }

        else if(i==1){
                for(int i=0; i<SIZE/2; i++){
                    startX=u;
                    for(int j=SIZE/2; j<SIZE; j++){
                        image2[i][j]=image[startY][startX];
                        startX++;
                    }
                    startY++;
            }
        }
        
        else if(i==2){
                for(int i=SIZE/2; i<SIZE; i++){
                    startX=u;
                    for(int j=0; j<SIZE/2; j++){
                        image2[i][j]=image[startY][startX];
                        startX++;
                    }
                    startY++;
            }
        }

        else if(i==3){
            for(int i=SIZE/2; i<SIZE; i++){
                startX=u;
                for(int j=SIZE/2; j<SIZE; j++){
                    image2[i][j]=image[startY][startX];
                    startX++;
                }
                startY++;
                }
            }
        }

}

void fc_Blur_Image() {
    int sum=0,avg,j=0,i=0;
    while(true){
        //avrage calc of each 2*2 group of pixels
        sum=image[i][j]+image[i][j+1]+image[i+1][j]+image[i+1][j+1];
        sum/=4;
        
        //assign avrage to each 2*2 group of pixels 
        image[i][j]=sum; image[i][j+1]=sum; image[i+1][j]=sum; image[i+1][j+1]=sum;

        sum=0;

        //increament and break condition
        if(i==254 && j==254){break;}
        else{i+=2;}
        if(i==256){i=0; j+=2;}
    }
}
