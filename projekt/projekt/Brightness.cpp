#include "Brightness.h"

Brightness::Brightness()
{
}

Brightness::~Brightness()
{
}

void Brightness::change_shadows(std::list<std::shared_ptr<Mat>>& lista, double FromSlider, std::vector<int> wektor)
{
    Mat buffer = lista.front()->clone();
    std::shared_ptr<Mat> final = std::make_shared<Mat>(buffer.clone());
    Mat new_image = Mat::zeros(final->size(), final->type());

    
    int beta = FromSlider * (2);
    int beta_poprzednia = wektor.at(0) * 2;


    for (int y = 0; y < final->rows; y++) {
        for (int x = 0; x < final->cols; x++) {
            for (int c = 0; c < final->channels(); c++) {
                uchar piksel = final->at<Vec3b>(y, x)[c];
                uchar default_piksel = saturate_cast<uchar>(piksel - beta_poprzednia);
                new_image.at<Vec3b>(y, x)[c] =
                    saturate_cast<uchar>(1*default_piksel + beta);

            }
        }
    }


 lista.push_front(std::make_shared<Mat>(new_image));

        
  
}

