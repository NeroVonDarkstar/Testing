//Includes for the items needed to create an SSL connection
#include <QCoreApplication>
#include <QSslCipher>
#include <QSslSocket>
#include <iostream>
#include <QTextStream>
#include <QDebug>
#include <QByteArray>
#include <QFile>
#include <QIODevice>
#include <QSslKey>
#include <QSslCertificate>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSsl>
#include <QHostAddress>

//A little something added to gain access to standard libraries
using namespace std;

bool SSLStarter();
void SSLServer();
void NewDBS();
void DBSAddMember();
void DBSNewHandle();
void DBSEditHandle();
void DBSEditPassword();
void DBSDeleteUser();
void DBSDeleteHandle();
void DBSAddMessage();
void DBSDeleteMessage();
void DBSDeleteAllMSG();
void DBSRetrieveMSG();


//The lovely main part of the code
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    string exitclause = " ";
    cout << "Checking for available drivers: " << endl;
    QSqlDatabase NewDatabase;
    NewDatabase.drivers();
    cout << "Press S for server connection, C for client or D for database scripts: " << endl;
    cin >> exitclause;
    if (exitclause == "S"){
        SSLServer();
    }
    else if(exitclause == "C"){
        cout << "Please enter the Address you wish to connect to: " << endl;
        string HostAddress = "";
        cin >> HostAddress;
        cout << "Please enter the port number, type 443 for the default port: " << endl;
        int Port = 0;
        cin >> Port;
        SSLStarter(HostAddress, Port);
    }
    else{
        string strDBSChoice = " ";
        cout << "Press A to Add to the database, D to delete or V to view: " << endl;
        cin >> strDBSChoice;
        if (strDBSChoice == "A"){
            {
                cout << "Starting new database" << endl;
                QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
                string ubuffer = "";
                string pbuffer = "";
                db.setConnectOptions();
                db.setDatabaseName("test");
                db.setHostName("ephesus.cs.cf.ac.uk");
                db.setPort(3306);
                cout << "Please enter a username" << endl;
                cin >> ubuffer;
                QString username = QString::fromStdString(ubuffer);
                db.setUserName(username);
                cout << "Please enter a password" << endl;
                cin >> pbuffer;
                QString password = QString::fromStdString(pbuffer);
                db.setPassword(password);
                bool x = db.open();
                if (x == true){
                    cout << "Connection successful" << endl;
                    addMember();
                }
                else{
                    cout << "not yet jim" << endl;
                }
                return a.exec();
            }
        }
        else if (strDBSChoice == "D"){

        }
        else{

        }
    }
    cout << "Press enter to exit" << endl;
    cin >> exitclause;
    if (exitclause != "1"){
        return 0;
    }

    return a.exec();
}

bool SSLStarter(string Address, int Port){
       QHostAddress HostAddress;
       HostAddress.setAddress(Address);

       QSslSocket Socket;

       Socket.connectToHostEncrypted(Address, Port);

       if(!Socket.waitForEncrypted()) {
          return false;
       }
       cout << "Connection established" << endl;

       return true;
}

void SSLServer(){
    QSslSocket serversocket;
    serversocket.setProtocol(QSsl::SslV3);
    QByteArray key;
    QByteArray cert;
    QFile file_key("www.nerovon.com.key");
    if(file_key.open(QIODevice::ReadOnly))
    {
        key = file_key.readAll();
        file_key.close();
    }
    else
    {
        qDebug()<<file_key.errorString();
    }

    QSslKey ssl_key(key, QSsl::Rsa);

    QSslCertificate ssl_cert(cert);

    serversocket.setPrivateKey(ssl_key);
    serversocket.setLocalCertificate(ssl_cert);
    cout << "Starting the server encryption" << endl;
    serversocket.startServerEncryption();
    cout << "Encrypted server successful" << endl;

}

void DBSAddMember(string UserName, string Password){
    int newId = -1;
    bool ret = false;
        if (db.isOpen())
                    {
                    QSqlQuery query;
                    ret = query.exec("insert into persons values(NULL,'%1','%2')");
                    .arg(UserName).arg(Password));

                    //Get database given autoincrement value
                    if (ret)
                    {
                        newId = query.lastInsertId().toInt();
                        cout << newId << endl;
                        }
                    }
}

void DBSNewHandle(string UserID, string Handle){
    int newId = -1;
    bool ret = false;
        if (db.isOpen())
                    {
                    QSqlQuery query;
                    ret = query.exec("insert into handles values(NULL,'%1','%2')");
                    .arg(UserID).arg(Handle));

                    //Get database given autoincrement value
                    if (ret)
                    {
                        newId = query.lastInsertId().toInt();
                        cout << newId << endl;
                        }

                    }
}

void DBSAddMessage(string handleID, string message){
    int newId = -1;
    bool ret = false;
        if (db.isOpen())
                    {
                    QSqlQuery query;
                    ret = query.exec("insert into handles values(NULL,'%1','%2')");
                    .arg(handleID).arg(message));

                    //Get database given autoincrement value
                    if (ret)
                    {
                        newId = query.lastInsertId().toInt();
                        cout << newId << endl;
                        }

                    }
}

void DBSEditHandle(string OldHandle, string NewHandle){
    int newId = -1;
    bool ret = false;
        if (db.isOpen())
                    {
                    QSqlQuery query;
                    ret = query.exec("Update DBNames Set Handle= ’%1’ Where Handle = ‘%2’");
                    .arg(handleID).arg(message));

                    //Get database given autoincrement value
                    if (ret)
                    {
                        newId = query.lastInsertId().toInt();
                        cout << newId << endl;
                        }

                    }
	}

void DBSEditPassword(string Username, string OldPassword, string NewPassword){
	int newId = -1;
    bool ret = false;
        if (db.isOpen())
                    {
                    QSqlQuery query;
                    ret = query.exec("Update DBNames Set Password =’%3' Where Password=’%2’ AND Username = '%1'");
                    .arg(handleID).arg(message));

                    //Get database given autoincrement value
                    if (ret)
                    {
                        newId = query.lastInsertId().toInt();
                        cout << newId << endl;
                        }
                    }
		}

void DBSDeleteUser(string Username, string Password){
	int newId = -1;
    bool ret = false;
        if (db.isOpen())
                    {
                    QSqlQuery query;
                    ret = query.exec("Delete from DBNames(UID, UName, Password, Handle Where UName = ‘%1’ AND Password = '%2'");
                    .arg(handleID).arg(message));

                    //Get database given autoincrement value
                    if (ret)
                    {
                        newId = query.lastInsertId().toInt();
                        cout << newId << endl;
                        }
                    }
		}


void DBSDeleteHandle(string Username, string Handle){
	
	int newId = -1;
    bool ret = false;
        if (db.isOpen())
                    {
                    QSqlQuery query;
                    ret = query.exec("Delete from DBNames(Handle) Where UName = ‘%1’ AND Handle = '%2'");
                    .arg(handleID).arg(message));

                    //Get database given autoincrement value
                    if (ret)
                    {
                        newId = query.lastInsertId().toInt();
                        cout << newId << endl;
                        }
                    }
		}

void DBSDeleteMessage(string Handle, string StrTStmp){

	int newId = -1;
    bool ret = false;
        if (db.isOpen())
                    {
                    QSqlQuery query;
                    ret = query.exec("Delete from DBMsg(Handle, Message, Timestamp) Where Handle = ‘%1’ AND Timestamp = ‘%2’");
                    .arg(handleID).arg(message));

                    //Get database given autoincrement value
                    if (ret)
                    {
                        newId = query.lastInsertId().toInt();
                        cout << newId << endl;
                        }
                    }
		}

void DBSDeleteAllMSG(string Handle){

	int newId = -1;
    bool ret = false;
        if (db.isOpen())
                    {
                    QSqlQuery query;
                    ret = query.exec("Delete from DBMsg(Handle, Message, Timestamp) Where Handle = ‘%1’");
                    .arg(handleID).arg(message));

                    //Get database given autoincrement value
                    if (ret)
                    {
                        newId = query.lastInsertId().toInt();
                        cout << newId << endl;
                        }
                    }
		}

void DBSRetrieveMSG(string Handle, string Password){

	int newId = -1;
    bool ret = false;
        if (db.isOpen())
                    {
                    QSqlQuery query;
                    ret = query.exec("Select (Handle, Message, Timestamp) from DBMsg Where Handle = ‘%1’ AND Password = '%2'");
                    .arg(handleID).arg(message));

                    //Get database given autoincrement value
                    if (ret)
                    {
                        newId = query.lastInsertId().toInt();
                        cout << newId << endl;
                        }
                    }
		}
