
/**
 * @file Photo.h
 * @brief The file contains class which manages the loaded image during the procces of edition.
 * @author Oliwia Mlonek
 */

#pragma once
#include <wx/wx.h>
#include <opencv2/opencv.hpp>
#include <wx/image.h>
#include <list>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace cv;

/**
 * @class Photo
 * @brief Class is reponsible for holding the image and the list with all with all versions of the image that was created, as well as stores data about the properties of the photo.
 */
class Photo
{
	
public:
	/**
   * Create the Photo object.
   */
	Photo();

	/**
   * Destroys object.
   */
	~Photo();

	/**
   * Function allows the access to the private Photo's list of pointers to Mats.
   * @return the list pf pointers to Mats.
   */
	std::list< std::shared_ptr<Mat>>& GetImageList();

	/**
   * Function allows the access to the private Photo's vector which stores the previous brightness values.
   * @return the vector.
   */
	std::vector<int>& GetBrightness();

	/**
   * Function allows the access to the private Photo's vector which stores the previously chosen color spaces.
   * @return the vector.
   */
	std::vector<int>& GetSpaces();

	/**
   * Function loades and opens chosen by the user image to a Mat array ans sets initial values in list and vectors.
   * @param FileName is a string variable which holds name of the image.
   */
	void LoadImageFromFile(std::string FileName);
	


private:
	Mat image;
	std::shared_ptr<Mat> imageToPush;
	std::list<std::shared_ptr<Mat>> ImagesList;
	std::vector<int> brightness;
	std::vector<int> PreviousSpaces;


};


