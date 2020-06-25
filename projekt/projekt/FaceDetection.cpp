#include "FaceDetection.h"

FaceDetection::FaceDetection()
{
}

FaceDetection::~FaceDetection()
{
}

void FaceDetection::find_face(std::list<std::shared_ptr<Mat>>& lista)
{
	CascadeClassifier cascade;
	cascade.load("E:/opencv/sources/data/haarcascades/haarcascade_frontalface_alt2.xml");
	double scale = 1;
	Mat buffer = lista.front()->clone();
	Mat finish = detectAndDraw(buffer, cascade, scale);
	lista.push_front(std::make_shared<Mat>(finish));
	
}

Mat FaceDetection::detectAndDraw(Mat& img, CascadeClassifier& cascade, double scale)
{
	vector<Rect> faces;
	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	cascade.detectMultiScale(gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

		for (size_t i = 0; i < faces.size(); i++)
	{
		Rect r = faces[i];
		Scalar color = Scalar(255, 0, 0);
		rectangle(img, Point(cvRound(r.x * scale), cvRound(r.y * scale)), Point(cvRound((r.x +
		r.width - 1) * scale), cvRound((r.y + r.height - 1) * scale)), color, 3, 8, 0);
	}

	return img;

}
