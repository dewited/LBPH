#ifndef DEFAULT_RUN_H
#define DEFAULT_RUN_H

//******************************************************************************
// Includes

#include "global.hpp"

//******************************************************************************

//******************************************************************************
//Functions

void csv_read (string, vector<Mat>&, vector<int>&);
void csv_write (string, vector<Mat>, vector<int>);
void model_build (vector<Mat>, vector<int>);
void model_update (vector<Mat>, vector<int>);

//******************************************************************************

//******************************************************************************
//Global

extern CascadeClassifier face_cascade;
extern Ptr<FaceRecognizer> model_lbph;

//******************************************************************************

#endif
