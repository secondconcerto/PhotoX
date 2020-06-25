/**
 * @file ChangeUndo.h
 * @brief The file contains class which manipulates the list of pointers to the images represented by an n-dimensional dense numerical multi-channel array (Mat) by deleting unwanted nodes.
 * @author Oliwia Mlonek
 */
#pragma once
#include <memory>
#include <opencv2/opencv.hpp>
using namespace cv;

/**
 * @class ChangeUndo
 * @brief An abstract class responsible for getting rid of images with unwanted changes. The class interface declares operations common to all supported versions.
 */
class ChangeUndo
{
public:
	
	/**
	 * Create the ChangeUndo object.
	 */
	ChangeUndo();

	/**
	 * Destroys objects.
	 */
	~ChangeUndo();
	/**
	* Function erases unwanted images from a list.
	* @param lista is a list containing pointers to previously loaded images in the form of Mats.
	*/
	virtual void change_undo(std::list<std::shared_ptr<Mat>>& lista);
};