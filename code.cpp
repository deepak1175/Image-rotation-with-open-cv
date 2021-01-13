#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat rotate(Mat sourc, double angle){
    Mat dest;
    Point2f pt(sourc.cols/2., sourc.rows/2.);
    Mat a = getRotationMatrix2D(pt, angle, 1.0);
    warpAffine(sourc, dest, a, Size(sourc.cols, sourc.rows));
    return dest;
}

int main(){
    string imgpath;
    double an;
    Mat sourc, dest;

    cout << "Enter the Path of the Image : ";
    cin >> imgpath;
    src = imread(imgpath, CV_LOAD_IMAGE_UNCHANGED);
    cout << "Enter the angle : ";
    cin >> an;

    dest = rotate(sourc, an);

    const char* pzRotatedImage = "Rotated Image";
    namedWindow(pzRotatedImage, CV_WINDOW_AUTOSIZE);
    imshow(pzRotatedImage, dest);

    waitKey(0);
    return 0;
}
