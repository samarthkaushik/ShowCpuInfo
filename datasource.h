/*
  MBRDNA Assignment
  DataSource.h
  @author Samarth Kaushik
  @version 1.0  09/14/2015
*/
#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QStringList>
#include <QProcess>
#include <QDebug>

/* DataSource Class:  SINGLETON
 * simulate the data Source for different models.
 */
class DataSource
{

private:
    static DataSource* ptrData; // pointer for single object
    DataSource(); // private constructor for singleton
    QStringList list;

public:
    ~DataSource();
    static DataSource* getInstance(); // intsance creation
    QStringList& getData() ; // get the latest data
    void updateData(QString cmd);
};

#endif // DATASOURCE_H
