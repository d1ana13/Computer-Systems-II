/*-------------------------------------------------------------------------*
 *---									---*
 *---		computePolynomial.cpp					---*
 *---									---*
 *---	    This file defines a function that creates a child process,	---*
 *---	sends the contents of '*inputStackPtr' to the child process  	---*
 *---	via a pipe, reads the results that the child gives back using	---*
 *---	another pipe, and put those results into '*outputStackPtr'.	---*
 *---									---*
 *---	----	----	----	----	----	----	----	----	---*
 *---									---*
 *---	Version 1.0		2021 May 27		Joseph Phillips	---*
 *---									---*
 *-------------------------------------------------------------------------*/

#include	"PolynomialServerHeaders.h"
#include	<wait.h>

void		computePolynomials
				(FloatStack*	outputStackPtr,
				 FloatStack*	inputStackPtr
				)
{
  int		toChild[2];
  int		fromChild[2];
  pid_t		polynomialPid;
  char		buffer[BUFFER_LEN];
  float		fOfX;
  float		x;

  //  YOUR CODE HERE
  if  (polynomialPid == 0)
  {
    //  YOUR CODE HERE
  }

  //  YOUR CODE HERE
  while  ( !inputStackPtr->isEmpty() )
  {
    //  YOUR CODE HERE
  }

  //  YOUR CODE HERE
  FILE*	inputPtr	= fdopen(fromChild[0],"r");

  while  ( fgets(buffer,BUFFER_LEN,inputPtr) != NULL )
  {
    //  YOUR CODE HERE
  }

  //  YOUR CODE HERE
}
