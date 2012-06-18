//
//  main.cpp
//  SWPUE5-Observer
//
//  Created by Patrick Schwab on 5/23/12.
//  Copyright (c) 2012 Patrick Schwab. All rights reserved.
//

#include <QtGui/QApplication.h>
#include "ClockWindow.h"
#include "ClockLabelWindow.h"

class ClockApp : public QApplication {
public:
    ClockApp(ClockModel* model, int argc, char** argv) :
        QApplication(argc, argv),
        model_(model)
    {
        ;
    }
protected:
    void timerEvent(QTimerEvent *event)
    {
        int h = model_->getHours(), m = model_->getMinutes(), s = model_->getSeconds();
        
        s++;
        
        if( s > 59 )
        {
            s = 0;
            
            m++;
            
            if( m > 59 )
            {
                m = 0;
                
                h++;
                
                if( h > 23 )
                {
                    h = 0;
                }
            }
        }
        
        model_->setTime(h, m, s);
    }
private:
    ClockModel* model_;
};

int main(int argc, char** argv)
{
    ClockModel* model = new ClockModel(0, 0, 0);
    
    ClockApp app(model, argc, argv);
    ClockLabelWindow window1(model);
    ClockWindow window2(model);
    
    model->setTime(11, 0, 0);
    
    /** 1 second intervals. */
    app.startTimer(1000);
    
    window1.show();
    window1.raise();
    window1.activateWindow();
    window1.move(300, 400);
    
    window2.show();
    window2.raise();
    window2.activateWindow();
    window2.move(600, 300);
    
    return app.exec();
}

