/**
 * @file Editor.h
 * @brief The file contains class which maintains a reference to one of the concrete strategies and communicates with this object only via the strategy interface.
 * @author Oliwia Mlonek
 */

#pragma once
#include "Photo.h"
#include "ChangeColor.h"
#include "ChangeFlip.h"
#include "ChangeUndo.h"
#include "ChangeShadows.h"
#include "ChangeRotation.h"
#include "ChangeHistogram.h"
#include "ChangeEffect.h"
#include "ChangeSpace.h"
#include "SearchFace.h"
#include "BlackWhite.h"
#include "Grey.h"
#include "Sepia.h"
#include "FlipX.h"
#include "FlipY.h"
#include "FlipXY.h"
#include "UndoOne.h"
#include "UndoAll.h"
#include "Brightness.h"
#include "Gamma.h"
#include "FaceDetection.h"
#include "RotateRight.h"
#include "RotateLeft.h"
#include "ShowHistogram.h"
#include "HistogramEq.h"
#include "HSV.h"
#include "RBG.h"
#include "HLS.h"
#include "YCrCb.h"
#include "BGR.h"
#include "Erode.h"
#include "Dilate.h"
#include "Exceptions.h"

#include <memory>

 /**
   * @class Editor
   * @brief Class is responsible of maintaining a reference to one of the concrete strategies and communicates with this object only via the strategy interface.
   */
class Editor
{
	
	shared_ptr<ChangeColor> choose_color;
	shared_ptr<ChangeFlip> choose_flip;
	shared_ptr<ChangeUndo> choose_undo;
	shared_ptr<ChangeShadows> choose_shadows;
	shared_ptr<SearchFace> choose_face;
	shared_ptr<ChangeRotation> choose_rotation;
	shared_ptr<ChangeHistogram> choose_histogram;
	shared_ptr<ChangeSpace> choose_space;
	shared_ptr<ChangeEffect> choose_effect;
	shared_ptr<Photo> picture;


public:

	/**
	 * Create the Editor object.
	 */
	Editor();

	/**
	 * Destroys objects.
	 */
	~Editor();

	/**
	* Function assigns the pointer with the Photo object to the Editor attribute. 
	* @param X is a shared pointer to a Photo object.
	*/
	void SetPhoto(std::shared_ptr<Photo> X);

	/**
	* Function assigns strategies to the ChangeColor pointer depending on the user's choice, then calls the appropriate function to perform operations on the photo.
	* @param which is an integer variable informing about the user choice.
	* @throw if the list of Mats is empty.
	*/
	void which_color(int which);

	/**
	* Function assigns strategies to the ChangeFlip pointer depending on the user's choice, then calls the appropriate function to perform operations on the photo.
	* @param which is an integer variable informing about the user choice.
	* @throws IsNull if the list of images is empty.
	*/
	void which_flip(int which);


	/**
	* Function assigns strategies to the ChangeUndo pointer depending on the user's choice, then calls the appropriate function to perform operations on the photo.
	* @param which is an integer variable informing about the user choice.
	* @throws IsNull if the list of images is empty.
	* @throws IsOneElementOnly if the list of images has only one element.
	*/
	void which_undo(int which);

	/**
	* Function assigns strategies to the ChangeShadows pointer depending on the user's choice, then calls the appropriate function to perform operations on the photo.
	* @param which is an integer variable informing about the user choice.
	* @param HowMuch is a double variable that stores information about the intensity of the operation to be performed.
	* @param wektor is a vector of integers which holds previously set values from slider.
	* @throws IsNull if the list of images is empty.
	*/
	void which_shadow(int which, double HowMuch, std::vector<int> wektor);

	/**
	* Function assigns strategies to the SearchFace pointer depending on the user's choice, then calls the appropriate function to perform operations on the photo.
	* @throws IsNull if the list of images is empty.
	* @throws NoFaceFound if no face was detected.
	*/
	void which_face();

	/**
	* Function assigns strategies to the ChangeRotation pointer depending on the user's choice, then calls the appropriate function to perform operations on the photo.
	* @param which is an integer variable informing about the user choice.
	* @throws IsNull if the list of images is empty.
	*/
	void which_rotation(int which);

	/**
	* Function assigns strategies to the ChangeHistogram pointer depending on the user's choice, then calls the appropriate function to perform operations on the photo.
	* @param which is an integer variable informing about the user choice.
	* @throws IsNull if the list of images is empty.
	*/
	void which_histogram(int which);

	/**
	* Function assigns strategies to the ChangeHistogram pointer depending on the user's choice, then calls the appropriate function to perform operations on the photo.
	* @param which is an integer variable informing about the user choice.
	* @param Vector is a vector of integers which holds the information about the previous changes of color space made to the given image.
	* @throws IsNull if the list of images is empty.
	*/
	void which_space(int which, std::vector<int> Vector);

	/**
	* Function assigns strategies to the ChangeEffect pointer depending on the user's choice, then calls the appropriate function to perform operations on the photo.
	* @param which is an integer variable informing about the user choice.
	* @param morph informs which of the three shapes was chosen for our kernel (a fixed size array of numerical coefficeints) which is responsible for carring out the operations..
	* @throws IsNull if the list of images is empty.
	*/
	void which_effect(int which, int morph);

	/**
	* The function checks if two given Mat arrays are equal (i.e. if they are exactly the same).
	* @param Mat1 is a first Mat variable to compare with.
	* @param Mat2 is a  second Mat variable to compare with.
	* @return bool value, true if they are the same, false if they are not.
	*/
	bool CheckMatEquality(const cv::Mat Mat1, const cv::Mat Mat2);
};