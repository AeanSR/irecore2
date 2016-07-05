/*
    Copyright (C) 2015-2016 Aean(a.k.a. fhsvengetta)
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

#include "irecrash.h"
#include <QtWidgets/QApplication>
#include <QMessageBox>
#include <QTranslator>
#include "auth.h"

int main( int argc, char *argv[] ) {
    QApplication a( argc, argv );
    QTranslator* myappTranslator = new QTranslator;
    QString lang = QLocale::system().name().split( '_' ).at( 0 ).toLower();
    QString qm_name = QString( "icc_" ) + lang + QString( ".qm" );
    myappTranslator->load( qm_name );
    a.installTranslator( myappTranslator );

    QFont font( "SimSun", 9 );
    a.setFont( font );
    QCoreApplication::setOrganizationName( "Aean" );
    QCoreApplication::setOrganizationDomain( "aean.net" );
    QCoreApplication::setApplicationName( "IreCore Crash Report" );

    irecrash w;
    w.show();
    return a.exec();
}

void irecrash::illegal_start(){
    QMessageBox::information( this, QApplication::translate( "irecrash", "IreCore Crash Report" ), QApplication::translate( "irecrash", "This executable is used to send crash report when IreCore is in trouble.\nYou won't want to see IreCrash, I promise :)\n\nRun irecore.exe if you want to start the simulator." ), QMessageBox::Ok );
    QApplication::exit();
}

irecrash::irecrash( QWidget *parent )
    : QMainWindow( parent ) {
    ui.setupUi( this );
    auto argv = QApplication::arguments();
    if (argv.size() != 2) {
        illegal_start();
    }
    FILE* f = NULL;
    f = fopen( argv.at(1).toLocal8Bit(), "rb" );
    if (!f) {
        illegal_start();
    }
    fseek(f, 0, SEEK_END);
    size_t len = ftell(f);
    rewind(f);
    char* buf = (char*)alloca(len+1);
    fread(buf, 1, len, f);
    fclose(f);
    ui.txtReport->setText(QString().fromUtf8(buf));

}

irecrash::~irecrash() {

}

void irecrash::send_report() {
    SmtpClient smtp(ICC_SMTP_HOST, 465, SmtpClient::SslConnection);
    smtp.setUser(ICC_USER_NAME);
    smtp.setPassword(ICC_PASSWORD);

    MimeMessage message;

    EmailAddress sender(ICC_USER_NAME, "IreCore Crash Report");
    message.setSender(&sender);

    EmailAddress to("ic_dev@aean.net", "Aean");
    message.addRecipient(&to);

    message.setSubject("IreCore Crash Report.");

    MimeText text;

    text.setText(ui.txtUserInput->toPlainText() + QString("\n\n") +  ui.txtReport->toPlainText());
    message.addPart(&text);

    if (!smtp.connectToHost()) {
        qDebug() << "Failed to connect to host!" << endl;
    }

    if (!smtp.login()) {
        qDebug() << "Failed to login!" << endl;
    }

    if (!smtp.sendMail(message)) {
        qDebug() << "Failed to send mail!" << endl;
    }

    smtp.quit();
}

void irecrash::on_btnSend_clicked() {
    this->hide();
    send_report();
    QApplication::exit();
}
void irecrash::on_btnDontSend_clicked() {
    QApplication::exit();
}
