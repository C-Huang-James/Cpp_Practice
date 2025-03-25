#include "person.h"
#include "player.h"

Player::Player(std::string_view game_param)
    : m_game(game_param)
{
    //first_name = "John"; Compiler errors
    //last_name = "Snow";
}

std::ostream& operator<<(std::ostream& out, const Player& player){

    // first and last name are private members of the Person class (Base class)
    /*out << "Player : [ game : "  << player.m_game
    << ", names : " << player.first_name
        << " " << player.last_name << "]";*/

    out << "Player : [ game : "  << player.m_game
         << ", names : " << player.get_first_name()
             << " " << player.get_last_name() << "]";
    return out;
}