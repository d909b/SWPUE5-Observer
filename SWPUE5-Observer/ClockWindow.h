/**
*
*  @file ClockWindow.h
*  
*  Declaration of class ClockWindow.
*
*  @author Patrick Schwab 
*  @date 5/23/12
*
*/

#pragma once

#include <QtGui/QWidget.h>
#include "Observer.h"
#include "ClockModel.h"

/**
* @class ClockWindow
*
* This class implements a widget for displaying a clock model in analogue form.
*
* @author Patrick Schwab
*/
class ClockWindow : public QWidget, public Observer {
public:
	ClockWindow(ClockModel* model);
private:
    ClockModel* model_;
    
    void paintEvent(QPaintEvent *event);
    void valueChanged(Observable* observable);
};
