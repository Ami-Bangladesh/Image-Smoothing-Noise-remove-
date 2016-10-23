Smoothing:
Smoothing, also called blurring, is an image-processing operation that is frequently
used to reduce noise, among other purposes. A smoothing operation is performed by
applying linear filters to the image. Then, the pixel values of the output at positions
(xi,yj) are computed as a weighted sum of the input pixel values at positions (xi,yj) and
their neighborhoods. The weights for the pixels in the linear operation are usually
stored in a matrix called kernel. Therefore, a filter could be represented as a sliding
window of coefficients.

Median, Gaussian, and bilateral are the most used OpenCV smoothing filters.
Median filtering is very good to get rid of salt-and-pepper or speckle noise, while
Gaussian is a much better preprocessing step for edge detection. On the other
hand, bilateral filtering is a good technique to smooth an image while respecting
strong edges.

The functions included in OpenCV for this purpose are:

• void boxFilter(InputArray src, OutputArray dst, int ddepth,
Size ksize, Point anchor = Point(-1,-1), bool normalize = true,
int borderType = BORDER_DEFAULT): This is a box filter whose kernel
coefficients are equal. With normalize=true, each output pixel value is the
mean of its kernel neighbors with all coefficients equal to 1/n, where n = the
number of elements. With normalize=false, all coefficients are equal to 1.
The src argument is the input image, while the filtered image is stored in
dst. The ddepth parameter indicates the output image depth that is -1 to use
the same depth as the input image. The kernel size is indicated in ksize. The
anchor point indicates the position of the so-called anchor pixel. The (-1, -1)
default value means that the anchor is at the center of the kernel. Finally, the
border-type treatment is indicated in the borderType parameter.

• void GaussianBlur(InputArray src, OutputArray dst, Size ksize,
double sigmaX, double sigmaY = 0, int borderType=BORDER_
DEFAULT): This is done by convolving each point in the src input array
with a Gaussian kernel to produce the dst output. The sigmaX and sigmaY
parameters indicate the Gaussian kernel standard deviation in X and Y
directions. If sigmaY is zero, it is set to be equal to sigmaX, and if both are
equal to zero, they are computed using the width and height given in ksize.

• void medianBlur(InputArray src, OutputArray dst, int ksize):
This runs through each element of the image and replaces each pixel with the
median of its neighboring pixels.
