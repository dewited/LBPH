#include "user_inputs.hpp"
void user_predict(Mat& user)
{
	Mat frame_gray;
	Mat input;
	string user_keeper = "n";
	VideoCapture cap(0);
	while( user_keeper == "n" or user_keeper == "N")
	{
		for(;;)
		{
			vector<Rect_<int> > face;
			cap >> input;
			namedWindow("User", WINDOW_AUTOSIZE);
			namedWindow("Frame", WINDOW_AUTOSIZE);
			cvtColor(input, frame_gray, CV_RGB2GRAY);
			face_cascade.detectMultiScale(frame_gray, face, 1.1, 4, (60,60));
	   		for (int i = 0; i < face.size(); i++)
	   		{
				user = frame_gray(face[i]);
				rectangle(input, face[i], CV_RGB(0, 255, 0), 1);	    	
	    			imshow("User", user);
			}
			
			imshow("Frame", input);
			if(waitKey(30) >=0) break;
		}
		cout << "would you like to keep this image? (Y/N)" << endl;
		cin>> user_keeper;
	}
	destroyWindow("User");
	destroyWindow("Frame");
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
	for (int v = 0; v < 10; v++)
	{
		while(user_keeper == "n" or user_keeper == "N")
		{
        		cout << "Push Enter to take picture ("<<v+1<<"/10)" << endl;
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
        		cout << "Would you like to keep this picture? (Y/N)" << endl;
			cin >> user_keeper;
			if (user_keeper == "y" or user_keeper == "Y");
			{
				imshow("Frame", frame_out);
				update.push_back(frame_out);
        			update_label.push_back(current_pos);
			}
		} 
		user_keeper = "n";
	}
		destroyWindow("Frame");
		destroyWindow("Input");
}
