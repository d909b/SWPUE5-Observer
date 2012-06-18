/**
*
*  @file ClockLabelWindow.h
*  
*  Declaration of class ClockLabelWindow.
*
*  @author Patrick Schwab 
*  @date 5/23/12
*
*/

#pragma once

#include <QtGui/QWidget.h>
#include "Observer.h"
#include "ClockModel.h"

class QLabel;

/**
* @class ClockLabelWindow
*
* ${DESCRIPTION}
*
* @author Patrick Schwab
*/
class ClockLabelWindow : public QWidget, public Observer {
public:
	ClockLabelWindow(ClockModel* model);
private:
    QLabel* label;
    ClockModel* model;
    
    void valueChanged(Observable* observable);
};
