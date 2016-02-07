#ifndef TESTING_H
#define TESTING_H

//******************************************************************************
// Includes
#include "global.hpp"

//******************************************************************************

//******************************************************************************
//Functions

void model_lbph_test (vector<Mat>, vector<int>, vector<int>&, vector<int>&);
void write_file (vector<int>, vector<int>);
void image_show (vector<Mat>, vector<int>);
static Mat norm_0_255 (InputArray);

//******************************************************************************

//******************************************************************************
//Globals
extern int conf;
extern string file_name;
extern Ptr<FaceRecognizer> model_lbph;
//******************************************************************************

#endif
