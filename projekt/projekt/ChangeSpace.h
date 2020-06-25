/**
 * @file ChangeSpace.h
 * @brief The file contains class which manipulates the image represented by an n-dimensional dense numerical multi-channel array (Mat) by changing the color space of the image.
 * @author Oliwia Mlonek
 */
#pragma once
#include <memory>
#include <opencv2/opencv.hpp>
#include <opencv2/core/types_c.h>
using namespace cv;
/**
 * @class ChangeSpace
 * @brief An abstract class responsible for changing the color space of the image. The class interface declares operations common to all supported versions.
 */
class ChangeSpace
{
public:
	
	/**
	 * Create the ChangeSpace object.
	 */
	ChangeSpace();

	/**
	 * Destroys objects.
	 */
	~ChangeSpace();


	/**
	* Function performs coversion from  current color space to another.
	* @param lista is a list containing pointers to previously loaded images in the form of Mats.
	* @param wektor is a vector of integers which holds the information about the previous changes of color space made to the given image.
	*/
	virtual void change_space(std::list<std::shared_ptr<Mat>>& lista, std::vector<int> Vector );
};

