#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_labels()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::nord_enabled()
{
    QString status = "systemctl status | grep -o '[o]penvpn-client@nordvpn' >/dev/null 2>&1 || exit -1";
    return QProcess::execute("bash", QStringList() << "-c" << status) == 0;
}

void MainWindow::start_nord()
{
    QProcess::execute("pkexec nordvpn start");
}

void MainWindow::stop_nord()
{
    QProcess::execute("pkexec nordvpn stop");
}

void MainWindow::update_labels()
{
    if (nord_enabled()) {
        ui->label->setText("Enabled");
        ui->pushButton->setText("Disable");
        ui->label_3->setPixmap(QPixmap(":/assets/switch-on.svg"));
    }
    else {
        ui->label->setText("Disabled");
        ui->pushButton->setText("Enable");
        ui->label_3->setPixmap(QPixmap(":/assets/switch-off.svg"));
    }
}

void MainWindow::on_pushButton_released()
{
    this->nord_enabled() ? this->stop_nord() : this->start_nord();
}
