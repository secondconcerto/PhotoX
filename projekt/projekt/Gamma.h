/**
 * @file Gamma.h
 * @brief The file contains class which manipulates the image represented by an n-dimensional dense numerical multi-channel array (Mat) by changing the lighting of the image using gamma correction.
 * @author Oliwia Mlonek
 */
#pragma once
#include "ChangeShadows.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

 /**
  * @class Gamma
  * @brief Responsible for changing the gamma correction of the image. Implements operations while following the base strategy (ChangeShadows) interface.
  */


class Gamma : public ChangeShadows
{

public:
	/**
   * Create the Brightness object.
   */
	Gamma();

	/**
   * Destroys object.
   */
	~Gamma();

	/**
   * Function brightens or darkens the first Mat found on the list with the selected intensity by adjusting gamma correction.
   * @param lista is a list containing pointers to previously loaded images in the form of Mats.
   * @param FromSlider is a double variable that stores the intensity value set by the user.
   * @param wektor is a vector of integers which holds previously set values from slider.
   */
	void change_shadows(std::list<std::shared_ptr<Mat>>& lista, double FromSlider, std::vector<int> wektor);
	bool matIsEqual(const cv::Mat Mat1, const cv::Mat Mat2);
};
