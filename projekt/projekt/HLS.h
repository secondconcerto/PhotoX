/**
 * @file HLS.h
 * @brief The file contains class which manipulates the image represented by an n-dimensional dense numerical multi-channel array (Mat) by changing the color space of the image to HLS.
 * @author Oliwia Mlonek
 */
#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "ChangeSpace.h"

 /**
  * @class HLS
  * @brief responsible for changing the color space of the image to HLS space. Implements operations while following the base strategy (SearchFace) interface.
 */
class HLS : public ChangeSpace
{

public:

	/**
	 * Create the HLS object.
	 */
	HLS();

	/**
	 * Destroys objects.
	 */
	~HLS();

	/**
	* Function performs coversion from BGR color space to HLS.
	* @param lista is a list containing pointers to previously loaded images in the form of Mats.
	* @param wektor is a vector of integers which holds the information about the previous changes of color space made to the given image.
	*/
	void change_space(std::list<std::shared_ptr<Mat>>& lista, std::vector<int> Vector);
};
