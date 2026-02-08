#include "global.h"
#include <QApplication>
#include <qlogging.h>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    global::GlobalWindow()->show();
    global::GlobalRouter().Navigate("/");

    return app.exec();
}