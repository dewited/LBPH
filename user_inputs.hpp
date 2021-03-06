#ifndef USER_INPUTS_H
#define USER_INPUTS_H

//******************************************************************************
// Includes
#include "global.hpp"
//#include "lbph.hpp"
//******************************************************************************

//******************************************************************************
//Functions

void user_predict (Mat&);
void user_train ( int, string, vector<Mat>&, vector<int>&);

//******************************************************************************

//******************************************************************************
//Globals

extern Ptr<FaceRecognizer> model_lbph;
extern CascadeClassifier face_cascade;
//******************************************************************************
#endif
