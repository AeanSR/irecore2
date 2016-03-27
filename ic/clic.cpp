/*
    Copyright (C) 2015-2016 Aean(a.k.a. fhsvengetta)
    All rights reserved.

    IreCore is distributed under the terms of The MIT License.
    You should have received a copy of the MIT License along with this program.
    If not, see <http://opensource.org/licenses/mit-license.php>.
*/

#include "clic.h"

void build_arglist( std::vector<kvpair_t>& arglist, int argc, char** argv ) {
    for (int i = 1; i < argc; i++) {
        kvpair_t kv;
        char* p;
        for (p = argv[i]; *p; p++) {
            if (*p == '=') {
                p++;
                break;
            } else {
                kv.key.push_back( *p );
            }
        }
        if (*p) {
            for (; *p; p++) {
                kv.value.push_back( *p );
            }
            arglist.push_back( kv );
        } else {
            FILE* f = fopen( kv.key.c_str(), "rb" );
            if (!f) { std::cout << "Parameter \"" << kv.key << "\" is neither a valid key-value pair, nor a exist configuration file." << std::endl; continue; }
            char** rargv = ( char** ) calloc( 65536, sizeof( char* ) );
            int rargc = 1;
            char buffer[4096];
            size_t buffer_i = 0;
            char ch;
            int comment = 0;
            do {
                ch = fgetc( f );
                if (!comment) {
                    if (ch == '\r' || ch == '\n' || ch == '\t' || ch == ' ' || ch == EOF) {
                        if (buffer_i) {
                            buffer[buffer_i++] = 0;
                            rargv[rargc] = ( char* ) malloc( buffer_i );
                            memcpy( rargv[rargc], buffer, buffer_i );
                            rargc++;
                            buffer_i = 0;
                            if (rargc >= 65536) { std::cout << "Configuration file too long." << std::endl; break; }
                        }
                    } else if (ch == '#' && buffer_i == 0) {
                        comment = 1;
                    } else {
                        buffer[buffer_i++] = ch;
                        if (buffer_i >= 4096) { std::cout << "Configuration line too long." << std::endl; break; }
                    }
                } else {
                    if (ch == '\r' || ch == '\n') {
                        comment = 0;
                        buffer_i = 0;
                    }
                }
            } while (ch != EOF);
            build_arglist( arglist, rargc, rargv );
            for (int i = 1; i < rargc; i++) {
                free( rargv[i] );
            }
            free( rargv );
        }
    }
}


int clic_main( int argc, char *argv[] ) {
    ic_init();
    ic_setprintcallback( &vprintf );
    ic_printbanner();
    std::vector<kvpair_t> arglist;
    build_arglist( arglist, argc, argv );
    for (auto i = arglist.begin(); i != arglist.end(); i++) {
        ic_setparam( i->key.c_str(), i->value.c_str() );
    }
    ic_runsim( 0, 0, 0, 0 );
    return 0;
}