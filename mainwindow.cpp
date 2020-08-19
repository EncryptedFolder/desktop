#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(600, 165);

    ui->progressBar->setVisible(false);

    connect(ui->btnOpen, &QPushButton::clicked, this, &MainWindow::setDirectory);
    connect(ui->btnEncrypt, &QPushButton::clicked, this, &MainWindow::encrypt);
    connect(ui->btnDecrypt, &QPushButton::clicked, this, &MainWindow::decrypt);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::checkData()
{
    if (ui->lePath->text().isEmpty() || ui->lePassword->text().isEmpty()) {
        QMessageBox msgBox;
        msgBox.setModal(true);
        msgBox.setText(tr("Path and Password is required."));
        msgBox.exec();
        return false;
    }

    return true;
}

void MainWindow::showInfo(QString text)
{
    QMessageBox msgBox;
    msgBox.setModal(true);
    msgBox.setText(text);
    msgBox.exec();
}

void MainWindow::setDirectory()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::Directory);

    if (dialog.exec()) {
        ui->lePath->setText(dialog.selectedFiles().first());
    }
}

void MainWindow::encrypt()
{
    if (!checkData()) {
        return;
    }

    ui->progressBar->setVisible(true);

    std::string dir = ui->lePath->text().toStdString();
    std::string password = ui->lePassword->text().toStdString();
    GoString dirName = { dir.c_str(), (long) strlen(dir.c_str()) };
    GoString passwd = { password.c_str(), (long) strlen(password.c_str()) };

    Encrypt(dirName, passwd);
    ui->progressBar->setVisible(false);
}

void MainWindow::decrypt()
{
    if (!checkData()) {
        return;
    }

    ui->progressBar->setVisible(true);

    std::string dir = ui->lePath->text().toStdString();
    std::string password = ui->lePassword->text().toStdString();
    GoString dirName = { dir.c_str(), (long) strlen(dir.c_str()) };
    GoString passwd = { password.c_str(), (long) strlen(password.c_str()) };

    Decrypt(dirName, passwd);
    ui->progressBar->setVisible(false);
}

