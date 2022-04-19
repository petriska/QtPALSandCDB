#include "histplot.h"
#include <qwt_curve_fitter.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_layout.h>
#include <qwt_scale_widget.h>

histplot::histplot(QWidget *parent) :
    QWidget(parent)
{
 plot = new QwtPlot(this);
 plot->setStyleSheet("color:white; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #606060, stop: 1 #8a8b8e);");
 plot->setAutoReplot(false);
 plot->setPalette( Qt::white);
 plot->plotLayout()->setAlignCanvasToScales( true );
 for ( int axis = 0; axis < QwtPlot::axisCnt; axis++ )
   plot->axisWidget( axis )->setMargin( 0 );

 QwtPlotCanvas *canvas = new QwtPlotCanvas();
 canvas->setAutoFillBackground( false );
 canvas->setFrameStyle( QFrame::NoFrame );
 plot->setCanvas( canvas );

 QwtPlotGrid *grid=new QwtPlotGrid;
 grid->enableXMin(true);
 grid->enableYMin(true);
 grid->setMajorPen(QPen(Qt::black, 0, Qt::DotLine));
 grid->setMinorPen(QPen(Qt::lightGray, 0 , Qt::DotLine));
 grid->attach(plot);

 vblayout = new QVBoxLayout(this);
 vblayout->addWidget(plot);
}

histplot::~histplot()
{

}
