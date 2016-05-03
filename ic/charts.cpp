/*
    Copyright (C) 2015-2016 Aean(a.k.a. fhsvengetta)
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

#include "gic.h"
#define QCUSTOMPLOT_USE_LIBRARY
#include "qcustomplot.h"

std::vector<bar_data_t>& bar_data() {
    static std::vector<bar_data_t> vec;
    return vec;
}
std::vector<contour_data_t>& contour_data() {
    static std::vector<contour_data_t> vec;
    return vec;
}
QString& contour_zlbl() {
    static QString zlbl;
    return zlbl;
}
std::vector<plot_data_t>& plot_data() {
    static std::vector<plot_data_t> vec;
    return vec;
}
int& plot_sets() {
    static int sets = 3;
    return sets;
}

void QChartDialog::setQCP( QCustomPlot* pqcp ) {
    qcp = pqcp;
}

void QChartDialog::resizeEvent( QResizeEvent * e ) {
    qcp->setGeometry( QRect( 10, 10, size().width() - 20, size().height() - 20 ) );
}

void gic::new_bar_chart() {
    delete uiCharts.customPlot;
    delete dlgCharts;
    dlgCharts = new QChartDialog();
    uiCharts.setupUi( dlgCharts );
    dlgCharts->setQCP( uiCharts.customPlot );

    bar_data().clear();
    uiCharts.customPlot->axisRect()->setupFullAxesBox( false );
    uiCharts.customPlot->xAxis->setLabel( "" );
    uiCharts.customPlot->yAxis->setLabel( "" );
}

void gic::add_bar( QString name, double value, double error ) {
    bar_data().push_back( bar_data_t( name, value, error ) );
}

void gic::finish_bar() {
    auto customPlot = uiCharts.customPlot;
    QVector<double> ticks;
    QVector<QString> labels;
    QVector<double> value;
    QVector<double> error;
    std::sort( bar_data().begin(), bar_data().end() );
    for (int i = 0; i < bar_data().size(); i++) {
        ticks.push_back( i + 1 );
        labels.push_back( bar_data()[i].name );
        value.push_back( bar_data()[i].value - bar_data()[i].error );
        error.push_back( bar_data()[i].error );
    }
    QCPBars* bar = new QCPBars( customPlot->yAxis, customPlot->xAxis );
    QCPBars* baren = new QCPBars( customPlot->yAxis, customPlot->xAxis );
    QCPBars* barep = new QCPBars( customPlot->yAxis, customPlot->xAxis );
    customPlot->addPlottable( bar );
    customPlot->addPlottable( baren );
    customPlot->addPlottable( barep );
    QPen pen;
    pen.setWidthF( 1.2 );
    pen.setColor( QColor( 0, 66, 255 ) );
    bar->setPen( pen );
    bar->setBrush( QColor( 0, 66, 255, 50 ) );
    pen.setColor( QColor( 128, 33, 128 ) );
    baren->setPen( pen );
    baren->setBrush( QColor( 128, 33, 128, 75 ) );
    pen.setColor( QColor( 255, 0, 0 ) );
    barep->setPen( pen );
    barep->setBrush( QColor( 255, 0, 0, 50 ) );
    customPlot->yAxis->setAutoTicks( false );
    customPlot->yAxis->setAutoTickLabels( false );
    customPlot->yAxis->setTickVector( ticks );
    customPlot->yAxis->setTickVectorLabels( labels );
    customPlot->yAxis->setSubTickCount( 0 );
    customPlot->yAxis->setTickLength( 0, 4 );
    customPlot->yAxis->grid()->setVisible( true );
    customPlot->yAxis->setRange( 0, bar_data().size() + 1 );
    customPlot->xAxis->setRange( 0, 1.05 * ( bar_data().rbegin()->value + bar_data().rbegin()->error ) );
    customPlot->xAxis->setPadding( 5 );
    customPlot->xAxis->grid()->setSubGridVisible( true );
    QPen gridPen;
    gridPen.setStyle( Qt::SolidLine );
    gridPen.setColor( QColor( 0, 0, 0, 25 ) );
    customPlot->xAxis->grid()->setPen( gridPen );
    gridPen.setStyle( Qt::DotLine );
    customPlot->xAxis->grid()->setSubGridPen( gridPen );

    bar->setData( ticks, value );
    baren->setData( ticks, error );
    barep->setData( ticks, error );
    baren->moveAbove( bar );
    barep->moveAbove( baren );

    dlgCharts->show();
}

void gic::new_contour_chart( QString xlbl, QString ylbl, QString zlbl ) {
    delete uiCharts.customPlot;
    delete dlgCharts;
    dlgCharts = new QChartDialog();
    uiCharts.setupUi( dlgCharts );
    dlgCharts->setQCP( uiCharts.customPlot );

    contour_data().clear();
    uiCharts.customPlot->axisRect()->setupFullAxesBox( true );
    uiCharts.customPlot->xAxis->setLabel( xlbl );
    uiCharts.customPlot->yAxis->setLabel( ylbl );
    contour_zlbl() = zlbl;
}

void gic::add_contour( int x, int y, double value ) {
    contour_data().push_back( contour_data_t( x, y, value ) );
}

void gic::finish_contour() {
    auto customPlot = uiCharts.customPlot;
    std::sort( contour_data().begin(), contour_data().end() );
    QCPColorMap* map = new QCPColorMap( customPlot->xAxis, customPlot->yAxis );
    customPlot->addPlottable( map );
    int min_x, max_x, min_y, max_y, delta_x, delta_y;
    min_x = contour_data().begin()->x;
    max_x = contour_data().begin()->x;
    min_y = contour_data().begin()->y;
    max_y = contour_data().begin()->y;
    for (auto i = contour_data().begin(); i != contour_data().end(); i++) {
        min_x = std::min( min_x, i->x );
        max_x = std::max( max_x, i->x );
        min_y = std::min( min_y, i->y );
        max_y = std::max( max_y, i->y );
    }
    delta_x = max_x - min_x;
    delta_y = max_y - min_y;
    for (auto i = contour_data().begin(); i != contour_data().end(); i++) {
        if (i->x > min_x) delta_x = std::min( delta_x, i->x - min_x );
        if (i->y > min_y) delta_y = std::min( delta_y, i->y - min_y );
    }
    int nx = ( max_x - min_x ) / delta_x;
    int ny = ( max_y - min_y ) / delta_y;
    map->data()->setSize( nx, ny );
    map->data()->setRange( QCPRange( min_x, max_x ), QCPRange( min_y, max_y ) );
    for (auto i = contour_data().begin(); i != contour_data().end(); i++) {
        int idx = ( i->x - min_x ) / delta_x, idy = ( i->y - min_y ) / delta_y;
        map->data()->cellToCoord( idx, idy, 0, 0 );
        map->data()->setCell( idx, idy, i->value );
    }
    QCPColorScale *colorScale = new QCPColorScale( customPlot );
    customPlot->plotLayout()->addElement( 0, 1, colorScale );
    colorScale->setType( QCPAxis::atRight );
    map->setColorScale( colorScale );
    colorScale->axis()->setLabel( contour_zlbl() );
    QCPColorGradient grad( QCPColorGradient::gpNight );
    grad.setColorStopAt( 1.0 / 350.0, grad.color( 0, QCPRange( 0, 1 ) ) );
    grad.setColorStopAt( 1.0, grad.color( 0.9, QCPRange( 0, 1 ) ) );
    grad.setColorStopAt( 0, Qt::white );
    map->setGradient( grad );
    map->setDataRange( QCPRange( contour_data().begin()->value * 1.003 - contour_data().rbegin()->value * 0.003, contour_data().rbegin()->value ) );
    QCPMarginGroup *marginGroup = new QCPMarginGroup( customPlot );
    customPlot->axisRect()->setMarginGroup( QCP::msBottom | QCP::msTop, marginGroup );
    colorScale->setMarginGroup( QCP::msBottom | QCP::msTop, marginGroup );
    customPlot->rescaleAxes();
    dlgCharts->show();
}

void gic::new_plot_chart( int sets ) {
    delete uiCharts.customPlot;
    delete dlgCharts;
    dlgCharts = new QChartDialog();
    uiCharts.setupUi( dlgCharts );
    dlgCharts->setQCP( uiCharts.customPlot );

    plot_data().clear();
    uiCharts.customPlot->axisRect()->setupFullAxesBox( true );
    uiCharts.customPlot->xAxis->setLabel( "" );
    uiCharts.customPlot->yAxis->setLabel( "" );
    sets = std::min( sets, 3 );
    sets = std::max( sets, 1 );
    for( int i = 0; i < sets; i++ ) uiCharts.customPlot->addGraph();
    plot_sets() = sets;
}
void gic::add_plot( double x, double y1, double y2, double y3 ) {
    plot_data().push_back( plot_data_t( x, y1, y2, y3 ) );
}
void gic::finish_plot() {
    std::sort(plot_data().begin(), plot_data().end());
    QVector<double> x(plot_data().size());
    QVector<double> y[3];
    for( int i = 0; i < plot_sets(); i++ )
        y[i].resize(plot_data().size());
    for( int i = 0; i <= plot_data().size(); i++ ) {
        x[i] = plot_data()[i].x;
        for( int j = 0; j < plot_sets(); j++ ) {
            y[j][i] = plot_data()[i].y[j];
        }
    }
    for( int i = 0; i < plot_sets(); i++ )
        uiCharts.customPlot->graph(i)->setData(x, y[i]);
    QPen pen;
    pen.setWidthF( 1.2 );
    pen.setColor( QColor( 0, 0, 0 ) );
    if (plot_sets() >= 1) uiCharts.customPlot->graph(0)->setPen(pen);
    pen.setColor( QColor( 225, 30, 30 ) );
    if (plot_sets() >= 2) uiCharts.customPlot->graph(1)->setPen(pen);
    pen.setColor( QColor( 30, 30, 225 ) );
    if (plot_sets() >= 3) uiCharts.customPlot->graph(2)->setPen(pen);
    uiCharts.customPlot->rescaleAxes();
    uiCharts.customPlot->replot();
    dlgCharts->show();
}