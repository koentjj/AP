#pragma once
#include <string>
#include <math.h>
#include <ctime>


int getCurrentYear()
{
  std::time_t t = std::time(nullptr);
  std::tm *const pTInfo = std::localtime(&t);
  return (1900 + pTInfo->tm_year);
}


class Game
{
private:
    std::string m_title;
    int m_releaseDate;
    float m_originalPrice;
public:
    Game(std::string title, int releasedate, float originalprice){
        m_title = title;
        m_releaseDate = releasedate;
        m_originalPrice = originalprice;
    }

    std::string getTitle(){
        return m_title;
    }

    void setTitle(std::string title){
        m_title = title;
    }

    int getReleaseDate(){
        return m_releaseDate;
    }

    void setReleaseDate(int releasedate){
        m_releaseDate = releasedate;
    }

    float getOriginalPrice(){
        return m_originalPrice;
    }

    void setOriginalPrice(float originalPrice){
        m_originalPrice = originalPrice;
    }

    float calculateCurrentPrice(){
        int currtime = getCurrentYear();
        return floorf((m_originalPrice * (0.7 * (currtime - m_releaseDate))) * 100) / 100;
    }
};



