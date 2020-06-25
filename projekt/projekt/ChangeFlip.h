/**
 * @file ChangeFlip.h
 * @brief The file contains class which manipulates the image represented by an n-dimensional dense numerical multi-channel array (Mat) by flipping it in three ways.
 * @author Oliwia Mlonek
 */
#pragma once
#include <memory>
#include <opencv2/opencv.hpp>
using namespace cv;

/**
 * @class ChangeFlip
 * @brief An abstract class responsible for flipping the image. The class interface declares operations common to all supported versions.
 */
class ChangeFlip 
{
public:
	/**
	 * Create the FaceDetection object.
	 */
	ChangeFlip();

	/**
	 * Destroys objects.
	 */
	~ChangeFlip();

	/**
   * Function flips the image.
   * @param lista is a list containing pointers to previously loaded images in the form of Mats.
   */
	virtual void change_flip(std::list<std::shared_ptr<Mat>>& lista);
};


