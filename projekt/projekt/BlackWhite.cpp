#include "BlackWhite.h"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/mat.hpp>
#include "opencv2/core/utility.hpp"
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"

BlackWhite::BlackWhite()
{
}

BlackWhite::~BlackWhite()
{
}

void BlackWhite::change_color(std::list<std::shared_ptr<Mat>>& lista)
{
	Mat buffer = lista.front()->clone();
	Mat final = (buffer.clone());
	cvtColor(buffer, final, cv::COLOR_BGR2GRAY, 0);
	threshold(final, final, 127, 255, cv::THRESH_BINARY);
	cv::Mat out;
	cv::Mat in[] = { final, final, final };
	cv::merge(in, 3, out);
	int ch = out.channels();

	lista.push_front(std::make_shared<Mat>(out));

}



