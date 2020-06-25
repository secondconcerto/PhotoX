#include "Grey.h"

Grey::Grey()
{
}

Grey::~Grey()
{
}

void Grey::change_color(std::list<std::shared_ptr<Mat>>& lista)
{
	Mat buffer = lista.front()->clone();
	Mat final = (buffer.clone());
	cvtColor(buffer, final, COLOR_BGR2GRAY, 0);
	cv::Mat out;
	cv::Mat in[] = { final, final, final };
	cv::merge(in, 3, out);
	int ch = out.channels();
	lista.push_front(std::make_shared<Mat>(out));

}
