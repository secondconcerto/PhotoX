/**
 * @file FaceDetection.h
 * @brief The file contains class which is designed to detect all human faces that are in a given image (represented by an n-dimensional dense numerical multi-channel array- Mat).
 * @author Oliwia Mlonek
 */

#pragma once
#include "SearchFace.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

 /**
  * @class FaceDetection
  * @brief Responsible for finding human faces in the given image and outlining the area in which they are located. Implements operations while following the base strategy (SearchFace) interface.
 */
  
class FaceDetection : public SearchFace
{

public:

	/**
	 * Create the FaceDetection object.
	 */
	FaceDetection();

	/**
	 * Destroys objects.
	 */
	~FaceDetection();

	/**
   * Function prepares necessary variables and files to perform face detection operation. 
   * @param lista is a list containing pointers to previously loaded images in the form of Mats.
  */
	void find_face(std::list<std::shared_ptr<Mat>>& lista);

	 /**
	* Function that actually finds a face in a given image and contours it.
	* @param img is a Mat respresenting the chosen image.
	* @param cascade is a chosen cascade classifier.
	* @return A Mat of changed image.
	*/
	Mat detectAndDraw(Mat& img, CascadeClassifier& cascade, double scale);
};
