#pragma once
#include <string>
#include <list>
#include <algorithm>
#include "Game.hpp"

class Person
{
private:
    float m_budget;
    std::string m_name;
    std::list<Game> m_games;
public:
    Person(std::string name, float budget){
        m_budget = budget;
        m_name = name;
    }

    bool buy(Game game){
        if (hasGame(game)){
            return false;
        }
        if (m_budget >= game.calculateCurrentPrice()){
            m_budget -= game.calculateCurrentPrice();
            addGame(game);
            return true;
        }else{
            return false;
        }
    }
      
    bool sell(Game game, Person& buyer){
        if (!hasGame(game)){
            return false;
        }
        if ((buyer.getBudget() >= game.calculateCurrentPrice())){
            buyer.setBudget(buyer.getBudget()-game.calculateCurrentPrice());
            removeGame(game);
            m_budget += game.calculateCurrentPrice();
            return true;
        }
        return false;
    }
    
    float getBudget(){
        return m_budget;
    }

    void setBudget(float budget){
        m_budget = budget;
    }

    std::list<Game> getGames(){
        return m_games;
    }

    void setGames(std::list<Game> games){
        m_games = games;
    }

    void addGame(Game game){
        m_games.push_back(game);
    }

    void removeGame(Game game){
        int i = 0;
        for (Game owned_game: m_games){
            if (owned_game.getTitle() == game.getTitle()){
                // m_games.splice(i, 1);
            }
        }
    }

    std::string getName(){
        return m_name;
    }

    void setName(std::string name){
        m_name = name;
    }

    bool hasGame(Game game){
        for (Game owned_game: m_games){
            if (owned_game.getTitle() == game.getTitle()){
                return true;
            }
        }
        return false;
    }
};
