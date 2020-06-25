/**
 * @file ChangeEffect.h
 * @brief The file contains class which manipulates the image represented by an n-dimensional dense numerical multi-channel array (Mat) by applying morphology operations.
 * @author Oliwia Mlonek
 */
#pragma once
#include <opencv2/opencv.hpp>
#include <unordered_map>
using namespace cv;

/**
 * @class ChangeEffect
 * @brief An abstract class responsible for applying chosen operation to the image. The class interface declares operations common to all supported versions.
 */
class ChangeEffect
{
public:
	/**
   * Create the ChangeEffect object.
   */
	ChangeEffect();

	/**
   * Destroys object.
   */
	~ChangeEffect();

	/**
   * Function applies the chosen operation to the first Mat found on the list.
   * @param lista is a list containing pointers to previously loaded images in the form of Mats.
   * @param morph informs which of the three shapes was chosen for our kernel (a fixed size array of numerical coefficeints) which is responsible for carring out the operations..
   */
	virtual void change_effect(std::list<std::shared_ptr<Mat>>& lista, int morph);
};

