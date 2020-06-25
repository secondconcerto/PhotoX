/**
 * @file FliFlipYpX.h
 * @brief The file contains class which manipulates the image represented by an n-dimensional dense numerical multi-channel array (Mat) by flipping it vertically.
 * @author Oliwia Mlonek
 */
#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "ChangeFlip.h"

 /**
   * @class FlipY
   * @brief Responsible for flipping the image vertically. Implements operations while following the base strategy (ChangeFlip) interface.
   */
class FlipY : public ChangeFlip
{

public:


	/**
	 * Create the FlipY object.
	 */
	FlipY();

	/**
	 * Destroys objects.
	 */
	~FlipY();

	/**
   * Function flips the image vertically.
   * @param lista is a list containing pointers to previously loaded images in the form of Mats.
  */
	void change_flip(std::list<std::shared_ptr<Mat>>& lista);
};

