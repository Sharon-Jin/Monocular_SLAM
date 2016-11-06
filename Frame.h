//
// Created by 金晓晗 on 16/11/5.
//

#ifndef MONOCULAR_SLAM_FRAME_H
#define MONOCULAR_SLAM_FRAME_H

#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

class Frame {
public:
    // Frame info
    Mat frame;
    double timestamp;
    int frameID;
    string framename;
    vector<pair<Point3d, int>> current_points;

    // Calibration matrix and OpenCV distortion parameters.
    cv::Mat mK;
    static float fx;
    static float fy;
    static float cx;
    static float cy;
    static float invfx;
    static float invfy;
    Mat mDistCoef;

    // Camera pose.
    Mat mTcw;

    // Number of KeyPoints.
    int N;
    vector<cv::KeyPoint> mvKeys, mvKeysRight;
    vector<cv::KeyPoint> mvKeysUn;

    /*
    // Bag of Words Vector structures.
    DBoW2::BowVector mBowVec;
    DBoW2::FeatureVector mFeatVec;

    // Vocabulary used for relocalization.
    ORBVocabulary* mpORBvocabulary;
    ORBextractor* mpORBextractorLeft;
    */

    // ORB descriptor, each row associated to a keypoint.
    Mat mDescriptors, mDescriptorsRight;

    // Map points associated to keypoints, NULL pointer if no association.
    vector<pair<Point3d, int>> mvpMapPoints;

    // Reference Keyframe.
    Frame* mpReferenceKF;

    void ExtractORB(int flag, const cv::Mat &im);
    bool operator < (const Frame & frameB) const
    {
        return frameB.timestamp > timestamp;
    }
};


#endif //MONOCULAR_SLAM_FRAME_H
