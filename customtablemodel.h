/*
  MBRDNA Assignment
  CustomTableModel.h
  @author Samarth Kaushik
  @version 1.0  09/14/2015
*/
#ifndef CUSTOMTABLEMODEL_H
#define CUSTOMTABLEMODEL_H

#include <QAbstractTableModel>
#include "datasource.h"

/* CustomTableModel Class:
 * Demonstrates the concept of developing custom models to be used by different views.
 */
class CustomTableModel: public QAbstractTableModel
{
public:
    CustomTableModel(QObject *parent = 0);
    int rowCount(const QModelIndex &parent) const;  // abstract method from parent
    int columnCount(const QModelIndex &parent) const; // abstract method from parent
    QVariant data(const QModelIndex &index, int role) const; // abstract method from parent
    QVariant headerData(int section, Qt::Orientation orientation, int role) const; // abstract method from parent
    void fillData();
    ~CustomTableModel();

private:
    DataSource* ptrDataSource; // pointer to hold data source
    QStringList list;


};

#endif // CUSTOMTABLEMODEL_H
