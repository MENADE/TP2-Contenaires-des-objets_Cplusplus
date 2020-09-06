#ifndef __SCORE_H__
#define __SCORE_H__

#pragma once
#include <fstream>
#include<string>
#include<iostream>


class Score
{

private :
	long identifiantPartie;
	std::string login;
	long score;

public :

	Score() {

		this->identifiantPartie = 0;
		this->login ="";
		this->score =0;
		
	}

	Score(long identifiantPartie, 	std::string login,	long score) {

		this->identifiantPartie= identifiantPartie;
		this->login = login;
		this->score = score;
	}


	long getScore () const
	{
		return this->score;
	}

	std::string getLogin() const
	{
		return this->login;
	}

	long getIdentifiantPartie() const
	{
		return this->identifiantPartie;
	}

	//--2-1--Implémentation de l'operator< qui compare inversement les joueurs 
	bool operator<(const Score& score_doite) const {
		if (score_doite.score < this->score ) return true;
		return false;
	}


};
#endif

