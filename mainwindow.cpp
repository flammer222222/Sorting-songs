#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include "Dialog.h"
#include <QTextStream>
#include <cstring>
#define G 999
//C:\Users\Alamez\Desktop\qq.bin
using namespace std;
struct songs
{
    int kolvo[G] ;
    char  stil[G] [20];
      QString name;
       QString data;
       QString autor;
      char mass[G][80];
      char names[G][20];
      QString autor3;
      QString data3;
      QString name3;
};
struct songs qqq[G];
QString mass[G];
int g=0;
int kolvo_pesen=8;
QString ch=";";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionRead_triggered()
{
    Dialog *wnd= new Dialog (this);
    wnd->show();

    connect (wnd,SIGNAL (FilePath (QString)),this,SLOT (ReadToFile(QString)));
}
void MainWindow::ReadToFile(const QString & filePath)
{
    QFile mFile(filePath);
    if (!mFile.open(QFile::ReadOnly ))
    {
        QMessageBox::information(this,"Eror","Path not correct!");
        return;
    }
    ui->textEdit->clear();
    QTextStream stream(&mFile);
  QString buffer;
   QString test;
  QStringList w;
  int i=0;
//  int line_count=0;
//  QString line[100];
  while( !stream.atEnd())
  {
      buffer = stream.readLine();
            w = buffer.split(";", QString::SkipEmptyParts);
            qqq[i].name=w[0];
            qqq[i].autor=w[1];
            qqq[i].data=w[2];
            ui->textEdit->append(qqq[i].name+ch+qqq[i].autor+ch+qqq[i].data);
             mFile.flush();
             i++;
 }
  kolvo_pesen=i;
//     kolvo_pesen= line_count;
  //
  //
  //
//   for(int i=0;i<kolvo_pesen;i++)
//      {
//        buffer = stream.readLine();
//       w = buffer.split(";", QString::SkipEmptyParts);
//       qqq[i].name=w[0];
//       qqq[i].autor=w[1];
//       qqq[i].data=w[2];
//       ui->textEdit->append(qqq[i].name+ch+qqq[i].autor+ch+qqq[i].data);
//        mFile.flush();
//       }
   //
   //
   //
  //   buffer = stream.readAll();
   //  ui->textEdit->setText(buffer);
  //   mFile.flush();
     mFile.close();
}

void MainWindow::on_actionWrite_triggered()
{
    Dialog *wnd= new Dialog (this);
    wnd->show();

    connect (wnd,SIGNAL (FilePath (QString)),this,SLOT (WriteToFile(QString)));
}




void MainWindow::WriteToFile(const QString & filePath)
{
    QFile mFile(filePath);

    if (!mFile.open(QFile::WriteOnly ))
    {
        QMessageBox::information(this,"Eror","Path not correct!");
        return;
    }
    QTextStream stream(&mFile) ;
    stream<< ui->textEdit->toPlainText();
     mFile.close();
}

void MainWindow::on_actionSort_by_name_triggered()
{
    int i,j,r;
           int n=kolvo_pesen;
            int result[n];
           for (int i=0;i<n;i++)
               {
                  result[i]=i;
               }
              for (i = 0; i < n - 1; i++)
              {
                  for ( j = i + 1; j < n; j++)
                      {
                      if (QString::compare(qqq[i].name, qqq[j].name)>0)
                          {
                              swap(qqq[i].name,qqq[j].name);
                              swap (result [i], result[j]);
                          }
                  }
              }
               ui->textEdit->clear();
             // ui->textEdit->setText("Песни отсортированные по названию");
              for (r = 0; r < n; r++)
                  {
                    ui->textEdit->append(qqq[r].name+ch+qqq[result[r]].autor+ch+qqq[result[r]].data);
                    qqq[r].autor3= qqq[result[r]].autor;
                     qqq[r].data3 = qqq[result[r]].data;
                  }
              for (r = 0; r < n; r++)
              {
                  qqq[r].data=qqq[r].data3;
                  qqq[r].autor=qqq[r].autor3;
              }
}

void MainWindow::on_actionSort_by_data_triggered()
{
    int i,j,r;
        int n=kolvo_pesen;
         int result[n];
        for (int i=0;i<n;i++)
            {
               result[i]=i;
            }
           for (i = 0; i < n - 1; i++)
           {
               for ( j = i + 1; j < n; j++)
                   {
                   if (QString::compare(qqq[i].data, qqq[j].data)>0)
                       {
                           swap(qqq[i].data,qqq[j].data);
                           swap (result [i], result[j]);
                       }
               }
           }
            ui->textEdit->clear();
      //     ui->textEdit->setText("Песни отсортированные по годам");
           for (r = 0; r < n; r++)
               {
                 ui->textEdit->append(qqq[result[r]].name+ch+qqq[result[r]].autor+ch+qqq[r].data);
                 qqq[r].autor3=qqq[result[r]].autor;
                  qqq[r].name3=qqq[result[r]].name;
               }
           for (r = 0; r < n; r++)
           {
              qqq[r].name=qqq[r].name3;
              qqq[r].autor=qqq[r].autor3;
           }
}

void MainWindow::on_actionSort_by_autor_triggered()
{
    int i,j,r;
       int n=kolvo_pesen;
        int result[n];
       for (int i=0;i<n;i++)
           {
              result[i]=i;
           }
          for (i = 0; i < n - 1; i++)
          {
              for ( j = i + 1; j < n; j++)
                  {
                  if (QString::compare(qqq[i].autor, qqq[j].autor)>0)
                      {
                          swap(qqq[i].autor,qqq[j].autor);
                          swap (result [i], result[j]);
                      }
              }
          }
           ui->textEdit->clear();
       //   ui->textEdit->setText("Песни отсортированные по авторам");
          for (r = 0; r < n; r++)
              {
                ui->textEdit->append(qqq[result[r]].name+ch+qqq[r].autor+ch+qqq[result[r]].data);
                qqq[r].data3=qqq[result[r]].data;
                 qqq[r].name3=qqq[result[r]].name;
              }
          for (r = 0; r < n; r++)
          {
              qqq[r].name=qqq[r].name3;
              qqq[r].data=qqq[r].data3;
          }
}
