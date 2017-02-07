# Monocular_SLAM
Monocular SLAM with C++ implementation

In this project, we designed from scratch a feature-based monocular SLAM system, which includes tracking and mapping of key map points. The system pipeline consists of the following steps: initial triangulation by eight point algorithm and RANSAC, data association refinement by Perspective-n-Point algorithm, mapping by bundle adjustment (g2o), and 3D mesh reconstruction.
