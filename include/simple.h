#pragma once
#include "window.h"
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <global.h>

namespace Simple {
static QFont font(int size, std::string family = "Fira Code") {
  return QFont(QString::fromStdString(family), size);
}
static void info(std::string message, int width = 400, int height = 200,
                 int fontSize = 16, std::string title = "消息") {
  QDialog dialog;
  dialog.setWindowTitle(QString::fromStdString(title));
  dialog.setMinimumSize(width, height);

  QVBoxLayout *layout = new QVBoxLayout(&dialog);

  QLabel *label = new QLabel(QString::fromStdString(message), &dialog);
  label->setFont(font(fontSize));
  label->setAlignment(Qt::AlignCenter);

  QPushButton *okButton = new QPushButton("确定", &dialog);

  layout->addWidget(label);
  layout->addWidget(okButton, 0, Qt::AlignCenter);

  QObject::connect(okButton, &QPushButton::clicked, &dialog, &QDialog::accept);

  dialog.exec();
}

static void button(const char *show, std::function<void()> callback,
                   QWidget *centralWidget, QVBoxLayout *layout, int font = 20,
                   Qt::Alignment align = Qt::AlignCenter) {

  auto button = new QPushButton(show, centralWidget);
  button->setFont(Simple::font(font));
  MainWindow::connect(button, &QPushButton::clicked, callback);
  layout->addWidget(button, 0, align);
}

static void title(const char *title, QWidget *centralWidget,
                  QVBoxLayout *layout, int font = 30,
                  Qt::Alignment align = Qt::AlignCenter) {
  auto titlex = new QLabel(title, centralWidget);
  titlex->setFont(Simple::font(font));
  layout->addWidget(titlex, 0, align);
}

static void text(const char *title, QWidget *centralWidget,
                  QVBoxLayout *layout, int font = 20,
                  Qt::Alignment align = Qt::AlignCenter) {
  auto titlex = new QLabel(title, centralWidget);
  titlex->setFont(Simple::font(font));
  layout->addWidget(titlex, 0, align);
}

static void back(std::string route, QWidget *centralWidget,
                 QVBoxLayout *layout) {
  Simple::button("返回", [=](){
    global::GlobalRouter().Navigate(route);
  }, centralWidget, layout, 17, Qt::AlignRight);
}
} // namespace Simple