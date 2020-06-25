/**
 * @file ChangeColor.h
 * @brief The file contains class which manipulates the image represented by an n-dimensional dense numerical multi-channel array (Mat) by changing the colours of the image.
 * @author Oliwia Mlonek
 */
#pragma once
#include <memory>
#include <opencv2/opencv.hpp>
using namespace cv;

/**
 * @class ChangeShadows
 * @brief An abstract clas responsible for applying chosen colours to the image. The class interface declares operations common to all supported versions.
 */

class ChangeColor
{
public:

	/**
   * Create the ChangeColor object.
   */
	ChangeColor();


	/**
   * Destroys object.
   */
	~ChangeColor();

	/**
   * Function applies the chosen colours to the first Mat found on the list.
   * @param lista is a list containing pointers to previously loaded images in the form of Mats.
   */
	virtual void change_color(std::list<std::shared_ptr<Mat>>& lista);
};

