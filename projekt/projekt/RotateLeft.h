/**
 * @file RotateLeft.h
 * @brief The file contains class which manipulates the image represented by an n-dimensional dense numerical multi-channel array (Mat) by rotating the image to the left.
 * @author Oliwia Mlonek
 */
#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "ChangeRotation.h"

 /**
  * @class RotateLeft
  * @brief An abstract class responsible for rotating the given image 90 degrees to the left. Implements operations while following the base strategy (ChangeFlip) interface.
  */
class RotateLeft : public ChangeRotation
{
public:

	/**
	 * Create the RotateLeft object.
	 */
	RotateLeft();

	/**
	 * Destroys objects.
	 */
	~RotateLeft();

	/**
	* Function performs image rotation to the left.
	* @param lista is a list containing pointers to previously loaded images in the form of Mats.
	*/
	void change_rotation(std::list<std::shared_ptr<Mat>>& lista);
};