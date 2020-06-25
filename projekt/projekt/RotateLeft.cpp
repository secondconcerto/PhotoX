#include "RotateLeft.h"

RotateLeft::RotateLeft()
{
}

RotateLeft::~RotateLeft()
{
}

void RotateLeft::change_rotation(std::list<std::shared_ptr<Mat>>& lista)
{

    Mat src = lista.front()->clone();
  //  Mat dst = src.clone();

    double angle = -90;

    // get rotation matrix for rotating the image around its center in pixel coordinates
    Point2f center((src.cols - 1) / 2.0, (src.rows - 1) / 2.0);
    Mat rot = getRotationMatrix2D(center, angle, 1.0);
   
    // determine bounding rectangle, center not relevant
    Rect2f bbox = RotatedRect(Point2f(), src.size(), angle).boundingRect2f();
  
    // adjust transformation matrix
    rot.at<double>(0, 2) += bbox.width / 2.0 - src.cols / 2.0;
    rot.at<double>(1, 2) += bbox.height / 2.0 - src.rows / 2.0;

    Mat dst;
    warpAffine(src, dst, rot, bbox.size());
    lista.push_front(std::make_shared<Mat>(dst));
}
