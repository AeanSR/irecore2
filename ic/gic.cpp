/*
    Copyright (C) 2015-2016 Aean(a.k.a. fhsvengetta)
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

#include "gic.h"
#include <QBitmap>
#include <QSplashScreen>

gic::gic(QWidget *parent)
    : QMainWindow(parent)
{
    QPixmap pixmap(":/gic/splash.png");
    QSplashScreen splash(pixmap);
    splash.setMask(pixmap.mask());
    splash.show();

    ic_init();

    ui.setupUi(this);
    splash.finish(this);
}

gic::~gic()
{

}
