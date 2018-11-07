#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->timerList=new QWidget;
    this->timerList->setLayout(new QVBoxLayout);
    ui->timerList->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    ui->timerList->setWidget(this->timerList);

    this->alarmList=new QWidget;
    this->alarmList->setLayout(new QVBoxLayout);
    ui->alarmList->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    ui->alarmList->setWidget(this->alarmList);

    this->settings=new Settings;
    this->settings->timeFormat="hh:mm:ss";
    this->settings->timerPlaylist=new QMediaPlaylist;
    this->settings->alarmPlaylist=new QMediaPlaylist;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_addTimerButton_clicked()
{
    AddTimerDialog* dialog=new AddTimerDialog;
    dialog->show();
    if(dialog->exec())
    {
        connect(dialog,SIGNAL(accepted()),this,SLOT(nonadd()));
        TimerListItem* item=new TimerListItem;
        item->setTime(dialog->getValues());
        this->timerList->layout()->addWidget(item);
        this->timers.push_back(item);
    }
}


void MainWindow::on_addAlarmButton_clicked()
{
    AddAlarmDialog* dialog=new AddAlarmDialog;
    dialog->show();
    if(dialog->exec())
    {
        connect(dialog,SIGNAL(accepted()),this,SLOT(nonadd()));
        AlarmListItem* item=new AlarmListItem;
        item->setTime(dialog->getValues());
        item->setWeek(dialog->getWeek());
        this->alarmList->layout()->addWidget(item);
        this->alarms.push_back(item);
    }
}

void MainWindow::on_actionNo_filter_triggered()
{
    foreach(TimerListItem* iter,this->timers)
        iter->setVisible(true);
    foreach(AlarmListItem* iter,this->alarms)
        iter->setVisible(true);
}

void MainWindow::on_actionShow_enabled_triggered()
{
    foreach(TimerListItem* iter,this->timers)
    {
        if(iter->getState()==on)
            iter->setVisible(true);
        else
            iter->setVisible(false);
    }
    foreach(AlarmListItem* iter,this->alarms)
    {
        if(iter->getState()==on)
            iter->setVisible(true);
        else
            iter->setVisible(false);
    }
}

void MainWindow::on_actionShow_disabled_triggered()
{
    foreach(TimerListItem* iter,this->timers)
    {
        if(iter->getState()==off)
            iter->setVisible(true);
        else
            iter->setVisible(false);
    }
    foreach(AlarmListItem* iter,this->alarms)
    {
        if(iter->getState()==off)
            iter->setVisible(true);
        else
            iter->setVisible(false);
    }
}

void MainWindow::on_actionSunday_triggered()
{
    foreach(TimerListItem* iter,this->timers)
        iter->setVisible(true);
    foreach(AlarmListItem* iter,this->alarms)
    {
        if(iter->checkDay(0))
            iter->setVisible(true);
        else
            iter->setVisible(false);
    }
}

void MainWindow::on_actionMonday_triggered()
{
    foreach(TimerListItem* iter,this->timers)
        iter->setVisible(true);
    foreach(AlarmListItem* iter,this->alarms)
    {
        if(iter->checkDay(1))
            iter->setVisible(true);
        else
            iter->setVisible(false);
    }
}

void MainWindow::on_actionTuesday_triggered()
{
    foreach(TimerListItem* iter,this->timers)
        iter->setVisible(true);
    foreach(AlarmListItem* iter,this->alarms)
    {
        if(iter->checkDay(2))
            iter->setVisible(true);
        else
            iter->setVisible(false);
    }
}

void MainWindow::on_actionWednesday_triggered()
{
    foreach(TimerListItem* iter,this->timers)
        iter->setVisible(true);
    foreach(AlarmListItem* iter,this->alarms)
    {
        if(iter->checkDay(3))
            iter->setVisible(true);
        else
            iter->setVisible(false);
    }
}

void MainWindow::on_actionThursday_triggered()
{
    foreach(TimerListItem* iter,this->timers)
        iter->setVisible(true);
    foreach(AlarmListItem* iter,this->alarms)
    {
        if(iter->checkDay(4))
            iter->setVisible(true);
        else
            iter->setVisible(false);
    }
}

void MainWindow::on_actionFriday_triggered()
{
    foreach(TimerListItem* iter,this->timers)
        iter->setVisible(true);
    foreach(AlarmListItem* iter,this->alarms)
    {
        if(iter->checkDay(5))
            iter->setVisible(true);
        else
            iter->setVisible(false);
    }
}

void MainWindow::on_actionSaturday_triggered()
{
    foreach(TimerListItem* iter,this->timers)
        iter->setVisible(true);
    foreach(AlarmListItem* iter,this->alarms)
    {
        if(iter->checkDay(6))
            iter->setVisible(true);
        else
            iter->setVisible(false);
    }
}

void MainWindow::on_actionEveryday_triggered()
{
    foreach(TimerListItem* iter,this->timers)
        iter->setVisible(true);
    foreach(AlarmListItem* iter,this->alarms)
    {
        if(iter->checkWeek())
            iter->setVisible(true);
        else
            iter->setVisible(false);
    }
}

void MainWindow::on_actionChange_triggered()
{
    SettingsDialog* dialog=new SettingsDialog;
    if(dialog->exec())
    {
        connect(dialog,SIGNAL(accepted()),this,SLOT(nonadd()));
        this->settings=dialog->getSettings();
    }
}
