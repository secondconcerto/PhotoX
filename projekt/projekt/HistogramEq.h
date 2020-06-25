/**
 * @file HistogramEq.h
 * @brief The file contains class which manipulates the image represented by an n-dimensional dense numerical multi-channel array (Mat) by executing histogram equalization in the image.
 * @author Oliwia Mlonek
 */

#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "ChangeHistogram.h"

 /**
  * @class HistogramEq
  * @brief Responsible for histogram equalization. Implements operations while following the base strategy (ChangeFlip) interface.
  */
class HistogramEq : public ChangeHistogram
{

public:

	/**
	 * Create the HistogramEq object.
	 */
	HistogramEq();

	/**
	 * Destroys objects.
	 */
	~HistogramEq();

	/**
	* Function performs histogram equalization.
	* @param lista is a list containing pointers to previously loaded images in the form of Mats.
	*/
	void change_histogram(std::list<std::shared_ptr<Mat>>& lista);
};
