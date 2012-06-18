/**
*
*  @file ClockLabelWindow.cpp
*  
*  Implementation of class ClockLabelWindow.
*
*  @author Patrick Schwab 
*  @date 5/23/12
*
*/

#include <QtGui/qlabel.h>
#include <QtGui/qboxlayout.h>
#include "ClockLabelWindow.h"

ClockLabelWindow::ClockLabelWindow(ClockModel* model) :
    model(model)
{
    model->addObserver(this);
    
	setWindowTitle("Clock Label");
    
    label = new QLabel;
    
    label->setText("00:00:00");
    
    QFont font;
	font.setPointSize(32);
	font.setBold(true);
    
    label->setFont(font);
    
    QVBoxLayout *vbl = new QVBoxLayout(this);
    
    vbl->addWidget(label);
}

void 
ClockLabelWindow::valueChanged(Observable* observable)
{
    QString text;
    
    text.sprintf("%02d:%02d:%02d", model->getHours(), model->getMinutes(), model->getSeconds());
    
    label->setText(text);
}