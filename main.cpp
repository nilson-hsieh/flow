#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include <iostream>
#include <unistd.h>
using namespace cv;
using namespace std;
int main(){
cv::VideoCapture capture("rtsp://admin:@your ip address"); 
while(capture.isOpened()) {
     cv::Mat frame; 
    vector<Rect> found;
    capture.read(frame); 
    HOGDescriptor defaultHog;
    defaultHog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
    defaultHog.detectMultiScale(frame, found);
    for (int i = 0; i < found.size(); i++){
        Rect r = found[i];
        rectangle(frame, r, Scalar(0, 255, 0), 1);
    }
    printf("%d\n",found.size() );
    namedWindow("檢測行人",0);
    resizeWindow("檢測行人",640,480);
    imshow("檢測行人",frame);
    cv::waitKey(30);
} 
}
