#include "global.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    global::GlobalWindow()->show();
    global::GlobalRouter().Navigate("/");

    return app.exec();
}