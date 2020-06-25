#include "FlipXY.h"
#include <opencv2/core.hpp>

FlipXY::FlipXY()
{
}

FlipXY::~FlipXY()
{
}

void FlipXY::change_flip(std::list<std::shared_ptr<Mat>>& lista)
{
	Mat buffer = lista.front()->clone();
	std::shared_ptr<Mat> finald = std::make_shared<Mat>(buffer.clone());
	cv::flip(buffer, *finald, -1);
	lista.push_front(finald);

}
