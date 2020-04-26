#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <cstring>

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>

#include "core/core.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void setDirectory();
    void encrypt();
    void decrypt();
};

#endif // MAINWINDOW_H
