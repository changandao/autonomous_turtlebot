//**************************************//
//****************

// COUT PROBLEM

//**********************//
///**************************************/

#include <iostream>
#include <cstdlib>
#include "Controller.h"
#include <QApplication>
//Referee * referee;

//Controller::Controller(QWidget * parent, int argc, char * argv[]) :
//	argc(argc),
//	argv(argv) {

Controller::Controller(QObject * parent) :QObject(parent),referee(0){
	
	referee = new Referee(2, this);
	
	// listen signals
	connect(referee, SIGNAL(disconnected()), this, SLOT(slotDisconnected()));
	connect(referee, SIGNAL(detectionStart()), this, SLOT(slotDetectionStart()));
	connect(referee, SIGNAL(gameStart()), this, SLOT(slotGameStart()));
	connect(referee, SIGNAL(trueColorOfTeam(TeamColor)), this, SLOT(slotTrueColorOfTeam(TeamColor)));
	connect(referee, SIGNAL(gameOver()), this, SLOT(slotGameOver()));
	connect(referee, SIGNAL(stopMovement()), this, SLOT(slotStopMovement()));
	connect(referee, SIGNAL(connected()), this, SLOT(slotConnected()));
	connect(referee, SIGNAL(connectFailed()), this, SLOT(slotConnectFailed()));
	
	// Connect to Server
	std::cout << "Connecting to server..." << std::endl;
	referee->connectToServer("127.0.0.1", 11111);

	//report ready
	de_started = false;
	ended = false;
	reportReady();

	// set alive timer
	aliveTimer = new QTimer(this);
	connect(aliveTimer, SIGNAL(timeout()), this, SLOT(slotSendAlive()));
	aliveTimer->start(15000);
	
	// set timer
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(slotTimer()));
	timer->start(5000);
	
}

Controller::~Controller() {
	
	delete referee;
	
}

//void Controller::changeStatus() {
//	status = status + 1;
//}


/**********************************************************/
/****************      methods            *****************/
/****************                         *****************/
/**********************************************************/

void Controller::reportReady(){
	
	referee->reportReady();
	
}

void Controller::slotTellAbValue()
{
	double ratio = 0.4;
	referee->tellAbRatio(ratio);
}

void Controller::tellTeamColor(TeamColor color)
{
	//Teamcolor colors = color;
	referee->tellTeamColor(color);
}

void Controller::slotSendAlive()
{
      std::cout << "send alive, send alive" << std::endl;
      referee->sendAlive();
}


/**********************************************************/
/*******************   signals      ***********************/
/*******************                ***********************/
/**********************************************************/
void Controller::slotTimer() {

        TeamColor teamcolor_ = blue;    // the color we tell Angelina
	if(de_started){
	   std::cout << "Now, start detect" << std::endl;
           slotTellAbValue();
	   tellTeamColor(teamcolor_);
	}
	//std::cout << "Current tick: " << tick << std::endl;


	// referee->reportReady();
	// referee->reportDone();
	// referee->reportGoal();
	// referee->tellEgoPos(double x, double y);

	//switch(status) {

		//STATUS_LIST(MAKE_CASE)

		//	break;
	//	default:
	
	//		break;
	//}
	
	
	//if (ended) {
	//	timer->stop();
	//	app->quit();
	//}

	//tick += 1;
}


//! Wird gesendet, falls die Verbindung zum Server erfolgreich war.
void Controller::slotConnected() {

	// tell angelina our color
        //US_COLOR = yellow;
	//referee->tellTeamColor(US_COLOR);

	

}

void Controller::slotConnectFailed() {

	//std::cout << BOLD(FRED("Connection failed.")) << std::endl;
	//exit(EXIT_FAILURE);

}

void Controller::slotDisconnected() {

	//std::cerr << BOLD(FRED("Server Lost")) << std::endl;
	ended = true;

}

void Controller::slotDetectionStart() {

	de_started = true;
	//changeStatus(status_free_explore);

}

void Controller::slotGameStart() {

	 game_started = true;
	//changeStatus(status_select_target);

}

void Controller::slotTrueColorOfTeam(TeamColor color) {

	if (color == blue) {

		US_COLOR = blue;
		OP_COLOR = yellow;

		//cout << FBLU("We are now blue.") << endl;
		std::cout << "We are now blue" << std::endl;
	} else {

		US_COLOR = yellow;
		OP_COLOR = blue;

		//cout << FYEL("We are yellow.") << endl;
		std::cout << "We are yellow" << std::endl;
	}

}

void Controller::slotGameOver() {

}

void Controller::slotStopMovement() {

}



