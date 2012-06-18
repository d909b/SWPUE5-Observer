/**
*
*  @file ClockWindow.cpp
*  
*  Implementation of class ClockWindow.
*
*  @author Patrick Schwab 
*  @date 5/23/12
*
*/

#include "ClockWindow.h"
#include <QtGui/QPainter.h>

/**
 *  Window constructor. Adds itself to the __model__'s observers.
 */
ClockWindow::ClockWindow(ClockModel* model) :
    model_(model)
{
    model_->addObserver(this);
    
    setWindowTitle("Clock");
}

/**
 * Paints the analogue clock according to the backing time model __model__.
 *
 * Adapted from http://doc.qt.nokia.com/4.7/widgets-analogclock.html
 */
void 
ClockWindow::paintEvent(QPaintEvent *event)
{    
    static const QPoint hourHand[3] = 
    {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -40)
    };
    static const QPoint minuteHand[3] =
    {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -70)
    };
    static const QPoint secondHand[3] = 
    {
        QPoint(3, 3),
        QPoint(-3, 3),
        QPoint(0, -90)
    };
    
    QColor hourColor(127, 0, 127);
    QColor minuteColor(0, 127, 127, 191);
    QColor secondColor(127, 127, 127);
    
    int side = qMin(width(), height());
    
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / 200.0, side / 200.0);
    
    painter.setPen(Qt::NoPen);
    painter.setBrush(hourColor);
    
    painter.save();
    painter.rotate(30.0 * ((model_->getHours() + model_->getMinutes() / 60.0)));
    painter.drawConvexPolygon(hourHand, 3);
    painter.restore();
    
    painter.setPen(hourColor);
    
    for (int i = 0; i < 12; ++i) 
    {
        painter.drawLine(88, 0, 96, 0);
        painter.rotate(30.0);
    }
    
    painter.setPen(Qt::NoPen);
    painter.setBrush(minuteColor);
    
    painter.save();
    painter.rotate(6.0 * (model_->getMinutes() + model_->getSeconds() / 60.0));
    painter.drawConvexPolygon(minuteHand, 3);
    painter.restore();
    
    painter.setPen(minuteColor);
    
    for (int j = 0; j < 60; ++j)
    {
        if ((j % 5) != 0)
        {
            painter.drawLine(92, 0, 96, 0);
        }
        
        painter.rotate(6.0);
    }
    
    painter.setPen(Qt::NoPen);
    painter.setBrush(secondColor);
    
    painter.save();
    painter.rotate(6.0 * model_->getSeconds() );
    painter.drawConvexPolygon(secondHand, 3);
    painter.restore();
}

/** 
 * Event received when the backing __model__ changes. 
 * Triggers a new draw event.
 */
void 
ClockWindow::valueChanged(Observable* observable)
{
    repaint(rect());
}