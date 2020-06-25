#include "BGR.h"

BGR::BGR()
{
}

BGR::~BGR()
{
}

void BGR::change_space(std::list<std::shared_ptr<Mat>>& lista, std::vector<int> Vector )
{
	Mat img = lista.front()->clone();
	Mat result = img.clone();
	int i = Vector.at(0);
	switch (i)
	{
	case 1:
		cvtColor(img, result, COLOR_HSV2BGR );
		break;
	case 2:
		cvtColor(img, result, COLOR_RGB2BGR);
		break;
	case 3:
		cvtColor(img, result, COLOR_HLS2BGR);
		break;
	case 4:
		cvtColor(img, result, COLOR_YCrCb2BGR);
	case 5:
		return;
		break;
	}

	lista.push_front(std::make_shared <Mat>(result));
}
