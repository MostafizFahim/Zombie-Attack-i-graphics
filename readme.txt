Last updated: 16 December 2017 
####################################

To make it work, you need to include stb_image.h in your project.

2 new functions in iGraphics.h which are iLoadImage(filename) and iShowImage(x, y, width, height, id). Here's the functionalities:

1) int iLoadImage(filename): returns an integer id for the image specified in filename. The id will be used later for rendering (like file pointer). This function needs to be invoked in the main function.

2) void iShowImage(x, y, width, height, id): render the image of specific id obtained from previous function. Image will be rendered at (x,y) with width and height (like iRectangle()). So you can scale the image by tweaking width and height.

Note that, other image functions, i.e. iShowBMP(), iShowBMP2(), iShowBMPAlternative() etc. will also work as they are. Feel free to use whichever you want.

iMain.cpp is an example where these functions are invoked to render png images. The images are in ./images.

Note that, there is a new function iStart() that needs to be called at the end of the main function. Here, iInitialize() will setup the requirements for rendering (i.e. window, axis etc.) and iStart() will start rendering. All of the other inititialization codes should go in between iInitialize() and iStart().

See main() in iMain.cpp for better understanding.



------------
Jubair

