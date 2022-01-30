#include <iostream>
#include <opencv2/opencv.hpp>

#ifdef _DEBUG
#pragma comment(lib, "opencv_world455d.lib")
#else
#pragma comment(lib, "opencv_world455.lib")
#endif

int main()
{
	const char* windowName = "Image";
	

	cv::VideoCapture cap(0);
	if (!cap.isOpened())//カメラデバイスが正常にオープンしたか確認．
	{
		return -1;
	}

	while (1)
	{
		cv::Mat img;
		cap >> img;

		// 必要に応じてここに画像処理
		cv::Mat gray;
		cv::Mat binary;
		cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
		cv::threshold(gray, binary, 127, 255, cv::THRESH_BINARY);

		cv::imshow(windowName, binary);//画像を表示．

		int key = cv::waitKey(1);
		if (key == 113)//qボタンが押されたとき
		{
			break;//whileループから抜ける．
		}
	}
	cv::destroyAllWindows();

	return(0);
}