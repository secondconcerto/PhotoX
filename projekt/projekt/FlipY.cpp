#include "FlipY.h"
#include <opencv2/core.hpp>

FlipY::FlipY()
{
}

FlipY::~FlipY()
{
}

void FlipY::change_flip(std::list<std::shared_ptr<Mat>>& lista)
{
	Mat buffer = lista.front()->clone();
	std::shared_ptr<Mat> final = std::make_shared<Mat>(buffer.clone());
	cv::flip(buffer, *final, 0);
	lista.push_front(final);

}
