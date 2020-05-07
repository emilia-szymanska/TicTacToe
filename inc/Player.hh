#ifndef PLAYER_HH
#define PLAYER_HH

struct Player
{
	unsigned int playerID;
	char playerSign;
	Player(unsigned int playerID, char playerSign)
	{
		this->playerID = playerID;
		this->playerSign = playerSign;
	}	
};

#endif
