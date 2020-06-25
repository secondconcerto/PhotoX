/**
 * @file ChangeShadows.h
 * @brief The file contains class which manipulates the image represented by an n-dimensional dense numerical multi-channel array (Mat) by changing the lighting intensity of the image.
 * @author Oliwia Mlonek
 */
#pragma once
#include <memory>
#include <opencv2/opencv.hpp>
using namespace cv;

/**
 * @class ChangeShadows
 * @brief An abstract clas responsible for applying chosen brightness corrections to the image. The class interface declares operations common to all supported versions.
 */
class ChangeShadows
{
public:

	/**
   * Create the ChangeShadows object.
   */
	ChangeShadows();

	/**
   * Destroys object.
   */
	~ChangeShadows();

	/**
   * Function applies the chosen brightness corrections to the first Mat found on the list with the selected intensity.* @param lista is a list containing pointers to previously loaded images in the form of Mats.
   * @param FromSlider is a double variable that stores the value set by the user on the light intensity slider.
   * @param wektor is a vector of integers which holds previously set values from slider.
   */
	virtual void change_shadows(std::list<std::shared_ptr<Mat>>& lista, double FromSlider, std::vector<int> wektor);
};