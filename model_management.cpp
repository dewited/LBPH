#include "model_management.hpp"

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

void csv_write (string csv_filename, vector<Mat> update_images, vector<int> update_label)
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

void model_build(vector<Mat> images, vector<int> labels)
{
	model_lbph -> train(images, labels);
}
void model_update(vector<Mat> images, vector<int> labels)
{
	model_lbph -> update(images, labels);
}
