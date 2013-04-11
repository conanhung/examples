/************************************************************************/
/* qt-opencv-multithreaded:                                             */
/* A multithreaded OpenCV application using the Qt framework.           */
/*                                                                      */
/* ProcessingThead.h                                                    */
/*                                                                      */
/* Nick D'Ademo <nickdademo@gmail.com>                                  */
/*                                                                      */
/* Copyright (c) 2012-2013 Nick D'Ademo                                 */
/*                                                                      */
/* Permission is hereby granted, free of charge, to any person          */
/* obtaining a copy of this software and associated documentation       */
/* files (the "Software"), to deal in the Software without restriction, */
/* including without limitation the rights to use, copy, modify, merge, */
/* publish, distribute, sublicense, and/or sell copies of the Software, */
/* and to permit persons to whom the Software is furnished to do so,    */
/* subject to the following conditions:                                 */
/*                                                                      */
/* The above copyright notice and this permission notice shall be       */
/* included in all copies or substantial portions of the Software.      */
/*                                                                      */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,      */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF   */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND                */
/* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  */
/* BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN   */
/* ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN    */
/* CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE     */
/* SOFTWARE.                                                            */
/*                                                                      */
/************************************************************************/

#ifndef PROCESSINGTHREAD_H
#define PROCESSINGTHREAD_H

// Qt
#include <QThread>
#include <QDebug>
// OpenCV
#include <opencv/cv.h>
#include <opencv/highgui.h>
// Local
#include "Structures.h"
#include "Config.h"
#include "ImageBuffer.h"
#include "MatToQImage.h"

using namespace cv;

class ProcessingThread : public QThread
{
    Q_OBJECT

    public:
        ProcessingThread(ImageBuffer *imageBuffer);
        QRect getCurrentROI();
        void stop();
        int getAverageFPS();
        int getNFramesProcessed();

    private:
        void updateFPS(int);
        void setROI();
        void resetROI();
        ImageBuffer *imageBuffer;
        Mat currentFrame;
        Mat currentFrameGrayscale;
        Rect currentROI;
        QImage frame;
        QTime t;
        QQueue<int> fps;
        QMutex doStopMutex;
        QMutex processingMutex;
        Size frameSize;
        Point framePoint;
        struct ImageProcessingFlags imgProcFlags;
        struct ImageProcessingSettings imgProcSettings;
        volatile bool doStop;
        int processingTime;
        int fpsSum;
        int sampleNumber;
        int averageFPS;
        int nFramesProcessed;

    protected:
        void run();

    private slots:
        void updateImageProcessingFlags(struct ImageProcessingFlags);
        void updateImageProcessingSettings(struct ImageProcessingSettings);
        void setROI(QRect roi);

    signals:
        void newFrame(const QImage &frame);
};

#endif // PROCESSINGTHREAD_H
