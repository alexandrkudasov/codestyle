#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "math.h"
#define PI 3.14159265
double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_pm,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_prcnt,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_mod,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_sin,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_cos,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_tg,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_ctg,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_fact,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_ln,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_K_2,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_degree,SIGNAL(clicked()),this,SLOT(math_operations()));
     connect(ui->pushButton_mult,SIGNAL(clicked()),this,SLOT(math_operations()));


 ui->pushButton_mod->setCheckable(true);
 ui->pushButton_plus->setCheckable(true);
 ui->pushButton_minus->setCheckable(true);
 ui->pushButton_mult->setCheckable(true);
  ui->pushButton_sin->setCheckable(true);
   ui->pushButton_cos->setCheckable(true);
    ui->pushButton_tg->setCheckable(true);
     ui->pushButton_ctg->setCheckable(true);
      ui->pushButton_fact->setCheckable(true);
       ui->pushButton_ln->setCheckable(true);
        ui->pushButton_K_2->setCheckable(true);
          ui->pushButton_degree->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers(){

    QPushButton *button =(QPushButton *) sender();
    double all_numbers;
    QString new_label;

    if (ui->result_show->text().contains(".")&&button->text()=="0"){
        new_label=ui->result_show->text()+button->text();
    }else{
    all_numbers =(ui->result_show->text()+button->text()).toDouble();
    new_label= QString::number(all_numbers,'g',15);
    }
    ui->result_show->setText(new_label);

}
double fac(int N)
{
    if(N < 0)
        return 0;
    if (N == 0)
        return 1;
    else
        return N * fac(N - 1);
}
void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->result_show->text().contains('.')))
    ui->result_show->setText(ui->result_show->text()+".");
}
void MainWindow::operations(){

    QPushButton *button =(QPushButton *) sender();
    double all_numbers;
    QString new_label;

    if(button->text()=="+/-"){
    all_numbers =(ui->result_show->text()).toDouble();
    all_numbers=all_numbers * -1;
    new_label= QString::number(all_numbers,'g',15);
    ui->result_show->setText(new_label);

    } else if(button->text()=="%"){
        all_numbers =(ui->result_show->text()).toDouble();
        all_numbers=all_numbers * 0.01;
        new_label= QString::number(all_numbers,'g',15);
        ui->result_show->setText(new_label);

        }
}

void MainWindow::on_pushButton_result_clicked()
{
    double labelNumber,num_second;
            QString new_label;

            num_second=ui->result_show->text().toDouble();
if(ui->pushButton_plus->isChecked()){
    labelNumber =num_first + num_second;
    new_label= QString::number(labelNumber,'g',15);
    ui->result_show->setText(new_label);
    ui->pushButton_plus->setChecked(false);

}else if(ui->pushButton_minus->isChecked()){
    labelNumber =num_first - num_second;
    new_label= QString::number(labelNumber,'g',15);
    ui->result_show->setText(new_label);
    ui->pushButton_minus->setChecked(false);

}else if(ui->pushButton_mod->isChecked()){
    if(num_second==0){
        ui->result_show->setText("0");
    }else {


    labelNumber =num_first / num_second;
    new_label= QString::number(labelNumber,'g',15);
    ui->result_show->setText(new_label);
    }
    ui->pushButton_mod->setChecked(false);

}else if(ui->pushButton_mult->isChecked()){
    labelNumber =num_first * num_second;
    new_label= QString::number(labelNumber,'g',15);
    ui->result_show->setText(new_label);
    ui->pushButton_mult->setChecked(false);

}else if(ui->pushButton_sin->isChecked()){
    labelNumber = sin(num_first*PI/180);
    new_label= QString::number(labelNumber,'g',15);
    ui->result_show->setText(new_label);
    ui->pushButton_sin->setChecked(false);


}else if(ui->pushButton_K_2->isChecked()){
    labelNumber = sqrt(num_first);
    new_label = QString::number(labelNumber, 'g', 15);

    ui->result_show->setText(new_label);
    ui->pushButton_K_2->setChecked(false);

}else if(ui->pushButton_degree->isChecked()){
    labelNumber = pow(num_first, num_second);
    new_label = QString::number(labelNumber, 'g', 15);

    ui->result_show->setText(new_label);
    ui->pushButton_degree->setChecked(false);

}else if(ui->pushButton_cos->isChecked()){
    labelNumber = cos(num_first*PI/180);
    new_label = QString::number(labelNumber, 'g', 15);

    ui->result_show->setText(new_label);
    ui->pushButton_cos->setChecked(false);

}else if(ui->pushButton_tg->isChecked()){
    labelNumber = tan(num_first*PI/180);
    new_label = QString::number(labelNumber, 'g', 15);

    ui->result_show->setText(new_label);
    ui->pushButton_tg->setChecked(false);

}else if(ui->pushButton_ctg->isChecked()){
    labelNumber = 1/tan(num_first*PI/180);
    new_label = QString::number(labelNumber, 'g', 15);

    ui->result_show->setText(new_label);
    ui->pushButton_ctg->setChecked(false);

}else if(ui->pushButton_fact->isChecked()){
    labelNumber = fac(num_first);
    new_label = QString::number(labelNumber, 'g', 15);

    ui->result_show->setText(new_label);
    ui->pushButton_fact->setChecked(false);

}else if(ui->pushButton_ln->isChecked()){
    labelNumber = log(num_first)/log(num_second);
    new_label = QString::number(labelNumber, 'g', 15);

    ui->result_show->setText(new_label);
    ui->pushButton_ln->setChecked(false);
}
}
void MainWindow::math_operations()
{
 QPushButton *button =(QPushButton *) sender();
 num_first=ui->result_show->text().toDouble();
 ui->result_show->setText("");
 button->setChecked(true);

}


void MainWindow::on_pushButton_ac_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_mod->setChecked(false);
    ui->pushButton_mult->setChecked(false);
    ui->pushButton_cos->setChecked(false);
    ui->pushButton_sin->setChecked(false);
    ui->pushButton_tg->setChecked(false);
    ui->pushButton_ctg->setChecked(false);
    ui->pushButton_fact->setChecked(false);
    ui->pushButton_ln->setChecked(false);
    ui->pushButton_K_2->setChecked(false);
    ui->pushButton_degree->setChecked(false);
     ui->result_show->setText("0");
}




void MainWindow::on_pushButton_dele_clicked()
{
     ui->result_show->setText("0");
}


void MainWindow::on_pushButton_ls_clicked()
{
    ui->result_show->setText(ui->result_show->text() + "(");
}


void MainWindow::on_pushButton_ps_clicked()
{
    ui->result_show->setText(ui->result_show->text() + ")");
}

