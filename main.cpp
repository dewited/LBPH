#include "main.hpp"
#include "model_management.hpp"
#include "testing.hpp"
#include "user_acquisition.hpp"
#include "image_processing.hpp"

//For which functions will run
//For actual program
#define csv_read_run 1
#define equalize_fastnldenoising_run 0
#define detect_crop_run 0
#define model_build_run 1
#define user_train_run 0
#define user_test 1
// For testing purpose
#define model_lbph_test_run 0
#define write_file_run 0

/** @function main */
int main( void )
{
	//csv file that has the information to import the database
	string filename = "/home/pi/Downloads/att_csv.csv";
	//vector to store the database of images
	vector<Mat> images;

	//vector to store the databse labels
	vector<int> labels;

	//actual/predicted labels are for the results performed by the testing
	vector<int> actual_labels;
	vector<int> predicted_labels;
	
	//train_labels and train images are used for the user inputs
	vector<int> train_labels;
	vector<Mat> train_images;

	// used for the prediction of a user input
	Mat image_user;
	
	//if the face_cascade failed to load error out
	if( !face_cascade.load( face_cascade_name ) or !eye_cascade.load(eye_cascade_name) )
	{ 
		printf("--(!)Error loading cascade\n"); 
		return -1; 
	};

//The Following should all be run together
//*****************************************************************************

	//reads in the scv file and imports the database of pictures and labels
	if( csv_read_run == 1)
	{
		csv_read	(filename, images, labels); 
		cout <<"CSV read: Pass"<<endl;
	}
	
	//used to equalize the images that are imported. 
	//This will be removed, assumed that the database is already standardized
	if (equalize_fastnldenoising_run ==1)
	{
		equalize_fastnldenoising(images);
		cout << "equalize_fastnldenoising: Pass"<<endl;
	}
	
	// used to detect and crop on a face
	// will be removed due to the fact it will be assumed that the databse is standardized
	if( detect_crop_run ==1)
	{
		detect_crop	(images);  
		cout<<"DetectAndCrop: Pass" <<endl;
	}
	
	// Used to build the model from the database.
	if( model_build_run == 1)
	{
		model_build( images, labels);
		cout<< "model_build: Pass" << endl;
	}

//*****************************************************************************

	// Used to add a user to the model
	if ( user_train_run == 1)
	{
		//current label is the label that will be applied to the new input user
		int current_label = labels[labels.size()-1]+1;
		
		// Image_pass and retake are used to decipher how many pictures will need to be retaken
		int image_pass = 0;
		int retake = 0;
		
		// G is an arbituary variable for a while loop
		int g = 0;

		// variable for how many of the input pictures we have looped through
		int training_size = 0;

		// allows for user input on whether we keep or discard the picture
		string image_keep;

		//function to get user pictures
		user_train (current_label, train_images, train_labels, 10);
		cout << "Passed user pictured input" << endl;
		
		//loops while we do not have 10 accepted pictures
		while(image_pass < 10)
		{
			//training_size is the amount of pictures we need to go through
			training_size = train_images.size();

			//named window for the images to be shown
			namedWindow("Check", WINDOW_AUTOSIZE);
			
			//while our loop variable is less then the training_size
			while(g < training_size)
			{
				//show the user the image
				imshow("Check", train_images[g]);
				waitKey(200);
				
				//Do we want to keep the image?
				cout << "Would you like to keep this image? Y/N" << endl;
				cin >> image_keep;
				
				//If we dont then we add a count to the # of retakes
				//Delete the image and respective label
				//reduce the size of images we need to go through
				if (image_keep == "N" or image_keep == "n")
				{
					retake++;
					train_images.erase(train_images.begin()+g);
					train_labels.erase(train_labels.begin()+g);
					training_size = training_size-1;

				}

				//If we do keep it we continue the loop
				if(image_keep =="Y" or image_keep =="y")
				{
					image_pass++;
					g++;
				}
			}
			
			//At the end of the loop we destroy the window
			destroyWindow("Check");

			//we update the model with the images that are left
			model_update(train_images, train_labels);

			//Write to the update file
			csv_write 	(filename, train_images, train_labels);
			// Push back the images and labels into the databse of images/labels
			// Clear the training vectors
			for(int i = 0; i < train_images.size(); i++)
			{
				images.push_back(train_images[i]);
				labels.push_back(train_labels[i]);
				train_images.clear();
				train_labels.clear();
			}
			
			//If we have to retake any pictures we repeat and reset the retake variable and g
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
	}
	
	//function to test a user against the database
	if (user_test == 1)
	{
		//sets up the string to see if the picture is valid
		string user_image_check = "n";

		//stating test and setting up a window
		cout << "starting user test" << endl;
		namedWindow("UserCheck", WINDOW_AUTOSIZE);
		
		//While the picture is unacceptable we continue to take pictures
		while( user_image_check == "n" or user_image_check =="N")
		{
			waitKey(200);
			destroyAllWindows();
			waitKey(200);
			user_predict(image_user);
			imshow("UserCheck", image_user);
			cout << "Would you like to keep this image (Y/N)" << endl;
			cin >> user_image_check;
		}
		
		//train_images.push_back(image_user);	
		//equalize_fastnldenoising(train_images);
		//detect_crop(train_images);
		//image_user = train_images[0];	
		
		//Outputs the predicted label and shows the images
		int label_user = model_lbph -> predict(image_user);
		cout << "Predicted User is: " << label_user << endl;
		namedWindow("Predicted", WINDOW_AUTOSIZE);
		imshow("Predicted", images[label_user*10+1]);
		waitKey();
		//train_images.clear();
	}

//The Following is for testing
//*****************************************************************************
	
	//Tests the whole databse
	if( model_lbph_test_run ==1)
	{
		model_lbph_test	(images, labels, actual_labels, predicted_labels);
		cout << "model_build_test: Pass" << endl;
	}
	//Writes the results
	if( write_file_run ==1)
	{
		write_file	(predicted_labels, actual_labels);
		cout << "write_file: Pass" << endl;
	}

//*****************************************************************************
	return 0;
}
