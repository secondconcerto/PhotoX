/**
 * @file Erode.h
 * @brief The file contains class which manipulates the image represented by an n-dimensional dense numerical multi-channel array (Mat) by applying erosion effect on it.
 * @author Oliwia Mlonek
 */


#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "ChangeEffect.h"

 /**
  * @class Erode
  * @brief Responsible for applying the erosion effect to the image. Implements operations while following the base strategy (ChangeEffect) interface.
 */
  
class Erode : public ChangeEffect
{

public:
public:

	 /**
	* Create the Erode object.
	*/
	Erode();

	/**
   * Destroys object.
   */
	~Erode();

	/**
   * Function applies the erosion effect to the first Mat found on the list.
   * @param lista is a list containing pointers to previously loaded images in the form of Mats.
   * @param morph informs which of the three shapes was chosen for our kernel (a fixed size array of numerical coefficeints) which is responsible for carring out the operation.
   */
	void change_effect(std::list<std::shared_ptr<Mat>>& lista, int morph);
};
