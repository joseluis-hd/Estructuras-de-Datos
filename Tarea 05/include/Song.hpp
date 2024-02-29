#ifndef SONG_HPP
#define SONG_HPP

#include <iostream>
#include <string>

class Song
{
    private:
        std::string name;
        std::string author;
        std::string interpreter;
        std::string fileName;
        int ranking;
        int position;

    public:
        Song();
        Song(const Song&);

        std::string getName() const;
        std::string getAuthor() const;
        std::string getInterpreter() const;
        std::string getFileName() const;
        int getPosition() const;
        int getRanking() const;

        void setName(const std::string&);
        void setAuthor(const std::string&);
        void setInterpreter(const std::string&);
        void setFileName(const std::string&);
        void setPosition(const int&);
        void setRanking(const int&);

        std::string toString() const;

        bool operator == (const Song &) const;
        bool operator != (const Song &) const;
        bool operator > (const Song &) const;
        bool operator >= (const Song &) const;
        bool operator < (const Song &) const;
        bool operator <= (const Song &) const;

        friend std::ostream& operator << (std::ostream&, const Song&);
        friend std::istream& operator >> (std::istream&, Song&);
};

#endif // SONG_HPP
