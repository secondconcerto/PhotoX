/**
 * @file BlackWhite.h
 * @brief The file contains class which manipulates the image represented by an n-dimensional dense numerical multi-channel array (Mat) by changing the colours of the image to black and white only.
 * @author Oliwia Mlonek
 */
#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "ChangeColor.h"

 /**
  * @class BlackWhite
  * @brief Responsible for applying black and white colour to the image. Implements operations while following the base strategy (ChangeColor) interface.
  */
class BlackWhite :
	public ChangeColor
{

public:
	/**
   * Create the BlackWhite object.
   */
	BlackWhite();


	/**
   * Destroys object.
   */
	~BlackWhite();


	/**
   * Function applies the black and white colours to the first Mat found on the list .
   * @param lista is a list containing pointers to previously loaded images in the form of Mats.
   */
	void change_color(std::list<std::shared_ptr<Mat>>& lista);
};

