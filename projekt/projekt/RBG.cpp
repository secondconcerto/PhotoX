#include "RBG.h"

_RGB::_RGB()
{
}

_RGB::~_RGB()
{
}

void _RGB::change_space(std::list<std::shared_ptr<Mat>>& lista, std::vector<int> Vector)
{
	Mat img = lista.front()->clone();
	Mat result = img.clone();
	cvtColor(img, result, COLOR_BGR2RGB);
	lista.push_front(std::make_shared<Mat>(result));
}
