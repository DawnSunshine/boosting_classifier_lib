#include "face_haar_detector.h"

FaceHaarDetector::FaceHaarDetector():
    error_inf("")
{
    detect_param.scaleFactor = 1.0;
    detect_param.findLargestObject = false;
    detect_param.filterRects = true;
    detect_param.extra_param_1 = 0;
    detect_param.extra_param_2 = 0;
}
FaceHaarDetector::~FaceHaarDetector()
{

}

bool FaceHaarDetector::loadCascade(const std::string &name)
{
    if(!cascade_gpu.load(name))
    {
        error_inf = "ERROR: can't load haar cascade\n";
        return false;
    }
    return true;
}

void FaceHaarDetector::setParam(const DetectParam &param)
{
    detect_param = param;
}

bool FaceHaarDetector::detect(const cv::gpu::GpuMat &frame, DetectResult &result)
{
    if(frame.empty())
    {
        error_inf = "ERROR: frame is empty";
        return false;
    }

    convertAndResize(frame, gray_gpu, resized_gpu, detect_param.scaleFactor);
    cascade_gpu.findLargestObject = detect_param.findLargestObject;

    result.num = cascade_gpu.detectMultiScale(resized_gpu, facesBuf_gpu, cv::Size(80, 80), cv::Size(15, 15),1.2,
                                                  (detect_param.filterRects || detect_param.findLargestObject) ? 2 : 0);

    facesBuf_gpu.colRange(0, result.num).download(faces_downloaded);
    result.rect.clear();
    for (int i = 0; i <  result.num; ++i)
    {
        result.rect.push_back(faces_downloaded.ptr<cv::Rect>()[i]);
    }
    return true;
}

std::string FaceHaarDetector::getError()
{
    //printf("hello, you are right,get error");
    return error_inf;
}

void FaceHaarDetector::convertAndResize(const cv::gpu::GpuMat &src, cv::gpu::GpuMat &gray, cv::gpu::GpuMat &resized, double scale)
{
    if (src.channels() == 3)
    {
        cv::gpu::cvtColor( src, gray, CV_BGR2GRAY );
    }
    else
    {
        gray = src;
    }

    cv::Size sz(cvRound(gray.cols * scale), cvRound(gray.rows * scale));

    if (scale != 1)
    {
        cv::gpu::resize(gray, resized, sz);
    }
    else
    {
        resized = gray;
    }
}

DETECTORSHARED_EXPORT bool getFaceDetectorObject(void** _RtObject)
{
    Detector* pMan = NULL;
    pMan = new FaceHaarDetector();
    *_RtObject = (void*)pMan;
    return true;
}
