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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_logicas_activated(int index);
    void on_canales_activated(int index);
    void on_geometricas_activated(int index);

    void on_open1_clicked();

    void on_open2_clicked();

    void on_close_clicked();

    void on_clean1_clicked();

    void on_clean2_clicked();

    void on_ejex_valueChanged(int arg1);

    void on_ejey_valueChanged(int arg1);

    void on_clean3_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
