#include"State.h"
#include"../Handler.h"

State*State::currentState = NULL;
void State::setState(State*state){
	currentState = state;
}
State* State::getState(){
	return currentState;
}

//CLASS
State::State(Handler*handler)
	:handler(handler)
{
}
State::~State(){
	handler = NULL;
}