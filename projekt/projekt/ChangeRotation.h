/**
 * @file ChangeRotation.h
 * @brief The file contains class which manipulates the image represented by an n-dimensional dense numerical multi-channel array (Mat) by rotating the image.
 * @author Oliwia Mlonek
 */
#pragma once
#include <memory>
#include <opencv2/opencv.hpp>
using namespace cv;

/**
 * @class ChangeRotation
 * @brief An abstract class responsible for rotating the given image. The class interface declares operations common to all supported versions.
 */
class ChangeRotation
{
public:

	/**
	 * Create the ChangeHistogram object.
	 */
	ChangeRotation();

	/**
	 * Destroys objects.
	 */
	~ChangeRotation();

	/**
	* Function performs image rotation.
	* @param lista is a list containing pointers to previously loaded images in the form of Mats.
	*/
	virtual void change_rotation(std::list<std::shared_ptr<Mat>>& lista);
};

