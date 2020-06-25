/**
 * @file Brightness.h
 * @brief The file contains class which manipulates the image represented by an n-dimensional dense numerical multi-channel array (Mat) by changing the lighting intensity of the image.
 * @author Oliwia Mlonek
 */
#pragma once
#include "ChangeShadows.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

 /**
  * @class Brightness
  * @brief Responsible for brightening the image. Implements operations while following the base strategy (ChangeShadows) interface.
  */

class Brightness : public ChangeShadows
{
	
public:

	/**
   * Create the Brightness object.
   */
	Brightness();

	/**
   * Destroys object.
   */
	~Brightness();

	/**
   * Function brightens or darkens the first Mat found on the list with the selected intensity.
   * @param lista is a list containing pointers to previously loaded images in the form of Mats.
   * @param FromSlider is a double variable that stores the value set by the user on the light intensity slider.
   * @param wektor  is a vector of integers which holds previously set values from slider.
   */
	void change_shadows(std::list<std::shared_ptr<Mat>>& lista, double FromSlider, std::vector<int> wektor);


};

