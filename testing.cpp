#include "testing.hpp"
void model_lbph_test (vector<Mat> images, vector<int> label, vector<int>& actual_label, vector<int>& predicted_label)
{
	//1 dimensional vector to test
	vector<Mat> images_1D_train;
	// 1 dimensional label that correlates to the 1 dimensional test vector
	vector<int> train_label;
	// image being tested against the database
	Mat image_test;
	//variable to rotate through the database
	int q = 0;
	//loops through the database
	while (q < images.size())
	{
		//assigns the input database to a test database that will be altered
		images_1D_train = images;

		// image to test against database is set
		image_test = images_1D_train[q];

		// remove the image to be tested from the test database
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
		
		//predicts the label and stores it in a vector
		predicted_label.push_back( model -> predict(image_test));
		
		//couts results
		cout << "Run: "<< q << " Actual: " << actual_label.back() << " Predicted: " << predicted_label.back()<< endl; 
		
		//loops through databse
	    	q++;
		
		//clears both vectors
		train_label.clear();

		images_1D_train.clear();
	}
}

//function to write to csv file to store the results of the test
void write_file(vector<int>  predicted_label, vector<int> actual_label)
{
	// opens up an output stream
	ofstream outputFile;
	// opens or creates a file based on the desired filename
	outputFile.open(file_name.c_str());
	// gives us the information for the amount of correct/wrong/unknown predictions
	int correct, wrong, unknown = 0;
	// loops through the input vectors writing out to the csv file
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
	
	//writes amount of correct matches
	outputFile<< "Corect Matches: "<< correct << " Incorrect Matches: " << wrong-unknown << " Unknown Matches: " << unknown << endl;
	
	//outputs results
	for (int i =0; i < predicted_label.size(); i++)
	{
		outputFile << actual_label[i] <<"," << predicted_label[i] << endl; 
	}

	//closes file
	outputFile.close();
}

// for test only
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
//ignore to display eigenfaces
static Mat norm_0_255(InputArray _src)
{
	Mat src = _src.getMat();
	Mat dst;
	normalize(src, dst, 0, 255, NORM_MINMAX, CV_8UC1);
	return dst;
}
