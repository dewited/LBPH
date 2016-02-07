#include "user_inputs.hpp"
void user_predict(Mat& user)
{
	Mat frame_gray;
	VideoCapture cap(0);
	for(;;)
	{
		vector<Rect_<int> > face;
		cap >> user;
		namedWindow("User", 1);
		frame_gray = user;
		face_cascade.detectMultiScale(frame_gray, face);
	   	for (int i = 0; i < face.size(); i++)
	   	{
			Rect face_i = face[i];
			rectangle(user, face_i, CV_RGB(0, 255, 0), 1);	    	
	    	}
		imshow("User", user);
		if(waitKey(30) >=0) break;
	}
	cvtColor(user, user, CV_BGR2GRAY);
	//int label = model_lbph->predict(user);
	//cout << "Predicted User: "<< label;
}

/*
void user_train(int current_pos, string filename, vector<Mat>& update, vector<int>& update_label)
{
	Mat frame;
	VideoCapture cap(0);
    	Mat frame_gray;
	Mat frame_out;
	int loop = 0;
	string face_keep;
	//namedWindow("Scene", CV_WINDOW_AUTOSIZE);
	//namedWindow("Face", CV_WINDOW_AUTOSIZE);
	for (int v= 0; v < 10; v++)
	{
		loop = 0;
        	cout << "Push Enter to take picture ("<<v<<"/10)" << endl;
        	while(loop == 0)
        	{	
			vector<Rect_<int> > face;
        	  	cap >> frame;
			cvtColor(frame, frame_gray, CV_RGB2GRAY);
			face_cascade.detectMultiScale(frame_gray, face);
	   		//for (int i = 0; i < face.size(); i++)
	   		//{
				//Rect face_i = face[i];
				//rectangle(frame, face_i, CV_RGB(0, 255, 0), 1);	    	
	    			//frame_out = frame_gray;
				//imshow("Face", frame(face[i]));
				//cin >> face_keep;
				//if(face_keep == "Y")
				//{
				//	frame_out = frame_gray(face[i]);
				//	loop = 1;
				//}	
			//}
			imshow("Scene", frame);
        	    	//if(waitKey(30)>= 0) break;
        	}
		//cvtColor(frame, frame, COLOR_RGB2GRAY);
        	update.push_back(frame_out);
        	update_label.push_back(current_pos);
	}
}
*/

/*void user_train(int current_pos, string filename, vector<Mat>& update, vector<int>& update_label)
{
	Mat frame;
	VideoCapture cap(0);
    
	for (int v = 0; v < 10; v++)
	{
        	cout << "Push Enter to take picture ("<<v<<"/10)" << endl;
        	for(;;)
        	{
        	    cap >> frame;
		    imshow("Input", frame);
        	    if(waitKey(30)>= 0) break;
        	}
		cvtColor(frame, frame, COLOR_RGB2GRAY);
        	update.push_back(frame);
        	update_label.push_back(current_pos);
	}
}*/

void user_train(int current_pos, string filename, vector<Mat>& update, vector<int>& update_label)
{
	Mat frame;
	VideoCapture cap(0);
    	Mat frame_gray;
	Mat frame_out;
	namedWindow("Input", WINDOW_AUTOSIZE);
	namedWindow("Frame", WINDOW_AUTOSIZE);
	for (int v = 0; v < 10; v++)
	{
        	cout << "Push Enter to take picture ("<<v<<"/10)" << endl;
        	for(;;)
        	{	
			vector<Rect_<int> > face;
        	  	cap >> frame;
			cvtColor(frame, frame_gray, CV_RGB2GRAY);
			face_cascade.detectMultiScale(frame_gray,face,  1.3, 5);
	   		for (int i = 0; i < face.size(); i++)
	   		{
				Rect face_i = face[i];
				rectangle(frame, face_i, CV_RGB(0, 255, 0), 1);	    	
	    			frame_out = frame_gray(face[i]);
				imshow("Frame", frame_out);
			}
	    		imshow("Input", frame);
			if(waitKey(1)>= 0) break;
        	}
		//cvtColor(frame, frame, COLOR_RGB2GRAY);
        	update.push_back(frame_out);
        	update_label.push_back(current_pos);
	}
}
