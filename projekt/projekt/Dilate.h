/**
 * @file Dilate.h
 * @brief The file contains class which manipulates the image represented by an n-dimensional dense numerical multi-channel array (Mat) by applying dilation effect on it.
 * @author Oliwia Mlonek
 */
#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "ChangeEffect.h"

/**
 * @class Dilate
 * @brief Responsible for applying the dilation effect to the image. Implements operations while following the base strategy (ChangeEffect) interface.
 */
class Dilate : public ChangeEffect
{

public:

	/**
   * Create the ChangeEffect object.
   */
	Dilate();

	/**
   * Destroys object.
   */
	~Dilate();

	/**
   * Function applies the dilation effect to the first Mat found on the list.
   * @param lista is a list containing pointers to previously loaded images in the form of Mats.
   * @param morph informs which of the three shapes was chosen for our kernel (a fixed size array of numerical coefficeints) which is responsible for carring out the operation.
   */
	void change_effect(std::list<std::shared_ptr<Mat>>& lista,  int morph);
};
