// Diana Marczuk

//  Compile with:
//  $ g++ referee.c -o referee

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<wait.h>
#include	<unistd.h>
#include	<signal.h>
#include	<sys/types.h>

const int	MAX_NUM_PLAYERS		= 2;

const int	TEXT_LEN		= 256;

const int	NUM_POINTS_TO_WIN	= 4;

#define		PLAYER_PROG		"tennisPlayer"

const char*	pointNames[]		= {"love","15","30","40","game",
                                           "game-over","game-over"};

int		currentNumPlayers	= 0;

int		shouldPlay		= 1;

pid_t		playerArray[MAX_NUM_PLAYERS];

int		points[MAX_NUM_PLAYERS];

void		sigUsr1Handler	(int		sigNum,
				 siginfo_t*	infoPtr,
				 void*		dataPtr
				)
{
  //  I.D.  YOUR CODE to increment the corresponding points[] elements

	//points[0] --> receive player, 1 is server
	//pid == infoPtr->si_pid ---> match to a player id of 0 or 1
	//if (player_1 sent sig) points[0]++;
	//else points[1]++;
	if (playerArray[0] == infoPtr -> si_pid) 
	{
		points[0]++;	
	}
	else
	{
		points[1]++;
	}
	
	//if either point[0] or points[1] becomes NUM_POINTS_TO_WIN then shouldPLay should
	//be set to 0
	if (points[0]==NUM_POINTS_TO_WIN || points[1]==NUM_POINTS_TO_WIN)
	{
		shouldPlay = 0;
	}




  printf("Referee: \"%s %s (server %d, receiver %d)\"\n",
	 pointNames[points[1]],pointNames[points[0]],
	 points[1],points[0]
	);
}


int		main		()
{
  struct sigaction	act;
  int			i;

  //  I.C.1.  YOUR CODE to install sigUsr1Handler() as the SIGUSR1 handler
  
  //  Diana notes- Think of the sig action call as linking the handler to the signal for
  //  sig user 1
  memset(&act, '\0', sizeof(act));
  sigemptyset(&act.sa_mask);
  act.sa_flags = SA_SIGINFO | SA_RESTART;
  act.sa_sigaction = sigUsr1Handler;
  sigaction(SIGUSR1, &act, NULL);

  //  I.C.2.  YOUR CODE to start both child processes
  pid_t pid = fork();
  if (pid == 0) //I am child process, launch tennisPlayer w/ no args
  {
	//do launchy things here
	//do not pass any arguments so left null in the first one
	execl(PLAYER_PROG, PLAYER_PROG, NULL);
	fprintf(stderr, "Cannot run %s\n", PLAYER_PROG);
	exit(EXIT_FAILURE);
  }

  playerArray[0]= pid;

  //passing the pid of the first child in a string to pass to the first call
  char text[TEXT_LEN];
  snprintf(text, TEXT_LEN, "%d", playerArray[0]);

  //wah wah another child
  //can reuse the variable name pid because last one was alread stored off
  pid = fork();
  if (pid == 0) //I am child process, launch tennisPlayer w/ no args
  {
	//do launchy things here
	//do not pass any arguments so left null in the first one
	//do text to pass in the pid to the second call
	execl(PLAYER_PROG, PLAYER_PROG, text, NULL);
	fprintf(stderr, "Cannot run %s\n", PLAYER_PROG);
	exit(EXIT_FAILURE);
  }

  playerArray[1]= pid;


  //  I.C.3.  Wait for the game to be over
  while  (shouldPlay)
    sleep(1);

  //  I.C.4.  YOUR CODE to tell children to stop:
  for (i = 0; i < MAX_NUM_PLAYERS; i++)
  {
		kill(playerArray[i], SIGTERM);
	}

  //  III.  Finished:
  return(EXIT_SUCCESS);
}
