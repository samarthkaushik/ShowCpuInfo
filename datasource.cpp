/*
  MBRDNA Assignment
  DataSource.cpp
  @author Samarth Kaushik
  @version 1.0  09/14/2015
*/
#include "datasource.h"

//Initialization
DataSource* DataSource::ptrData = 0;

/* Destructor: free the resources from heap.
 * @param: none
 * @return: none
 */
DataSource::~DataSource()
{
    delete ptrData;
}

/* Constructor for Singleton class
 * @param: none
 * @return: none
 */
DataSource::DataSource()
{
    updateData(QString(""));
}

/* getInstance: creates a single instance of the class.
 * @param: none
 * @return: DataSource object
 */
DataSource* DataSource::getInstance()
{
    if(ptrData == 0)
    {
        ptrData = new DataSource();
    }

    return ptrData;
}

/* getData: fille the list with cpuInfo.
 * @param: none
 * @return: String list,
 */
QStringList& DataSource::getData()
{
    return list;
}

/* updateData: fill the list with cpuInfo.
 * @param: command
 * @return: none
 */
void DataSource::updateData(QString cmd)
{
    QProcess process;

    if(cmd.isEmpty())
        cmd.append("cat /proc/cpuinfo");

    process.start(cmd);
    process.waitForFinished(1000);

    list.clear();

    QString screenOutput = QString::fromLatin1(process.readAllStandardOutput());
    if(!screenOutput.isEmpty())
        list = screenOutput.split("\n", QString::SkipEmptyParts);
    else
        list << "No Element: No Data";
}
