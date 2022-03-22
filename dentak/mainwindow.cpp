#include "mainwindow.h"
#include "ui_mainwindow.h"

int culcMode;
int holdCulcMode;
int clearMode; //AC or C
double holdNum; //被演算値
double displayNum;

bool doubleMode;
int doubleDigit;

bool isWaitNextInput;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowOpacity(0.95);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayUpdate(){
    if(displayNum!=0 || holdNum!=0) //入力中..
        clearMode = 1;

    if(culcMode!=0){ //演算モード時、入力値ホールド
        holdNum = displayNum;
        holdCulcMode = culcMode;
        displayNum = 0;
        culcMode = 0;
    }

    if(isWaitNextInput){
        displayNum = 0;
        isWaitNextInput = false;
    }

    if(clearMode==0)
        ui->botton_clear->setText("AC");
    else
        ui->botton_clear->setText("C");
}


void MainWindow::culc(){
    switch(holdCulcMode){
    case 1: displayNum = holdNum / displayNum; break;
    case 2: displayNum = holdNum * displayNum; break;
    case 3: displayNum = holdNum - displayNum; break;
    case 4: displayNum = holdNum + displayNum; break;
    }
    culcMode = 0;
    holdNum = 0;
    holdCulcMode = 0;
    ui->display->display(displayNum);
    isWaitNextInput = true;
}



void MainWindow::on_botton_clear_clicked()
{
    displayNum = 0;
    doubleMode = false;
    doubleDigit = 0;
    if(clearMode==0){ //AC
        holdNum = 0;
        culcMode = 0;
    }else
        clearMode = 0;

    if(clearMode==0)
        ui->botton_clear->setText("AC");
    else
        ui->botton_clear->setText("C");

    ui->display->display(displayNum);
}


void MainWindow::transDisplayNum(int num){
    if(doubleMode == false){ //入力:整数
        displayNum *= 10;
        displayNum += num;
    }else{ //小数
        doubleDigit++;
        if(num!=0)
            displayNum += num/pow(10, doubleDigit);
        else
            displayNum += 0;
    }
}


//演算
void MainWindow::on_botton_equal_clicked()
{
    doubleMode = false;
    doubleDigit = 0;
    culc();
}


//演算キー
void MainWindow::on_botton_division_clicked()
{
    doubleMode = false;
    doubleDigit = 0;
    culcMode = 1;
}

void MainWindow::on_botton_multiply_clicked()
{
    doubleMode = false;
    doubleDigit = 0;
    culcMode = 2;
}

void MainWindow::on_botton_minus_clicked()
{
    doubleMode = false;
    doubleDigit = 0;
    culcMode = 3;
}

void MainWindow::on_botton_plus_clicked()
{
    doubleMode = false;
    doubleDigit = 0;
    culcMode = 4;
}


void MainWindow::on_botton_sign_clicked()
{
    if(isWaitNextInput)return;
    displayNum *= -1;
    ui->display->display(displayNum);
}


void MainWindow::on_botton_dot_clicked()
{
    doubleMode = true;
}


void MainWindow::on_botton_backspace_clicked()
{
    if(isWaitNextInput)return;
    if(doubleMode){
        doubleDigit--;
        displayNum = floor(displayNum*pow(10,doubleDigit)) / pow(10,doubleDigit);
        if(doubleDigit<=0)doubleMode=false;
    }else
        displayNum = floor(displayNum/10);
    ui->display->display(displayNum);
}


//数字キー
void MainWindow::on_botton_0_clicked()
{
    displayUpdate();
    transDisplayNum(0);
    ui->display->display(displayNum);
}


void MainWindow::on_botton_1_clicked()
{
    displayUpdate();
    transDisplayNum(1);
    ui->display->display(displayNum);
}


void MainWindow::on_botton_2_clicked()
{
    displayUpdate();
    transDisplayNum(2);
    ui->display->display(displayNum);
}


void MainWindow::on_botton_3_clicked()
{
    displayUpdate();
    transDisplayNum(3);
    ui->display->display(displayNum);
}


void MainWindow::on_botton_4_clicked()
{
    displayUpdate();
    transDisplayNum(4);
    ui->display->display(displayNum);
}


void MainWindow::on_botton_5_clicked()
{
    displayUpdate();
    transDisplayNum(5);
    ui->display->display(displayNum);
}


void MainWindow::on_botton_6_clicked()
{
    displayUpdate();
    transDisplayNum(6);
    ui->display->display(displayNum);
}


void MainWindow::on_botton_7_clicked()
{
    displayUpdate();
    transDisplayNum(7);
    ui->display->display(displayNum);
}


void MainWindow::on_botton_8_clicked()
{
    displayUpdate();
    transDisplayNum(8);
    ui->display->display(displayNum);
}


void MainWindow::on_botton_9_clicked()
{
    displayUpdate();
    transDisplayNum(9);
    ui->display->display(displayNum);
}
