#pragma once

#include <string>

class State {
	public:
		State() {}
		virtual void reset() = 0;
		virtual void update() = 0;
		virtual void draw() = 0;
        virtual void keyPressed(int key) = 0;

		bool hasFinished(){
			return finished;
		}
		std::string getNextState(){
			return nextState;
		}
		void setFinished(bool finished){
			this->finished = finished;
		}

		void setNextState(std::string nextState){
			this->nextState = nextState;
		}

		int getScore(){
			return score;
		}

		void setScore(int score){
			this->score = score;
		}

		void increaseScore(){
			score += 10;
		}


	private:
		std::string nextState;
		bool finished = false;
		int score = 0;
};