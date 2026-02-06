#include "window.h"
#include <header.h>
#include <qlogging.h>

QWidget *main_page(QMainWindow *window) { 
    QWidget *centralWidget = new QWidget(window);
    
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    auto button = new QPushButton("点击我", centralWidget);
    auto exitButton = new QPushButton("退出", centralWidget);
    
    MainWindow::connect(button, &QPushButton::clicked, []() {
        Simple::info("点击了按钮");
        qDebug() << "点击了按钮";
    });
    MainWindow::connect(exitButton, &QPushButton::clicked, qApp, &QApplication::quit);

    layout->addWidget(button);
    layout->addWidget(exitButton);
    layout->addStretch();

    return centralWidget;
}