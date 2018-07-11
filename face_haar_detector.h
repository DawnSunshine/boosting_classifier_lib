#ifndef FACE_HAAR_DETECTOR_H
#define FACE_HAAR_DETECTOR_H

//#include "face_haar_detector_global.h"

#include "detector.h"
#include "opencv2/contrib/contrib.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/imgproc/imgproc.hpp"

class FaceHaarDetector : public Detector
{
public:
    FaceHaarDetector();
    ~FaceHaarDetector();
public:
    virtual bool loadCascade(const std::string &name) ;
    virtual void setParam(const DetectParam &param) ;
    virtual bool detect(const cv::gpu::GpuMat &frame, DetectResult &result) ;
    virtual std::string getError() ;

private:

    void convertAndResize(const cv::gpu::GpuMat& src, cv::gpu::GpuMat& gray,
                          cv::gpu::GpuMat& resized, double scale);

private:
    cv::gpu::CascadeClassifier_GPU cascade_gpu;
    cv::gpu::GpuMat gray_gpu;
    cv::gpu::GpuMat resized_gpu;
    cv::gpu::GpuMat facesBuf_gpu;
    cv::Mat faces_downloaded;
private:
    std::string error_inf;
    DetectParam detect_param;
};

#endif // FACE_HAAR_DETECTOR_H
