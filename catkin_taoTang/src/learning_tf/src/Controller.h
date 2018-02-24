
//ROS headers
//#include "ros/ros.h"
//#include <tf/tf.h>
//#include <geometry_msgs/PoseArray.h>

//Angelina headers
#include "referee.h"

#include <QLineEdit>
#include <QListWidget>
#include <QRadioButton>
#include <QTimer>
#include <QWidget>
#include <QMap>

// Seng,Gao's class


class Controller:public QWidget
{
    Q_OBJECT

    public:
        //Controller(QWidget *parent = 0, int argc = 0, char * argv[] = 0);
	//Controller(ros::NodeHandle &nh, QWidget *parent = 0);
        Controller(QWidget *parent = 0);
        ~Controller();
        bool de_started;
	bool game_started;
    private:
        Referee *referee;
	QTimer *aliveTimer;
        QTimer *timer;
	TeamColor US_COLOR;
	TeamColor OP_COLOR;
	//int status = 0;

	bool ended;
	void changeStatus();
        //void slotSendAlive();
    private Q_SLOTS:
        void reportReady();
	void slotTellAbValue();
	void tellTeamColor(TeamColor color);
	void slotSendAlive();
        void slotTimer();
        void slotConnected();
        void slotConnectFailed();
        void slotDisconnected();
        void slotDetectionStart();
        void slotGameStart();
        void slotTrueColorOfTeam(TeamColor);
        void slotGameOver();
        void slotStopMovement();
};
