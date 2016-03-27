/*
    Copyright (C) 2015-2016 Aean(a.k.a. fhsvengetta)
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

#include "clic.h"
#include "gic.h"
#include <QtWidgets/QApplication>
#include <Windows.h>

int main( int argc, char *argv[] ) {
    if (GetStdHandle( STD_OUTPUT_HANDLE ) == 0) // this is a detached gui process. show gui.
    {
        QApplication a( argc, argv );
        QString lang = QLocale::system().name().split( '_' ).at( 0 ).toLower();
        QTranslator* myappTranslator = new QTranslator;
        QString qm_name = QString( "gic_" ) + lang + QString( ".qm" );
        myappTranslator->load( qm_name );
        a.installTranslator( myappTranslator );

        QFont font( "SimSun", 9 );
        a.setFont( font );
        QCoreApplication::setOrganizationName( "Aean" );
        QCoreApplication::setOrganizationDomain( "aean.net" );
        QCoreApplication::setApplicationName( "IreCore" );
        //QSettings history;
        //history.clear();

        gic w;

        w.show();
        return a.exec();
    } else if (argc > 1) // user given command line arguments. treat as cli.
    {
        return clic_main( argc, argv );
    } else // create a new detached gui process, and close this one.
    {
        DWORD dwCreationFlags = CREATE_DEFAULT_ERROR_MODE | DETACHED_PROCESS;
        STARTUPINFO startinfo;
        PROCESS_INFORMATION procinfo;
        ZeroMemory( &startinfo, sizeof( startinfo ) );
        startinfo.cb = sizeof( startinfo );
        if (!CreateProcess( NULL, GetCommandLine(), NULL, NULL, FALSE, dwCreationFlags, NULL, NULL, &startinfo, &procinfo ))
            MessageBox( 0, TEXT( "CreateProcess failed." ), TEXT( "" ), 0 );
        return 0;
    }
}
