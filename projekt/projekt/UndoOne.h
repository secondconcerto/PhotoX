/**
 * @file UndoOne.h
 * @brief The file contains class which manipulates the list of pointers to the images represented by an n-dimensional dense numerical multi-channel array (Mat) by deleting unwanted (first) node.
 * @author Oliwia Mlonek
 */
#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "ChangeUndo.h"

 /**
  * @class UndoOne
  * @brief responsible for getting rid of the last created image with unwanted change. Implements operations while following the base strategy (SearchFace) interface.
  */
class UndoOne :
	public ChangeUndo
{
	
public:

	/**
	 * Create the UndoOne object.
	 */
	UndoOne();

	/**
	 * Destroys objects.
	 */
	~UndoOne();

	/**
	* Function erases unwanted image from a beggining of a list, so the image before the last change will be displayed again.
	* @param lista is a list containing pointers to previously loaded images in the form of Mats.
	*/
	void change_undo(std::list<std::shared_ptr<Mat>>& lista);
};