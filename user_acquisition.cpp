#include "user_acquisition.hpp"

void user_predict(Mat& user)
{
	Mat frame_gray;
	Mat input;
	VideoCapture cap(0);
	for(;;)
	{
		vector<Rect_<int> > face;
		cap >> input;
		namedWindow("User", WINDOW_AUTOSIZE);
		namedWindow("Frame", WINDOW_AUTOSIZE);
		cvtColor(input, frame_gray, CV_RGB2GRAY);
		face_cascade.detectMultiScale(frame_gray, face, 1.07, 4, (60,60));
	   	for (int i = 0; i < face.size(); i++)
		{
			user = frame_gray(face[i]);
			rectangle(input, face[i], CV_RGB(0, 255, 0), 1);	    	
	    		imshow("User", user);
		}	
		imshow("Frame", input);
		if(waitKey(1) >=0) break;
	}
	waitKey(200);
	destroyAllWindows();
	waitKey(200);
	//int label = model_lbph->predict(user);
	//cout << "Predicted User: "<< label;
}

void user_train(int current_pos, vector<Mat>& update, vector<int>& update_label, int pic_to_take)
{
	//For testing //
	double scale_factor = 1.07;//was 1.1
	int confidence = 4;//was 2
	Mat frame_temp;
	//******************************//

	Mat frame;
	VideoCapture cap(0);
	Mat frame_gray;
	Mat frame_out;
	vector<Rect_<int> > face;
	vector<Rect_<int> > eye;
	string user_keeper = "n";
	while(!cap.isOpened())
	{
	}
	namedWindow("Input", WINDOW_AUTOSIZE);
	namedWindow("Frame", WINDOW_AUTOSIZE);
	for (int v = 0; v < pic_to_take; v++)
	{
       		cout << "Push Enter to take picture ("<<v+1<<"/" << pic_to_take<<")" << endl;
		for(;;)
        	{	
			cap >> frame;
			cvtColor(frame, frame_gray, CV_RGB2GRAY);
			//frame_gray = frame;
			face_cascade.detectMultiScale(frame_gray,face,  scale_factor, confidence,(60,60));
			for (int i = 0; i < face.size(); i++)
   			{
				if(face[i].x >= 0 && face[i].y >= 0 && face[i].width + face[i].x < frame.cols && face[i].height + face[i].y < frame.rows) 
				{
					frame = frame_gray(face[i]);
					rectangle(frame_gray, face[i], CV_RGB(0, 255, 0), 1);	    	
					frame_out = frame;
					//resize(frame, frame, Size(320, 320));
					//bilateralFilter(frame_gray, frame_temp, 40,80,20);
					imshow("Frame", frame);
				}	
			}
    			face.clear();
			imshow("Input", frame_gray);
			if(waitKey(1)>= 0) break;
        	}
        	update_label.push_back(current_pos);
		update.push_back(frame_out);
	}
	waitKey(200);
	destroyAllWindows();	
	waitKey(200);
	//destroyWindow("Frame");
	//destroyWindow("Input");
}
