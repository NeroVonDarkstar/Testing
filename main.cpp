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

}

void DBSAddMember(string UserName, string Password){

}

void DBSNewHandle(string UserName, string Password, string Handle){

}

void DBSEditHandle(string OldHandle, string NewHandle){

}


void DBSEditPassword(string Username, string OldPassword, string NewPassword){

}

void DBSDeleteUser(string Username, string Password){

}

void DBSDeleteHandle(string Username, string Handle){

}

void DBSAddMessage(string Handle, string Message){

}

void DBSDeleteMessage(string Handle, string Message){

}

void DBSDeleteAllMSG(string Handle){

}

void DBSRetrieveMSG(string Handle, string Password){

}
