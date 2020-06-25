/**
 * @file FlipX.h
 * @brief The file contains class which manipulates the image represented by an n-dimensional dense numerical multi-channel array (Mat) by flipping it horizontally.
 * @author Oliwia Mlonek
 */
#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "ChangeFlip.h"

 /**
  * @class FlipX
  * @brief Responsible for flipping the image horizontally. Implements operations while following the base strategy (ChangeFlip) interface.
  */
class FlipX : public ChangeFlip
{

public:

	/**
	 * Create the FaceDetection object.
	 */
	FlipX();

	/**
	 * Destroys objects.
	 */
	~FlipX();

	/**
   * Function flips the image horizontally.
   * @param lista is a list containing pointers to previously loaded images in the form of Mats.
  */
	void change_flip(std::list<std::shared_ptr<Mat>>& lista);
};

