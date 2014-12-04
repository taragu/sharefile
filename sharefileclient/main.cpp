#include "mainwindow.h"
#include "clientcommand.h"
#include <QApplication>

int main(int argc, char *argv[])
{


//    if ( argc < 3 )
//        {
//            std::cout << argv[0] << "<IP><Port>" << std::endl ;
//            return - 1 ;
//        }
//        ClientCommand clientcommand( argv[1], atoi(argv[2]) )  ;
//        clientcommand.manager() ;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
