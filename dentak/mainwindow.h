#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void displayUpdate();

    void culc();

    void transDisplayNum(int num);


    void on_botton_0_clicked();

    void on_botton_1_clicked();

    void on_botton_2_clicked();

    void on_botton_3_clicked();

    void on_botton_4_clicked();

    void on_botton_5_clicked();

    void on_botton_6_clicked();

    void on_botton_7_clicked();

    void on_botton_8_clicked();

    void on_botton_9_clicked();

    void on_botton_equal_clicked();

    void on_botton_clear_clicked();

    void on_botton_division_clicked();

    void on_botton_multiply_clicked();

    void on_botton_minus_clicked();

    void on_botton_plus_clicked();

    void on_botton_sign_clicked();

    void on_botton_dot_clicked();

    void on_botton_backspace_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
