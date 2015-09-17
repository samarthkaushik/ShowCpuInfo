/*
  MBRDNA Assignment
  CpuInfoDialogView.h
  @author Samarth Kaushik
  @version 1.0  09/14/2015
*/
#ifndef CPUINFODIALOGVIEW_H
#define CPUINFODIALOGVIEW_H

#include <QDialog>
#include "customtablemodel.h"
#include "standardlistmodel.h"

/* CpuInfoDialogView Class:
 * provide a dialog for displaying CPU information.
 */
namespace Ui {
class CpuInfoDialogView;
}

class CpuInfoDialogView : public QDialog
{
    Q_OBJECT

public:
    explicit CpuInfoDialogView(QWidget *parent = 0);
    ~CpuInfoDialogView();

private slots:
    void on_pushButton_clicked(); // Slot for push button

private:
    Ui::CpuInfoDialogView *ui;
    CustomTableModel* cstModel;  //pointer to custom model
    StandardListModel* stdModel; //pointer to standard model
};

#endif // CPUINFODIALOGVIEW_H
