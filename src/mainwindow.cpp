#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStyle>
#include <QClipboard>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    createActions();
    createTrayIcon();
    trayIcon->show();
    QStyle* style = QApplication::style();
    QIcon icon = style->standardIcon(QStyle::SP_DialogResetButton);
    trayIcon->setIcon(icon);
    connect(trayIcon, &QSystemTrayIcon::activated,
            this, &MainWindow::iconActivated);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
    case QSystemTrayIcon::DoubleClick:
        setLastClipboardItemPlainText();
        break;
    case QSystemTrayIcon::MiddleClick:
        //showMessage();
        break;
    default:
        ;
    }
}

void MainWindow::setLastClipboardItemPlainText()
{
    QClipboard *clipboard = QGuiApplication::clipboard();
    QString originalText = clipboard->text();
    clipboard->setText(originalText);

}

void MainWindow::createTrayIcon()
{
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(quitAction);
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
}
void MainWindow::createActions()
{

    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);
}
