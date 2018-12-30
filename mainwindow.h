#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void update_labels();

    void on_pushButton_released();

private:
    Ui::MainWindow *ui;

    bool nord_enabled();

    void start_nord();

    void stop_nord();
};

#endif // MAINWINDOW_H
