/**
 * @file Sepia.h
 * @brief The file contains class which manipulates the image represented by an n-dimensional dense numerical multi-channel array (Mat) by changing the colours of the image to black and white only.
 * @author Oliwia Mlonek
 */
#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "ChangeColor.h"


 /**
  * @class Sepia
  * @brief Responsible for applying sepia colour to the image. Implements operations while following the base strategy (ChangeColor) interface.
  */
class Sepia : public ChangeColor
{

public:
	/**
   * Create the Sepia object.
   */
	Sepia();


	/**
   * Destroys object.
   */
	~Sepia();

	/**
   * Function applies the sepia colour to the first Mat found on the list .
   * @param lista is a list containing pointers to previously loaded images in the form of Mats.
   */
	void change_color(std::list<std::shared_ptr<Mat>>& lista);
};

