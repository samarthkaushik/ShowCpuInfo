/*
  MBRDNA Assignment
  StandardListModel.cpp
  @author Samarth Kaushik
  @version 1.0  09/14/2015
*/
#include "standardlistmodel.h"

/* Constructor: obtains the pointer to data source
 * @param: none
 * @return: none
 */
StandardListModel::StandardListModel(QObject *parent):QStringListModel(parent)
{
    ptrDataSource = DataSource::getInstance();
}

/* filldata:  gets the latest update from source.
 * @param: none
 * @return: none
 */
void StandardListModel::fillData()
{
    this->setStringList(ptrDataSource->getData());
}

/* ~StandardListModel: to check if the destructor is called due to object hierarchy.
 * @param: none
 * @return: none
 */
StandardListModel::~StandardListModel()
{
    qDebug("StandardListModel Destructor called.");
}
