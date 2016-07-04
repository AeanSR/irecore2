/*
    Copyright (C) 2015-2016 Aean(a.k.a. fhsvengetta)
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

#ifndef IRECRASH_H
#define IRECRASH_H

#include <QtWidgets/QMainWindow>
#include <string>
#include "SmtpMime"
#include "ui_irecrash.h"

class irecrash : public QMainWindow
{
    Q_OBJECT

public:
    irecrash(QWidget *parent = 0);
    ~irecrash();

private:
    Ui::irecrashClass ui;
};

#endif // IRECRASH_H
