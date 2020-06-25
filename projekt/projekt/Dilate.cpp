#include "Dilate.h"

Dilate::Dilate()
{
}

Dilate::~Dilate()
{
}

void Dilate::change_effect(std::list<std::shared_ptr<Mat>>& lista, int morph)
{
    Mat img = lista.front()->clone();
    Mat result;
    int dilation_type = 0;
    if (morph == 0) { dilation_type = MORPH_RECT; }
    else if (morph == 1) { dilation_type = MORPH_CROSS; }
    else if (morph == 2) { dilation_type = MORPH_ELLIPSE; }
    Mat element = getStructuringElement(dilation_type,
        Size(2 * 1 + 1, 2 * 1 + 1), Point(1, 1));
    dilate(img, result, element);

    lista.push_front(std::make_shared<Mat>(result));
}
