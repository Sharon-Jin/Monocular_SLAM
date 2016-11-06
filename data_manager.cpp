//
//
// Monocular SLAM
// Following the pipeline of ORB_SLAM with optimisation framework implemented in OPT
//
// Xiaohan Jin, Yifan Xing, Yu Mao @ CMU
// 11/01/2016
//

#include "data_manager.h"

void DataManager::loadImgFileList(string directory, int begin_frame, int end_frame) {
    cout << "Loading image from : " << directory << "..." << endl;
    if (directory.back()!='/') {
        directory += '/';
    }

    DIR *pDIR;
    int index=0;
    struct dirent *entry;
    vector<Frame> imgNamelist;
    if( (pDIR=opendir(directory.c_str())) !=NULL){
        while((entry = readdir(pDIR))!= NULL){
            if( has_suffix(entry->d_name, ".png") || has_suffix(entry->d_name, ".jpg") ) {
                imgNamelist.push_back(parseImgRawFileName(directory, entry->d_name));
                index++;
            }
        }
        closedir(pDIR);
    }
    sort(imgNamelist.begin(), imgNamelist.end());

    for (int i=begin_frame; i<MIN(end_frame, imgNamelist.size()); i++){
        Frame f;
        f.timestamp=imgNamelist[i].timestamp;
        f.framename=imgNamelist[i].framename;
        f.frameID=i;
        f.frame=imread(imgNamelist[i].framename, CV_LOAD_IMAGE_UNCHANGED);
        cout << "Frame: " << f.framename << endl;
        imshow("frame", f.frame);
        waitKey();
        frames.push_back(f);
    }
    cout<<"Imagelist loaded"<<endl;
}

bool has_suffix(const string& s, const string& suffix)
{
    return (s.size() >= suffix.size()) && equal(suffix.rbegin(), suffix.rend(), s.rbegin());
}

Frame DataManager::parseImgRawFileName(string directory, string filename)
{
    double timestamp;
    sscanf(filename.c_str(), "%lf.png", &timestamp);
    Frame f;
    f.timestamp = timestamp;
    f.framename = directory + filename;
    return f;
}

