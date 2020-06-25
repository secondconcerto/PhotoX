/**
 * @file UndoAll.h
 * @brief The file contains class which manipulates the list of pointers to the images represented by an n-dimensional dense numerical multi-channel array (Mat) by deleting all but the last one elements from the list.
 * @author Oliwia Mlonek
 */
#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "ChangeUndo.h"


 /**
   * @class UndoAll
   * @brief responsible for getting rid of all but the last one images from the list. Implements operations while following the base strategy (SearchFace) interface.
   */
class UndoAll :
	public ChangeUndo
{

public:

	/**
	 * Create the UndoAll object.
	 */
	UndoAll();

	/**
	 * Destroys objects.
	 */
	~UndoAll();

	/**
	* Function erases all but the last one images from the list, so the image can be displayed as it was before making any change.
	* @param lista is a list containing pointers to previously loaded images in the form of Mats.
	*/
	void change_undo(std::list<std::shared_ptr<Mat>>& lista);
};