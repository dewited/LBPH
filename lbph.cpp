#include "lbph.hpp"
#include "default_run.hpp"
#include "testing.hpp"
#include "user_inputs.hpp"

//For which functions will run
//For actual program
#define csv_read_run 1
#define equalize_fastnldenoising_run 0
#define detect_crop_run 0
#define model_build_run 1
#define user_train_run 1
#define user_test 0
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
	if( !face_cascade.load( face_cascade_name ) or !eye_cascade.load(eye_cascade_name) )
	{ 
		printf("--(!)Error loading cascade\n"); 
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
		int current_label = labels[labels.size()-1]+1;
		int image_pass = 0;
		int retake = 0;
		int g = 0;
		int training_size = 0;
		string image_keep;
		user_train (current_label, train_images, train_labels, 10);
		cout << "Passed user pictured input" << endl;
		cout << image_pass << endl;
		cout << train_images.size()<< train_labels.size() << endl;
		while(image_pass < 10)
		{
			training_size = train_images.size();
			namedWindow("Check", WINDOW_AUTOSIZE);
			while(g < training_size)
			{
				imshow("Check", train_images[g]);
				waitKey(200);
				cout << "Would you like to keep this image? Y/N" << endl;
				cin >> image_keep;
				if (image_keep == "N" or image_keep == "n")
				{
					retake++;
					train_images.erase(train_images.begin()+g);
					train_labels.erase(train_labels.begin()+g);
					training_size = training_size-1;

				}
				if(image_keep =="Y" or image_keep =="y")
				{
					image_pass++;
					g++;
				}
			}
			destroyWindow("Check");
			model_update(train_images, train_labels);
			for(int i = 0; i < train_images.size(); i++)
			{
				images.push_back(train_images[i]);
				labels.push_back(train_labels[i]);
				train_images.clear();
				train_labels.clear();
			}
			if (retake !=0)
			{
				
				user_train(current_label, train_images, train_labels, retake);
				retake =0;
				g = 0;
			}
		}
	//	equalize_fastnldenoising(train_images);
	//	cout << "Passed equalize" << endl;
	//	detect_crop	(train_images);	
//		csv_update 	(filename, train_images, train_labels);
	}
	
	if (user_test == 1)
	{
		cout << "starting user test" << endl;
		user_predict(image_user);
		//train_images.push_back(image_user);	
		//equalize_fastnldenoising(train_images);
		//detect_crop(train_images);
		//image_user = train_images[0];	
		int label_user = model_lbph -> predict(image_user);
		cout << "Predicted User is: " << label_user << endl;
		namedWindow("Predicted", WINDOW_AUTOSIZE);
		namedWindow("Test", WINDOW_AUTOSIZE);
		imshow("Predicted", images[label_user*10+1]);
		imshow("Test", image_user);
		waitKey();
		//train_images.clear();
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
