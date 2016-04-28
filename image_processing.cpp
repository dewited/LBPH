#include "image_processing.hpp"

void detect_crop( vector<Mat>& frame)
{
/*	Mat frame_gray;
	for(int space =0; space < frame.size(); space++)
	{
		vector<Rect> faces;
		frame_gray = frame[space];
		face_cascade.detectMultiScale( frame_gray, faces, 1.1, 1.1, 0|CASCADE_SCALE_IMAGE, Size(0, 0) );
		for( size_t i = 0; i < faces.size(); i++ )
		{
			Mat faceROI = frame[space]( faces[i] );
			//resize(faceROI, faceROI, Size((int)(frame[1].cols),(int)(frame[1].rows))); 
			frame[space]=faceROI;
		}
	    	faces.clear();
    	}
   */
	for (int x = 0; x < frame.size(); x++)
	{
		vector<Rect_<int> > face;
		face_cascade.detectMultiScale(frame[x], face);
		for (int i = 0; i < face.size(); i++)
		{
			Rect face_i = face[i];
			Mat faces = frame[x](face_i);
			//rectangle(frame[x], face_i, CV_RGB(0,255,0), 1);
			frame[x]=frame[x](face_i);
			//resize(faces, frame[x], Size(frame[0].rows, frame[0].cols), 1.0, 1.0, INTER_CUBIC);
		}
	}
}

void equalize_fastnldenoising(vector<Mat>& frame)
{
	float filter_length = 3;
	int template_window_size = 7;
	int search_window_size = 21;
	for (int space = 0; space < frame.size(); space++)
	{
		//cvtColor(frame[space], frame[space], CV_BGR2GRAY);
		equalizeHist(frame[space], frame[space]);
		//fastNlMeansDenoising(frame[space], frame[space],template_window_size, search_window_size);
	}
}