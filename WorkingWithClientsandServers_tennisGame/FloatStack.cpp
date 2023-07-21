/*-------------------------------------------------------------------------*
 *---									---*
 *---		FloatStack.cpp						---*
 *---									---*
 *---	    This file defines methods for a class that implements a	---*
 *---	stack ADT of 'float' instances using individually 'new'ed	---*
 *---	FloatNode instances.						---*
 *---									---*
 *---	----	----	----	----	----	----	----	----	---*
 *---									---*
 *---	Version 1.0		2021 May 27		Joseph Phillips	---*
 *---									---*
 *-------------------------------------------------------------------------*/

#include	"PolynomialServerHeaders.h"

FloatStack::~FloatStack	()
{
  FloatNode*	next;

  //  YOUR CODE HERE
}


void		FloatStack::push(float	number
				)
{
  FloatNode*	next	= new FloatNode(number);

  //  YOUR CODE HERE
}


float		FloatStack::pop	()
{
  if  (isEmpty())
  {
    fprintf(stderr,"Attempt to pop() empty stack!\n");
    exit(EXIT_FAILURE);
  }

  float		toReturn	= topPtr_->number_;
  //  YOUR CODE HERE

  return(toReturn);
}
