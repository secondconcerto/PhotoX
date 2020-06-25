#include "Photo.h"



Photo::Photo()
{
}

Photo::~Photo()
{
}

std::list<std::shared_ptr<Mat>>& Photo::GetImageList()
{
	return ImagesList;
}

std::vector<int>& Photo::GetBrightness()
{
	return brightness;
}

std::vector<int>& Photo::GetSpaces()
{
	return PreviousSpaces;
}

void Photo::LoadImageFromFile(std::string FileName)
{
	if (!ImagesList.empty())
	{
		ImagesList.clear();
		brightness.clear();
		//erode.clear();

	}
	destroyAllWindows();
	image = imread(FileName, IMREAD_ANYCOLOR);
	imageToPush = std::make_shared<Mat>(image);
	ImagesList.push_front(imageToPush);
	brightness.insert(brightness.begin(), 0);
	PreviousSpaces.insert(PreviousSpaces.begin(), 5);

}


