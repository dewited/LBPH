#include "opencv2/objdetect.hpp"
//#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/core.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/core/ocl.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/calib3d.hpp"
#include "opencv2/xfeatures2d.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/face.hpp"
//Needed for Filter
#include "opencv2/photo.hpp"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <vector>

//for checking fps;
#include <time.h>
// for making directory
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;
using namespace cv::face;
