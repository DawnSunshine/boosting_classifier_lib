#ifndef DETECTOR_H
#define DETECTOR_H

#include <QtCore/qglobal.h>

#if defined(FACE_HAAR_DETECTOR_LIBRARY)
#  define DETECTORSHARED_EXPORT Q_DECL_EXPORT
#else
#  define DETECTORSHARED_EXPORT Q_DECL_IMPORT
#endif

#include <vector>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/gpu/gpu.hpp>

typedef struct
{
    int num;//检测结果个数
    std::vector<cv::Rect> rect;//检测结果矩形容器
}DetectResult;

typedef struct
{
    bool findLargestObject;//是否只检测最大目标
    bool filterRects;//是否矩形过滤
    double scaleFactor;//缩放系数
    double extra_param_1;//预留参数1
    double extra_param_2;//预留参数2
}DetectParam;

class Detector
{
public:
    virtual bool loadCascade(const std::string &name) = 0;
    virtual void setParam(const DetectParam &param) = 0;
    virtual bool detect(const cv::gpu::GpuMat &frame, DetectResult &result) = 0;
    virtual std::string getError() = 0;
};

#endif // DETECTOR_H
