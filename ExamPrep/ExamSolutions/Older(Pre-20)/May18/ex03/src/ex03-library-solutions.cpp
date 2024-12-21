#include <iostream>
#include "ex03-library.h"

//Do not modify
MovieEvaluations::MovieEvaluations() {
	movies.insert("The Godfather");
	movieToEvaluation["The Godfather"]=10;
}

//Do not modify
bool MovieEvaluations::hasEvaluation(string movie){
	//if(currencies.count(currencyCode) > 0){
	if(movies.find(movie) != movies.end()){
		//I have an evaluation for the movie
		return true;
	}
	else{
		return false;
	}
}

//Exercise 3 (a) Check and correct if necessary
void MovieEvaluations::print(){
	cout << "I have the following evaluations:"<<endl;
	for (map<string,double>::iterator it=movieToEvaluation.begin(); it!=movieToEvaluation.end(); ++it){
		cout << ' '<< "movie " << it->first  << " has evaluation " << it->second << endl;
	}
}

/*
void MovieEvaluations::printWrong(){
	cout << "I have the following evaluations:"<<endl;
	for (map<string,double>::iterator it=movieToEvaluation.begin(); it!=movieToEvaluation.end(); ++it){
		//cout << ' '<< "movie " << it->first  << " has evaluation " << it->second << endl;
		  cout << ' '<< "movie " << it->second  << " has evaluation " << it->first << endl;
	}
}
 */

//Exercise 3 (b) Implement this function
bool MovieEvaluations::addEvaluation(string movie,double evaluation) {
	if(hasEvaluation(movie)){
		//I already have this element. Hence I return false
		return false;
	}
	else if(evaluation < 0){
		//Evaluations must be non-negative
		return false;
	}
	else if(evaluation > 10){
		//Evaluations must be smaller than 10
		return false;
	}
	else{
		movies.insert(movie);
		movieToEvaluation[movie]=evaluation;
		return true;
	}
}

//Exercise 3 (c) Implement this function
bool MovieEvaluations::updateEvaluation(string movie,double newEvaluation) {
	if(!hasEvaluation(movie)){
		//I do not have yet an evaluation for this movie.
		return false;
	}
	else if(newEvaluation < 0){
		//Evaluations must be non-negative
		return false;
	}
	else if(newEvaluation > 10){
		//Evaluations must be smaller than 10
		return false;
	}
	else{
		movieToEvaluation[movie]=newEvaluation;
		return true;
	}
}

//Exercise 3 (d) Implement this function
string MovieEvaluations::computeVerboseEvaluation(string movie) {
	if(!hasEvaluation(movie)){
		//I do not have an evaluation for this movie.
		return "not evaluated";
	}
	else{
		double evaluation=movieToEvaluation[movie];
		/* 		"very bad"  if 0.0 <= evaluation <=  2.5
		 * 		"bad"	    if 2.5 <  evaluation <=  5.0
		 * 		"good"      if 5.0 <  evaluation <=  7.5
		 * 		"very good" if 7.5 <  evaluation <= 10.0 */
		if(evaluation<=2.5){
			return "very bad";
		}
		else if(evaluation<=5){
			return "bad";
		}
		else if(evaluation<=7.5){
			return "good";
		}
		return "very good";
	}
}
