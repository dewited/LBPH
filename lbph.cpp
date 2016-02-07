#include "lbph.hpp"
#include "default_run.hpp"
#include "testing.hpp"
#include "user_inputs.hpp"

//For which functions will run
//For actual program
#define csv_read_run 1
#define equalize_fastnldenoising_run 0
#define detect_crop_run 1
#define model_build_run 1
#define user_train_run 1
#define user_test 1
// For testing purpose
#define model_lbph_test_run 0
#define write_file_run 0

/** @function main */
int main( void )
{
	string filename = "/home/pi/Downloads/att_csv.csv";
	string cascade_trainer = "lbpcascade_frontalface.xml";
	vector<Mat> images;
	vector<int> labels;
	vector<int> actual_labels;
	vector<int> predicted_labels;
	vector<int> train_labels;
	vector<Mat> train_images;
	Mat image_user;
	if( !face_cascade.load( face_cascade_name ) )
	{ 
		printf("--(!)Error loading face cascade\n"); 
		return -1; 
	};

//The Following should all be run together
//*****************************************************************************

	if( csv_read_run == 1)
	{
		csv_read	(filename, images, labels); 
		cout <<"CSV read: Pass"<<endl;
	}
	
	if (equalize_fastnldenoising_run ==1)
	{
		equalize_fastnldenoising(images);
		cout << "equalize_fastnldenoising: Pass"<<endl;
	}

	if( detect_crop_run ==1)
	{
		detect_crop	(images);  
		cout<<"DetectAndCrop: Pass" <<endl;
	}

	if( model_build_run == 1)
	{
		model_build( images, labels);
		cout<< "model_build: Pass" << endl;
	}

//*****************************************************************************

	if ( user_train_run == 1)
	{
		user_train 	(labels[labels.size()-1]+1, filename, train_images, train_labels);
		cout << "Passed user pictured input" << endl;
		if (train_images.size() != 0)
		{
			for(int g = 0; g < train_images.size(); g++)
			{
				imshow("Check", train_images[g]);
				waitKey();
			}
		}
	//	equalize_fastnldenoising(train_images);
	//	cout << "Passed equalize" << endl;
	//	detect_crop	(train_images);	
		cout << "Passed detect&crop" << endl;
		//csv_update 	(filename, train_images, train_labels);
		model_update 	(train_images, train_labels);
		for (int i = 0; i < train_images.size(); i++)
		{
			images.push_back(train_images[i]);
			labels.push_back(train_labels[i]);
		}
		train_images.clear();
		train_labels.clear();
	}
	
	if (user_test == 1)
	{
		cout << "starting user test" << endl;
		user_predict(image_user);
		train_images.push_back(image_user);	
		equalize_fastnldenoising(train_images);
		detect_crop(train_images);
		image_user = train_images[0];	
		int label_user = model_lbph -> predict(image_user);
		cout << "Predicted User is: " << label_user << endl;
		train_images.clear();
	}

//The Following is for testing
//*****************************************************************************
	
	if( model_lbph_test_run ==1)
	{
		model_lbph_test	(images, labels, actual_labels, predicted_labels);
		cout << "model_build_test: Pass" << endl;
	}

	if( write_file_run ==1)
	{
		write_file	(predicted_labels, actual_labels);
		cout << "write_file: Pass" << endl;
	}

//*****************************************************************************
	return 0;
}
