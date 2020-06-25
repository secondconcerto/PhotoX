#include "FlipX.h"
#include <opencv2/core.hpp>

FlipX::FlipX()
{
}

FlipX::~FlipX()
{
}

void FlipX::change_flip(std::list<std::shared_ptr<Mat>>& lista)
{
	Mat buffer = lista.front()->clone();
	std::shared_ptr<Mat> final= std::make_shared<Mat>(buffer.clone());

	cv::flip(buffer, *final, 1);

	lista.push_front(final);

}
