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

//A little something added to gain access to standard libraries
using namespace std;

void SSLStarter();
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
        SSLStarter();
    }
    else{
        string strDBSChoice = " ";
        cout << "Press A to Add to the database, D to delete or V to view: " << endl;
        cin >> strDBSChoice;
        if (strDBSChoice == "A"){
            cout << "Starting new database" << endl;
            QSqlDatabase NewDatabase;
            NewDatabase.setHostName("mysql9.000webhost.com");
            NewDatabase.setUserName("a1014897_Crypto");
            NewDatabase.setPassword("1lovefr4nk");
            NewDatabase.setDatabaseName("a1014897_Crypto");
            NewDatabase.setPort(1433);
            bool ok = NewDatabase.open();
            QSqlQuery query(NewDatabase);
            query.exec("INSERT INTO Messages (UserID, Username, Time, Date, Message) "
                        "VALUES (1, 'Matt', 00:00, 01/01/14, 'This is a test')");
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

void SSLStarter(){
        string websiteentry = " ";
        cout << "Select the website to connect to: " << endl;
        cin >> websiteentry;
        cout << "Connecting... Please wait." << endl;
        QSslSocket socket;
        socket.connectToHostEncrypted("www.paypal.com", 443);
        socket.write("GET / HTTP/1.0rnrn");
        while (socket.waitForReadyRead())
            qDebug() << socket.readAll().data();
        cout << "Connection established" << endl;
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

void NewDBS(string UserName, string Password){
    QSqlDatabase NewDatabase;
    NewDatabase.setHostName("mysql9.000webhost.com");
    NewDatabase.setUserName("a1014897_Crypto");
    NewDatabase.setPassword("1lovefr4nk");
    NewDatabase.setDatabaseName("a1014897_Crypto");
    NewDatabase.setPort(1433);
    bool ok = NewDatabase.open();
    NewDatabase.close();
}

void DBSAddMember(string UserName, string Password, string Handle){
    QSqlDatabase NewDatabase;
    NewDatabase.setHostName("mysql9.000webhost.com");
    NewDatabase.setUserName("a1014897_Crypto");
    NewDatabase.setPassword("1lovefr4nk");
    NewDatabase.setDatabaseName("a1014897_Crypto");
    NewDatabase.setPort(1433);
    bool ok = NewDatabase.open();
    QSqlQuery query(NewDatabase);
    query.exec("INSERT INTO DBNames (UserName, Password, Handle) "
                "VALUES (UserName, Password, Handle)");
    NewDatabase.close();
}

void DBSNewHandle(string UserName, string Password, string Handle){
    QSqlDatabase NewDatabase;
    NewDatabase.setHostName("mysql9.000webhost.com");
    NewDatabase.setUserName("a1014897_Crypto");
    NewDatabase.setPassword("1lovefr4nk");
    NewDatabase.setDatabaseName("a1014897_Crypto");
    NewDatabase.setPort(1433);
    bool ok = NewDatabase.open();
    QSqlQuery query(NewDatabase);
    query.exec("INSERT INTO DBNames (UserName, Password, Handle) "
                "VALUES (UserName, Handle)");
    NewDatabase.close();
}

void DBSEditHandle(string OldHandle, string NewHandle){
    QSqlDatabase NewDatabase;
    NewDatabase.setHostName("mysql9.000webhost.com");
    NewDatabase.setUserName("a1014897_Crypto");
    NewDatabase.setPassword("1lovefr4nk");
    NewDatabase.setDatabaseName("a1014897_Crypto");
    NewDatabase.setPort(1433);
    bool ok = NewDatabase.open();
    QSqlQuery query(NewDatabase);
    query.exec("Update DBNames"
               "Set Handle= ’NewHandle’"
               "Where Handle = ‘OldHandle’");
    NewDatabase.close();
}


void DBSEditPassword(string Username, string OldPassword, string NewPassword){
    QSqlDatabase NewDatabase;
    NewDatabase.setHostName("mysql9.000webhost.com");
    NewDatabase.setUserName("a1014897_Crypto");
    NewDatabase.setPassword("1lovefr4nk");
    NewDatabase.setDatabaseName("a1014897_Crypto");
    NewDatabase.setPort(1433);
    bool ok = NewDatabase.open();
    QSqlQuery query(NewDatabase);
    query.exec ("Update DBNames"
    "Set Password =’NewPassword’"
    "Where Password=’OldPassword’ AND Username = 'Username'");
    NewDatabase.close();
}

void DBSDeleteUser(string Username, string Password){
    QSqlDatabase NewDatabase;
    NewDatabase.setHostName("mysql9.000webhost.com");
    NewDatabase.setUserName("a1014897_Crypto");
    NewDatabase.setPassword("1lovefr4nk");
    NewDatabase.setDatabaseName("a1014897_Crypto");
    NewDatabase.setPort(1433);
    bool ok = NewDatabase.open();
    QSqlQuery query(NewDatabase);
    query.exec ("Delete from DBNames(UID, UName, Password, Handle)"
                "Where UName = ‘Username’ AND Password = 'Password'");
    NewDatabase.close();
}

void DBSDeleteHandle(string Username, string Handle){
    QSqlDatabase NewDatabase;
    NewDatabase.setHostName("mysql9.000webhost.com");
    NewDatabase.setUserName("a1014897_Crypto");
    NewDatabase.setPassword("1lovefr4nk");
    NewDatabase.setDatabaseName("a1014897_Crypto");
    NewDatabase.setPort(1433);
    bool ok = NewDatabase.open();
    QSqlQuery query(NewDatabase);
    query.exec ("Delete from DBNames(Handle)"
                "Where UName = ‘Username’ AND Handle = 'Handle'");
    NewDatabase.close();
}

void DBSAddMessage(string Handle, string Message, string StrTStmp){
    QSqlDatabase NewDatabase;
    NewDatabase.setHostName("mysql9.000webhost.com");
    NewDatabase.setUserName("a1014897_Crypto");
    NewDatabase.setPassword("1lovefr4nk");
    NewDatabase.setDatabaseName("a1014897_Crypto");
    NewDatabase.setPort(1433);
    bool ok = NewDatabase.open();
    QSqlQuery query(NewDatabase);
    query.exec ("Insert into DBMsg(Handle, Message, Timestamp)"
                "Values(Handle, Message, StrTStmp)");
    NewDatabase.close();
}

void DBSDeleteMessage(string Handle, string StrTStmp){
    QSqlDatabase NewDatabase;
    NewDatabase.setHostName("mysql9.000webhost.com");
    NewDatabase.setUserName("a1014897_Crypto");
    NewDatabase.setPassword("1lovefr4nk");
    NewDatabase.setDatabaseName("a1014897_Crypto");
    NewDatabase.setPort(1433);
    bool ok = NewDatabase.open();
    QSqlQuery query(NewDatabase);
    query.exec ("Delete from DBMsg(Handle, Message, Timestamp)"
                "Where Handle = ‘Handle’ AND Timestamp = ‘StrTStmp’");
    NewDatabase.close();
}

void DBSDeleteAllMSG(string Handle){
    QSqlDatabase NewDatabase;
    NewDatabase.setHostName("mysql9.000webhost.com");
    NewDatabase.setUserName("a1014897_Crypto");
    NewDatabase.setPassword("1lovefr4nk");
    NewDatabase.setDatabaseName("a1014897_Crypto");
    NewDatabase.setPort(1433);
    bool ok = NewDatabase.open();
    QSqlQuery query(NewDatabase);
    query.exec ("Delete from DBMsg(Handle, Message, Timestamp)"
                "Where Handle = ‘Handle’");
    NewDatabase.close();
}

void DBSRetrieveMSG(string Handle, string Password){
    QSqlDatabase NewDatabase;
    NewDatabase.setHostName("mysql9.000webhost.com");
    NewDatabase.setUserName("a1014897_Crypto");
    NewDatabase.setPassword("1lovefr4nk");
    NewDatabase.setDatabaseName("a1014897_Crypto");
    NewDatabase.setPort(1433);
    bool ok = NewDatabase.open();
    QSqlQuery query(NewDatabase);
    query.exec ("Select (Handle, Message, Timestamp) from DBMsg"
                "Where Handle = ‘Handle’ AND Password = 'Password'");
    NewDatabase.close();
}
