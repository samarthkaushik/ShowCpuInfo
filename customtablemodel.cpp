/*
  MBRDNA Assignment
  CustomTableModel.cpp
  @author Samarth Kaushik
  @version 1.0  09/14/2015
*/
#include "customtablemodel.h"


/* Constructor: obtains the pointer to data source.
 * @param: none
 * @return: none
 */
CustomTableModel::CustomTableModel(QObject *parent):QAbstractTableModel(parent)
{
    ptrDataSource = DataSource::getInstance();
}


/* filldata:  gets the latest update from source.
 * @param: none
 * @return: none
 */
void CustomTableModel::fillData()
{
    //ptrDataSource->updateData(QString("lscpu"));  /* Ability to request different data from source */
    list = ptrDataSource->getData();
}


/* rowCount: returns the number of rows in the data.
 * @param: QModelIndex
 * @return: int
 */
int CustomTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent); //prevent compiler warning for unused param
    return list.size();
}


/* columnCount: returns the number of columns in the data.
 * @param: QModelIndex
 * @return: int
 */
int CustomTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent); //prevent compiler warning for unused param
    return 2; // Hardcoded for this particular example.
}


/* data: provides the data to view.
 * @param: QModelIndex, int
 * @return: string
 */
QVariant CustomTableModel::data(const QModelIndex &index, int role) const
{
    if(Qt::DisplayRole == role)
    {
        if(0 == index.column())
        {
            return list[index.row()].split(':').front();
        }
        else if(1 == index.column())
        {
            if(!list[index.row()].split(':').last().isEmpty())
                return list[index.row()].split(':').last();
            else
                return QString("No Information");
        }

    }
    return QVariant::Invalid;
}

/* headerData: sets the header for the table.
 * @param: none
 * @return: string
 */
QVariant CustomTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(Qt::DisplayRole == role)
    {
        if(Qt::Horizontal == orientation)
        {
            if(0 == section)
            {
                return QString("Element");
            }
            else if(1 == section)
            {
                return QString("Info");
            }
        }

    }
    return QVariant::Invalid;
}

/* ~CustomTableModel: to check if the destructor is called due to object hierarchy.
 * @param: none
 * @return: none
 */
CustomTableModel::~CustomTableModel()
{
    qDebug("CustomTableModel Destructor called.");
}
