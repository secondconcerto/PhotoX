#include "Editor.h"

Editor:: Editor()
{

}

Editor::~Editor()
{
}

void Editor::which_color(int which)
{
	if (picture->GetImageList().empty())
		throw(IsNull());
	
	switch (which) {
	case 1:
		choose_color = make_shared<BlackWhite>();
		break;
	case 2: 
		choose_color = make_shared<Grey>();
		break;
	case 3:
		choose_color = make_shared<Sepia>();

	}

	choose_color->change_color(picture->GetImageList());
	
}

void Editor::which_flip(int which)
{
	if (picture->GetImageList().empty())
		throw(IsNull());

	switch (which)
	{
	case 1:
		choose_flip = make_shared<FlipX>();
		break;
	case 2:
		choose_flip = make_shared<FlipY>();
		break;
	case 3:
		choose_flip = make_shared<FlipXY>();
		break;

	}
		choose_flip->change_flip(picture->GetImageList());

}

void Editor::which_undo(int which)
{
	if (picture->GetImageList().empty())
		throw(IsNull());
	else if (picture->GetImageList().size() == 1)
		throw(IsOneElementOnly());

	switch (which)
	{
	case 1:
		choose_undo = make_shared<UndoOne>();
		break;
	case 2:
		choose_undo = make_shared<UndoAll>();
		break;

	}
	choose_undo->change_undo(picture->GetImageList());

}

void Editor::which_shadow(int which, double HowMuch, std::vector<int> wektor)
{
	if (picture->GetImageList().empty())
		throw(IsNull());

	switch (which)
	{
	case 1:
		choose_shadows = make_shared<Brightness>();
		break;
	case 2:
		choose_shadows = make_shared<Gamma>();
		break;
	}
	choose_shadows->change_shadows(picture->GetImageList(), HowMuch, wektor);

}

void Editor::which_face()
{
	if (picture->GetImageList().empty())
		throw(IsNull());


	choose_face = make_shared<FaceDetection>();
	choose_face->find_face(picture->GetImageList());
	auto it = std::next(picture->GetImageList().begin(), 1);
	
	if (CheckMatEquality(*picture->GetImageList().front(), (**it)))
		throw(NoFaceFound());
}

void Editor::which_rotation(int which)
{
	if (picture->GetImageList().empty())
		throw(IsNull());

	switch(which)
	{
	case 1:
		choose_rotation = make_shared<RotateLeft>();
		break;
	case 2:
		choose_rotation = make_shared<RotateRight>();
		break;

	}
	choose_rotation->change_rotation(picture->GetImageList());
}

void Editor::which_histogram(int which)
{
	if (picture->GetImageList().empty())
		throw(IsNull());

	switch (which)
	{
	case 1:
		choose_histogram = make_shared<ShowHistogram>();
		break;
	case 2:
		choose_histogram = make_shared<HistogramEq>();
		break;

	}
	choose_histogram->change_histogram(picture->GetImageList());
}

void Editor::which_space(int which, std::vector<int> Vector )
{
	if (picture->GetImageList().empty())
		throw(IsNull());

	switch (which)
	{
	case 1:
		choose_space = make_shared<HSV>();
		break;
	case 2:
		choose_space = make_shared<_RGB>();
		break;
	case 3:
		choose_space = make_shared<HLS>();
		break;
	case 4:
		choose_space = make_shared<YCrCb>();
		break;
	case 5:
		choose_space = make_shared<BGR>();
		break;


	}
	choose_space->change_space(picture->GetImageList(), Vector);
}

void Editor::which_effect(int which, int morph)
{
	if (picture->GetImageList().empty())
		throw(IsNull());

	switch (which)
	{
	case 1:
		choose_effect = make_shared<Erode>();
		break;
	case 2:
		choose_effect = make_shared<Dilate>();
		break;

	}
	choose_effect->change_effect(picture->GetImageList(), morph);
}

bool Editor::CheckMatEquality(const cv::Mat Mat1, const cv::Mat Mat2)
{
	if (Mat1.dims == Mat2.dims &&
		Mat1.size == Mat2.size &&
		Mat1.elemSize() == Mat2.elemSize())
	{
		if (Mat1.isContinuous() && Mat2.isContinuous())
		{
			return 0 == memcmp(Mat1.ptr(), Mat2.ptr(), Mat1.total() * Mat1.elemSize());
		}
		else
		{
			const cv::Mat* arrays[] = { &Mat1, &Mat2, 0 };
			uchar* ptrs[2];
			cv::NAryMatIterator it(arrays, ptrs, 2);
			for (unsigned int p = 0; p < it.nplanes; p++, ++it)
				if (0 != memcmp(it.ptrs[0], it.ptrs[1], it.size * Mat1.elemSize()))
					return false;

			return true;
		}
	}
	return false;
}





void Editor::SetPhoto(std::shared_ptr<Photo> X)
{
	picture = X;

}