#include "window.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QApplication>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) 
    : QMainWindow(parent){
    setupUI();
}

void MainWindow::setupUI() {
    setWindowTitle("开发工具");
    setMinimumSize(700, 700);
}
