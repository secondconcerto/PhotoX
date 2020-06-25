/**
 * @file HSV.h
 * @brief The file contains class which manipulates the image represented by an n-dimensional dense numerical multi-channel array (Mat) by changing the color space of the image to HSV.
 * @author Oliwia Mlonek
 */
#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "ChangeSpace.h"


 /**
  * @class HSV
  * @brief responsible for changing the color space of the image to HSV space. Implements operations while following the base strategy (SearchFace) interface.
 */
class HSV : public ChangeSpace
{

public:

	/**
	 * Create the HSV object.
	 */
	HSV();

	/**
	 * Destroys objects.
	 */
	~HSV();

	/**
	* Function performs coversion from BGR color space to HSV.
	* @param lista is a list containing pointers to previously loaded images in the form of Mats.
	* @param wektor is a vector of integers which holds the information about the previous changes of color space made to the given image.
	*/
	void change_space(std::list<std::shared_ptr<Mat>>& lista, std::vector<int> Vector);
};
