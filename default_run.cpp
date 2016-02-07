#include "default_run.hpp"

void csv_read(string csv_filename, vector<Mat>& images, vector<int>& label)
{
    	string line;
    	string path;
    	string seperator = ";";
    	ifstream file(csv_filename.c_str());
    	int lab_start= 0;
	string lab;
    	
	if (!file)
    	{
        	cout <<"File does not exist"<<endl;
    	}
	
    	else
    	{
		while (file.good())
        	{    
              		getline (file, line);
			lab_start = line.find(seperator);
			path = line.substr(0, lab_start);
                	lab = line.substr(lab_start+1, line.length()-lab_start-1);
				label.push_back((atoi(lab.c_str())));
                    		images.push_back(imread(path, CV_LOAD_IMAGE_GRAYSCALE));
		}
    	}
}

void csv_update (string csv_filename, vector<Mat> update_images, vector<int> update_label)
{
	ofstream csv_file (csv_filename.c_str(), ifstream::app);
	stringstream line_update;
	line_update <<"/home/pi/Downloads/att_faces/"<<update_label[0]+1;
	cout << line_update.str() << endl;
	mkdir(line_update.str().c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	if(!csv_file)	{ cout<<"CSV File does not exist" << endl;}
	else
	{
		for( int i = 0; i < update_images.size(); i++)
		{
			line_update.str("");
			line_update.clear();
			line_update << "/home/pi/Downloads/att_faces/"<<update_label[i]+1<<"/"<<i<<".pgm";
			csv_file <<"\n"<<line_update.str()<<";"<<update_label[i];
			imwrite(line_update.str(), update_images[i]);
		}
	}
}

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

void model_build(vector<Mat> images, vector<int> labels)
{
	model_lbph -> train(images, labels);
}
void model_update(vector<Mat> images, vector<int> labels)
{
	model_lbph -> update(images, labels);
}
