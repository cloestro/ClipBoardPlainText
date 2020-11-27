#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMenu>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void createTrayIcon();
    void createActions();
    void setLastClipboardItemPlainText();

    QAction *quitAction;
    QSystemTrayIcon *trayIcon;
    QMenu* trayIconMenu;


private slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);

};

#endif // MAINWINDOW_H
