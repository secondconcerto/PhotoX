/**
 * @file ChangeHistogram.h
 * @brief The file contains class which manipulates the image represented by an n-dimensional dense numerical multi-channel array (Mat) by executing some operations related to image histogram.
 * @author Oliwia Mlonek
 */
#pragma once
#include <memory>
#include <opencv2/opencv.hpp>
using namespace cv;

/**
 * @class ChangeFlip
 * @brief An abstract class responsible for operations related to the image histogram. The class interface declares operations common to all supported versions.
 */
class ChangeHistogram
{
public:

	/**
	 * Create the ChangeHistogram object.
	 */
	ChangeHistogram();

	/**
	 * Destroys objects.
	 */
	~ChangeHistogram();


	 /**
	* Function performs histogram-related operations.
	* @param lista is a list containing pointers to previously loaded images in the form of Mats.
	*/
	virtual void change_histogram(std::list<std::shared_ptr<Mat>>& lista);
};

