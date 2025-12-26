#include "mainwindow.h"

#include "system.h"
#include "./ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitSlotSignals();

    ComboboxDevicesClicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitSlotSignals()
{
    connect(ui->comboBoxDevice, &QComboBox::activated, this, &MainWindow::ComboboxDevicesClicked);
}

void MainWindow::ComboboxDevicesClicked()
{
    auto devices = systemWrappers::GetDevices();
    ui->comboBoxDevice->clear();
    ui->comboBoxDevice->addItems(devices);

    qDebug() << "ddd";
}
