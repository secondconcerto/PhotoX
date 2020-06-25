/**
 * @file SearchFace.h
 * @brief The file contains class which is designed to detect all human faces that are in a given image (represented by an n-dimensional dense numerical multi-channel array- Mat).
 * @author Oliwia Mlonek
 */
#pragma once
#include <memory>
#include <opencv2/opencv.hpp>
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/core/core_c.h>
#include <iostream>

using namespace std;
using namespace cv;

/**
 * @class  SearchFace
 * @brief An abstract clas responsible for finding human faces in the given image. The class interface declares operations common to all supported versions.
 */
class SearchFace
{
public:
	 /**
	* Create the SearchFace object.
	*/
	SearchFace();

	/**
	 * Destroys objects.
	 */
	~SearchFace();

	/**
   * Function detects faces on the given image.
   * @param lista is a list containing pointers to previously loaded images in the form of Mats.
  */
	virtual void find_face(std::list<std::shared_ptr<Mat>>& lista);
};