#include "testing.hpp"
void model_lbph_test (vector<Mat> images, vector<int> label, vector<int>& actual_label, vector<int>& predicted_label)
{
	vector<Mat> images_1D_train;
	vector<int> train_label;
	Mat image_test;
	int q = 0;

	while (q < images.size())
	{
		images_1D_train = images;

		// image to test against database is set
		image_test = images_1D_train[q];

		// remove the image to be tested from the database
		images_1D_train.erase(images_1D_train.begin()+q);

		//put the label of the image to be tested intoa vector that will be stored
		actual_label.push_back(label[q]);

		//create a label for the database set
		train_label=label;

		// removes the test label from the database set
		train_label.erase(train_label.begin()+q);

		//creates the model
		Ptr<face::FaceRecognizer> model = face::createLBPHFaceRecognizer(1,8,8,8, conf);

		//trains the model
		model -> train(images_1D_train, train_label);

		predicted_label.push_back( model -> predict(image_test));
		
		cout << "Run: "<< q << " Actual: " << actual_label.back() << " Predicted: " << predicted_label.back()<< endl; 
		
	    q++;

		train_label.clear();

		images_1D_train.clear();
	}
}

void write_file(vector<int>  predicted_label, vector<int> actual_label)
{
	ofstream outputFile;
	outputFile.open(file_name.c_str());
	int correct, wrong, unknown = 0;
	for ( int x = 0; x < predicted_label.size(); x++)
	{
		if( predicted_label[x] != actual_label[x])
		{
			wrong++;
			if (predicted_label[x] == -1)
			{
				unknown++;
			}
		}
		else
		{
			correct++;
		}
	}
	
	outputFile<< "Corect Matches: "<< correct << " Incorrect Matches: " << wrong-unknown << " Unknown Matches: " << unknown << endl;
		
	for (int i =0; i < predicted_label.size(); i++)
	{
		outputFile << actual_label[i] <<"," << predicted_label[i] << endl; 
	}
	outputFile.close();
}

void image_show(vector<Mat> images, vector<int> label)
{
	int i = 0;
	stringstream ss;
	string goob;
	while( i < images.size())
	{
		ss << label[i];
		ss >> goob;
		imshow(goob, images[i]);
		waitKey();
		i = i+10;
	}
}

static Mat norm_0_255(InputArray _src)
{
	Mat src = _src.getMat();
	Mat dst;
	normalize(src, dst, 0, 255, NORM_MINMAX, CV_8UC1);
	return dst;
}
