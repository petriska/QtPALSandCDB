#ifndef HISTPLOT_H
#define HISTPLOT_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QLabel>
#include <QDateTime>
#include <QSettings>
#include <QTimer>
#include <QVector>
#include <qwt_plot.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>
#include <qwt_picker_machine.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_zoomer.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_renderer.h>
#include <qwt_scale_engine.h>
#include <qwt_plot_zoneitem.h>
#include <qwt_plot_intervalcurve.h>

class histplot : public QWidget
{
    Q_OBJECT

public:
    explicit histplot(QWidget *parent = nullptr);
    ~histplot();

private:
    QwtPlot *plot;
    QVector<QwtPlotCurve* > curves;
    QVector<QwtPlotIntervalCurve* > errorbars;
    QVBoxLayout *vblayout;
    QMenuBar *menubar;
};

#endif // HISTPLOT_H
