#include "HSV.h"

HSV::HSV()
{
}

HSV::~HSV()
{
}

void HSV::change_space(std::list<std::shared_ptr<Mat>>& lista, std::vector<int> Vector)
{
	Mat img = lista.front()->clone();
	Mat result = img.clone();
	cvtColor(img, result,COLOR_BGR2HSV);
	lista.push_front(std::make_shared<Mat>(result));
}
