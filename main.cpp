//
//
// Monocular SLAM
// Following the pipeline of ORB_SLAM with optimisation framework implemented in OPT
//
// Xiaohan Jin, Yifan Xing, Yu Mao @ CMU
// 11/01/2016
//

#include <iostream>
#include "DataManager.h"

#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;
using namespace std;

int main() {
    DataManager dm;
<<<<<<< HEAD
    string directory="data/rgbd_dataset_freiburg1_desk2_secret";
=======
    string directory="./data/rgbd_dataset_freiburg1_desk2_secret";
>>>>>>> 185f47d20f55ce4fae52c7aab29e39fc9884bbcf
    dm.loadImgFileList(directory, 0, 20);

    return 0;
}