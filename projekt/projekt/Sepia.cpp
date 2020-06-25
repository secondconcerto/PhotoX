#include "Sepia.h"

Sepia::Sepia()
{
}

Sepia::~Sepia()
{
}

void Sepia::change_color(std::list<std::shared_ptr<Mat>>& lista)
{
	cv::Mat kernel =
		(cv::Mat_<float>(3, 3)
			<<
			0.272, 0.534, 0.131,
			0.349, 0.686, 0.168,
			0.393, 0.769, 0.189);

	Mat buffer = lista.front()->clone();
	Mat final = (buffer.clone());
	cv::transform(buffer, final, kernel);

	lista.push_front(std::make_shared<Mat>(final));
	
}
