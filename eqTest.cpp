//
// Created by tong on 4/26/17.
//
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;


int main(int argc, char **argv) {
  int n = atoi(argv[1]);
  Mat img1_eq, img2_eq;
  for (int i = 1; i <= n; ++i) {
    Mat img1 = imread("../imgs/exposure0/" + to_string(i) + ".jpg", cv::IMREAD_GRAYSCALE);
    Mat img2 = imread("../imgs/exposure-1/" + to_string(i) + ".jpg", cv::IMREAD_GRAYSCALE);

    equalizeHist(img1, img1_eq);
    equalizeHist(img2, img2_eq);

    imwrite("../imgs/exposure0/" + to_string(i) + "_eq.jpg", img1_eq);
    imwrite("../imgs/exposure-1/" + to_string(i) + "_eq.jpg", img2_eq);
  }
  imshow("1", img1_eq);
  imshow("2", img2_eq);
  waitKey();
  return 0;
}
