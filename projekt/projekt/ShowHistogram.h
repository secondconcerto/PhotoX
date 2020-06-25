/**
 * @file ShowHistogram.h
 * @brief The file contains class which manipulates the image represented by an n-dimensional dense numerical multi-channel array (Mat) by plotting and displaying image histogram.
 * @author Oliwia Mlonek
 */
#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "ChangeHistogram.h"

 /**
  * @class ShowHistogram
  * @brief Responsible for displaying histogram. Implements operations while following the base strategy (ChangeFlip) interface.
  */
class ShowHistogram : public ChangeHistogram
{

public:

	/**
	 * Create the ChangeHistogram object.
	 */
	ShowHistogram();

	/**
	 * Destroys objects.
	 */
	~ShowHistogram();


	/**
	* Function plots and displays histogram in separate window.
	* @param lista is a list containing pointers to previously loaded images in the form of Mats.
	*/
	void change_histogram(std::list<std::shared_ptr<Mat>>& lista);
};
