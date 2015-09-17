/*
  MBRDNA Assignment
  CpuInfoDialogView.cpp
  @author Samarth Kaushik
  @version 1.0  09/14/2015
*/
#include "cpuinfodialogview.h"
#include "ui_cpuinfodialogview.h"

/* Constructor: create new models for views.
 * @param: none
 * @return: none
 */
CpuInfoDialogView::CpuInfoDialogView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CpuInfoDialogView)
{
    ui->setupUi(this);

    this->setWindowTitle("MBRDNA Assignment");

    // Model objects
    stdModel = new StandardListModel(this);
    cstModel = new CustomTableModel(this);
}

/* destructor: free the resources from heap.
 * @param: none
 * @return: none
 */
CpuInfoDialogView::~CpuInfoDialogView()
{
    // free heap memory
    delete ui;
    /* No need to free heap resources (models) due to parent child relationship*/
}

/* on_pushButton_clicked: function is called when button is clicked. links the views with corresponding models.
 * @param: none
 * @return: none
 */
void CpuInfoDialogView::on_pushButton_clicked()
{

    //link view and model
    stdModel->fillData();
    ui->listView->setModel(stdModel);

    //link view and model
    cstModel->fillData();
    ui->tableView->setModel(cstModel);
    // view config
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}
