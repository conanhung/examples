/*
 *  preprocessing.h
 *  
 *
 *  Created by damiles on 18/11/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 *  Modified by haoest on 7/27/2011 (mm/dd/yyyy)
 
 */
#ifndef __BASICOCR_HPP__
#define __BASICOCR_HPP__


#include <opencv/cv.h>
//#include <opencv/highgui.h>
#include <opencv/ml.h>
#include <stdio.h>
#include <ctype.h>


class basicOCR{
public:
    float classify(IplImage* img,int showResult);
    basicOCR ();
    void test();
	~basicOCR();
private:
    int train_samples;
    int classes;
    CvMat* trainData;
    CvMat* trainClasses;
    int size;
    int OCRTemplateCharacterSize;
    int K;
    CvKNearest *knn;
    void getData(IplImage* OCRTemplate);
    void train();
};

#endif
