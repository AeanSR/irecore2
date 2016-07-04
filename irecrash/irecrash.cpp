/*
    Copyright (C) 2015-2016 Aean(a.k.a. fhsvengetta)
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

#include "irecrash.h"
#include <QtWidgets/QApplication>
#include "auth.h"

int main( int argc, char *argv[] ) {
    QApplication a( argc, argv );
    irecrash w;
    w.show();
    return a.exec();
}

irecrash::irecrash( QWidget *parent )
    : QMainWindow( parent ) {
    ui.setupUi( this );

    SmtpClient smtp("smtp.qq.com", 465, SmtpClient::SslConnection);
    smtp.setUser(ICC_USER_NAME);
    smtp.setPassword(ICC_PASSWORD);

    MimeMessage message;

    EmailAddress sender(ICC_USER_NAME, "IreCore Crash Report");
    message.setSender(&sender);

    EmailAddress to("ic_dev@aean.net", "Aean");
    message.addRecipient(&to);

    message.setSubject("This is a test mail.");

    MimeText text;

    text.setText("Hi,\nThis is a simple email message.\n");
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

irecrash::~irecrash() {

}
