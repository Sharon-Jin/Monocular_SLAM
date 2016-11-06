//
//
// Monocular SLAM
// Following the pipeline of ORB_SLAM with optimisation framework implemented in OPT
//
// Xiaohan Jin, Yifan Xing, Yu Mao @ CMU
// 11/01/2016
//

#ifndef MONOCULAR_SLAM_DATA_MANAGER_H
#define MONOCULAR_SLAM_DATA_MANAGER_H

#include<stdio.h>
#include<cstdlib>
#include <string.h>
#include <fstream>
#include <iostream>
#include <math.h>
#include <vector>
#include <time.h>
#include <dirent.h>
#include "Frame.h"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

class DataManager{
public:
    vector<Frame> frames;
    vector<Point3d> total_points;
    void loadImgFileList(string directory, int begin_frame, int end_frame);
    Frame parseImgRawFileName(string directory, string filename);
};

bool has_suffix(const string& s, const string& suffix);

#endif //MONOCULAR_SLAM_DATA_MANAGER_H
