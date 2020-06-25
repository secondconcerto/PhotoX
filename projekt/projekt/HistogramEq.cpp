#include "HistogramEq.h"

HistogramEq::HistogramEq()
{
}

HistogramEq::~HistogramEq()
{
}

void HistogramEq::change_histogram(std::list<std::shared_ptr<Mat>>& lista)
{
    cv::Mat img = lista.front()->clone();
    cvtColor(img, img, COLOR_BGR2GRAY);

    // Total number of occurance of the number of each pixels at different levels from 0 - 256
  // Flattening our 2d matrix
    int flat_img[256] = { 0 };
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            int index;
            index = static_cast<int>(img.at<uchar>(i, j)); // safe convertion to int
            flat_img[index]++;
        }
    }

    // calculate CDF corresponding to flat_img
    // CDF --> cumsum
    int cumsum[256] = { 0 };
    int memory = 0;
    for (int i = 0; i < 256; i++) {
        memory += flat_img[i];
        cumsum[i] = memory;
    }

    // using general histogram equalization formula
    int normalize_img[256] = { 0 };
    for (int i = 0; i < 256; i++) {
        // norm(v) = round(((cdf(v) - mincdf) / (M * N) - mincdf) * (L - 1));
        normalize_img[i] = ((cumsum[i] - cumsum[0]) * 255) / (img.rows * img.cols - cumsum[0]);
        normalize_img[i] = static_cast<int>(normalize_img[i]);
    }

    // convert 1d back into a 2d matrix
    cv::Mat result(img.rows, img.cols, CV_8U);

    Mat_<uchar>::iterator itr_result = result.begin<uchar>(); // our result
    Mat_<uchar>::iterator it_begin = img.begin<uchar>(); // beginning of the image
    Mat_<uchar>::iterator itr_end = img.end<uchar>(); // end of the image

    for (; it_begin != itr_end; it_begin++) {
        int intensity_value = static_cast<int>(*it_begin); // get the value and cast it into an int
        *itr_result = normalize_img[intensity_value];
        itr_result++;
    }

    cv::Mat out;
    cv::Mat in[] = { result, result, result };
    cv::merge(in, 3, out);
    lista.push_front(std::make_shared<Mat>(out));
}
