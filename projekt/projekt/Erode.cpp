#include "Erode.h"


Erode::Erode()
{
}

Erode::~Erode()
{
}

void Erode::change_effect(std::list<std::shared_ptr<Mat>>& lista, int morph)
{
    Mat img = lista.front()->clone();
    Mat result;
    int erosion_type = 0; if (morph == 0) { erosion_type = MORPH_RECT; }
    else if (morph == 1) { erosion_type = MORPH_CROSS; }
    else if (morph == 2) { erosion_type = MORPH_ELLIPSE; }
    Mat element = getStructuringElement(erosion_type, Size(2 * 1 + 1, 2 * 1 + 1), Point(1, 1)); 
    erode(img, result, element);
 
    lista.push_front(std::make_shared<Mat>(result));
}
