#include "Gamma.h"

Gamma::Gamma()
{
}

Gamma::~Gamma()
{
}

bool Gamma::matIsEqual(const cv::Mat Mat1, const cv::Mat Mat2)
{
    if (Mat1.dims == Mat2.dims &&
        Mat1.size == Mat2.size &&
        Mat1.elemSize() == Mat2.elemSize())
    {
        if (Mat1.isContinuous() && Mat2.isContinuous())
        {
            return 0 == memcmp(Mat1.ptr(), Mat2.ptr(), Mat1.total() * Mat1.elemSize());
        }
        else
        {
            const cv::Mat* arrays[] = { &Mat1, &Mat2, 0 };
            uchar* ptrs[2];
            cv::NAryMatIterator it(arrays, ptrs, 2);
            for (unsigned int p = 0; p < it.nplanes; p++, ++it)
                if (0 != memcmp(it.ptrs[0], it.ptrs[1], it.size * Mat1.elemSize()))
                    return false;

            return true;
        }
    }
    return false;
}


void Gamma::change_shadows(std::list<std::shared_ptr<Mat>>& lista, double FromSlider, std::vector<int> wektor)
{
   Mat buffer = lista.front()->clone();
   std::shared_ptr<Mat> src = std::make_shared<Mat>(buffer.clone());
   std::shared_ptr<Mat> dst = std::make_shared<Mat>(buffer.clone());
   
   double invGamma = 1 / FromSlider;
  
    Mat lookUpTable(1, 256, CV_8U);
    uchar* p = lookUpTable.ptr();
    for (int i = 0; i < 256; ++i)
        p[i] = saturate_cast<uchar>(pow(i / 255.0, invGamma) * 255.0);

    
    LUT(*src, lookUpTable, *dst);

    lista.push_front(dst);
 

    
   
}
