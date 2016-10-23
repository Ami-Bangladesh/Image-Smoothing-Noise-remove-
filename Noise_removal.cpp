#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include<iostream>
#include<conio.h>           // may have to modify this line if not using Windows

using namespace std;
using namespace cv;

int main( int argc, char** argv )
{
// Read the source file
Mat src;
src = imread("Tazmahal.jpg",IMREAD_COLOR);
// Apply the filters
Mat dst, dst2;
GaussianBlur( src, dst, Size( 9, 9 ), 0, 0);
medianBlur( src, dst2, 9);
// Show the results
namedWindow( " ORIGINAL ", WINDOW_AUTOSIZE );
imshow( " ORIGINAL ", src );
namedWindow( " GAUSSIAN BLUR ", WINDOW_AUTOSIZE );
imshow( " GAUSSIAN BLUR ", dst );
namedWindow( " MEDIAN BLUR ", WINDOW_AUTOSIZE );
imshow( " MEDIAN BLUR ", dst2 );
waitKey();
return 0;
}