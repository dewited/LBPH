//Globals
#include "global.hpp"
#ifndef GLOBAL
#define GLOBAL
string file_name = "lbph_results_400_with_filter.csv";
int conf = 400;
string face_cascade_name = "lbpcascade_frontalface.xml";
//string face_cascade_name = "haarcascade_frontalface_alt.xml";
CascadeClassifier face_cascade;
Ptr<FaceRecognizer> model_lbph = createLBPHFaceRecognizer(1,8,8,8, conf);
#endif
