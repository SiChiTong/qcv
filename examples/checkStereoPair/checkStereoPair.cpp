
#include <QApplication>

#include "../cinterface.h"

#include <cv.h>
#include <highgui.h>

using namespace QCV;

bool callBackMouse    ( CMouseEvent *f_mevent_p );

int main(int f_argc_i, char *f_argv_p[])
{
    if (f_argc_i != 3)
    {
        printf("Usage %s left_image right_image\n", f_argv_p[0]);
        exit(1);        
    }
    
    QApplication app (f_argc_i, f_argv_p);
    
    /// Initialize application
    initialize("Top Level Drawing Lists");
    
    /// Read left image.
    cv::Mat img = cv::imread(f_argv_p[1]);

    /// Set screen size.
    setScreenSize( img.size() );

    /// Display left image.
    displayImage ( img, "Left Image", true, 0, 0);

    /// Read right image.
    img = cv::imread(f_argv_p[2]);
    displayImage ( img, "Right Image", true, 1, 0);

    /// Set screen count.
    setScreenCount ( cv::Size(2,1));
    
    /// Set callback functions
    setMouseMovedEventCBF ( &callBackMouse );

    int retval_i = app.exec();

    terminate();

    return retval_i;
}

bool callBackMouse( CMouseEvent *f_mevent_p )
{
    int scrWidth_i  = getScreenWidth();
    int scrHeight_i = getScreenHeight();
    
    CDrawingList *       list_p;
    const CDrawingList * imgList_p;
    

    for (int i = 0; i < 2; ++i)
    {
        if ( i == 0 )
        {
            list_p    = getDrawingList ( "Left Calibration Line" );  
            imgList_p = getDrawingList ( "Left Image" ); 
        }
        else
        {
            list_p    = getDrawingList ( "Right Calibration Line" );  
            imgList_p = getDrawingList ( "Right Image" ); 
        }
        
        list_p->clear();
        
        SRgba color(255,0,0);
        
        list_p->setLineColor(color);
        list_p->setFillColor(SRgba(color, 40));
        
        list_p->setPosition( imgList_p->getPosition() );
        
        list_p->addFilledRectangle ( 0,          f_mevent_p->posInScreen.y - 2.f, 
                                     scrWidth_i, f_mevent_p->posInScreen.y + 2.f );
        
        list_p->addFilledRectangle ( f_mevent_p->posInScreen.x - 2.f, 0,
                                     f_mevent_p->posInScreen.x + 2.f, scrHeight_i );
        
    }
    
    updateDisplay();
        
    return true;
}

