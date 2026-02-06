#pragma once
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

namespace Simple
{
    static QFont font(int size, std::string family = "Fira Code"){
        return QFont(QString::fromStdString(family), size);
    }
    static void info(std::string message, int width = 400, int height = 200, int fontSize = 16, std::string title = "消息")
    {
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
}