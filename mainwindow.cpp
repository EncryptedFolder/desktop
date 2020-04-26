#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->progressBar->setVisible(false);

    connect(ui->btnOpen, &QPushButton::clicked, this, &MainWindow::setDirectory);
    connect(ui->btnEncrypt, &QPushButton::clicked, this, &MainWindow::encrypt);
    connect(ui->btnDecrypt, &QPushButton::clicked, this, &MainWindow::decrypt);
}

MainWindow::~MainWindow()
{
    delete ui;
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
    if (ui->lePath->text().isEmpty() || ui->lePassword->text().isEmpty()) {
        QMessageBox msgBox;
        msgBox.setModal(true);
        msgBox.setText("Path and Password is required.");
        msgBox.exec();
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
    if (ui->lePath->text().isEmpty() || ui->lePassword->text().isEmpty()) {
        QMessageBox msgBox;
        msgBox.setModal(true);
        msgBox.setText("Path and Password is required.");
        msgBox.exec();
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

