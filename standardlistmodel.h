/*
  MBRDNA Assignment
  StandardListModel.h
  @author Samarth Kaushik
  @version 1.0  09/14/2015
*/
#ifndef STANDARDLISTMODEL_H
#define STANDARDLISTMODEL_H

#include <datasource.h>
#include <QStringListModel>

/* StandardListModel Class:
 * Demonstrates the usage of standard list model.
 */
class StandardListModel: public QStringListModel
{
public:
    StandardListModel(QObject *parent = 0);
    void fillData(); // gets updated data
    ~StandardListModel();
 private:
    DataSource* ptrDataSource; // pointer to data source
};

#endif // STANDARDLISTMODEL_H
